#include "task.h"
#include<string>
using namespace std;

string Task::to_line()
{
    string line = "Title: ";
    line += title;            // add title text

    line += " | Description: ";
    line += description;      // add description text

    line += " | End: ";
    line += end_time;         // add end time text

    return line;  
}