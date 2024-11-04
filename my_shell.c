#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

/* Read a line of characters from stdin. */
int getcmd(char *buf, int nbuf) {
    int i = 0;
    while (i < nbuf - 1) { // Leave space for null terminator
        int n = read(0, buf + i, 1); // Read one character at a time from stdin (fd 0)
        if (n < 0) { // Error in reading
            return -1;
        } else if (n == 0) { // EOF
            if (i == 0) return -1; // No input read
            break;
        } else {
            if (buf[i] == '\n') { // Newline character signifies end of command
                buf[i] = 0; // Replace newline with null terminator
                break;
            }
            i++;
        }
    }
    buf[i] = 0; // Ensure null termination
    return i; // Return number of characters read
}

/*
  A recursive function which parses the command
  at *buf and executes it.
*/
__attribute__((noreturn))
void run_command(char *buf, int nbuf, int *pcp) {

    /* Useful data structures and flags. */
    char *arguments[10];
    int numargs = 0;
    /* Word start/end */
    int ws = 1;
    int we = 0;

    int redirection_left = 0;
    int redirection_right = 0;
    char *file_name_l = 0;
    char *file_name_r = 0;

    int p[2];
    int pipe_cmd = 0;

    int sequence_cmd = 0;

    int i = 0;
    /* Parse the command character by character. */
    for (; i < nbuf; i++) {

        /* Parse the current character and set-up various flags:
           sequence_cmd, redirection, pipe_cmd and similar. */
        switch(buf[i]) {
            case ' ':
            case '\t':
                if (!ws && !we) {
                    buf[i] = 0;
                    arguments[numargs++] = &buf[we];
                    ws = 1;
                    we = 0;
                }
                break;
            case ';':
                sequence_cmd = 1;
                buf[i] = 0;
                if (!ws && !we) {
                    arguments[numargs++] = &buf[we];
                }
                break;
            case '|':
                pipe_cmd = 1;
                buf[i] = 0;
                if (!ws && !we) {
                    arguments[numargs++] = &buf[we];
                }
                break;
            case '<':
                redirection_left = 1;
                buf[i] = 0;
                if (!ws && !we) {
                    arguments[numargs++] = &buf[we];
                }
                break;
            case '>':
                redirection_right = 1;
                buf[i] = 0;
                if (!ws && !we) {
                    arguments[numargs++] = &buf[we];
                }
                break;
            default:
                if (ws) {
                    we = i;
                    ws = 0;
                }
                break;
        }

        if (!(redirection_left || redirection_right)) {
            /* No redirection, continue parsing command. */
            if (!ws && !we && (buf[i] == ' ' || buf[i] == '\t' || buf[i] == ';' || buf[i] == '|' || buf[i] == '<' || buf[i] == '>')) {
                buf[i] = 0; // Null-terminate the argument
                arguments[numargs++] = &buf[we]; // Add to arguments
                ws = 1; // Reset word start flag
                we = 0; // Reset word end index
            }
        } else {
            /* Redirection command. Capture the file names. */
            if (redirection_left) {
                ws = 1; // Reset word start flag
                we = i + 1; // The filename starts after the redirection symbol
                redirection_left = 0; // Reset the flag
                // Extract the filename
                while (we < nbuf && buf[we] == ' ') we++; // Skip any leading spaces
                file_name_l = &buf[we];
                // Find the end of the filename
                while (we < nbuf && buf[we] != ' ' && buf[we] != '\n') we++;
                buf[we] = 0; // Null-terminate the filename
            }
            if (redirection_right) {
                ws = 1; // Reset word start flag
                we = i + 1; // The filename starts after the redirection symbol
                redirection_right = 0; // Reset the flag
                // Extract the filename
                while (we < nbuf && buf[we] == ' ') we++; // Skip any leading spaces
                file_name_r = &buf[we];
                // Find the end of the filename
                while (we < nbuf && buf[we] != ' ' && buf[we] != '\n') we++;
                buf[we] = 0; // Null-terminate the filename
            }
        }
    }

    /*
      Sequence command. Continue this command in a new process.
      Wait for it to complete and execute the command following ';'.
    */
    if (sequence_cmd) {
        sequence_cmd = 0;
        if (fork() != 0) { // Parent process
            wait(0); // Wait for the child to finish
            // Execute the next command after ';'
            run_command(&buf[i + 1], nbuf - i - 1, pcp);
        }
    }

    /*
      If this is a redirection command,
      tie the specified files to std in/out.
    */
    if (redirection_left) {
        int fd = open(file_name_l, O_RDONLY);
        if (fd < 0) {
            fprintf(2, "Cannot open file %s for input redirection\n", file_name_l);
            exit(1);
        }
        dup(fd); // Redirect stdin to the file
        close(fd);
    }
    if (redirection_right) {
        int fd = open(file_name_r, O_WRONLY | O_CREATE);
        if (fd < 0) {
            fprintf(2, "Cannot open file %s for output redirection\n", file_name_r);
            exit(1);
        }
        dup(fd); // Redirect stdout to the file
        close(fd);
    }

    /* Parsing done. Execute the command. */

    /*
      If this command is a CD command, write the arguments to the pcp pipe
      and exit with '2' to tell the parent process about this.
    */
    if (strcmp(arguments[0], "cd") == 0) {
        if (numargs < 2) {
            fprintf(2, "cd: missing argument\n");
        } else {
            if (chdir(arguments[1]) < 0) {
                fprintf(2, "cd: cannot change directory to %s\n", arguments[1]);
            } else {
                // Write the success status to the pipe
                write(pcp[1], "2", 1);
            }
        }
        exit(2); // Exit with code '2' to indicate a 'cd' command
    } else {
        /*
          Pipe command: fork twice. Execute the left hand side directly.
          Call run_command recursion for the right side of the pipe.
        */
        if (pipe_cmd) {
            if (pipe(p) < 0) {
                fprintf(2, "Pipe failed\n");
                exit(1);
            }
            if (fork() == 0) { // Child process for the left-hand side command
                close(p[0]); // Close read end
                dup(p[1]); // Redirect stdout to pipe write end
                close(p[1]);
                run_command(buf, i, pcp); // Execute left-hand side command
            } else { // Parent process for the right-hand side command
                close(p[1]); // Close write end
                dup(p[0]); // Redirect stdin to pipe read end
                close(p[0]);
                run_command(&buf[i + 1], nbuf - i - 1, pcp); // Execute right-hand side command
            }
        } else {
            exec(arguments[0], arguments); // Execute the command with arguments
            fprintf(2, "exec %s failed\n", arguments[0]); // If exec returns, it failed
            exit(1);
        }
    }
    exit(0);
}

int main(void) {

    static char buf[100];

    int pcp[2];
    pipe(pcp);

    /* Read and run input commands. */
    while(getcmd(buf, sizeof(buf)) >= 0){
        if(fork() == 0)
            run_command(buf, 100, pcp);

        /*
          Check if run_command found this is
          a CD command and run it if required.
        */
        int child_status;
        char status;
        read(pcp[0], &status, 1); // Read the status code from the pipe
        if(status == '2') { // If status code indicates a 'cd' command
            // The child has already performed the 'cd', nothing more to do
        }
        wait(&child_status); // Wait for the child to finish
    }
    exit(0);
}
