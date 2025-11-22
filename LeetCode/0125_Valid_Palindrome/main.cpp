#include <string>

using namespace std;

class Solution
{
    bool isAnAlhpaNumChar(char c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }

public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;

        while (left < right)
        {
            while (!isAnAlhpaNumChar(s[left]) && left < right)
            {
                left++;
            }

            while (!isAnAlhpaNumChar(s[right]) && left < right)
            {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};