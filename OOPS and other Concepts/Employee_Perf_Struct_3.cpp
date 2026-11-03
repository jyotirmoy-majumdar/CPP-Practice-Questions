/* Create a struct named Employee containing:
- name — string
- salary — integer
- performanceScore — integer
Requirements
1. Ask the user how many employees they want to enter (maximum 10).
2. Store their details in an array of structs.
3. Use a loop to fill the employee records.
4. Create a function that receives an Employee and displays their details.
5. Create another function that receives an Employee and returns their performance category:
   - Score 90 or above → "Outstanding"
   - Score 70 or above → "Good"
   - Score 50 or above → "Average"
   - Below 50 → "Poor"
6. Use a loop to display every employee's details and category.
7. At the end, display:
   - Employee with the highest salary.
   - Employee with the highest performance score. */

#include <iostream>
#include <string>

using namespace std;

struct Employee
{
    string name;
    int salary;
    int performanceScore;
};

void Employee_array_fill(Employee employee_array[], int);
void Display_array(Employee employee_array[], int);
void Employee_Performance_Display(Employee employee_array[], int);
void Employee_Maximum_Displaying(Employee employee_array[], int);

void Employee_array_fill(Employee employee_array[], int size)
{
    cout << " ---------- EMPLOYEE RECORD ENTERING ----------- " << endl;
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "Enter the name of the employee " << endl;
        cin >> employee_array[i].name;
        cout << "Enter the salary of the employee " << endl;
        cin >> employee_array[i].salary;
        cout << "Enter the performance score of the employee " << endl;
        cin >> employee_array[i].performanceScore;
    }
    Display_array(employee_array, size);
}

void Display_array(Employee employee_array[], int size2)
{
    cout << " ----------- EMPLOYEE RECORD PRINTING -------------- " << endl;
    int i;
    for (i = 0; i < size2; i++)
    {
        cout << "The name of the employee : ";
        cout << employee_array[i].name << endl;

        cout << "The salary of the employee : ";
        cout << employee_array[i].salary << endl;

        cout << "The performance score of the employee : ";
        cout << employee_array[i].performanceScore << endl;
        cout << '\n';
    }
    Employee_Performance_Display(employee_array, size2);
}

void Employee_Performance_Display(Employee employee_array[], int size3)
{
    cout << " ----------- EMPLOYEE PERFORMANCE DISPLAY -------------- " << endl;
    int i;
    for (i = 0; i < size3; i++)
    {
        if (employee_array[i].performanceScore >= 90)
        {
            cout << employee_array[i].name << " has OUTSTANDING PERFORMANCE " << endl;
        }
        else if (employee_array[i].performanceScore >= 70 && employee_array[i].performanceScore < 90)
        {
            cout << employee_array[i].name << " has GOOD PERFORMANCE " << endl;
        }
        else if (employee_array[i].performanceScore >= 50 && employee_array[i].performanceScore < 70)
        {
            cout << employee_array[i].name << " has AVERAGE PERFORMANCE " << endl;
        }
        else
        {
            cout << employee_array[i].name << " has POOR PERFORMANCE " << endl;
        }
    }
    cout << endl;
    Employee_Maximum_Displaying(employee_array, size3);
}

void Employee_Maximum_Displaying(Employee employee_array[], int size4)
{
    cout << " ---------------- BEST EMPLOYEE PRINTING ---------------- " << endl;
    int i, ind1, ind2;
    int max_sal = 0, max_per = 0;
    max_per = employee_array[0].performanceScore;
    max_sal = employee_array[0].salary;
    for (i = 0; i < size4; i++)
    {
        if (max_per < employee_array[i].performanceScore)
        {
            max_per = employee_array[i].performanceScore;
            ind1 = i;
        }
    }
    for (i = 0; i < size4; i++)
    {
        if (max_sal < employee_array[i].salary)
        {
            max_sal = employee_array[i].salary;
            ind2 = i;
        }
    }
    cout << "Employee with the most SALARY is : " << employee_array[ind2].name << endl;
    cout << "Salary Amount " << max_sal << endl;
    cout << endl;
    cout << "Employee with the most PERFORMANCE SCORE  is : " << employee_array[ind1].name << endl;
    cout << "Performance Score " << max_per << endl;
}

int main()
{
    Employee employee_array[10];
    int n;
    cout << "Enter the number of Employee you want to record " << endl;
    cin >> n;
    while (n > 10 || n < 1)
    {
        cout << "Number of Employee is out of bounds " << endl;
        cout << "Enter the value again " << endl;
        cin >> n;
    }
    Employee_array_fill(employee_array, n);

    return 0;
}