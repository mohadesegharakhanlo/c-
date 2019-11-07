#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>


using namespace std;

struct Date
{  
    unsigned short int Year;   
    unsigned short int Month;    
    unsigned short int Day;
}; 
struct Student
{
    string Firstname;
    string Lastname;
    unsigned long long int ID;
    Date Birthday;
    float Grade;
};
struct Class
{
    string ClassName;
    float Average;
    unsigned short int Capacity;
    vector <Student> Date;
};
vector <Class> Database;
string select_class;
int Database_item;

void Start();
void SelectClass(string);
void AddClass(string);
void RemoveClass(string);
void AddStudent(string , Date, unsigned long int,float);
void RemoveStudent(unsigned long long int );
void Search(unsigned long long int);
void Search(string , string);
void ShowClass();
void ShowAll();
void SortByName();
void SortByID();
void Save();

int main()
{
    Start();
    return 0;
}


void Start()
{
    vector <string> command;
    string cmd;
    string temp="";
    cout<<"enter command>";
    getline(cin ,cmd);
    for(auto item:cmd)
    {
        if(item==' ')
        {
           command.push_back(temp);
           temp="";
        }
        else
        {
            temp=temp+item;
        }
    }
    command.push_back(temp);
    int size=command.size();
    if(size==4)
    {
        if(command[0]=="basu" && command[1]=="add" && command[2]=="class")//end
        {
            string filename=command[3];
            AddClass(filename);
        }
        else if(command[1]=="remove" && command[2]=="class")
        {
            string classname_re=command[3];
            RemoveClass(classname_re);
        }
        else if(command[2]=="student")//end
        {
            string id=command[3];
            unsigned long long int ID= stoull(id);
            RemoveStudent(ID);
        }
        else if(command[1]=="select")//end
        {
            string classname=command[3];
            int ctrl=0;
            for(int i=0;i<Database.size();i++)
            {
                if(Database[i].ClassName==classname)
                {
                    ctrl=1;
                    Database_item=i;
                }
            }
            if(ctrl==1)
            {
                SelectClass(classname);
            }
            else
            {
                cout<<"this class not found!"<<endl;
                Start();
            }
        }
        else if(command[1]=="search")//end
        {
            string fname_search = command[2];
            string lname_search = command[3];
            Search(fname_search, lname_search);

        }
        else
        {
            cout<<"this command not found!";
        }
        
    }
    else if(size==3)
    {
        if(command[1]=="add" && command[2]=="student")//end
        {
            string name;
            Date birthday;
            unsigned long long int id;
            float grade;
            cout<<"enter Fname and Lname:";
            getline(cin , name);
            cout<<"enter birthday(year month day):";
            cin>>birthday.Year;
            cin>>birthday.Month;
            cin>>birthday.Day;
            cout<<"enter id:";
            cin>>id;
            cout<<"enter grade:";
            cin>>grade;
            AddStudent(name , birthday ,id , grade);
        }
        else if(command[1]=="search")//end
        {
            string id=command[2];
            unsigned long long int ID_search = stoull(id);
            Search(ID_search);

        }
        else if(command[1]=="show")
        {
            string classname=command[2];
            // ShowClass(classname);
        }
        else if(command[1]=="sort" && command[2]=="name")
        {
            // SortByName();
        }
        else if(command[1]=="sort" && command[2]=="id")
        {
           // SortByID();
        }
        else if(command[0]=="basu" && command[1]=="show" && command[2]=="all")
        {
            ShowAll();
        }
        else
        {
            cout<<"not found!"<<endl;
            Start();
        }
        
    }
    else if(size==2)
    {
        if(command[1]=="show")//end
        {
            ShowClass();

        }
        else if(command[1]=="save")
        {
            //void Save();
        }
        else if(command[1]=="help")
        {
            
        }
        else
        {
           // cout<<"";
        }
    }
    else if(size==1)
    {

    }
}
void AddClass(string filename)
{
    const char* FileName= filename.c_str();
    ifstream input;
    input.open(FileName , ios::in);
    Class firstclass;
    getline(input , firstclass.ClassName);
    input>>firstclass.Capacity;
    for(int i=0 ; i<firstclass.Capacity ; i++)
    {
        Student newstudent;
        string date;
        input>>newstudent.Firstname;
        input>>newstudent.Lastname;
        input>>date;
        string temp[3];
        int ctr=0;
        for(auto item:date)
        {
            if(item !='/')
            {
                temp[ctr]+=item;
            }
            else
            {
                ctr++;
            }
            
        }
        newstudent.Birthday.Year=stoi(temp[0]);
        newstudent.Birthday.Month=stoi(temp[1]);
        newstudent.Birthday.Day=stoi(temp[2]);
        input>>newstudent.Grade;
        input>>newstudent.ID;
        firstclass.Date.push_back(newstudent);
    }
    float avg=0;
    for(int i=0 ; i<firstclass.Capacity ; i++)
    {
        avg = avg + firstclass.Date.at(i).Grade;
    }
    avg = avg/firstclass.Capacity;
    firstclass.Average = avg;
    Database.push_back(firstclass);
    input.close();
    Start();
}
void SelectClass(string classname)
{
    string select_class = classname;
    cout<<classname<<"selected"<<endl;
    Start();
}
void AddStudent(string name, Date birthday, unsigned long int id ,float grade)
{
    Student addstudent;
    string temp[2];
    int ctr=0;
    for(auto item:name)
    {
        if(item!=' ')
        {
            temp[ctr]=item;
        }
        else
        {
            ctr++;
        } 
    }
    addstudent.Firstname=temp[0];
    addstudent.Lastname=temp[1];
    addstudent.ID=id;
    addstudent.Birthday=birthday;
    addstudent.Grade=grade;
    Database[Database_item].Date.push_back(addstudent);
    float newavg = ((Database[Database_item].Average*Database[Database_item].Capacity)+(grade))/(Database[Database_item].Capacity+1);
    Database[Database_item].Average = newavg;
    Database[Database_item].Capacity += 1;
    cout<<"new student added to class"<<endl;
    Start();
}
void RemoveStudent(unsigned long long int ID)
{
    unsigned long long int remove_id = ID;
    int remove_item;
    for(int i=0 ; i<Database.at(Database_item).Date.size() ; i++)
    {
        if(Database.at(Database_item).Date.at(i).ID == remove_id)
        {
            remove_item = i;
        }
    }
    float newavg= ((Database.at(Database_item).Average * Database.at(Database_item).Capacity) - (Database.at(Database_item).Date.at(remove_item).Grade)) / (Database.at(Database_item).Capacity-1);
    Database.at(Database_item).Average = newavg;
    Database.at(Database_item).Capacity -+ 1; 
    Database.at(Database_item).Date.erase(Database.at(Database_item).Date.begin() + remove_item);
    cout<<remove_id <<"  removed and capacity and average changed"<<endl;
    Start();
}
void ShowClass()
{
    for(auto item:Database)
    {
        cout<<endl<<item.ClassName<<endl;
        cout<<item.Capacity<<endl;
        for(auto it:item.Date)
        {
            cout<<it.Firstname;
            cout<<" "<<it.Lastname;
            cout<<" "<<it.Birthday.Year<<"/";
            cout<<it.Birthday.Month<<"/";
            cout<<it.Birthday.Day;
            cout<<" "<<it.Grade;
            cout<<" "<<it.ID<<endl;
            
        }
        cout<<"Average = "<<item.Average<<endl;
    }
    Start();
}
void Search(string fname_search, string lname_search)
{
    int control = 0;
    for(auto item :Database.at(Database_item).Date)
    {
        if(item.Firstname == fname_search && item.Lastname == lname_search)
        {
            cout<<item.Firstname;
            cout<<" "<<item.Lastname<<" "<<item.Birthday.Year<<"/"<<item.Birthday.Month<<"/"<<item.Birthday.Day<<" "<<item.Grade<<" "<<item.ID<<endl;
            break;
        }
        control++;
    }
    if(control == Database.at(Database_item).Date.size())
    {
        cout<<"this student not found!"<<endl;
    }
    Start();   
}
void Search(unsigned long long int ID_search)
{
    int control = 0;
    for(auto item : Database.at(Database_item).Date)
    {
        if(item.ID == ID_search)
        {
            cout<<item.Firstname;
            cout<<" "<<item.Lastname<<" "<<item.Birthday.Year<<"/"<<item.Birthday.Month<<"/"<<item.Birthday.Day<<" "<<item.Grade<<" "<<item.ID<<endl;
            break;
        }
        control++;
    }
    if(control == Database.at(Database_item).Date.size())
    {
        cout<<"this student not found!";
    }
    Start();
}
void RemoveClass(string classname_re)
{
   for ( int i=0 ; i<Database.size() ; i++)
   {
       if(Database.at(i).ClassName == classname_re)
       {
           Database.erase(Database.begin() + i);
       }
   }
   
   for(auto item : Database)
   {
       cout<<item.ClassName<<endl;
   }
   Start();
}
/*void ShowAll()
{
    cout<<"yessss"<<endl;
    for(auto item : Database)
    {
        cout<<item.ClassName<<endl<<item.Capacity<<endl;
        for(auto it : item.Date)
        {
            cout<<it.Firstname<<" "<<it.Lastname<<" "<<it.Birthday.Year<<"/"<<it.Birthday.Month<<"/"<<it.Birthday.Day<<" "<<it.Grade<<" "<<it.ID<<endl;
        }
        cout<<"Average = "<<item.Average<<endl;
    }
    Start();
}*/
void ShowClass(string classname)
{
    
}