#include<bits/stdc++.h>
using namespace std;



class student
{

private:
    int sl;
    string id;
    string name;
    double cgpa;
public:
    student()
    {

    }
    student(int sl, string i, string n, double cg)
    {
        this->sl=sl;
        this->id=i;
        this->name = n;
        this->cgpa = cg;
    }

    int getSl(){
        return sl;
    }
    string getId(){
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
        return a.getCgpa()>b.getCgpa()?true:false;
    }
};

priority_queue<student,vector<student>,cmp> pq;

 void printStudent(){


     while (!pq.empty())
    {
        student value = pq.top();
        cout << value.getSl()<<" "<<value.getId() << " " << value.getName() <<" "<<value.getCgpa()<< endl;

        pq.pop();
    }
 }



int main()
{
    int sl;
    string id;
    string name;
    double cgpa;

    ifstream fin("input_priority_queue.txt");

    for(int i=0;i<37;i++){
        fin>>sl>>id>>name>>cgpa;
        student s1(sl,id,name,cgpa);
        pq.push(s1);


    }

    printStudent();





    return 0;
}
