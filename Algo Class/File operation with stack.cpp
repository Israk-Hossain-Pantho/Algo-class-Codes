#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> st;

    //freopen("I H P.txt", "r", stdin);

    ifstream fin("name.txt");

    string name;

    for(int i=0; i<5; i++)
    {
        fin>>name;
        st.push(name);
    }

    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<endl;

}
