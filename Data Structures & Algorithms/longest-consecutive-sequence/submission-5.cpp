class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int count = 0;
        for(int i : numSet)
        {

            if(numSet.find(i - 1) == numSet.end())
            {
                int length = 1;
                while(numSet.find(i + length) != numSet.end())
                {
                    length++;
                }
                res = max(res, length);
            }
        }
        return res;
        
    }
};



