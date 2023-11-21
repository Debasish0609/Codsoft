#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};


void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "\n==== TO-DO LIST MANAGER ====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
}


void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, description);

    tasks.push_back(Task(description));
    cout << "Task added successfully.\n";
}


void viewTasks(const vector<Task>& tasks) {
    cout << "\n==== TASK LIST ====\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << "\n";
        }
    }
}

// Function to delete a task from the to-do list
void deleteTask(vector<Task>& tasks) {
    viewTasks(tasks);

    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }

    int index;
    cout << "Enter the task number to delete: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

