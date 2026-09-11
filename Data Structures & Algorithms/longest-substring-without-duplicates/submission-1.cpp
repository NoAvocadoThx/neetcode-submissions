class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int l = 0;
        int longest = 0;
        for(int i = 0; i<s.size();i++)
        {
            while(set.contains(s[i]))
            {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[i]);
            longest = max(longest, i-l+1);
        }
        return longest;
    }
};
