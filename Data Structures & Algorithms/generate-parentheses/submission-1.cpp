class Solution {
public:
vector<string> res;
    vector<string> generateParenthesis(int n) {
        string cur;
        dfs(0,0,n, cur);
        return res;
    }


    void dfs(int leftCount, int rightCount, int n, string& cur)
    {
        
        if(leftCount == n && leftCount == rightCount )
        {
            res.push_back(cur);
            return;
        }

        if(leftCount < n)
        {
            cur += '(';
            dfs(leftCount + 1, rightCount, n, cur);
            cur.pop_back();
        }
       if(rightCount < leftCount)
       {
            cur +=')';
            dfs(leftCount, rightCount + 1, n, cur);
            cur.pop_back();
       }
    }
};



