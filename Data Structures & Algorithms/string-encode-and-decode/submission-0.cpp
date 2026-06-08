class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s:strs)
        {
            res += to_string(s.length()) + "#" + s;
        }
        return res;
    }


    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        
        while (i < s.length())
        {
            int j = i;
            
            // Find '#'
            while (s[j] != '#')
            {
                j++;
            }
            
            // Extract length
            int len = stoi(s.substr(i, j - i));
            
            // Move to start of actual string
            j++;  // skip '#'
            
            // Extract the string
            string word = s.substr(j, len);
            res.push_back(word);
            
            // Move to next encoded chunk
            i = j + len;
        }
        
        return res;
    }
};
