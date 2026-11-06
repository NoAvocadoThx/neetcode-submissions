class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        dfs(cur, s, 0);
        return res;
    }

    void dfs(vector<string>& cur, string& s, int i)
    {
        if(i>=s.length())
        {
            res.push_back( cur);
            return;
        }
        for(int j = i ; j < s.length();j++)
        {
            if(IsPali(s, i, j))
            {
                cur.push_back(s.substr(i, j-i+1));
                dfs(cur, s, j+ 1);
                cur.pop_back();
            }
        }

    }

    bool IsPali(string& s, int i, int j)
    {
        while(i< j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
