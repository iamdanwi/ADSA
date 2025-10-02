#include <iostream>
#include <stack>
#include <string>

bool isValid(string s)
{
    std::stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;
            if (c == ')' && st.top() != '(')
                return false;
            if (c == '}' && st.top() != '{')
                return false;
            if (c == ']' && st.top() != '[')
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    std::string s = "()[]{}";
    std::cout << (isValid(s) ? "Valid" : "Invalid");
    return 0;
}
