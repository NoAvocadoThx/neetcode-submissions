class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        empty = dict()
        for i in nums:
            if i in empty:
                empty[i] += 1
            else:
                empty[i] = 1
            if empty[i] > 1:
                return True
        return False

        