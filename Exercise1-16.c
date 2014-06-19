//
//  main.c
//  ExampleC
//
//  Created by Matthew Lu on 6/06/2014.
//  Copyright (c) 2014 Matthew Lu. All rights reserved.
//




#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

int myGetline(char line[], int maxline);
void copy(char to[], char from[]);


//print longest input line
int main(int argc, const char * argv[])
{

    int len; // current line length
    int max; // maximum length seen so far
    char line[MAXLINE];  // current input line
    char longest[MAXLINE]; //longest line saved here

    max = 0;
    
    while ((len = myGetline(line, MAXLINE)) > 0) {
        printf("%d, %s",len-1,line);
        
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    
    if (max > 0) {  // there was a line
        printf("length : %d the line: %s",max-1, longest);
    }
    
    
    return 0;
}

// myGetline: read a line into s, return length
int myGetline(char s[], int lim)
{
    int c=0,i,j;
    j=0;
    
    for (i=0; (c=getchar()) != EOF && c!= '\n'; ++i) {
        if (i < lim-2) {
        s[i]=c;
            ++j;
        }
        
    }
    
    if (c == '\n') {
        s[i]=c;
        ++j;
        ++i;
    }
    
    s[i] = '\0';
    return i;
}

//copy: copy 'from' into 'to', assume to is big enough
void copy(char to[],char from[])
{
    int i;
    i=0;
    while ((to[i] = from[i]) !='\0' ) {
        ++i;
    }
}
