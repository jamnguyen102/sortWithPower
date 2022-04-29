
/* C program for Merge Sort */
#include<stdlib.h>
#include<stdio.h>
#include "merge.h"

void merge(int a[], int b[], int c[], int m , int n){
    // a[] & b[] are two arrays
    // c[] will be the merged array of a[] & b[]
    // m is size of a[], n is size of b[]
    
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
        
        while (i < m)
            c[k++] = a [i++];
        while (j < n)
            c[k++] = b[j++];
}