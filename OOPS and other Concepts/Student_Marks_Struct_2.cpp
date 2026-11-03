/* Create a struct named Student containing:
- name — string
- marks — integer
Store the details of 3 students using an array of structs.
Create a function that receives a student and displays their details.
Create another function that receives a student and returns their result:
- Marks ≥ 90 → "Excellent"
- Marks ≥ 60 → "Pass"
- Marks below 60 → "Fail"
Display each student's name, marks, and result.
At the end, display the name of the student with the highest marks. */

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int marks;
};

void Marks_Checker(Student students[], int size)
{
    if (students[0].marks >= 90 || students[1].marks >= 90 || students[2].marks >= 90)
    {
        cout << "STUDENT EXCELLENT" << endl;
    }
    else if (students[0].marks >= 60 || students[1].marks >= 60 || students[1].marks >= 60)
    {
        cout << "STUDENT PASS" << endl;
    }
    else if (students[0].marks < 60 || students[1].marks < 60 || students[1].marks < 60)
    {
        cout << "STUDENT FAIL" << endl;
    }
}

void Student_Checker(Student students[], int size)
{
    cout << "Enter the details of the first student, first name and then marks " << endl;
    cin >> students[0].name;
    cin >> students[0].marks;
    cout << "Enter the details of the second student, first name and then marks " << endl;
    cin >> students[1].name;
    cin >> students[1].marks;
    cout << "Enter the details of the third student, first name and then marks " << endl;
    cin >> students[2].name;
    cin >> students[2].marks;

    cout << " ------------ THE SET OF STUDENT DETAILS -------------- " << endl;
    cout << students[0].name << endl;
    cout << students[0].marks << endl;
    cout << '\n';
    cout << students[1].name << endl;
    cout << students[1].marks << endl;
    cout << '\n';
    cout << students[2].name << endl;
    cout << students[2].marks << endl;
    cout << '\n';

    Marks_Checker(students, 3);
}

int main()
{
    Student students[3];
    Student_Checker(students, 3);
    return 0;
}