/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include "merge.h"

int main()
{


    
    int array[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    
    int elemNumber = sizeof(array)/sizeof(array[0]);
    
    printf("Before sort: \n");
    printArray(array, elemNumber);
    
    printf("Processing: \n");
    mergesort(array, elemNumber);
    
    printf("After sort: \n");
    printArray(array, elemNumber);
    
    
    return 0;
}
