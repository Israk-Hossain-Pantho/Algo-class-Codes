#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int selectionSort(int *x, int p)
{
    for(int i=0; i<p-1; i++)
    {
        int indexmin=i;
        for(int j=i+1; j<p; j++)
        {
            if(x[indexmin]>x[j])
            {
                indexmin =j;
            }
        }
        if(indexmin!=i)
        {
            swap(&x[indexmin],&x[i]);
        }
    }

    cout<<"Sorted Array\n";
    for(int i=0; i<10; i++)
    {
        cout<<x[i]<<" ";
    }
}

