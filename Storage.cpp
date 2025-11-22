#include "Storage.h"
#include <fstream>
#include <sstream>

void Storage::saveTasks(const vector<Task>& tasks) {
    ofstream file("data.txt");
    for (const auto& task : tasks) {
        // const_cast hack to access helper, clean way
        Task t = task; 
        file << t.toFileString() << endl;
    }
    file.close();
}

vector<Task> Storage::loadTasks() {
    vector<Task> tasks;
    ifstream file("data.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;
        
        // Parse line: "1|Do Homework"
        size_t delimiterPos = line.find('|');
        if (delimiterPos != string::npos) {
            string status = line.substr(0, delimiterPos);
            string desc = line.substr(delimiterPos + 1);
            bool isDone = (status == "1");
            tasks.push_back(Task(desc, isDone));
        }
    }
    file.close();
    return tasks;
}
