/*
Create an enum called Day containing all seven days of the week.
Ask the user to enter a day and determine whether it is:
- Weekday
- Weekend
Create a function that receives a Day and returns the classification using if-else .
*/

#include <iostream>
using namespace std;

enum Day
{
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

Day Receive_Day();
int Day_Checker(Day);

Day Receive_Day()
{
    cout << "Enter a day number (Sunday = 1): ";
    int d1;
    cin >> d1;

    Day d = static_cast<Day>(d1);
    return d;
}

int Day_Checker(Day d3)
{
    if (d3 == SUNDAY || d3 == SATURDAY)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Day d2 = Receive_Day();

    switch (d2)
    {
    case SUNDAY:
        cout << "SUNDAY" << endl;
        break;
    case MONDAY:
        cout << "MONDAY" << endl;
        break;
    case TUESDAY:
        cout << "TUESDAY" << endl;
        break;
    case WEDNESDAY:
        cout << "WEDNESDAY" << endl;
        break;
    case THURSDAY:
        cout << "THURSDAY" << endl;
        break;
    case FRIDAY:
        cout << "FRIDAY" << endl;
        break;
    case SATURDAY:
        cout << "SATURDAY" << endl;
        break;
    default:
        cout << "INVALID DAY" << endl;
        return 0;
    }

    int d4 = Day_Checker(d2);

    if (d4 == 1)
    {
        cout << "ITS WEEKEND" << endl;
    }
    else
    {
        cout << "ITS WEEKDAY" << endl;
    }

    return 0;
}