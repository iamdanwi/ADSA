#include <bits/stdc++.h>

using namespace std;

void countNumbers(int n)
{
    if (n == 0)
    {
        return;
    }
    countNumbers(n - 1);
    cout << n << " ";
}

void printName(int n, string name)
{
    if (n <= 0)
        return;

    printName(n - 1, name);
    cout << name << " ";
}

int sumOfNumbers(int n)
{
    if (n == 1)
        return 1;

    return n + sumOfNumbers(n - 1);
}

int factorial(int n)
{
    if (n == 1)
        return 1;

    return n * factorial(n - 1);
}

void revArr(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(nums[start], nums[end]);
    start++;
    end--;
    revArr(nums, start, end);
}

void reversArray(vector<int> &nums)
{
    revArr(nums, 0, nums.size() - 1);
}

bool isPalindrome(string &str, int i)
{
    if (i >= str.length() / 2)
        return true;

    if (str[i] != str[str.length() - i - 1])
        return false;

    return isPalindrome(str, i + 1);
}

int fibonacci(int n)
{
    if (n <= 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << fibonacci(n);

    // countNumbers(n);
    // printName(n, "bubu");
    // cout << sumOfNumbers(n);
    // cout << factorial(n);

    /*
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    reversArray(v);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
   */

    /*
     string s = "madam";
     cout << isPalindrome(s, 0);
     */
    return 0;
}
