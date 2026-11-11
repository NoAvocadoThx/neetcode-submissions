class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        dfs(s, cur, 0);
        return res;
    }


    void dfs(string& s, vector<string>& cur, int i)
    {
        if(i == s.size())
        {
            res.push_back(cur);
            return;
        }

        for(int j = i; j < s.size();j++)
        {
            if(IsPali(s,i,j))
            {
                cur.push_back(s.substr(i, j-i+1));
                dfs(s, cur, j + 1);
                cur.pop_back();
            }
        }
    }



    bool IsPali(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!= s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
