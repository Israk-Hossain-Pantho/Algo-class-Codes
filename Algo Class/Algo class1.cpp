#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int **Matrix(int r, int c)
{
    int **m= new int *[r];
    for(int i=0; i<c; i++)
        m[i] = new int[c];

    srand(time(0));
    for(int i=0; i<r;i++)
    {
        for(int j=0; j<c;j++)
        {
            m[i][j]= rand()%10;
        }
    }
        return m;
}

void printMatrix(int **m, int r, int c)
{
    for(int i=0; i<r;i++)
    {
        for(int j=0; j<c;j++)
        {
            cout<<m[i][j]<<" ";
        }
            cout<<endl;
    }
    cout<<endl<<endl;
}

int **matrixsubs(int **x,int r, int c, int **y)
{
    int **m= new int *[r];
    for(int i=0; i<c; i++)
        m[i] = new int[c];

    for(int i=0; i<r;i++)
    {
        for(int j=0; j<c;j++)
        {
            m[i][j]= x[i][j]+ y[i][j];
        }
    }
    printMatrix(m,r,c);
}

int **matrixmul(int **x,int r, int c, int **y)
{
    int **m= new int *[r];
    for(int i=0; i<c; i++)
        m[i] = new int[c];

    for(int i=0; i<r;i++)
    {
        for(int j=0; j<c;j++)
        {
            m[i][j]=0;
            for(int k=0; k<c;k++)
            {
                m[i][j]= (x[i][k])*(y[k][j]);
            }
        }
    }
    printMatrix(m,r,c);
}

int main()
{
    int rows;
    int colm;
    cin>>rows>>colm;

    int **A = Matrix(rows,colm);
    printMatrix(A,rows,colm);
    cout<<endl;
    int **B = Matrix(rows,colm);
    printMatrix(B,rows,colm);

    int **C = matrixsubs(A,rows,colm,B);
    int **D = matrixmul(A,rows,colm,B);

}


