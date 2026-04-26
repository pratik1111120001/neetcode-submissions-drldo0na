class TimeMap {
public:
    map<pair<string,int>,string> timeMap;
    map<string,set<int>> timeSet;
    TimeMap() {
        // timeMap.clear();
        // timeSet.clear();
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[{key,timestamp}] = value;
        std::set<int> st = timeSet[key];
        st.insert(timestamp);
        timeSet[key] = st;
    }
    
    string get(string key, int timestamp) {
        if(!timeSet.contains(key))
            return "";
        std::set<int> st = timeSet[key];
        auto it = st.lower_bound(timestamp);
        if(it == st.end()) it--;
        if(it == st.begin() && *(it) > timestamp)
            return "";
        if(*(it) > timestamp) it--;
        int currTimestamp = *(it);
        if(!timeMap.contains({key,currTimestamp}))
            return "";
        return timeMap[{key,currTimestamp}];
    }
};
