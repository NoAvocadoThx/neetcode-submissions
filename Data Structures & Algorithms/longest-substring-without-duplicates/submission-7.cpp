class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charMap;
        int longest = 0;
        int l = 0;
        for(int r = 0; r < s.length();r++)
        {
            while(charMap.find(s[r]) != charMap.end())
            {
                charMap.erase(s[l]);
                l++;
            }
            charMap.insert(s[r]);

            longest = max(longest, r- l + 1);
        }
        return longest;


    }
};
