class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> maps = {
        {')', '('},
        {'}', '{'},
        {']', '['}
        };

        stack<char> valid;

        for(char c: s)
        {
            if(maps.find(c) != maps.end())
            {
                if(!valid.empty() && maps[c] == valid.top())
                {
                    valid.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                valid.push(c);
            }
        }
        return valid.empty();
    }
};
