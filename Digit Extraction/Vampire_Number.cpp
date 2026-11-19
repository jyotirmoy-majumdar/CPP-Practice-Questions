/* Write a program to check whether a no is a Vampire No or not
Criterias are :
The vampire number must have an even number of digits.
It must be the product of two numbers, each having half as many digits as the original number.
The two fangs must contain exactly the same digits as the original number, including digit frequencies.
Both fangs cannot end in zero simultaneously.

ex : 1260
the fangs are :  21 * 60 = 1260 */

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

int countDigits(int n)
{
    int p = n, c = 0;
    while (p > 0)
    {
        p = p / 10;
        c++;
    }
    return c;
}

int digitExtract(int n)
{
    int p = n, r;
    while (p > 0)
    {
        r = p % 10;
        p = p / 10;
        return r;
    }
}
using namespace std;

int main()
{
    int num, i, flag = 0;
    cout << "Enter a Number : " << endl;
    cin >> num;
    while (countDigits(num) % 2 != 0)
    {
        cout << "The no is not even enter again : ";
        cin >> num;
    }
    int firstfang = 0;
    int secondfang = 0;
    for (i = pow(10, (countDigits(num) / 2 - 1)); i < pow(10, (countDigits(num) / 2 + 1)); i++)
    {
        firstfang = i;
        if (num % firstfang == 0)
        {
            secondfang = num / firstfang;
            if ((firstfang * secondfang == num) &&
                ((countDigits(firstfang) == countDigits(num) / 2) && (countDigits(secondfang) == countDigits(num) / 2)) &&
                (!(firstfang % 10 == 0 && secondfang % 10 == 0)))
            {
                string fangs = to_string(firstfang) + to_string(secondfang);
                string n = to_string(num);
                sort(fangs.begin(), fangs.end());
                sort(n.begin(), n.end());
                if (n == fangs)
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (flag == 1)
    {
        cout << "The given no is a Vampire Number" << endl;
        cout << "Its fangs are : " << endl;
        cout << firstfang << " " << secondfang;
    }
}