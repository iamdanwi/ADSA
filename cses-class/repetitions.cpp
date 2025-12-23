#include <iostream>
#include <string>

long long int count_repetation(std::string &str)
{
    if (str.empty())
        return 0;

    if (str.length() == 1)
        return 1;

    long long int max_count = 0, curr_count = 1;

    for (size_t i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == str[i])
        {
            curr_count += 1;
        }
        else
        {
            max_count = std::max(max_count, curr_count);
            curr_count = 1;
        }
    }

    return std::max(max_count, curr_count);
}

int main()
{
    std::string str;
    std::cin >> str;
    std::cout << count_repetation(str);
    // std::cout << "\nTotal count is: " << c << "\n";

    return 0;
}