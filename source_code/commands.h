#ifndef COMMANDS_H
#define COMMANDS_H
#include<string>
using namespace std;

void handle_add(const string &path);
bool isfile_empty();
void handle_list(const std::string &path);
void handle_help();
void view_task(int view_id,const std::string &path);
void donetask(const std::string &path);
void pendingtask(const std::string &path);
void searchtask(const std::string task,const std::string &path);

#endif