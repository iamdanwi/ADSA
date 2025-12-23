#include <iostream>
#include <string>

std::string reverseString(std::string s)
{
    if (s.length() <= 1)
    {
        return s;
    }
    return reverseString(s.substr(1)) + s[0];
}

int main()
{
    std::string str = "abcd";
    std::cout << reverseString(str);

    return 0;
}