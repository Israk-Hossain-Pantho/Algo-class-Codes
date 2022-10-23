#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int selectionSort(int *a, int m)
{
     for (int i=0; i<m-1; i++)
     {
         int Min = i;
         for (int j=i+1; j<m; j++)
         {
            if (a[j] < a[Min])
            Min = j;
         }

         swap(&a[Min], &a[i]);
     }

    return *a;
}

int binarySearch(int *a, int n,int itm)
{
    int fst=0, last=n-1;
    int mid= (last+fst)/2;

    selectionSort(a,n);

    while(true)
    {
        if(last<fst)
        {
            cout<<"Item Doesn't Found"<<endl;
            break;
        }
        else if(itm == a[fst])
        {
            cout<<"Item Found at Index "<<fst;
            break;
        }
        else if(mid<=itm)
        {
            fst = mid;
            mid = (fst+last)/2;
        }
        else if(mid>itm)
        {
            last = mid-1;
            mid = (fst+last)/2;
        }
    }

}

int linearSearch(int n,int *a)
{
    int count=0;
    for(int i=0; i<1000; i++)
    {
        if(n==a[i])
        {
            cout<<"Number Found\n";
            cout<<"Found at the index "<<i<<endl ;
            count++;
        }
    }
    if(count==0)
    {
        cout<<"Not found"<<endl;
    }

    cout<<endl;
}

int main()
{
    srand(time(0));

    /*freopen("Linear Search.txt","w",stdout);
    int a[1000];
    for(int i=0; i<1000; i++)
    {
       a[i]= rand();
       cout<<a[i]<<endl;
    }*/

    freopen("Linear Search.txt","r",stdin);
    int n=1000;
    int a[n];
    for(int i=0; i<n; i++)
    {
       cin>>a[i];
    }

    auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    /*  ..........Change your algorithm...............*/
    linearSearch(29448,a);
    binarySearch(a, n,29448);
    /* .......................................  */


    /*.....................Time taken by 1st Algorithm........................*/
    auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 =chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        time_taken1 *= 1e-9;
    cout << "Time taken by program is : " << fixed
         << time_taken1 << setprecision(9);
    cout << " sec" << endl;


}
