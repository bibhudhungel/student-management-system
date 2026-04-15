//Project: Student Management System

//About: A simple console-based application
// to manage student records, allowing users to 
// add, display, and search for students. 


#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

// Add Student
void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Marks: ";
    cin >> s.marks;

    file << s.id << " " << s.name << " " << s.marks << endl;
    cout << "Student Added!\n";

    file.close();
}

// Display Students
void displayStudents() {
    Student s;
    ifstream file("students.txt");

    cout << "\n--- Student List ---\n";

    while (file >> s.id >> s.name >> s.marks) {
        cout << s.id << " " << s.name << " " << s.marks << endl;
    }

    file.close();
}

// Search Student
void searchStudent() {
    Student s;
    int id;
    bool found = false;

    cout << "Enter ID to search: ";
    cin >> id;

    ifstream file("students.txt");

    while (file >> s.id >> s.name >> s.marks) {
        if (s.id == id) {
            cout << "Found: " << s.name << " " << s.marks << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Not Found!\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) displayStudents();
        else if (choice == 3) searchStudent();

    } while (choice != 4);

    return 0;
}