#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // NOTE: do not forget to check length
        if (s.length() != t.length())
            return false;

        // Hash Map and check for each key
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for (int i = 0; i < s.length(); i++)
        {
            countS[s[i]]++;
            countT[t[i]]++;
        }

        return countS == countT;

        // Pre-Sorting and string equality check
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // return s == t;

        // Array based Hash Table
        // Balances frequency of the character in `s` with the corresponding frequency in `t`
        // Radix = 26 as input is lowercase alphabets, will change if the input criteria changes for `s` and `t`
        // vector<int> count(26, 0);

        // const int base = 'a';

        // for (int i = 0; i < s.length(); i++)
        // {
        //     count[s[i] - base]++;
        //     count[t[i] - base]--;
        // }

        // for (int value : count)
        // {
        //     if (value != 0)
        //         return false;
        // }

        // return true;
    }
};