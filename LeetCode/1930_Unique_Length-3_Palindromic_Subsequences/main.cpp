#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        // Approach: Two-Pass Left-Right Tracking Approach
        // // Stores unique pairs (mid_char, outer_char)
        // set<pair<char, char>> result;
        // // Counter for characters on the right side
        // vector<int> right(26, 0);
        // // Have we seen this character on the left side
        // vector<bool> appearedOnLeftAtIndex(26, false);

        // for (char c : s)
        // {
        //     right[c - 'a']++;
        // }

        // for (char c : s)
        // {
        //     int currentMid = c - 'a';
        //     right[currentMid]--;

        //     for (int i = 0; i < 26; i++)
        //     {
        //         const bool willAppearOnRight = right[i] > 0;
        //         if (appearedOnLeftAtIndex[i] && willAppearOnRight)
        //         {
        //             result.insert({currentMid + 'a', i + 'a'});
        //         }
        //     }

        //     appearedOnLeftAtIndex[currentMid] = true;
        // }

        // return result.size();

        // Approach: First-and-Last Occurrence Interval Approach
        int n = s.size();
        vector<int> firstOccurrence(26, -1); // -1 -> not found yet
        vector<int> lastOccurrence(26, -1);  // -1 -> not found yet

        for (int i = 0; i < n; i++)
        {
            int currentCharIndex = s[i] - 'a';

            if (firstOccurrence[currentCharIndex] == -1)
            {
                firstOccurrence[currentCharIndex] = i;
            }

            lastOccurrence[currentCharIndex] = i;
        }

        int result = 0;

        for (int i = 0; i < 26; i++)
        {
            const bool hasAtLeastTwoOccurrences = firstOccurrence[i] < lastOccurrence[i];

            if (hasAtLeastTwoOccurrences)
            {
                // Distinct characters in between make the palindromes
                vector<bool> seen(26, false);

                for (int j = firstOccurrence[i] + 1; j < lastOccurrence[i]; j++)
                {
                    seen[s[j] - 'a'] = true;
                }

                result += count(seen.begin(), seen.end(), true);
            }
        }

        return result;
    }
};