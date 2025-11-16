#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // Reverse Polish Notation OR Postfix Notation
        stack<int> operandStack;
        int result;

        for (auto &token : tokens)
        {
            if (token == "+")
            {
                int a = operandStack.top();
                operandStack.pop();

                int b = operandStack.top();
                operandStack.pop();

                operandStack.push(a + b);
            }
            else if (token == "-")
            {
                int a = operandStack.top();
                operandStack.pop();

                int b = operandStack.top();
                operandStack.pop();

                operandStack.push(b - a);
            }
            else if (token == "*")
            {
                int a = operandStack.top();
                operandStack.pop();

                int b = operandStack.top();
                operandStack.pop();

                operandStack.push(a * b);
            }
            else if (token == "/")
            {
                int a = operandStack.top();
                operandStack.pop();

                int b = operandStack.top();
                operandStack.pop();

                operandStack.push(b / a);
            }
            else
            {
                operandStack.push(stoi(token));
            }
        }

        return operandStack.top();
    }
};