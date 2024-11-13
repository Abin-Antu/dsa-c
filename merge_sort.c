#include <stdio.h>
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void merge(int A[], int low, int mid, int high)
{

    int i, j, k, B[100];
 
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        while (i <= mid && j <= high)
        {
            if (L[i] < A[j])
            {
                B[k] = A[i];
                i++;
                k++;
            }
            else
            {
                B[k] = R[j];
                j++;
                k++;
            }
        }
    }while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int A[], int low,int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}
int main()
{
    int A[] = {2, 5, 3, 8, 3, 6};
    int i;
    // enter the size of the array
    int n = sizeof(A) / sizeof(A[0]);
    mergesort(A,0, n - 1);
    
     printArray(A, n);
}