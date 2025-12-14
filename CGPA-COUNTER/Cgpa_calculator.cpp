#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

struct Semester {
    string name;
    double credits;
};

void calculateOverallCGPA() {
    vector<Semester> semesters = {
        {"Spring 24", 19.5}, {"Fall 24", 19.5}, {"Spring 25", 13.5},
        {"Summer 25", 12},   {"Fall 25", 13.5}, {"Spring 26", 12},
        {"Summer 26", 13.5}, {"Fall 26", 13.5}, {"Spring 27", 13.5},
        {"Summer 27", 12},   {"Fall 27", 12}
    };

    double totalGradePoints = 0.0;
    double totalCredits = 0.0;

    cout << "\n=== Overall CGPA Calculator ===" << endl;
    cout << "Enter SGPA for each semester. If you haven't completed a semester, enter -1." << endl << endl;

    for (const auto& sem : semesters) {
        double sgpa;
        while (true) {
            cout << "SGPA for " << sem.name << " (" << sem.credits << " credits): ";
            cin >> sgpa;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid number between 0.0 and 4.0 or -1." << endl;
                continue;
            }
            if ((sgpa >= 0.0 && sgpa <= 4.0) || sgpa == -1) break;
            cout << "Invalid input! Enter a value between 0.0 and 4.0 or -1 if not completed." << endl;
        }
        if (sgpa != -1) {
            totalGradePoints += sgpa * sem.credits;
            totalCredits += sem.credits;
        }
    }

    if (totalCredits == 0) {
        cout << "No semesters completed. CGPA cannot be calculated." << endl;
    } else {
        double cgpa = totalGradePoints / totalCredits;
        cout << fixed << setprecision(2);
        cout << "\nTotal Credits Completed: " << totalCredits << endl;
        cout << "Current CGPA: " << cgpa << endl;
    }
}

void calculateSemesterSGPA() {
    int numCourses;
    cout << "\n=== Present Semester SGPA Calculator ===" << endl;

    while (true) {
        cout << "Enter the number of courses in this semester: ";
        cin >> numCourses;
        if (cin.fail() || numCourses <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a positive integer value." << endl;
        } else {
            break;
        }
    }

    double totalGradePoints = 0.0;
    double totalCredits = 0.0;

    for (int i = 1; i <= numCourses; ++i) {
        double credit, grade;
        while (true) {
            cout << "Enter the credit for course " << i << ": ";
            cin >> credit;
            if (cin.fail() || credit <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a positive number for credits." << endl;
            } else {
                break;
            }
        }
        while (true) {
            cout << "Enter the grade point for course " << i << " (0.0 - 4.0): ";
            cin >> grade;
            if (cin.fail() || grade < 0.0 || grade > 4.0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a number between 0.0 and 4.0." << endl;
            } else {
                break;
            }
        }
        totalGradePoints += credit * grade;
        totalCredits += credit;
    }

    double sgpa = (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0;
    cout << fixed << setprecision(2);
    cout << "\nTotal Credits this Semester: " << totalCredits << endl;
    cout << "Current Semester SGPA: " << sgpa << endl;
}

int main() {
    cout << "=== BSc in CSE CGPA Program ===" << endl;

    while (true) {
        cout << "\nWhat do you want to calculate?\n";
        cout << "1. Present semester SGPA\n";
        cout << "2. Overall CGPA\n";
        cout << "Enter 1 or 2: ";

        int choice;
        while (true) {
            cin >> choice;
            if (cin.fail() || (choice != 1 && choice != 2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice! Enter 1 or 2: ";
            } else {
                break;
            }
        }

        if (choice == 1)
            calculateSemesterSGPA();
        else
            calculateOverallCGPA();

        char again;
        while (true) {
            cout << "\nDo you want to perform another operation? (y/n): ";
            cin >> again;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // <-- Always clear newline!
            if (again == 'y' || again == 'Y' || again == 'n' || again == 'N')
                break;
            cout << "Invalid input! Please enter 'y' (yes) or 'n' (no)." << endl;
        }
        if (again == 'n' || again == 'N') {
            cout << "Thank you for using the CGPA Calculator! Goodbye.\n";
            break;
        }
        cout << "\n-------------------------------------------\n";
    }

    return 0;
}