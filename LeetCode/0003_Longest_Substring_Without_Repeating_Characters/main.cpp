#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // character -> latest index where appeared
        unordered_map<char, int> characterMap;
        int maxLength = 0;

        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            if (characterMap.find(s[right]) != characterMap.end())
            {
                left = max(characterMap[s[right]] + 1, left);
            }

            characterMap[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};