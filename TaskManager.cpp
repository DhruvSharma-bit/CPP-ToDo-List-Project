#include "TaskManager.h"
#include "Storage.h"
#include <iostream>

TaskManager::TaskManager() {
    tasks = Storage::loadTasks();
}

void TaskManager::addTask(string desc) {
    tasks.push_back(Task(desc));
    Storage::saveTasks(tasks);
    cout << ">> Task Added!\n";
}

void TaskManager::viewTasks() {
    cout << "\n--- YOUR TASKS ---\n";
    if (tasks.empty()) {
        cout << "No tasks found.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << (i + 1) << ". " << tasks[i].toString() << endl;
        }
    }
    cout << "------------------\n";
}

void TaskManager::markTaskDone(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].markAsDone();
        Storage::saveTasks(tasks);
        cout << ">> Task Completed!\n";
    } else {
        cout << ">> Invalid Number!\n";
    }
}

void TaskManager::deleteTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        Storage::saveTasks(tasks);
        cout << ">> Task Deleted!\n";
    } else {
        cout << ">> Invalid Number!\n";
    }
}
