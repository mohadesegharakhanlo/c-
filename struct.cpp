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


int main()
{    cin>>p1.fname;
    cout<<p1.fname<<endl;
    struct ali p2;
    cin>>p2.fname;
    cout<<p2.fname<<endl;
    cout<<p1.fname<<" LOVES "<<p2.fname;
    return 0;
}