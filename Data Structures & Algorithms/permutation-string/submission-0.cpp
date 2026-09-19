class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        unordered_map<char, int> need;
        for (char c : s1) need[c]++;

        int l = 0;
        for(int r = 0; r < s2.size();r++)
        {
            need[s2[r]]--; 
            while (need[s2[r]] < 0) 
            {
                need[s2[l]]++;
                l++;
            }
            if (r - l + 1 == n) return true; 
        }

     
        return false;

    }
};
