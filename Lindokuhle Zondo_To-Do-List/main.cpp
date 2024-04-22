#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        std::cout << "Task '" << taskDescription << "' added successfully!\n";
    }

    void viewTasks() {
        std::cout << "\nTasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::string status = tasks[i].completed ? "Completed" : "Pending";
            std::cout << i + 1 << ". " << tasks[i].description << " - " << status << "\n";
        }
        std::cout << "\n";
    }

    void markCompleted(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task '" << tasks[taskIndex - 1].description << "' marked as completed!\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            std::string removedTask = tasks[taskIndex - 1].description;
            tasks.erase(tasks.begin() + taskIndex - 1);
            std::cout << "Task '" << removedTask << "' removed successfully!\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoList todoList;

    while (true) {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";

        int choice;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter the task: ";
                std::cin.ignore(); // Clear input buffer
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                todoList.viewTasks();
                size_t taskIndex;
                std::cout << "Enter the index of the task to mark as completed: ";
                std::cin >> taskIndex;
                todoList.markCompleted(taskIndex);
                break;
            }
            case 4: {
                todoList.viewTasks();
                size_t taskIndex;
                std::cout << "Enter the index of the task to remove: ";
                std::cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}

