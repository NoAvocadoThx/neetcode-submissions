class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sets;
        int l=0;
        int maxSoFar = 0;

        for(int r = 0; r< s.length();r++)
        {
            while(sets.find(s[r]) != sets.end())
            {
                sets.erase(s[l]);
                l++;
            }

            sets.insert(s[r]);

            maxSoFar = max(maxSoFar, r-l +1);

        }
        return maxSoFar;
    }
};
