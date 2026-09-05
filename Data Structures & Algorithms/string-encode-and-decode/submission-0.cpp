class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;
        for(const auto& s:strs)
        {
            int count = s.size();
            ans+= to_string(count) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while( i < s.size())
        {
            int j=i;
            while(s[j] != '#')
            {
                j++;
            }
            int wordCount = stoi(s.substr(i, j - i));
            string ansString;
            for(int c = 0; c < wordCount ;c++)
            {
                ansString += s[j+1 +c];
            }
            ans.push_back(ansString);
            i = j+1+wordCount;
        }
        return ans;
    }
};
