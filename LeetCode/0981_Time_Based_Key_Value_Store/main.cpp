#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        store[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        string result = ""; // Default to empty string if not found
        auto &values = store[key];

        int left = 0, right = values.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp)
            {
                // Update result and search right for greater
                result = values[mid].second;
                left = mid + 1;
            }
            else
            {
                // Search left for smaller
                right = mid - 1;
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */