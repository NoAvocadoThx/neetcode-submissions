class Solution {
public:
    string mapping[10] = {"","","abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        dfs(digits, "", 0);
        return res;
    }


    void dfs(string& digits, string curStr, int i)
    {
        if(curStr.size() == digits.size())
        {
            res.push_back(curStr);
            return;
        }
        string chars = mapping[digits[i] - '0'];
        for(char c : chars)
        {
            dfs(digits, curStr + c, i+1);
        }
    }
};
