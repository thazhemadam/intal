#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include "intal.h"


int prinHelp ();

int main(int argc, char const *argv[]) {
    if (strcmp(argv[1], "--help") == 0 || argv[1][0] != '-') {
        prinHelp();
        return 0;
    }

    const char* ch = argv[1];

    


// Add
    if(!strcmp(ch,"-add")){
        printf("%s\n", intal_add(argv[2],argv[3]));
    }

// Difference
    if(!strcmp(ch,"-diff")){
        printf("%s\n", intal_diff(argv[2],argv[3]));
    }

// Multiplication   
    if(!strcmp(ch,"-mul")){
        printf("%s\n", intal_multiply(argv[2],argv[3]));
    }

// Comparison
    if(!strcmp(ch,"-comp")){
        printf("%d\n",intal_compare(argv[2],argv[3]));

    }

// Modulus   
    if(!strcmp(ch,"-mod")){
        printf("%s\n", intal_mod(argv[2],argv[3]));
    }

// Power
    if(!strcmp(ch,"-pow")){
        printf("%s\n", intal_pow(argv[2],atoi(argv[3])));
    }
// GCD
    if(!strcmp(ch,"-gcd")){
        printf("%s\n", intal_gcd(argv[2],argv[3]));
    }
// // Fibonacci 
    if(!strcmp(ch,"-fib")){
        printf("%s\n", intal_fibonacci(atoi(argv[2])));
    }
// Factorial
    if(!strcmp(ch,"-fact")){
        printf("%s\n",intal_factorial(atoi(argv[2])));
    }
// Binary Coefficient
    if(!strcmp(ch,"-bco")){
        printf("%s\n", intal_bincoeff(atoi(argv[2]),atoi(argv[3])));
    }
    return 0;
    


}

int prinHelp () {
    printf("\nUsage: $ ./test_suite <operation> <intal1> <intal2 (if applicable)>\n\n");
    printf("<num> : arbitrary length number with preceeding + or -\n");
    printf("<operation> : \n");
    printf("\t-add : num1 + num2\n");   //Addition
    printf("\t-diff : num1 - num2\n");   //Difference
    printf("\t-mul : (num1)*(num2)\n");   //Multiplication
    printf("\t-comp : num1 =/!= num2\n"); //Comparison
    printf("\t-mod : num1%%num2\n"); //Modulus
    printf("\t-pow : (num1)^(num2)\n"); //Exponential power
    printf("\t-gcd : gcd(num1, num2)\n"); //GCD
    printf("\t-fib : (num1)th Fibonacci element\n"); //Fibonacci Numbers
    printf("\t-fact : (num1)!\n"); //Factorial
    printf("\t-bco : num1 C num2\n"); //Binary Coefficients
    return 0;
}
