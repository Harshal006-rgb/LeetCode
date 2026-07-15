typedef pair<int, int> pp;

class Twitter {
  unordered_map<int, unordered_set<int>> following;
  unordered_map<int, vector<pp>> tweets;

  int timer;
  const int k = 10;

 public:
  Twitter() { timer = 0; }

  void postTweet(int userId, int tweetId) {
    tweets[userId].push_back({timer++, tweetId});
  }

  void follow(int followerId, int followeeId) {
    following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    following[followerId].erase(followeeId);
  }

  vector<int> getNewsFeed(int userId) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;

    int n = tweets[userId].size();

    for (int i = n - 1; i >= max(0, n - k); i--) {
      int time = tweets[userId][i].first;
      int tweet = tweets[userId][i].second;
      pq.push({time, tweet});

      if (pq.size() > k) {
        pq.pop();
      }
    }

    for (int followee : following[userId]) {
      n = tweets[followee].size();

      for (int i = n - 1; i >= max(0, n - k); i--) {
        int time = tweets[followee][i].first;
        int tweet = tweets[followee][i].second;
        pq.push({time, tweet});

        if (pq.size() > k) {
          pq.pop();
        }
      }
    }

    vector<int> feed;

    while(!pq.empty()){
      feed.push_back(pq.top().second);
      pq.pop();
    }

    reverse(feed.begin(),feed.end());
    return feed;
  }
};