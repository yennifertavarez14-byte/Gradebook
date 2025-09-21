#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Student {
    string name;
    int grade;
};

// Function to validate grade (0–100)
int inputGrade() {
    int g;
    while (true) {
        cin >> g;
        if (cin.fail() || g < 0 || g > 100) {
            cout << "Invalid grade. Please enter a number between 0 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return g;
        }
    }
}

int main() {
    vector<Student> students;
    int choice;

    cout << "Mini Student Gradebook" << endl;
    cout << "Choose data entry mode:" << endl;
    cout << "1. Counter-controlled (fixed number of students)" << endl;
    cout << "2. Sentinel-controlled (type STOP to finish)" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // Counter-controlled loop
        int n;
        cout << "How many students? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Student s;
            cout << "Enter student name: ";
            cin >> s.name;
            cout << "Enter grade (between 0 and 100): ";
            s.grade = inputGrade();
            students.push_back(s);
        }

    }
    else if (choice == 2) {
        // Sentinel-controlled loop
        while (true) {
            Student s;
            cout << "Enter student name (or STOP to finish): ";
            cin >> s.name;
            if (s.name == "STOP") break;
            cout << "Enter grade (between 0 and 100): ";
            s.grade = inputGrade();
            students.push_back(s);
        }
    }
    else {
        cout << "Invalid menu choice. Exiting." << endl;
        return 0;
    }

    // If no students were entered
    if (students.empty()) {
        cout << "No student data entered." << endl;
        return 0;
    }

    // Compute totals, average, highest, lowest
    double total = 0;
    int highest = -1, lowest = 101;
    string highName, lowName;

    for (auto& s : students) {
        total += s.grade; // compound assignment
        if (s.grade > highest) {
            highest = s.grade;
            highName = s.name;
        }
        if (s.grade < lowest) {
            lowest = s.grade;
            lowName = s.name;
        }
    }

    double average = total / students.size();

    // Display results
    cout << "\nGrade Report" << endl;
    for (auto& s : students) {
        cout << s.name << " - " << s.grade;
        if (s.grade >= 60)
            cout << " (Pass)";
        else
            cout << " (Fail)";
        cout << endl;
    }

    cout << "\nClass average: " << average << endl;
    cout << "Highest grade: " << highName << " (" << highest << ")" << endl;
    cout << "Lowest grade: " << lowName << " (" << lowest << ")" << endl;

    return 0;
}
