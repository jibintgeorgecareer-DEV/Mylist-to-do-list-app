#include "storage.h"
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

bool add_task(const string &path,const Task &task)//To add tasks to file
{
    ofstream file(path,ios::app);  //open file append mode

    if(!file)
    {
        cerr<<"Sorry Could Not Open File";
        return false;
    }

    string st;
    if(task.status==1)
    {
        st="Completed";
    }
    else if(task.status==0)
    {
        st="Pending";
    }

    file <<"ID:"<<task.ID<<endl
         <<"Titile:"<<task.title<<endl
         <<"Description:"<<task.description<<endl
         <<"End_Time:"<<task.end_time<<endl
         <<"Registered_Time:"<<task.reg_time
         <<"Status:"<<st<<endl<<endl;
file.close();
return true;
}

int next_id(const std::string path)  //To find next ID
{
    ifstream read(path);
    if(!read)
    {
        cerr<<"Sorry Cannot Open the file "<<path<<endl;
        return 1;
    }
    string word;
    int lastid=0;
    while(getline(read,word))
    {
           //Check if line starts with ID
           if(word.length() >= 3 && 
              word[0]=='I' &&
              word[1]=='D' &&
              word[2]==':'
             )
             {
                int id=0;
                //convert character after 'ID'
                for(int i=3;i<word.length();i++)
                {
                    if(word[i]>'0' && word[i]<'9')
                    {
                        id=id*10 + (word[i] - '0');
                    }
                } 
lastid=id;
             }
    }
read.close();
return lastid+1;
}

void edit_task(int edit_id,const std::string path)
{
    string tempfile="data/temp.txt";
    ifstream read(path);
    ofstream write(tempfile); //opening temp file for copy original file

    time_t now = time(0);
    string dt=ctime(&now);
    string time_now = dt;  //current time

    if(!read || !write)
    {
        cerr<<"Sorry Cannot open files !";
    }

    string line;
    bool isedit=false;

        while(getline(read,line))
        {
                        if(line.length() >= 3 &&  //Find the ID line
                            line[0]=='I' &&
                            line[1]=='D' &&
                            line[2]==':')
                        {
                                int id=0;
                                for(int i=3;i<line.length();i++)
                                {
                                    if(line[i]>='0' && line[i]<='9')
                                    {
                                        id=id*10 + (line[i]-'0');
                                    }
                                }
                            if(id==edit_id) //id thid task for to edit
                            {
                                isedit=true;

                                write<<"ID:"<<edit_id<<endl;

                                string tit,dec,et; //title,description,endtime

                                    
                                    cout<<"New Title:";
                                    getline(cin,tit);

                                    cout<<"New Description:";
                                    getline(cin,dec);

                                    cout<<"New End Time:";
                                    getline(cin,et);

                                write <<"Title:"<< tit <<endl 
                                      <<"Description:"<<dec<<endl
                                      <<"End_Time:"<<et<<endl
                                      <<"Registered_Time:"<<time_now;


                            // Skip old lines (Title, Desc, End, Reg)
                            for (int i = 0; i < 5; i++)
                            getline(read, line);

                            // Keep old registered time
                            write << line << endl;
                            write << endl;

                            continue;

                            }
                        }
                    write << line <<endl; //write taks  line that id!=edit_id
        }
read.close();
write.close();

// Delete old file
remove(path.c_str());

// Rename temp → original
rename("data/temp.txt", path.c_str());


    if (!isedit)
    {
        cout << "Task ID Not Found!\n";
        
    }

    cout << "Task Updated Successfully!\n";
}

void delete_task(int del_id,const std::string path) //To delete  a task
{
    
    string temp="data/temp.txt";

    ifstream read(path);
    ofstream write(temp);

    if(!read || !write)
    {
        return;
        cerr<<"Sorry Cannot Open Files !";
    }
string line;
bool found=false;

    while(getline(read,line))
    {
            if(line.length() >= 3 &&  //Find the ID line
                            line[0]=='I' &&
                            line[1]=='D' &&
                            line[2]==':')
                        {
                                int id=0;
                                for(int i=3;i<line.length();i++)
                                {
                                    if(line[i]>='0' && line[i]<='9')
                                    {
                                        id=id*10 + (line[i]-'0');
                                    }
                                }

                if(id==del_id)
                {
                        found=true; 

                        for(int i=0;i<5;i++)
                        {
                            getline(read,line);
                        }
                        continue;
                    
                }
            }
        write << line <<endl;


    }
read.close();
write.close();

        if(!found)
        {
        cout<<"ID Not Found !";
        remove(temp.c_str());
        return;
        }

    remove(path.c_str());
    rename(temp.c_str(), path.c_str());

    cout << "Task Deleted Successfully!\n";
    
}

void complete_task(int com_id,const std::string path)
{
    ifstream read(path);
    string temp="data/temp";
    ofstream write(temp);

    if(!read || !write)
    {
        cerr<<"Sorry Cannot Open File!";
    }
string line;
bool iscom; //Is task completed

    while(getline(read,line))
    {
            if(line.length() >= 3 &&  //Find the ID line
                            line[0]=='I' &&
                            line[1]=='D' &&
                            line[2]==':')
                        {
                            int id=0;
                            for(int i=0;i<line.length();i++)
                            {
                                if(line[i]>='0' && line[i]<='9')
                                {
                                    id=id*10+(line[i]-'0');
                                }
                            }

                            if(id==com_id)
                            {
                               iscom=true;
                               write<<"ID:"<<com_id<<endl;

                               string st="Completed";
                               for(int i=0;i<4;i++)
                               {
                                getline(read,line);

                                write << line << endl;
                               }
                               write << "Status:" << st <<endl;

                                // Skip Status line
                            for (int i = 0; i <2; i++)
                            getline(read, line); 

                            }
                        }
                write << line <<endl;

    }
read.close();
write.close();

        if(!iscom)
        {
        cout<<"ID not found !";
        remove(temp.c_str());
        return;
        }

    remove(path.c_str());
    rename(temp.c_str(), path.c_str());




    if (!iscom)
    {
        cout << "Task ID Not Found!\n";
        
    }

    cout << "Congratulations You Completed A Task.........\n";
}

void undo_task(int undo_id,const std::string path)
{
     ifstream read(path);
    string temp="data/temp";
    ofstream write(temp);

    if(!read || !write)
    {
        cerr<<"Sorry Cannot Open File!";
    }
string line;
bool isundo; //Is task pending

    while(getline(read,line))
    {
            if(line.length() >= 3 &&  //Find the ID line
                            line[0]=='I' &&
                            line[1]=='D' &&
                            line[2]==':')
                        {
                            int id=0;
                            for(int i=0;i<line.length();i++)
                            {
                                if(line[i]>='0' && line[i]<='9')
                                {
                                    id=id*10+(line[i]-'0');
                                }
                            }

                            if(id==undo_id)
                            {
                               isundo=true;
                               write<<"ID:"<<undo_id<<endl;

                               string st="pending";
                               for(int i=0;i<4;i++)
                               {
                                getline(read,line);

                                write << line << endl;
                               }
                               write << "Status:" << st <<endl;

                                // Skip Status line
                            for (int i = 0; i <2; i++)
                            getline(read, line); 

                            }
                        }
                write << line <<endl;

    }
read.close();
write.close();

        if(!isundo)
        {
        cout<<"ID Not Found !";
        remove(temp.c_str());
        return;
        }

    remove(path.c_str());
    rename(temp.c_str(), path.c_str());




    if (!isundo)
    {
        cout << "Task ID Not Found!\n";
        
    }

    cout << "Task Changed To pending\n";
}