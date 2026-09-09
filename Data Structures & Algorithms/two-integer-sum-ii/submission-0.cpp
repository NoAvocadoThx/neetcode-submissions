class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = (int)numbers.size()- 1;
        while(index1 < index2)
        {
            int targetSum = numbers[index2] +numbers[index1];
            if(targetSum < target)
            {
                index1 ++;
            }
            else if(targetSum > target)
            {
                index2--;
            }
            else
            {
                return {index1 + 1,index2 + 1};
            }
           
        }

        return {};
    }
};
