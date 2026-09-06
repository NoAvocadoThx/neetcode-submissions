class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(const auto& s : strs)
        {
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while( i < (int) s.size())
        {
            int pointer = i;
            // figure out the word count
            while( s[pointer] != '#')
            {
                pointer++;
            }
            int wordCount = stoi(s.substr(i, pointer - i));
            string ansString = s.substr(pointer + 1, wordCount );
            ans.push_back(ansString);
            i = pointer+1+wordCount;

        }
        return ans;

    }
};
