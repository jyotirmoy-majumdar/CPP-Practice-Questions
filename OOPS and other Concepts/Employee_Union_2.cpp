/*Create a union named EmployeeData containing:
- int employeeID
- float salary
- char performanceGrade
Create a struct named Employee containing:
- string name
- EmployeeData data
- int dataType
Requirements
1. Register employees
- Create an array of 3 Employee structs.
- Use a loop to collect their names.
- Ask the user which information they want to store for each employee:
  - 1 → Employee ID
  - 2 → Salary
  - 3 → Performance Grade
2. Store union data
Use a switch statement to store the selected information in the appropriate union member.
Also store the selected choice in dataType.
3. Create a display function
Create a function that receives one Employee and displays:
- Employee name.
- The correct union member based on dataType.
4. Display all employees
Use a loop to call your display function for all three employees.*/

#include <iostream>
using namespace std;

union EmployeeData
{
    int employeeId;
    float salary;
    char performanceGrade;
};

struct Employee
{
    string name;
    EmployeeData data;
    int datatype;
};

void DisplayEmployee(Employee e)
{
    cout << "The name of the Employee : " << e.name << endl;
    switch (e.datatype)
    {
    case 1:
        cout << "The Employeer Id is : " << e.data.employeeId << endl;
        break;

    case 2:
        cout << "The Salary of the Employeer is : " << e.data.salary << " Rs" << endl;
        break;

    case 3:
        cout << "The Performance Grade of the Employee is : " << e.data.performanceGrade << endl;
        break;
    }
}

int main()
{
    Employee Array[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        cout << "Enter the name of the Employee " << endl;
        cin >> Array[i].name;
        cout << "Enter the choice : " << endl;
        cout << "1 for Employee ID " << endl;
        cout << "2 for Salary " << endl;
        cout << "3 for Performance Grade " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the ID" << endl;
            cin >> Array[i].data.employeeId;
            Array[i].datatype = choice;
            break;

        case 2:
            cout << "Enter the Salary" << endl;
            cin >> Array[i].data.salary;
            Array[i].datatype = choice;
            break;

        case 3:
            cout << "Enter the Grade" << endl;
            cin >> Array[i].data.performanceGrade;
            Array[i].datatype = choice;
            break;

        default:
            cout << "Wrong Choice " << endl;
            break;
        }
    }
    for (i = 0; i < 3; i++)
    {
        DisplayEmployee(Array[i]);
    }
}
