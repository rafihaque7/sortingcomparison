# include "mergeSort.h"

uint32_t mergeSortMoves =0;
uint32_t mergeSortCompares=0;




/*
 * Pseudo code from https://www.youtube.com/watch?v=TzeBrDU-JaY
 * For additional help, I went to his gitHub https://gist.github.com/mycodeschool/9678029
 */

//void merge(uint32_t L[],uint32_t R[],uint32_t A[])
void merge(uint32_t A[],uint32_t L[], uint32_t leftCount, uint32_t R[],uint32_t rightCount)
{
//    int nL = sizeof(L); //Size of the left array
//    int nR = sizeof(R); //Size of the right array
//    printf("%d %d",nL,nR);

    uint32_t i=0,j=0,k=0; //Positon of everything starts at 0

    while(i<leftCount && j<rightCount)  //i is counting the left array, and j is counting the right array
    {

        if(L[i]<=R[j])  //if left is smaller than the right
        {
            mergeSortCompares++;
            A[k] = L[i];    //Then the number from the left array moves to the main array
            mergeSortMoves++;
            i++;    //The left array position moves by one
        }
        else
        {
            //mergeSortCompares++;
            A[k] = R[j];    //If the right number is bigger than left
            mergeSortMoves++;
            j++;    //The count for right array moves by one
        }
        k++;    //The k, which is counting the main array always moves by one
    }

    while(i<leftCount)  //What if one array has numbers left over
    {
        //mergeSortCompares++;
        A[k] = L[i];
        mergeSortMoves++;
        i++;
        k++;

    }

    while(j<rightCount)
    {
        //mergeSortCompares++;
        A[k] = R[j];
        mergeSortMoves++;
        j++;
        k++;
    }
}

/*
 * Pseudo code from https://www.youtube.com/watch?v=TzeBrDU-JaY
 * For additional help, I went to his gitHub https://gist.github.com/mycodeschool/9678029
 */

void mergeSort(uint32_t A[],uint32_t n) //This combines the two arrays together
{
    if(n<2) //Recursive call stop
    {
        mergeSortCompares++;
        return;
    }



    uint32_t mid = n/2; //Middle is the integer
    uint32_t *left = calloc(mid, sizeof(uint32_t));
    uint32_t *right = calloc(n-mid, sizeof(uint32_t));  //So if its an odd number
    for(uint32_t i=0; i<mid; i++)
    {
        left[i] = A[i]; //Puts it in the array
        mergeSortMoves++;
    }
    for(uint32_t i=mid; i<n; i++)
    {
        right[i-mid] = A[i];
        mergeSortMoves++;   //also puts it in the right array
    }

    mergeSort(left,mid);    //It breaks it down and sorts left half and right haf
    mergeSort(right,n-mid);
    merge(A,left,mid,right,n-mid);  //It puts it together

    free(left); //Deallocates the memory
    free(right);
}
