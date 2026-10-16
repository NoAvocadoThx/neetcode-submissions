class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> sets;
        int l=0;
        int longest = 0;
        for(int i=0;i<s.length();i++)
        {
            while(sets.find(s[i])!= sets.end())
            {
                sets.erase(s[l]);
                l++;
            }
            sets.insert(s[i]);
            longest = max(longest, i-l+1);
        }
        return longest;
    }
};
