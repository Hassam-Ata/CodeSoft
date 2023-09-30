#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void printTasks(const vector<string>& tasks) {
    cout << "Your Task List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void saveTasksToFile(const vector<string>& tasks, const string& file) {
    ofstream output(file);
    if (output.is_open()) {
        for (const string& task : tasks) {
            output << task << endl;
        }
        cout << "Tasks saved to " << file << endl;
    } else {
        cout << "Unable to save tasks to " << file << endl;
    }
}

void loadTasksFromFile(vector<string>& tasks, const string& file) {
    ifstream input(file);
    if (input.is_open()) {
        string task;
        while (getline(input, task)) {
            tasks.push_back(task);
        }
        cout << "Tasks loaded from " << file << endl;
    } else {
        cout << "No saved tasks found in " << file << endl;
    }
}

void completeTask(vector<string>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        cout << "Task marked as completed: " << tasks[index - 1] << endl;
        tasks.erase(tasks.begin() + (index - 1));
    } else {
        cout << "Invalid task index. No task marked as completed." << endl;
    }
}

void removeTaskFromList(vector<string>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        cout << "Task removed: " << tasks[index - 1] << endl;
        tasks.erase(tasks.begin() + (index - 1));
    } else {
        cout << "Invalid task index. No task removed." << endl;
    }
}

int main() {
    vector<string> taskList;
    const string filename = "D://tasks.txt";

    loadTasksFromFile(taskList, filename);

    cout << "\t\t\tYour Personal Task Manager" << endl;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a Task" << endl;
        cout << "2. View Your Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove a Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore();
                string description;
                cout << "Enter task description: ";
                getline(cin, description);
                taskList.push_back(description);
                saveTasksToFile(taskList, filename);
                break;
            }
            case 2:
                printTasks(taskList);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                completeTask(taskList, taskIndex);
                saveTasksToFile(taskList, filename);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                removeTaskFromList(taskList, taskIndex);
                saveTasksToFile(taskList, filename);
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
