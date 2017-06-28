
# include <stdint.h>
# include "bubbleSort.h"

int bubbleSortMoves = 0;
int bubbleSortCompares = 0;

//Psuedo code given by Darrell Long
void bubbleSort(uint32_t A[], uint32_t length)
{
    int n = length;

    //printf("the array size is %d \n",n);
    while(1)
    {
        int swapped = 0;

        for(int i =1; i<n ; i++)    //Not sure if i is suppose to start with 0 or 1
        {

            if(A[i-1] > A[i])
            {
                SWAP(A[i-1],A[i]);  //Swaps if the first number is greater than the second number
                swapped = 1;
                bubbleSortMoves+=3;
                bubbleSortCompares++;

            }
        }
        n = n - 1;
        if(swapped==0) break;
    }
    return;
}

int getbubbleSortMoves()
{
    return bubbleSortMoves;
}

int getbubbleSortCompares()
{
    return bubbleSortCompares;
}
