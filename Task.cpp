#include "Task.h"

Task::Task(string desc, bool done) {
    description = desc;
    isDone = done;
}

void Task::markAsDone() {
    isDone = true;
}

string Task::toString() {
    return (isDone ? "[X] " : "[ ] ") + description;
}

string Task::toFileString() {
    // Format: 0|Buy Milk (0 matlab not done, | separator hai)
    return (isDone ? "1" : "0") + string("|") + description;
}
