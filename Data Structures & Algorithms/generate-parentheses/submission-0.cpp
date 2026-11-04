class Solution {
public:
vector<string> res;
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(0,0,n, s);
        return res;
    }



    void dfs(int currentLeftPar, int rightPar, int n, string& curString)
    {
        if(currentLeftPar == n && currentLeftPar == rightPar)
        {
            res.push_back(curString);
            return;
        }
        if(currentLeftPar < n)
        {
            curString +='(';
            dfs(currentLeftPar + 1, rightPar, n, curString);
            curString.pop_back();
        }
        if(rightPar < currentLeftPar)
        {
            curString += ')';
            dfs(currentLeftPar, rightPar+ 1, n, curString);
            curString.pop_back();
        }



    }
};
