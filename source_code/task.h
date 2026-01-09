#ifndef TASK_H
#define TASK_H
#include <string>

class Task 
{
    public:
    int ID;
    int status=0; 
    std::string title;
    std::string description;
    std::string end_time;
    std::string reg_time;
    // Convert a task into a line for saving into tasks.txt
    std::string to_line();
};

#endif
