#ifndef TASK_H
#define TASK_H
#include <string>
#include <iostream>

using namespace std;

class Task {
public:
    string description;
    bool isDone;

    Task(string desc, bool done = false);
    void markAsDone();
    string toString();
    string toFileString(); // File mein save karne ke liye format
};

#endif
