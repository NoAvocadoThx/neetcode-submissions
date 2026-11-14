class Solution {
public:
 string charMap[10] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
 vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        dfs(digits, "", 0);
        return res;
    }

    void dfs(string digits, string cur, int i)
    {
        if(i == digits.size())
        {
            res.push_back(cur);
            return;
        }
        string s = charMap[digits[i] - '0'];
        for(char c: s)
        {
          
            dfs(digits, cur + c, i+1);
            
        }
    }
};
