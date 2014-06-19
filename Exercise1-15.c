//
//  main.c
//  ExampleC
//
//  Created by Matthew Lu on 6/06/2014.
//  Copyright (c) 2014 Matthew Lu. All rights reserved.
//




#include <stdio.h>

// print Fahrenheit-Celsius table

void printTemperature(int lower,int upper,int step)
{
    float fahr,celsius;
    fahr = lower;
    while (fahr <=upper) {
        celsius = (5.0 /9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n",fahr,celsius);
        fahr = fahr +step;
    }
    
}

int main(int argc, const char * argv[])
{

    int lower, upper,step;
    
    lower = 0; //lower limit of temperature table
    upper = 300; // upper limit
    step = 20;
    
    printTemperature(lower,upper,step);
   

    return 0;
}

