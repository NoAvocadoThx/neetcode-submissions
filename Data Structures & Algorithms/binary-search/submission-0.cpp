class Solution {
public:
    int search(vector<int>& nums, int target) {
        return BSearch(0, nums.size()-1,nums,target);
    }

    int BSearch(int l, int r, vector<int>& nums, int target)
    {
        if(l>r) return -1;
        int m = l + (r-l) /2;

        if(nums[m] == target) return m;
        return (nums[m] < target) ? BSearch(m+1, r, nums,target) : BSearch(l, m - 1, nums,target);
    }
};
