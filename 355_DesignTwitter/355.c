class Twitter {
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 1;
        unordered_set<int> followingId = followingMap[userId];
        vector<int> result;

        
        for(int i = post.size()-1;i >= 0;--i){
            //Iterate the post from the lastest, looking up if the post is posted by userId
            //or by himself (because users son't follow himself )
            
            if(followingId.find(post[i].first) != followingId.end() || post[i].first == userId){
                result.push_back(post[i].second);
                count++;
            }
            if(count > 10)break;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followingMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followingMap[followerId].erase(followeeId);
    }
private:
    vector<pair<int,int>> post;
    unordered_map<int,unordered_set<int>> followingMap;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */