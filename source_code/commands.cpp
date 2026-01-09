#include "commands.h"
#include "task.h"
#include "storage.h"
#include<iostream>
#include<limits>
#include<limits>
#include<ctime>
using namespace std;

void handle_add(const string &path) //hande add command
{
Task t;

    

    cout<<"Enter Title:";
    getline(cin,t.title);
    

    cout<<"Enter Description:";
    getline(cin,t.description);

    cout<<"Enter End Time:";
    getline(cin,t.end_time);

    time_t now = time(0);
    string dt=ctime(&now);
    t.reg_time = dt;

    if(next_id(path)==0)
    {
        t.ID=1;
    }
    else
    {
        t.ID=next_id(path);
    }


   
    if (!add_task(path, t)) {
        std::cerr << "Error: Could Not Save Task To " << path << "\n";
        return;
    }

    std::cout << "Task Added!\n";
    std::cout << "Title: " << t.title << "\n";
}

void handle_list(const string &path) //To list tasks
{
    ifstream read(path);
    string word;
    
bool hasTask = false; //task undo enn ariyan
string line;

if(read.peek() == ifstream::traits_type::eof()) 
{
cout<<"Your Task List Is Empty!"<<endl;
read.close();      
}

else
{
    while(getline(read,word))
    {
        cout<<word<<endl;
    }
}

read.close();
}

void handle_help()

{
    cout<<"COMMANDS      :   DESCRIPTION "<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"help          :   To view all commands"<<endl;
    cout<<"add           :   To add tasks to list"<<endl;
    cout<<"list          :   To view all tasks"<<endl;
    cout<<"done          :   To view all completed tasks"<<endl;
    cout<<"pending       :   To view all pending tasks"<<endl;
    cout<<"search        :   To search task by title"<<endl; 
    cout<<"delete <id>   :   To delete a task"<<endl;
    cout<<"edit <id>     :   To edit task"<<endl;
    cout<<"view <id>     :   To view a single task"<<endl;   
    cout<<"complete <id> :   To set a task completed"<<endl;
    cout<<"undo <id>     :   To set a task pending"<<endl;
}

void view_task(int view_id,const string &path)
{
    ifstream read(path);

    if(!read)
    {
        cerr<<"Sorry Cannot Open File!";
        return;
    }
string word;

 while(getline(read,word))
    {
            if(word.length() >= 3 &&  //Find the ID line
                            word[0]=='I' &&
                            word[1]=='D' &&
                            word[2]==':')
                        {
                                int id=0;
                                for(int i=3;i<word.length();i++)
                                {
                                    if(word[i]>='0' && word[i]<='9')
                                    {
                                        id=id*10 + (word[i]-'0');
                                    }
                                }
                            if(id==view_id)
                            {
                                cout<<word<<endl;
                                for(int i=0;i<5;i++)
                                {
                                    if (getline(read, word))
                                    {
                                    cout << word << endl;
                                    }               
                                }
                            return;
                        }
           

    }
}
cout<<"Task Not Found";
}

void donetask(const std::string &path)
{
    ifstream read(path);

    if(!read)
    {
        cerr<<"Sorry Cannot Open File!";
        return;
    }

    string id,ti,des,end,reg,st;  //temp variables 
    bool found=false;

    while (getline(read, id))    
    {
        if(id.empty()) //if line is empty
        {
            continue;
        }
        getline(read,ti);
        getline(read,des);
        getline(read,end);
        getline(read,reg);
        getline(read,st);

                if(st.find("Completed") != string::npos)
                {
                    found=true;
                    cout<<id<<endl;
                    cout<<ti<<endl;
                    cout<<des<<endl;
                    cout<<end<<endl;
                    cout<<reg<<endl;
                    cout<<st<<endl<<endl;
                }


    }
    if(!found)
    {
        cerr<<"No Completed Tasks"<<endl;
    }
read.close();
}

void pendingtask(const std::string &path)
{
    ifstream read(path);

    if(!read)
    {
        cerr<<"Sorry Cannot Open File!";
    }

    string id,ti,des,reg,end,st;
    bool found=false;

    while(getline(read,id))
    {
        if(id.empty())
        {
            continue;
        }
        getline(read,ti);
        getline(read,des);
        getline(read,end);
        getline(read,reg);
        getline(read,st);

        if(st.find("Pending") != string::npos)
        {
                    found=true;
                    cout<<id<<endl;
                    cout<<ti<<endl;
                    cout<<des<<endl;
                    cout<<end<<endl;
                    cout<<reg<<endl;
                    cout<<st<<endl<<endl;
        }
    }
if(!found)
{
    cerr<<"No Pending Tasks"<<endl;
}
read.close();
}

void searchtask(const std::string task,const std::string &path)
{
    ifstream read(path);

    if(!read)
    {
        cerr<<"Sorry Cannot Open File!";
    }

    string id,ti,des,reg,end,st;
    bool found=false;

    while(getline(read,id))
    {
        if(id.empty())
        {
            continue;
        }
        getline(read,ti);
        getline(read,des);
        getline(read,end);
        getline(read,reg);
        getline(read,st);

        if(ti.find(task) != string::npos)
        {
                    found=true;
                    cout<<id<<endl;
                    cout<<ti<<endl;
                    cout<<des<<endl;
                    cout<<end<<endl;
                    cout<<reg<<endl;
                    cout<<st<<endl<<endl;
        }
    }
if(!found)
{
    cerr<<"No Tasks With Title"<<task<<endl;
}
read.close();
}