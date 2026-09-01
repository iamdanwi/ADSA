#include <bits/stdc++.h>

using namespace std;

// Count all Digits of a Number
int countDigit(int n)
{
    int count = (int)(log10(n) + 1);
    // while (n > 0)
    // {
    //     count++;
    //     n = n / 10;
    // }

    return count;
}

// Reverse Digits of A Number
int reverseDigits(int n)
{
    int reverse = 0;

    while (n > 0)
    {
        int lastDigit = n % 10;
        n = n / 10;
        reverse = (reverse * 10) + lastDigit;
    }
    return reverse;
}

// Check if a number is Palindrome or Not
bool checkPalindrome(int n)
{
    int org = n;
    int reverse = 0;

    while (n > 0)
    {
        int lastDigit = n % 10;
        n = n / 10;
        reverse = (reverse * 10) + lastDigit;
    }
    return org == reverse ? true : false;
}

// Find GCD of two numbers
int gcd(int x, int y)
{
}

// Check if a number is Armstrong Number or not
bool armstrongNumber(int n)
{
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << checkPalindrome(n);
    return 0;
}
