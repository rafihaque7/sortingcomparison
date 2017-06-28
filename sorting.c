# include <stdio.h>
# include <stdlib.h> //Needed for rand and srand
# include <getopt.h>
# include <stdint.h>
# include "sorting.h"
# include "minSort.c"
# include "bubbleSort.c"
# include "insertionSort.c"
# include "quickSort.c"
# include "mergeSort.c"
# include "bv.h"
# define MASK 0x00ffffff


const char *sortName[] = {"Min Sort","Bubble Sort","Insertion Sort","Quick Sort","Merge Sort"}; //This is never used, it's just for me


int main(int argc, char **argv) //argv is how you get the argument
{
    int option; // for getopt


    uint32_t numElements = 100;
    //int numElementsFlag =0;
    uint32_t printElements = 100;
    //int printElementsFlag=0;
    int seedNum = 8062022;

    bitV *sortVec = newVec(5);  //Creates a bitvector for the five sorting method
    uint32_t *elementsArray = calloc(numElements,sizeof(uint32_t));

    opterr = 0;

    while ((option = getopt(argc, argv, "AmbiqMp:r:n:")) != -1)
    {
        switch (option)
        {
            case 'A':   //All sort
            {
                oneVec(sortVec);    //oneVec is set to all 1
            }
            case 'm':   //minSort
            {
                setBit(sortVec,0);
                break;
            }
            case 'b':   //bubbleSort
            {
                setBit(sortVec,1);
                break;
            }

            case 'i':   //insertionSort
            {
                setBit(sortVec,2);
                break;
            }
            case 'q':   //quickSort
            {
                setBit(sortVec,3);
                break;
            }
            case 'M':   //mergeSort
            {
                setBit(sortVec,4);
                break;
            }
            case 'p':   //for printing
            {
                //printElementsFlag=1;
                printElements=atoi(optarg); //So the user typed can type -p 23434
            }
            case 'r':
            {
                seedNum = atoi(optarg);
                //srand(atoi(optarg));
                break;
            }
            case 'n':   //When the user types in -n they will get to sellect how many elements they want.
            {
                // if (numElementsFlag) {
                //     fprintf(stderr, "[ARGUMENT ERROR] Value for option already set {-n: %d\n", numElements);
                //     return 3;
                // }
                //numElementsFlag=1;
                numElements = atoi(optarg);
                //printf("You set the the number of elements to be %d\n",numElements );
                elementsArray = realloc(elementsArray,sizeof(uint32_t)*numElements);
                break;
            }
        }
    }

srand(seedNum); //The seed gets initialized
setElementsFunc(elementsArray,numElements);
    for(uint32_t i=0;i<lenVec(sortVec);i++)
    {
        if(valBit(sortVec,i)==1)    //Bit vector to determine what it is
        {
            doAll(elementsArray,numElements,printElements,i);
        }
    }

    free(elementsArray);
    elementsArray=NULL;
    delVec(sortVec);
    return 0;
}

/*
To initialize a sorting method with an integer doAll(elementsArray,numElements,printElements,i);
*/
void doAll(uint32_t *elementsArray, uint32_t numElements, uint32_t printElements,int typeSort)
{
    switch(typeSort)
    {
        case 0:
        {
            uint32_t *minSortArray = calloc(numElements,sizeof(uint32_t)); //Make an array that is the size of elementsArray
            copyElementsFunc(elementsArray,numElements,minSortArray); //Copy from the main array
            minSort(minSortArray,numElements);  //Run the method
            printf("Min Sort\n"); //or sortName[i];
            printf("%d elements\n",numElements);    //Print the total number of elements
            printf("%d moves\n",getminSortMoves()); //Call the function
            printf("%d compares\n", getminSortCompares());
            printElementsFunc(minSortArray,numElements,printElements);  //Prints the sorted array
            free(minSortArray); //Free it
            minSortArray=NULL;
            break;
        }
        case 1:
        {
            uint32_t *bubbleSortArray = calloc(numElements,sizeof(uint32_t));   //For comments see minSort or case 0
            copyElementsFunc(elementsArray,numElements,bubbleSortArray);
            bubbleSort(bubbleSortArray,numElements);
            printf("Bubble Sort\n"); //or sortName[i];
            printf("%d elements\n",numElements);
            printf("%d moves\n",getbubbleSortMoves());
            printf("%d compares\n", getbubbleSortCompares());
            printElementsFunc(bubbleSortArray,numElements,printElements);
            free(bubbleSortArray);
            bubbleSortArray=NULL;
            break;
        }
        case 2:
        {
            uint32_t *insertionSortArray = calloc(numElements,sizeof(uint32_t)); //For comments see minSort or case 0
            copyElementsFunc(elementsArray,numElements,insertionSortArray);
            insertionSort(insertionSortArray,numElements);
            printf("Insertion Sort\n"); //or sortName[i];
            printf("%d elements\n",numElements);
            printf("%d moves\n",getinsertionSortMoves());
            printf("%d compares\n", getinsertionSortCompares());
            printElementsFunc(insertionSortArray,numElements,printElements);
            free(insertionSortArray);
            insertionSortArray=NULL;
            break;
        }
        case 3:
        {
            uint32_t *quickSortArray = calloc(numElements,sizeof(uint32_t)); //For comments see minSort or case 0
            copyElementsFunc(elementsArray,numElements,quickSortArray);
            quickSort(quickSortArray,0,numElements-1); //It quicksorts from 0 to the length, and position mapping would be 1 less
            printf("Quick Sort\n");
            printf("%d elements\n",numElements);
            printf("%d moves\n",quickSortMoves);    //Just calling the variable instead of the function
            printf("%u compares\n",quickSortCompares);
            printElementsFunc(quickSortArray,numElements,printElements);
            free(quickSortArray);
            quickSortArray=NULL;
            break;
        }
        case 4: //M
        {
            uint32_t *mergeSortArray = calloc(numElements,sizeof(uint32_t));
            copyElementsFunc(elementsArray,numElements,mergeSortArray);
            mergeSort(mergeSortArray,numElements); //It quicksorts from 0 to the length, and position mapping would be 1 less
            printf("Merge Sort\n");
            printf("%d elements\n",numElements);
            printf("%d moves\n",mergeSortMoves);
            printf("%u compares\n",mergeSortCompares);
            printElementsFunc(mergeSortArray,numElements,printElements);
            free(mergeSortArray);
            mergeSortArray=NULL;
            break;


        }

    }
}

/*
Intially the elementsArray is set to all 0s, setElementsFunc puts the random numbers
*/
void setElementsFunc(uint32_t *elementsArray,uint32_t numElements)
{

    for(uint32_t i=0; i<numElements; i++)
    {
        //elementsArray[i] = rand()%1000000;
        elementsArray[i] = (rand()&MASK);
    }
}

/*
Copies everything from main array(elementsArray) to the designated array ex(minSortArray)
*/
void copyElementsFunc(uint32_t *copyingFrom, uint32_t numElements, uint32_t *copyingTo)
{
    for(uint32_t i=0; i<numElements; i++)
    {
        copyingTo[i] = copyingFrom[i];
    }

}

/*
theArray parameter could be any array that you would like to print out.
*/
void printElementsFunc(uint32_t *theArray,uint32_t numElements,uint32_t printElements)
{
    int countSpace =0;

    for(uint32_t i=0; i<numElements&&i<printElements;i++)
    {

            printf("%13d", theArray[i]);
            countSpace++;
            if(countSpace==7)   //Will print out a new line, so it is 7 numbers at a time
            {
                printf("\n");
                countSpace=0;
            }

    }
    printf("\n");
}
