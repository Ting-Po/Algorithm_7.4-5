#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<limits.h>
#include<iostream>


int partition(int[], int, int);
void limited_quicksort(int[], int, int, int);
void insertion_sort(int[], int, int);

void quicksort(int A[], int p, int r) {
    if (p < r - 1) {
        int q = partition(A, p, r);
        quicksort(A, p, q);
        quicksort(A, q + 1, r);
    }
}

void modified_quicksort(int A[], int p, int r, int k) {
    limited_quicksort(A, p, r, k);
    insertion_sort(A, p, r);
}

void limited_quicksort(int A[], int p, int r, int treshold) {
    if (r - p > treshold) {
        int q = partition(A, p, r);
        limited_quicksort(A, p, q, treshold);
        limited_quicksort(A, q + 1, r, treshold);
    }
}

int partition(int A[], int p, int r) {
    int x, i, j, tmp;

    x = A[r - 1];
    i = p;

    for (j = p; j < r - 1; j++) {
        if (A[j] <= x) {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
        }
    }

    tmp = A[i];
    A[i] = A[r - 1];
    A[r - 1] = tmp;

    return i;
}

void insertion_sort(int A[], int p, int r) {
    int i, j, key;

    for (j = p + 1; j < r; j++) {
        key = A[j];
        for (i = j - 1; i >= p && A[i] > key; i--) {
            A[i + 1] = A[i];
        }
        A[i + 1] = key;
    }
}


void Random_Input(int* a)
{
    int i;
    int x;
    int plusminus;
    srand(time(NULL));
    for(i=0;i<300000;i++){
        plusminus = (rand()%2);
        x = (rand()%1000)+1;

        if(plusminus == 0){
            a[i] = x;
        }else{
            a[i] = x *(-1);
        }

    }




}


int main(void)
{

    int A[300000];




    int k;

    for(k=1;;k++){
    LARGE_INTEGER clockBegin;
    LARGE_INTEGER clockEnd;
    LARGE_INTEGER clockBr_begin;
    LARGE_INTEGER clockBr_end;


        Random_Input(A);
        QueryPerformanceCounter(&clockBr_begin);
                 // printf("123\n");

         quicksort(A,0,299999);

         //printf("123\n");
       QueryPerformanceCounter(&clockBr_end);
       Random_Input(A);
       QueryPerformanceCounter(&clockBegin);
        modified_quicksort(A ,0,299999,k);
                 //printf("123\n");

        QueryPerformanceCounter(&clockEnd);


        std::cout << clockBr_end.QuadPart-clockBr_begin.QuadPart << " " << clockEnd.QuadPart - clockBegin.QuadPart << std::endl;
       /* if(clockBr_end.QuadPart-clockBr_begin.QuadPart > clockEnd.QuadPart - clockBegin.QuadPart){
            break;
        }*/
        if(k >400) break;


	}

	printf("k = %d\n",k);




    return 0;

}

