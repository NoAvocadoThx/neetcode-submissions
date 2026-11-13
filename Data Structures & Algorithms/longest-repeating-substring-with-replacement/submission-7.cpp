class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCount;
        int res = 0;
        int l =0;
        int maxf = 0;
        for(int r = 0 ; r< s.size();r++)
        {
            charCount[s[r]]++;
            maxf = max(maxf, charCount[s[r]]);

            while(r-l+1 - maxf > k)
            {
                charCount[s[l]]--;
                l++;
            }
            res = max(res, r- l + 1);
        }

        return res;


    }
};
