class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> count;
        int res = 0;
        int l=0;
        for(int i=0;i<s.length();i++)
        {
            while(count.find(s[i]) != count.end())
            {
                count.erase(s[l]);
                l++;
            }
            count.insert(s[i]);
            res = max(res, i-l+1);
        }
        return res;

    }
};
