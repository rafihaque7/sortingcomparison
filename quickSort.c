//#include "quickSort.h"
# include "quickSort.h"

uint32_t quickSortMoves = 0;
uint32_t quickSortCompares = 0;
//The concept was explained by https://www.youtube.com/watch?v=MZaf_9IZCrc
void quickSort(uint32_t a[],int left, int right)
{
    if(left>=right)
    {
        //quickSortCompares++;
        return;
    }
    int pivot = right;  //The pivot point is where it puts all the number less than pivot left of pivot, and all the numbers greater right of pivot
    //quickSortMoves++;
    int i = left-1;
    //quickSortMoves++; //Apparently Darrell does not count temporary variables
    int j = left;
    //quickSortMoves++;

        while (j <=right)   //It stops depending on the function's parameter, and its inclusive
        {
            quickSortCompares++;
            if (a[j] < a[pivot])
            {
                //quickSortCompares++;
                i++;
                SWAP(a[j],a[i]);    //Swaps the two numbers so.
                quickSortMoves+=3;
            }
            j++;
        }

    SWAP(a[pivot],a[i+1]);  //Moves the right most, which is swap to swap position. And i+1 to rightmose
    quickSortMoves+=3;

    //if(left!=right)
    quickSort(a,left,i);
    quickSort(a,i+2,right);
}
