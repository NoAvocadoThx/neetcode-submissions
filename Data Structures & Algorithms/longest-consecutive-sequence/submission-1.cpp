class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count  = 0;
        unordered_set<int> set(nums.begin(),nums.end());
        for( int i : set)
        {
            if(set.find(i - 1) == set.end())
            {
                int length = 1;
                while(set.find(i + length) != set.end())
                {
                    length++;
                }
                count = max(count, length);
            }          
        }
        return count;


    }
};
