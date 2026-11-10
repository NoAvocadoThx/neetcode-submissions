class Solution {
public:
    vector<string> res;
    string maps[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        dfs(digits, "", 0);
    return res;
    }

    void dfs(string& digits, string cur, int i)
    {
       if(i == digits.length())
       {
            res.push_back(cur);
            return;
       }

        string chars = maps[digits[i]-'0'];
        for(char c : chars)
        {
            dfs(digits, cur+ c, i+1);
        }
    }
};
