#include<bits/stdc++.h>

using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}
void printList(int *p, int n){
    for(int i=0; i<n; i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;

}


int main()
{

    int n=20,value;
    int *A = new int[n];

    srand(time(0));

    for(int i=0; i<n; i++)
    {
        A[i]=rand()%100;
    }

    printList(A, n);

    quickSort(A, 0, n - 1);

    printList(A, n);

    return 0;
}
