class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char, int> count;
        for(char s: s1)
        {
            count[s]++;
        }

        int l=0;
        for(int i = 0; i < s2.length();i++)
        {
            count[s2[i]]--;
            while(count[s2[i]] < 0)
            {
                count[s2[l]]++;
                l++;
            }

            if(i-l+1 == s1.size()) return true;
        }

        return false;
    }
};
