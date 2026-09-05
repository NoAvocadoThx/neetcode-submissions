class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = defaultdict(int)
        for i in range(len(nums)):
            res[nums[i]] +=1
        pairs = sorted(res.items(), key = lambda x: x[1])
        top = pairs[-k:]
        ans = []
        for j, cnt in top:
            ans.append(j)
        return ans