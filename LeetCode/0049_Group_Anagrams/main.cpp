#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Sorting each string AND grouping same strings
        // (that is equal after sorting, which is anagrams)
        // unordered_map<string, vector<string>> anagramGroups; // sortedString -> [list of original strings]

        // for (const auto &word : strs)
        // {
        //     string sortedWord = word;
        //     sort(sortedWord.begin(), sortedWord.end());
        //     anagramGroups[sortedWord].push_back(word);
        // }

        // vector<vector<string>> result;

        // for (auto &pair : anagramGroups)
        // {
        //     result.push_back(pair.second);
        // }

        // return result;

        // Hash Map
        unordered_map<string, vector<string>> anagramGroups; // Frequency string -> [list of original strings]

        for (const auto &word : strs)
        {
            vector<int> count(26, 0); // 26 letters as radix (given)

            for (char c : word)
            {
                count[c - 'a']++;
            }

            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++)
            {
                key += ',' + to_string(count[i]);
            }

            anagramGroups[key].push_back(word);
        }

        vector<vector<string>> result;

        for (const auto &pair : anagramGroups)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};