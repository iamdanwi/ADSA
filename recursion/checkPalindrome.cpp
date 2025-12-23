#include <iostream>
#include <string>

bool checkPalindrome(std::string str, int start, int end)
{

    if (start >= end)
        return true;

    if (str[start] != str[end])
        return false;

    return checkPalindrome(str, start + 1, end - 1);
}

int main()
{
    std::string str = "ABB";

    std::cout << (checkPalindrome(str, 0, str.length()) ? "YES" : "NO");

    return 0;
}