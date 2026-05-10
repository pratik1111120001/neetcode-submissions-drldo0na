class TrieNode {
public:
    unordered_map<char, TrieNode*> node;
    bool endOfWord = false;
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto it : word){
            if(curr->node.find(it) == curr->node.end())
                curr->node[it] = new TrieNode();
            curr = curr->node[it];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        vector<TrieNode*> canbe;
        canbe.push_back(root);
        for(auto ch : word){
            vector<TrieNode*> curr;
            for(auto it : canbe){
                if(ch == '.'){
                    for(char ch1 = 'a' ; ch1 <= 'z' ; ch1++){
                        if(it->node.find(ch1) != it->node.end())
                            curr.push_back(it->node[ch1]);
                    }
                }
                else{
                    if(it->node.find(ch) != it->node.end())
                        curr.push_back(it->node[ch]);
                }
            }
            if(curr.size() == 0)
                return false;
            canbe = curr;
        }
        for(auto it : canbe){
            if(it->endOfWord)
                return true;
        }
        return false;
    }
};

