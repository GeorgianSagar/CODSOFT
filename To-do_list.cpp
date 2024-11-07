#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class TodoList
{
private:
    struct Task
    {
        string description;
        bool isCompleted;

        Task(string desc) : description(desc), isCompleted(false) {}
    };

    vector<Task> tasks;

public:
    // Function to check if task list is empty
    bool isEmpty()
    {
        return tasks.empty();
    }

    void addTask(const string &taskDescription)
    {
        tasks.push_back(Task(taskDescription));
        setColor(10); // Green color for confirmation
        cout << "Task added successfully!" << endl;
        setColor(7); // Reset color
    }

    void viewTasks()
    {
        if (isEmpty())
        {
            setColor(12); // Red color for no tasks
            cout << "No tasks available." << endl;
            setColor(7); // Reset color
        }
        else
        {
            cout << "\nTo-Do List:" << endl;
            for (int i = 0; i < tasks.size(); ++i)
            {
                setColor(tasks[i].isCompleted ? 10 : 7); // Green for completed, default for pending
                cout << i + 1 << ". " << tasks[i].description;
                if (tasks[i].isCompleted)
                {
                    cout << " [Completed]" << endl;
                }
                else
                {
                    cout << " [Pending]" << endl;
                }
            }
            setColor(7); // Reset color
        }
    }

    void markTaskCompleted(int index)
    {
        if (index >= 1 && index <= tasks.size())
        {
            tasks[index - 1].isCompleted = true;
            setColor(10); // Green color for completion
            cout << "Task marked as completed!" << endl;
            setColor(7); // Reset color
        }
        else
        {
            setColor(12); // Red color for error
            cout << "Invalid task number!" << endl;
            setColor(7); // Reset color
        }
    }

    void removeTask(int index)
    {
        if (index >= 1 && index <= tasks.size())
        {
            tasks.erase(tasks.begin() + index - 1);
            setColor(10); // Green color for success
            cout << "Task removed successfully!" << endl;
            setColor(7); // Reset color
        }
        else
        {
            setColor(12); // Red color for error
            cout << "Invalid task number!" << endl;
            setColor(7); // Reset color
        }
    }

    void displayMenu()
    {
        setColor(14); // Yellow color for the menu
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        setColor(7); // Reset color
    }

    // Function to set console text color
    void setColor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
};

int main()
{
    TodoList todoList;
    int choice, taskNumber;
    string task;

    while (true)
    {
        todoList.displayMenu();
        cin >> choice;
        cin.ignore(); // To discard the newline character after entering the choice

        switch (choice)
        {
        case 1: // Add Task
            cout << "Enter the task description: ";
            getline(cin, task);
            todoList.addTask(task);
            break;

        case 2: // View Tasks
            todoList.viewTasks();
            break;

        case 3: // Mark Task as Completed
            todoList.viewTasks();
            if (!todoList.isEmpty())
            { // Check if the list is not empty
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
            }
            break;

        case 4: // Remove Task
            todoList.viewTasks();
            if (!todoList.isEmpty())
            { // Check if the list is not empty
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
            }
            break;

        case 5: // Exit
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
