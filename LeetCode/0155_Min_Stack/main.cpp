#include <stack>

using namespace std;

class MinStack
{
    stack<long> stk; // long to prevent overflow
    long minimum;

public:
    MinStack()
    {
        // stack representation = its value - current minimum
        // Returned value = stack top + current minimum
    }

    void push(int val)
    {
        if (stk.empty())
        {
            stk.push(0); // val - minimum
            minimum = val;
        }
        else
        {
            stk.push(val - minimum);
            minimum = val < minimum ? val : minimum;
        }
    }

    void pop()
    {
        if (stk.empty())
        {
            return;
        }

        long top = stk.top();
        stk.pop();

        if (top < 0)
        {
            // If popped value was a new minimum during its push
            minimum = minimum - top;
        }
    }

    int top()
    {
        long top = stk.top();

        if (top >= 0)
        {
            return top + minimum;
        }

        // If top is negative, it means the actual top is the current minimum
        return (int)minimum;
    }

    int getMin()
    {
        // Brute Force
        // stack<int> temp;
        // int minimum = stk.top();

        // while (stk.size())
        // {
        //     temp.push(stk.top());
        //     stk.pop();
        //     minimum = min(minimum, temp.top());
        // }

        // while (temp.size())
        // {
        //     stk.push(temp.top());
        //     temp.pop();
        // }

        return (int)minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */