#include "insertionSort.h"


int insertionSortMoves = 0;
int insertionSortCompares = 0;

//Psuedo code given by darrell
void insertionSort(uint32_t A[],uint32_t length)
{
    int j;
    uint32_t tmp;
    int n = length;

    for(int i=0; i<n; i++ )
    {
        tmp = A[i];
        //i would put insertionSortMoves++, but if i do that then the moves becomes different from his
        j = i-1;
        while(j>=0 && A[j]>tmp) //When j becomes 0 it stop
        {
            insertionSortCompares++;
            A[j+1] = A[j];  //Moving it
            insertionSortMoves++;
            j = j -1;
        }
        A[j+1] = tmp;
        insertionSortMoves++;

    }

}

int getinsertionSortMoves()
{
    return insertionSortMoves;
}

int getinsertionSortCompares()
{
    return insertionSortCompares;
}
