#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<vector>
using namespace std;
string otx(string hads , char arr_random[4]);
vector<int> mynumber();


int main()
{
    char arr_character[8]={'a','b','c','d','e','f','g','h'};
    char arr_random[4];
    srand(time(0));
    string tekrari;
    cout<<"aya hrof takrari mojaz ast?";
    cin>>tekrari;
    if(tekrari=="yes")
    {
        /*for(int i=0;i<4;i++)
        {
            arr_random[i]=arr_character[rand()%8];
        }*/
        for(int i=0;i<4;i++)
        {
            cout<<arr_random[i];
        }
        bool condition=false;
        int condi=0;
        string hads;
        while(condition==false && condi<10 )
        {
            cout<<endl<<"hads khod ra vared konid:"<<endl;
            cin>>hads;
            string natije = otx(hads , arr_random);
            if(natije=="oooo")
            {
                cout<<natije<<endl;
                cout<<"shoma barande shodid!"<<endl;
                condition=true;

            }
            else
            {
               
                cout<<natije<<endl<<"hads shoma eshtebah ast"<<endl;
                condi++;
            }
        }
    }
    else if(tekrari=="no")
    {
       vector<int> random= mynumber();
       for(int i=0;i<4;i++)
       {
           arr_random[i]=arr_character[random[i]];
       }
      
        /*for(int i=0;i<4;i++)
        {
            cout<<arr_random[i];
        }*/
        bool condition=false;
        int condi=0;
        string hads;
        while(condition==false && condi<10 )
        {
            cout<<endl<<"hads khod ra vared konid:"<<endl;
            cin>>hads;
            string natije = otx(hads , arr_random);
            if(natije=="oooo")
            {
                cout<<natije<<endl;
                cout<<"shoma barande shodid!"<<endl;
                condition=true;

            }
            else
            {
               
                cout<<natije<<endl<<"hads shoma eshtebah ast"<<endl;
                condi++;
            }
        }
    
    }
    return 0;
}

string otx(string hads , char arr_random[4])
{
    vector <int> index;
    index.push_back(7);
    string s_otx;
    for(int i=0 ; i<4 ;i++)
    {
        if(hads[i]==arr_random[i]){
            s_otx=s_otx +'o';
        }
        else{
            s_otx=s_otx +'x';
        }
    }
    for(int i=0;i<4;i++)
    {
        if(s_otx[i]=='x')
        {
           
            for (int j = 0; j < 4; j++)
            {
                 if(hads[i]==arr_random[j] && s_otx[j]!='o')
                {
                    int ctr=0;
                    for(int k=0;k<index.size();k++)
                    {
                        if(index[k]==j)
                        {
                            ctr++;
                        }
                    }
                    
                    if(ctr==0)
                    {
                        index.push_back(j);
                        s_otx[i]='t';
                        break; 
                    }
                    
                }
               
            }
            
            
        }
    }
    string s_xx;
    string s_tt;
    string s_oo;
    for(int i=0; i<4;i++)
    {
        if(s_otx[i]=='o')
        {
            s_oo=s_oo + s_otx[i];
        }
        else if(s_otx[i]=='t')
        {
            s_tt=s_tt + s_otx[i];
        }
        else if(s_otx[i]=='x')
        {
            s_xx=s_xx + s_otx[i];
        }
    }
    s_otx = s_oo + s_tt + s_xx;
   
    
    return s_otx;
}

vector<int> mynumber()
{
    
  
    srand(time(0));
    int ctr_w=0;
    vector <int> vec_random;
    vec_random.push_back(rand()%8);
    while (ctr_w<3)
    {
        int random=rand()%8;
        int ctr_f=0;
        for(int i=0;i<vec_random.size();i++)
        {
            if(vec_random[i]==random)
            {
                ctr_f++;
            }
        }
        if(ctr_f==0)
        {
            vec_random.push_back(random);
            ctr_w++;
        }
    }
   
    
    return vec_random;

}