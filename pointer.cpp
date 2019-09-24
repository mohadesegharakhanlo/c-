#include<iostream>
using namespace std;
int main()
{
   /* int x=7;
    int *ptr=&x;
    *ptr=x;
    cout<< ptr;
    cout<<endl<<*ptr;
    cout<<endl<<&x;
    cout<<endl<<&ptr;*/
    int arr[3]={1,2,3};
    int *ptr=arr;
    for(int i=0;i<3;i++)
    {
        cout<<ptr[i]<<endl;

    }
    int brr[3]={4,5,6};
    int *bptr=brr;
    for(int i=0;i<3;i++)
    {
        cout<<*bptr<<endl;
        bptr++;
    }
    
    return 0;
}
