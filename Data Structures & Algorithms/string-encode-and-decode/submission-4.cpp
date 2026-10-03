class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(int i = 0 ;i< strs.size();i++)
        {
            int length = strs[i].size();

            res += to_string(length) + "#" + strs[i];
        }
        return res;
         
    }

 

    vector<string> decode(string s) {       
        vector<string> res;
        if(s.size() == 0) return res;

    
        for(int i = 0; i <s.size();)
        {          
            int j = i;
            while(s[j]!= '#')
            {
                j++;
            }
            int length = stoi(s.substr(i, j -i));
            string ansString = s.substr( j + 1, length);
            res.push_back(ansString);
            i = 1 + length+j;
        }
        return res;
    }
};
