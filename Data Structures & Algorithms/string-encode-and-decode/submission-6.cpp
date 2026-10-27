class Solution {
public:


    string encode(vector<string>& strs) {
        string res;
        for(string s:strs)
        {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

//3#abc12#abcdefghjias5#poiuy
    vector<string> decode(string s) {
        if(s.size()==0) return {};
        vector<string> res;
       
        for(int i = 0 ; i< s.size();)
        {
            int start = i;
            
            while(s[start]!= '#')
            {
               
                start++;
            }
            int wordCount = stoi(s.substr(i, start - i));

            string singleString = s.substr(start+1, wordCount);
            res.push_back(singleString);

            i = start+1+wordCount;
        }
        return res;

    }
};
