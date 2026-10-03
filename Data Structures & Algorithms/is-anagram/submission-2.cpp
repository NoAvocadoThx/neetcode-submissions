class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> words;
         unordered_map<char, int> words2;
        if(s.size() != t.size()) return false;
        for(auto c: s)
        {
            words[c]++;
        }

        for(auto c : t)
        {
           words2[c]++;
        }
        return words == words2;
        
    }
};
