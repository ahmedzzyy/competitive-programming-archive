#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter
{
    struct Tweet
    {
        int time;
        int id;
        int user;
        int idx;
    };

    struct TweetComparator
    {
        bool operator()(const Tweet &a, const Tweet &b)
        {
            return a.time < b.time; // Min-heap based on time
        }
    };

    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> [(tweetId, count)]
    unordered_map<int, unordered_set<int>> followers;  // followerId -> {followeeId}

public:
    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({tweetId, time});

        // Keep only the 10 most recent tweets
        if (tweets[userId].size() > 10)
            tweets[userId].erase(tweets[userId].begin());

        time++;
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;

        // Collect followers' + current user's tweets
        unordered_set<int> followeeIds = followers[userId];
        followeeIds.insert(userId);

        priority_queue<Tweet, vector<Tweet>, TweetComparator> recentTweets;

        // push recent tweet from each followee
        for (int followeeId : followeeIds)
        {
            if (!tweets.count(followeeId))
                continue;

            int lastIdx = tweets[followeeId].size() - 1;
            auto &tweet = tweets[followeeId][lastIdx];
            recentTweets.push({tweet.second, tweet.first, followeeId, lastIdx});
        }

        // k-way merge
        while (!recentTweets.empty() && result.size() < 10)
        {
            Tweet topTweet = recentTweets.top();
            recentTweets.pop();
            result.push_back(topTweet.id);

            // push the next tweet from the same user
            if (topTweet.idx > 0)
            {
                int nextIdx = topTweet.idx - 1;
                auto &nextTweet = tweets[topTweet.user][nextIdx];
                recentTweets.push({nextTweet.second, nextTweet.first, topTweet.user, nextIdx});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */