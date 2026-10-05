class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s: strs)
        {
            res += to_string(s.size()) + "#" +s;
        }
        return res;
    }
//4#qwer3#abc13#qwertyuiop
//i          i
    vector<string> decode(string s) 
    {
        if(s.size()==0) return {};

        vector<string> res;
        for(int i = 0;i< s.size();)
        {
            
            int start = i;
            while(s[start]!= '#')
            {
                start++;
             
            }
            int length = stoi(s.substr(i , start-i));
            res.push_back(s.substr(start + 1, length));
            i = 1 + start+length;

        }
        return res;
    }
};
