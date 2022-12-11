#include<bits/stdc++.h>
using namespace std;



class student
{

private:
    int id;
    string name;
    double cgpa;
public:
    student()
    {

    }
    student(int i, string n, double cg)
    {
        this->id=i;
        this->name = n;
        this->cgpa = cg;
    }

    int getId(){
        return this->id;
    }

   string getName(){
        return this->name;
    }

    double getCgpa(){

        return this->cgpa;
    }



};



class cmp{
public:
    bool operator()(student &a, student &b){
        return a.getCgpa()<b.getCgpa()?true:false;
    }
};

priority_queue<student,vector<student>,cmp> pq;

 void printStudent(){


     while (!pq.empty())
    {
        student value = pq.top();
        cout << value.getId() << " " << value.getName() <<" "<<value.getCgpa()<< endl;

        pq.pop();
    }
 }



int main()
{
    int id;
    string name;
    double cgpa;



    for(int i=0;i<2;i++){
        cin>>id>>name>>cgpa;
        student s1(id,name,cgpa);
        pq.push(s1);


    }

    printStudent();





    return 0;
}
