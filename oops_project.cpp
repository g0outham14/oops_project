#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student class
class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    Student(int roll, string nm, float mk) : rollNumber(roll), name(nm), marks(mk) {}

    void display() {
        cout << "Roll No: " << rollNumber
             << ", Name: " << name
             << ", Marks: " << marks << endl;
    }

    int getRollNumber() {
        return rollNumber;
    }

    void updateDetails(string newName, float newMarks) {
        name = newName;
        marks = newMarks;
        cout << "Details updated successfully.\n";
    }
};

// StudentManager class
class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int roll;
        string name;
        float marks;

        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore(); // Clear newline from input buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;

        students.push_back(Student(roll, name, marks));
        cout << "Student added successfully!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No students to display.\n";
            return;
        }

        cout << "\n--- Student List ---\n";
        for (auto& student : students) {
            student.display();
        }
    }

    void searchStudent() {
        int roll;
        cout << "Enter roll number to search: ";
        cin >> roll;

        for (auto& student : students) {
            if (student.getRollNumber() == roll) {
                cout << "Student found:\n";
                student.display();
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void updateStudent() {
        int roll;
        cout << "Enter roll number to update: ";
        cin >> roll;
        cin.ignore();

        for (auto& student : students) {
            if (student.getRollNumber() == roll) {
                string name;
                float marks;
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new marks: ";
                cin >> marks;
                student.updateDetails(name, marks);
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void deleteStudent() {
        int roll;
        cout << "Enter roll number to delete: ";
        cin >> roll;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getRollNumber() == roll) {
                students.erase(it);
                cout << "Student deleted successfully.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

// Main menu
int main() {
    StudentManager manager;
    int choice;

    while (true) {
        cout << "\n===== Student Management Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.searchStudent(); break;
            case 4: manager.updateStudent(); break;
            case 5: manager.deleteStudent(); break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
