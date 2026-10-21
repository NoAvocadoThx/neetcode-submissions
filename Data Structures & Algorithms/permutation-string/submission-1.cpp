class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int size = s1.size();
        unordered_map<char, int> need;
        for(char c : s1)
        {
            need[c] ++;
        }
        int l = 0;
        for(int r = 0; r< s2.size();r++)
        {
            need[s2[r]]--;
            while(need[s2[r]] < 0)
            {   
                need[s2[l]] ++;
                l++;
            }

             if (r - l + 1 == size) return true; 
        }
        return false;
    }
};
