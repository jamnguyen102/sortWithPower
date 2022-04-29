#include "merge.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int nearestPower(int num);
void printArray(int array[], int n);

void mergesort(int key[], int n){   
    int j, k ,m, *w;
    /*for ( m =1; m < n; m *= 2)
        ;
    if (n < m){
        printf("Error, array is not power of 2");
        exit(1);
    } */
    
    w = calloc(n,sizeof(int));  // key[j] is the array being modified, w[j] is a draft
    assert(w!= NULL);
    
    int currentPowerof2 = n; // n = 15 => currentPowerof2 = 8, 4, 2, 1
    int totalPowerOf2 = 0;  // totalPowerOf2 = 0, 0+8, 8+4, 12+2, 14 +1
    
    for ( m = n ; m != 0 ; m = m - currentPowerof2){ 
                                    // m holds value of n, so n shouldn't be modified, m is a remainder
                                    // m = m - currentPowerof2 i.e. m = 15 - 8 = 7
                                    // *loop*                       m = 7 - 4  = 3
                                    // *loop*                       m = 3 - 2  = 1 .... and m = 1 - 1 = 0, 
                                    // when m = 0 then the loop stops
                                    
        currentPowerof2 = nearestPower(m);
        //printf("\n\tcurrent power is %d \n", currentPowerof2);
        
        for( k = 1; k < currentPowerof2; k *=2){
            for ( j = totalPowerOf2; j < currentPowerof2 + totalPowerOf2 - k ; j += 2*k)
                merge(key + j, key + j + k, w + j, k, k);
                
            
            for ( j = totalPowerOf2; j < currentPowerof2 + totalPowerOf2; ++j)      //write back from draft to key[j]
                key[j] = w[j];
        
        }//internal loop to only merge arrays with size of power of 2 i.e 1,2,4,8,16...
        
        
        merge(key, key + totalPowerOf2, w, totalPowerOf2, currentPowerof2);         // merge the prev processed array with current array
        for ( j = 0; j < currentPowerof2 + totalPowerOf2; ++j)                      // write back from draft to key[j]
                key[j] = w[j];
        
        totalPowerOf2 += currentPowerof2;    
        
        
        //printArray(w, totalPowerOf2);  // just printing temporary array w[], uncommment it if you want to see the loops
        
    }//outer for loop
    
    
    free(w);
    
    
    
}

int nearestPower(int num){
    int index = 1;
    while (index*2 <= num)
        index *= 2;
        
    return index;
}

void printArray(int array[], int n){
    //wrt.c function
    int i;
    for (i = 0; i < n; ++i){
        printf("%4d%s", array[i], (( i < n - 1) ? "" : "\n") );
    }
}
