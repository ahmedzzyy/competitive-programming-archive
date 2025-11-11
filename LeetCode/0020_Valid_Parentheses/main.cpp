#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        // Brute Force (Iterative)
        // while (true)
        // {
        //     // find == npos if not found

        //     if (s.find("{}") != string::npos)
        //     {
        //         s.erase(s.find("{}"), 2);
        //         continue;
        //     }

        //     if (s.find("()") != string::npos)
        //     {
        //         s.erase(s.find("()"), 2);
        //         continue;
        //     }

        //     if (s.find("[]") != string::npos)
        //     {
        //         s.erase(s.find("[]"), 2);
        //         continue;
        //     }

        //     break;
        // }

        // return s.empty();

        // Stack
        stack<char> stk;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stk.push(c);
            }
            else
            {
                if (stk.empty())
                {
                    return false;
                }

                char top = stk.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '['))
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};