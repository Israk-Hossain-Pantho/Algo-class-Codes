#include<bits/stdc++.h>
using namespace std;

void write(int *p, int n){

    freopen("100_class3.txt","w",stdout);


    srand(time(0));

    for(int i=0; i<n; i++)
    {
        cout<<rand()%100<<endl;
    }
}

void read(int *p, int n){

    freopen("100_class3.txt","r",stdin);

    for(int i=0; i<n; i++)
    {
        if(i==0 || i%10==0)
        cin>>p[i];
    }

}


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

    //write(A,n);

    //cout<<"After Write the code";
    //printList(A,n);

    cout<<"After Read the code";
    read(A,n);

}
