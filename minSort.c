# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include "minSort.h"


uint32_t minSortMoves = 0;
uint32_t minSortCompares = 0;

//Code given by Darrell Long
uint32_t minIndex(uint32_t a[], uint32_t first, uint32_t last)
{
    uint32_t smallest = first;

    for(uint32_t i = first; i<last; i++)
    {
        smallest = a[i] < a[smallest] ? i : smallest;
        minSortCompares++;
    }
    return smallest;

}

//Method given by Darrell Long
void minSort(uint32_t a[], uint32_t length)
{
    for(uint32_t i=0; i<length-1; i++ )
    {
        uint32_t  smallest = minIndex(a,i,length);

        if(smallest != i)
        {
            SWAP(a[smallest],a[i]);
            minSortMoves+=3;
        }
    }
    return;
}

//So I can call the function to get the number of moves
uint32_t getminSortMoves()
{
    return minSortMoves;
}

uint32_t getminSortCompares()
{
return minSortCompares;
}
