#include <iostream>
#include <vector>
using namespace std;
class ToDoListManager {
private:
    vector<string> tasks;
    vector<int> status;
public:
    void addTask(string description) {
        tasks.push_back(description);
        status.push_back(0);
        cout<<"Task \""<<description<<"\" added successfully!\n";
    }
    void viewTasks() {
        if(tasks.empty()) {
            cout<<"\n\t\tNo tasks found.\n";
        }else{
            cout<<"\n\t\t\tTasks:\n";
            for(int i=0;i<tasks.size();i++) {
                cout<<"\t\t\t"<<i+1<<". "<<tasks[i]<<" - ";
                if(status[i]==1) cout<<"Completed\n";
                else cout<<"Pending\n";
            }
        }
    }
    void markTaskCompleted(int index) {
        if (index>0&&index<=tasks.size()){
            status[index-1]=1;
            cout<<"Task marked as completed.\n";
        }else{
            cout<<"Invalid task index.\n";
        }
    }
    void removeTask(int index) {
        if(index>0&&index<=tasks.size()) {
            tasks.erase(tasks.begin()+index-1);
            status.erase(status.begin()+index-1);
            cout<<"Task removed successfully.\n";
        } else {
            cout<<"Invalid task index.\n";
        }
    }
};
int main() {
    ToDoListManager toDoList;
    while (true) {
        cout<<"\nMenu:\n"
                 <<"1. Add Task\n"
                 <<"2. View Tasks\n"
                 <<"3. Mark Task as Completed\n"
                 <<"4. Remove Task\n"
                 <<"5. Exit\n";
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1: {
                string description;
                cout<<"Enter task description: ";
                cin>>description;
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int index;
                cout<<"Enter task index to mark as completed: ";
                cin>>index;
                toDoList.markTaskCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout<<"Enter task index to remove: ";
                cin>>index;
                toDoList.removeTask(index);
                break;
            }
            case 5:
                cout<<"Exiting the program.\n";
                return 0;
            default:
                cout<<"Invalid choice. Try again.\n";
        }
    }

    return 0;
}
