#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <vector>
#include <string>
#include "Task.h"

class TaskManager {
private:
    std::vector<Task> tasks;
public:
    TaskManager();
    void addTask(const std::string &desc);
    void viewTasks();
    void markTaskDone(int index);
    void deleteTask(int index);
};

#endif
