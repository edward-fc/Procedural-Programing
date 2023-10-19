#include <stdio.h>

float fahr_to_celsius (float f_temp)
{
    float c_temp;
    c_temp = (f_temp - 32)/1.8;
    return c_temp;
}
float celcius_to_fahr(float c_temp){
    float f_temp;
    f_temp = c_temp*1.8 + 32;
    return f_temp;
}

float fahr_to_kelvin (float f_temp)
{
    float k_temp;
    k_temp = fahr_to_celsius(f_temp) + 273.15;
    return k_temp;
}
float kelvin_to_fahr(float k_temp){
    float f_temp;
    f_temp = celcius_to_fahr(k_temp - 273.15);
    return f_temp;
}
float fahr_to_new(float f_temp){
    float n_temp;
    n_temp = (f_temp - 32) / 5.45454555;
    return n_temp;
}

int main () 
{
    float fahrenheit;
    char option;

    printf ("Enter a temperature to convert in Fahrenheit:\n");
    scanf ("%f", &fahrenheit);
    float celcius = fahr_to_celsius(fahrenheit),kelvin = fahr_to_kelvin(fahrenheit);
    printf ("\n");
    printf ("Select A to convert to Celsius\n");
    printf ("Select B to convert to Kelvin\n");
    printf ("Select C to convert to Celsius\n");
    printf ("Select D to convert to Kelvin\n");
     printf ("Select E to convert to Newton\n");
    printf ("Select Q to quit\n");

    scanf(" %c", &option);
    printf("%f and %f and %f and %f",celcius,kelvin,celcius_to_fahr(celcius),kelvin_to_fahr(kelvin));
    switch (option)
    {
        case 'A': 
        case 'a': printf ("Converted to degrees Celsius: %f\n", fahr_to_celsius(fahrenheit));
                  break;
        

        case 'B': 
        case 'b': printf ("Converted to Kelvin: %f\n", fahr_to_kelvin(fahrenheit));
                  break;
        case 'C': 
        case 'c': printf ("Kelvin Converted to fahrenheit: %f\n", kelvin_to_fahr(kelvin));
                  break;
        case 'D': 
        case 'd': printf ("Celcius Converted to fahrenheit: %f\n", celcius_to_fahr(celcius));
                  break;
        case 'E': 
        case 'e': printf ("Fahrenheit Converted to Newton: %f\n", fahr_to_new(fahrenheit));
                  break;

        case 'Q': break;

        default:  break;
    }

    return 0;
}