/* Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.  */

#include <iostream>
#include <string>
using namespace std;

int String_Checker(string hay, string need)
{
    int i, j;
    bool flag;

    if (need.length() == 0)
    {
        return 0;
    }

    if (need.length() > hay.length())
    {
        return -1;
    }

    for (i = 0; i <= hay.length() - need.length(); i++)
    {
        flag = true;

        for (j = 0; j < need.length(); j++)
        {
            if (!(need[j] == hay[i + j]))
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string haystack = "", needle = "";

    cout << "Enter the Haystack String" << endl;
    cin >> haystack;

    cout << "Enter the Needle String" << endl;
    cin >> needle;

    if ((haystack.length() >= 1 && haystack.length() <= 10000) &&
        (needle.length() >= 1 && needle.length() <= 10000))
    {
        cout << "Index: " << String_Checker(haystack, needle);
    }
    else
    {
        cout << "The provided strings don't match the required constraints" << endl;
    }

    return 0;
}