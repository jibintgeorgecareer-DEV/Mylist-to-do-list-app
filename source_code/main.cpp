#include "commands.h"
#include "storage.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    
    if (argc < 2) //check command 
    {
        cerr << "Enter a command!\n";
        cerr << "EXAMPLE: MyList help\n";
        return 1;
    }

    const string datafile = "data/tasks.txt";
    string cmd = argv[1]; //read the second command ex.Mylis add

    //Commands without extra arguments
    if (cmd == "add")
    {
        handle_add(datafile);
    }
    else if (cmd == "list")
    {
        handle_list(datafile);
    }
    else if (cmd == "help")
    {
        handle_help();
    }
    else if (cmd == "done")
    {
        donetask(datafile);
    }
    else if (cmd == "pending")
    {
        pendingtask(datafile);
    }

    
    else if (cmd == "search") //serch command 
    {
        if (argc < 3)
        {
            cerr << "Search requires a keyword\n";
            cerr << "EXAMPLE: MyList search <title name>\n";
            return 1;
        }

        string keyword = argv[2];
        searchtask(keyword, datafile); //serach fun called
    }

    //ID-based commands
    else if (cmd == "view" || cmd == "delete" || cmd == "edit" || cmd == "complete" || cmd == "undo")          
    {
        if (argc < 3)
        {
            cerr << "This command requires task ID\n";
            cerr << "EXAMPLE: MyList " << cmd << " 2\n";
            return 1;
        }

        int id = stoi(argv[2]); //used for command with ID

        if(cmd == "view")
        {        
            view_task(id,datafile);
        }
        else if(cmd == "delete")
        {
            delete_task(id,datafile);
        }
        else if(cmd == "edit")
        {   
            edit_task(id,datafile);
        }
        else if(cmd == "complete")
        { 
            complete_task(id,datafile);
        }
        else if(cmd == "undo")
        {   
            undo_task(id,datafile);
        }
    } 
    else
    {
        cerr << "Unknown Command!\n";
        cerr << "TYPE : MyList help\n";
        return 1;
    }

    return 0;
}
