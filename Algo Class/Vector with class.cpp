#include<bits/stdc++.h>
#include<vector>
using namespace std;

class student{
private:
    int id;
    string name;
    double cgpa;
public:
    student(){

    }
    student(int id, string name, double cgpa)
    {
        this->id= id;
        this->name= name;
        this->cgpa= cgpa;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    double getCgpa(){
        return cgpa;
    }

};

int main()
{
    vector<student> studentvec;
    vector<int> :: iterator it;

    //freopen("I H P.txt", "r", stdin);

    ifstream fin("Cgpa.txt");

    int id;
    string name;
    double cgpa;

    for(int i=0; i<4; i++)
    {
        fin>>id>>name>>cgpa;
        student s(id,name,cgpa);
        studentvec.push_back(s);
    }

    for(int i=0; i<studentvec.size(); i++)
    {
        student s = studentvec[i];
        cout<<s.getId()<<" "<<s.getName()<<" "<<s.getCgpa()<<endl;
    }

    cout<<endl;

}
