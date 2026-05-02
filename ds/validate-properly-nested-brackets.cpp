#include <iostream>
#include <string>

using namespace std;

bool areBracketsProperlyMatched(string code_snippet)
{
    if (code_snippet.empty())
        return true;

    stack<char> st;

    for (char c : code_snippet)
    {
        if (c == '{' || c == '[' || c == '(')
        {
            st.push(c);
        }
        else if (c == '}' || c == ']' || c == ')')
        {
            if (st.empty())
            {
                return false;
            }

            char top = st.top();

            st.pop();

            if (
                (c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{'))
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main(int argc, char const *argv[])
{
    string code_snippet = "() {} []";
    if (areBracketsProperlyMatched(code_snippet))
    {
        cout << "Properly Nested Brackets\n";
    }
    else
    {
        cout << "Not Properly Nested Brackets\n";
    }
    return 0;
}
