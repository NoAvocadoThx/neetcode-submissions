class Solution:
    def groupAnagrams(self, strs):
        res = defaultdict(list)
        for i in range(len(strs)):
            sortedStr = "".join(sorted(strs[i]))
            res[sortedStr].append(strs[i])
        return list(res.values())