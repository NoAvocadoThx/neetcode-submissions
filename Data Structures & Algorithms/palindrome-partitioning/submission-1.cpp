class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
         vector<string> cur;
        dfs(s, 0, cur);
        return res;
    }


    void dfs(string& s , int i, vector<string>& cur)
    {
        if(i >= s.length())
        {
            res.push_back(cur);
            return;
        }

        for(int j = i;j< s.size();j++)
        {
            if(isPali(s,i,j))
            {
                cur.push_back(s.substr(i, j - i +1));
                dfs(s, j +1, cur );
                cur.pop_back();
            }
        }
    }


    bool isPali(string& s, int i, int j)
    {
        while(i<j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
