#include <iostream>
#include <limits> // Input buffer clear karne ke liye
#include "TaskManager.h"

using namespace std;

int main() {
    TaskManager manager;
    int choice;
    string input;

    cout << "Welcome to C++ Task Manager\n";

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Done\n4. Delete Task\n5. Exit\n";
        cout << "Enter Choice: ";
        
        // Error Handling: Agar user number ki jagah text dale
        if (!(cin >> choice)) {
            cout << ">> Please enter a number only!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(); // Newline character hatane ke liye

        if (choice == 5) break;

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, input);
                manager.addTask(input);
                break;
            case 2:
                manager.viewTasks();
                break;
            case 3:
                manager.viewTasks();
                cout << "Enter number to mark done: ";
                int doneIdx;
                cin >> doneIdx;
                manager.markTaskDone(doneIdx - 1);
                break;
            case 4:
                manager.viewTasks();
                cout << "Enter number to delete: ";
                int delIdx;
                cin >> delIdx;
                manager.deleteTask(delIdx - 1);
                break;
            default:
                cout << ">> Invalid Choice!\n";
        }
    }
    return 0;
}
