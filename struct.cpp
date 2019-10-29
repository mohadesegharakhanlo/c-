#include<iostream>
using namespace std;




struct mody{
    string fname;
    string lname;

}p1;
struct ali{
    string fname;
    string lname;
};
struct student{
    string name;
    int age;
    
};
struct pointer
{
    int x;
    int y;
    int *z;
};

int main()
{  /* cout<<"enter p1.fname:"; 
    cin>>p1.fname;
    cout<<p1.fname<<endl;
    struct ali p2;
    cout<<"enter p2.fname:";
    cin>>p2.fname;
    cout<<p2.fname<<endl;
    cout<<p1.fname<<" LOVES "<<p2.fname<<endl;*/ //ali and mohadese

   /* struct student info[2];
    for(int i=0;i<2;i++){
       cout<<"enter your name:";
       cin>>info[i].name;
       cout<<"enter your age:";
       cin>>info[i].age;
    }
    for(int i=0;i<2;i++)
    {
        cout<<info[i].name<<endl <<info[i].age<<endl;
        
    }*/ //students
    int zz=7;
    pointer a;
    a.z=&zz;
    cout<<*(a.z);
    

    return 0;
}