#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        // current window size - frequency of the most frequent character in the current window
        // should be less than or equal to k
        unordered_map<char, int> charFrequency;
        int maxLength = 0;

        int left = 0, maxFreq = 0;
        for (int right = 0; right < s.size(); ++right)
        {
            charFrequency[s[right]]++;
            maxFreq = max(maxFreq, charFrequency[s[right]]);

            while (right - left + 1 - maxFreq > k)
            {
                charFrequency[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};