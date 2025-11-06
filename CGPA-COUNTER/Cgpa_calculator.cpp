#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Semester {
    std::string name;
    double credits;
};

int main() {
    vector<Semester> semesters = {
        {"Spring 24", 19.5},
        {"Fall 24", 19.5},
        {"Spring 25", 13.5},
        {"Summer 25", 12},
        {"Fall 25", 13.5},
        {"Spring 26", 12},
        {"Summer 26", 13.5},
        {"Fall 26", 13.5},
        {"Spring 27", 13.5},
        {"Summer 27", 12},
        {"Fall 27", 12}
    };

    double totalGradePoints = 0.0;
    double totalCredits = 0.0;

    cout << "=== BSc in CSE CGPA Calculator (Semester-wise) ===" << endl;
    cout << "Enter SGPA for each semester. If you haven't completed a semester, enter -1." << endl << endl;

    for (const auto& sem : semesters) {
        double sgpa;
        while (true) {
            cout << "SGPA for " << sem.name << " (" << sem.credits << " credits): ";
            cin >> sgpa;
            if ((sgpa >= 0.0 && sgpa <= 4.0) || sgpa == -1) break;
            cout << "Invalid input! Enter a value between 0.0 and 4.0 or -1 if not completed.\n";
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

    return 0;
}