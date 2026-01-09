#ifndef STORAGE_H
#define STORAGE_H

#include "task.h"
#include <vector>
#include <string>
#include <fstream>

// Save a single task (append to tasks.txt)
bool add_task(const std::string &filePath, const Task &task);
int next_id(const std::string path);  //To find next ID
void edit_task(int edit_id,const std::string path);
void delete_task(int del_id,const std::string path);
void complete_task(int com_id,const std::string path);
void undo_task(int undo_id,const std::string path);
#endif
