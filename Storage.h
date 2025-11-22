#ifndef STORAGE_H
#define STORAGE_H
#include <vector>
#include "Task.h"

class Storage {
public:
    static void saveTasks(const vector<Task>& tasks);
    static vector<Task> loadTasks();
};

#endif
