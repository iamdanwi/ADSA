#include <iostream>
#include <string>

using namespace std;

string longest_common_prefix(vector<string> &str)
{
    sort(str.begin(), str.end());

    string s = str[0], e = str.back(), res = "";

    for (int i = 0; i < min(s.size(), e.size()); i++)
    {
        if (s[i] != e[i])
        {
            break;
        }
        res += s[i];
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest common prefix is: " << longest_common_prefix(strs) << "\n";
    return 0;
}
