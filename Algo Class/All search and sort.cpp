#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i =0; i<n-1; i++)
    {   for (j=0; j<n-i-1; j++)
        {   if (arr[j] > arr[j + 1])
            {   swap(&arr[j], &arr[j + 1]); }
        }
    }
}
void selectionSort(int arr[], int n)
{
    int i, j, minIdx;

    for (i = 0; i < n-1; i++)
    {
        minIdx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[minIdx])
            minIdx = j;

        if(minIdx!=i)
            swap(&arr[minIdx], &arr[i]);
    }
}
void insertionSort(int *p, int n) {
  for (int i=1; i<n; i++) {
    int val = p[i];
    int j = i-1;

    while (val < p[j] && j >= 0) {
      p[j+1] = p[j];
      --j;
    }
    p[j+1] = val;
  }
}
    //Quick Sort Start
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
    //Merge Sort Start
void merge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void LinearSearch(int *p, int n,int val)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(p[i]==val)
        {
            cout<<"\nFound in the Index "<<i<<endl;
            count++;
        }
    }
    if(count==0)
    {
        cout<<"\nValue Doesn't found"<<endl;
    }
}

void binarySearch(int *p, int n,int val)
{
    int count=0, first=0, last=n-1, mid = (first+last)/2;
    if(first>last)
    {
        cout<<"\nValue Doesn't found"<<endl;
    }
    if(first==val)
    {
        cout<<"\nFound in the Index "<<first<<endl;
    }
    if(first<val)
    {
        first = mid+1;
        mid = (first+last)/2;
    }
    if(val>last)
    {
        last = mid-1;
        mid = (first+last)/2;
    }
}

/*void write(int *p, int n){

    freopen("100_class3.txt","w",stdout);


    srand(time(0));

    for(int i=0; i<n; i++)
    {
        p[i]=rand()%100;
    }
}*/

/*void read(int *p, int n){

    freopen("100_class3.txt","r",stdin);

    for(int i=0; i<n; i++)
    {
        cout<<p[i]<<" ";
    }

}*/


void printList(int *p, int n){
    for(int i=0; i<n; i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;

}



int main(){

    int n=20,value;
    int *A = new int[n];

    srand(time(0));

    for(int i=0; i<n; i++)
    {
        A[i]=rand()%100;
    }

          printList(A,n);

    auto start1 = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        /*  ..........Change your algorithm...............*/
        mergeSort(A, 0, n - 1);
        //selectionSort(A,n);
        //insertionSort(A,n);
        cout<<"\nWhich Value do you want to search : ";
        cin>>value;
        LinearSearch(A,n,value);
        //binarySearch(A,n,99);
        /* .......................................  */


        /*.....................Time taken by 1st Algorithm........................*/
        auto end1 = chrono::high_resolution_clock::now();
        double time_taken1 =chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
            time_taken1 *= 1e-9;
        cout << "\nData Size " << n <<" Time taken by program is : " << fixed
             << time_taken1 << setprecision(9);
        cout << " sec" << endl;

                  printList(A,n);

    return 0;
}
