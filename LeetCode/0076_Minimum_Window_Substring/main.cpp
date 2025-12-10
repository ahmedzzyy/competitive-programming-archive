#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty())
            return "";

        unordered_map<char, int> tCharFreq, window;
        for (char c : t)
        {
            tCharFreq[c]++;
        }

        int have = 0, need = tCharFreq.size();
        pair<int, int> resultSubstrIndices = {-1, -1};
        int minLength = INT_MAX;
        int left = 0;

        for (int right = 0; right < s.length(); right++)
        {
            char currentChar = s[right];
            window[currentChar]++;

            if (tCharFreq.count(currentChar) && window[currentChar] == tCharFreq[currentChar])
            {
                have++;
            }

            while (have == need)
            {
                if ((right - left + 1) < minLength)
                {
                    minLength = right - left + 1;
                    resultSubstrIndices = {left, right};
                }

                window[s[left]]--;
                if (tCharFreq.count(s[left]) && window[s[left]] < tCharFreq[s[left]])
                {
                    have--;
                }
                left++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(resultSubstrIndices.first, minLength);
    }
};