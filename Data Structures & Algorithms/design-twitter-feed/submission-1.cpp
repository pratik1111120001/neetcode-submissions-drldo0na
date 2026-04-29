class Twitter {
public:
    unordered_map<int,set<int>> followList;
    unordered_map<int,set<pair<int,int>>> tweetsList;
    int time;
    Twitter() {
        followList.clear();
        tweetsList.clear();
        time=1;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsList[userId].insert({-1*time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        set<pair<int,int>> st;
        for(auto it : tweetsList[userId]){
            st.insert(it);
            if(st.size() > 10){
                st.erase(st.find(*(st.rbegin())));
            }
        }
        for(auto x : followList[userId]){
            for(auto it : tweetsList[x]){
                st.insert(it);
                if(st.size() > 10){
                    st.erase(st.find(*(st.rbegin())));
                }
            }
        }
        vector<int> ans;
        for(auto it : st) ans.push_back(it.second);
        return ans;
        time++;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
        time++;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followList[followerId].contains(followeeId))
            followList[followerId].erase(followList[followerId].find(followeeId));
        time++;
    }
};
