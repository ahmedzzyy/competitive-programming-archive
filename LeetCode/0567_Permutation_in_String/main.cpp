#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> frequencyS1(26, 0);
        vector<int> frequencyWindow(26, 0);

        for (int i = 0; i < s1.length(); i++)
        {
            frequencyS1[s1[i] - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < s2.size(); right++)
        {
            frequencyWindow[s2[right] - 'a']++;

            if (right - left + 1 > s1.length())
            {
                // length exceeded, shrink from left
                frequencyWindow[s2[left] - 'a']--;
                left++;
            }

            if (frequencyWindow == frequencyS1)
            {
                return true;
            }
        }

        return false;
    }
};