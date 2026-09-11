class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> stringSet;
        int longest = 0;
        int l = 0;

        for(int i = 0;i<s.size();i++)
        {
            while(stringSet.contains(s[i]))
            {
                stringSet.erase(s[l]);
                l++;
            }
            stringSet.insert(s[i]);
            longest = max(longest,i-l+1);
        }
        return longest;
    }
};
