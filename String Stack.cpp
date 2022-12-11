#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> st;


    st.push("IHP");
    st.push("Pantho");
    st.push("Israk");
    st.push("Hossain");

    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<endl;

}
