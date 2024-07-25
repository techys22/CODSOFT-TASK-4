#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool isCompleted;

    Task(std::string desc) : description(desc), isCompleted(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDescription) {
        tasks.emplace_back(taskDescription);
        std::cout << "Task added: " << taskDescription << "\n";
    }

    void viewTasks() {
        std::cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description 
                      << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].isCompleted = true;
            std::cout << "Task " << index << " marked as completed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task " << index << " removed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    std::string description;
    size_t index;

    while (true) {
        std::cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                todoList.addTask(description);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> index;
                todoList.markTaskAsCompleted(index);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> index;
                todoList.removeTask(index);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
