#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

/* Read a line of characters from stdin. */
int getcmd(char *buf, int nbuf) {
  
  // ##### Place your code here
  printf(">>> ");

  // initalise the buff with memset
  memset(buf,0,nbuf);
  
  int n = read(0, buf, nbuf);
  
  if (n<0)
  {
    fprintf(2,"read error from getcmd: %d",n);
    return -1;
  }
  if(*buf == '\0'){
    fprintf(2,"you have entered nothing: %d",n);
    return 0;
  }
  
  return 0;
}


/*
  A recursive function which parses the command
  at *buf and executes it.
*/

__attribute__((noreturn))
void run_command(char *buf, int nbuf, int *pcp) {

  /* Useful data structures and flags. */
  char *arguments[10] = {0};
  int numargs = 0;
  /* Word start/end */
  int ws = -1;

  int redirection_left = 0;
  int redirection_right = 0;
  int main_redirection_left = 0;
  int main_redirection_right = 0;
  char *file_name_l = 0;
  char *file_name_r = 0;

  int p[2]={0};
  int pipe_cmd = 0,pipe_index = 0; //,redirection_right_index=0,redirection_left_index=0

  int sequence_cmd = 0;
  int sequence_index = 0;

  
  
  /* Parse the command character by character. */
  for (int i = 0; i < nbuf; i++) {
    // Tale the charectere from the buf
    char *c = &buf[i];
    /* Parse the current character and set-up various flags:
       sequence_cmd, redirection, pipe_cmd and similar. */

    if (*c == '|' ){
      pipe_cmd = 1;
      pipe_index = numargs+1;
    }
    if (*c == '>' ){
      main_redirection_right = 1;
      redirection_right = 1;
      // redirection_right_index = numargs+1;
    }
    if (*c == '<' ){
      redirection_left = 1;
      main_redirection_left = 1;
      // redirection_left_index = numargs+1;
    }
    if (*c == ';' ){
      sequence_cmd = 1;
      if(sequence_index == 0){
        sequence_index=numargs;
      }
    }
    if(*c=='\n' || *c=='@'){
      buf[i] = '\0';
      break;
    }
    
    if (!(redirection_left || redirection_right)) {
      /* No redirection, continue parsing command. */
      // Place your code here.
      if (*c != ' ' && *c!='\n' && *c != '\0' && *c !='\t' ){//
        if(ws == -1)
        {
          // Start a new word
          // go through the buff put the ws of buf into arguments 
          
          arguments[numargs] = c;
          
          ws=0;
          //Increment numargs
          numargs++;
          if (numargs >= 10)
          {
            fprintf(2,"Too Many Arguments\n");
            exit(0);
          }
          
        }
      }else{
        if (ws != -1)
        {
          if(*c=='\n'){
            buf[i] = '\0';
            ws = -1;
            break;
          }
          buf[i] = '\0';
          ws = -1;
        }
      }
      
    } else {
      /* Redirection command. Capture the file names. */
      // ##### Place your code here.
      if(*c != ' ' && *c!='\n' && *c != '\0' && *c !='\t' && *c !='<' && *c !='>'){
          // Start a new word
          // go through the buff put the ws of buf into arguments
          if(ws == -1){
            if (redirection_left)
            {
              file_name_l = c;
            }else{
              file_name_r = c;
            }
            ws=0;
          }
      } else {
        if (ws != -1)
        {
          if(*c=='\n'){
            buf[i] = '\0';
            ws = -1;
            break;
          }
          buf[i] = '\0';
          ws = -1;
          redirection_left = 0;
          redirection_right = 0;
        }
      }
    }

  }
  
  for (int i = 0; i < 10; i++)
  {
    fprintf(2,"%d %s\n",i,arguments[i]);
  }
  
  /*
    Sequence command. Continue this command in a new process.
    Wait for it to complete and execute the command following ';'.
  */
 
  if (sequence_cmd) {
    sequence_cmd = 0;
    char *left_exec[10]={0},*right_exec[10]={0};
    if(*arguments[sequence_index] == ';'){
      sequence_index++;
    }
    for (int i = 0; i < nbuf; i++)
    {
      if(buf[i] == ';'){
        buf[i] = '\n';
        buf[i+1] = '@';
        break;
      }
    }
    
    // printf("%d\n",sequence_index);
    left_exec[0] = arguments[0];
    right_exec[0] = arguments[sequence_index];
    // for(int i=0; i<10;i++){
    //   printf("r:%s\n",right_exec[i]);
    // }
    
    if (fork() != 0) {
      wait(0);
      // for (int i = 0; i < 10; i++)
      // {
      //   printf("r: %d %s\n",i,right_exec[i]);
      // }
      if (right_exec[0]){
        // printf("%d\n",*right_exec[0]);
        run_command(*right_exec,sizeof(right_exec),pcp);
      }
      exit(0);
    }
    else{
      // need to test left here
      // for (int i = 0; i < 10; i++)
      // {
      //   printf("l: %d %s\n",i,left_exec[i]);
      // }
      run_command(*left_exec,sizeof(left_exec),pcp);
    }
  }
  /*
    If this is a redirection command,
    tie the specified files to std in/out.
  */
  if (main_redirection_left) {
    // ##### Place your code here.
    int fd_in = open(file_name_l,O_RDONLY|O_CREATE);
    if (fd_in < 0){
      fprintf(2,"open input file\n");
      exit(1);
    }
    close(0);
    dup(fd_in);
    close(fd_in);
  }
  if (main_redirection_right) {
    // ##### Place your code here.
    int fd_out = open(file_name_r,O_WRONLY|O_CREATE|O_TRUNC);
    if (fd_out < 0){
      fprintf(2,"open input file\n");
      exit(1);
    }
    
    close(1);
    dup(fd_out);
    close(fd_out);
  }
  
  /* Parsing done. Execute the command. */
  
  
  
  /*
    If this command is a CD command, write the arguments to the pcp pipe
    and exit with '2' to tell the parent process about this.
  */
  if (strcmp(arguments[0], "cd") == 0) {
    // ##### Place your code here.#
    if (*arguments[1] != '\0'){
      fprintf(2,"Argument wrote: %d\n",write(pcp[1], 
      arguments[1], sizeof(arguments[1])));
      exit(2);
    }
  } else {
    /*
      Pipe command: fork twice. Execute the left hand side directly.
      Call run_command recursion for the right side of the pipe.
    */
    if (pipe_cmd) {
      // ##### Place your code here.
      char *left_exec[10]={0},*right_exec[10]={0};
      for (int i = 0; i < pipe_index; i++)
      {
        if(*arguments[i] == '|')
        {
          pipe_index = i+1;
          *arguments[i] = '\n';
          break;
        }else{
          left_exec[i]=arguments[i];
        }
      }
      right_exec[0] = arguments[pipe_index];
      fprintf(2,"%s\n",right_exec[0]);
      int count_pipes = 0;
      for (int i = 0; i < nbuf; i++)
      {
        if(buf[i] == '|'){
          count_pipes++;
        }
        // if(buf[i] == '\n'){
        //   break;
        // }
        if (buf[i]=='@'){
          if(count_pipes==1){
            buf[i-1]='\n';
          }
        }
      }
      
      // Initlised the pipe
      pipe(p);
      int pid1 = fork();
      // Left side of the pipe 
      if (pid1 == 0)
      {
        close(p[0]);
        close(1);
        dup(p[1]);
        close(p[1]);
        exec(left_exec[0],left_exec);
        fprintf(2,"exec has failed\n");
      }
      // Right side of the pipe
      
      int pid2 = fork();
      if (pid2 == 0)
      {
        close(p[1]);
        close(0);
        dup(p[0]);
        close(p[0]);
        run_command(*right_exec,sizeof(right_exec),pcp);
      }
      
      close(p[0]);
      close(p[1]);

      wait((int *) 0);
      wait((int *) 0);
      
    } else {
      // ##### Place your code here.
      // Create a Child Process 
      if(arguments[0]){
        exec(arguments[0],arguments);
        fprintf(2,"There is an error when exec\n");
      }
      
    }
  }
  exit(0);
}


int main(void) {

  static char buf[100];

  int pcp[2];
  if(pipe(pcp) == -1){
    printf("Pipe Error");
  }
  
  /* Read and run input commands. */
  while(getcmd(buf, sizeof(buf)) >= 0){ 
    int pid = fork();
    if(pid == 0)
    {
      // CHild Process
      // printf("i ran\n");
      run_command(buf, 100, pcp);
      
    }
    else
    {
      /*
        Check if run_command found this is
        a CD command and run it if required.
      */
      // Parent Process
      int child_status;
      wait(&child_status);
      
      // ##### Place your code here
      if (child_status == 2)
      {
        char received_byte[100];
        if(read(pcp[0], &received_byte, sizeof(received_byte)) != sizeof(received_byte))
        {
          printf("Reading of directory error: %s\n",received_byte);
        }
        printf("chdir gave: %d\n",chdir(received_byte));
      }
    }
    
  }
  exit(0);
}
