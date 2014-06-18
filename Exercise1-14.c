//
//  main.c
//  ExampleC
//
//  Created by Matthew Lu on 6/06/2014.
//  Copyright (c) 2014 Matthew Lu. All rights reserved.
//




#include <stdio.h>
#include <ctype.h>
#define MAXHIST 15    //max length of histogram
#define MAXCHAR 128   //max different characters，最多128个字符

//print horizontal histogram freq. of different characters
int main(int argc, const char * argv[])
{
    int c,i;
    int len; // length of each bar
    int maxvalue; // maximum value for c[]
    
    int cc[MAXCHAR]; // character counters 整形数组存128个字符
    
    
    
    
    for (i=0; i<MAXCHAR; ++i) {
        cc[i] = 0; //初始化都为零
    }
    
    
    
    while ((c=getchar())!=EOF) {
        if (c<MAXCHAR) {
            ++cc[c];    //读输入的字符的ACS2码,如果小于128， 对应的数组的值加1
        }
    }
    
    
    maxvalue = 0; //最大长度，初始为零
    
    for (i=1; i<MAXCHAR; ++i) {
        if (cc[i] > maxvalue) {
            maxvalue = cc[i];  // bar的最大长度设为数组中出现最大的值
        }
    }
    
    
    for (i=1; i<MAXCHAR; ++i) {
        
        if (isprint(i)) { // 参数c是否可打印
            printf("%5d -  %c - %5d : ", i, i, cc[i]);
        }
        else{
            printf("%5d - - %5d : ", i, cc[i]);
        }
        
        
        if (cc[i]>0) {
            if ((len = cc[i] * MAXHIST / maxvalue) <= 0) { // 先赋值给len，按比例算len的值
                len =1;
            }
        }else
        {
            len = 0;
        }
        
        while (len > 0) {
            putchar('*');
            --len;
        }
        
        putchar('\n');
        
    }
    
    
    

    return 0;
}

