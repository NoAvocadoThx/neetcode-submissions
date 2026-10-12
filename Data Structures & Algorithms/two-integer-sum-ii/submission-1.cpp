class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l =0;
        int r = numbers.size()-1;

        while(l<r)
        {
            int targetSum = numbers[l] + numbers[r];
            if(targetSum < target)
            {
                l++;
            }
            else if(targetSum > target)
            {
                r--;
            }
            else
            {
                return {l+1, r+1};
            }
            
        }
        return {};
    }
};
