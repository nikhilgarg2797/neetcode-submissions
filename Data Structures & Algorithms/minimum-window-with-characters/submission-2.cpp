class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(t.size() > s.size()) return "";

        unordered_map<char,int> tcount, window;
        for(char c:t) tcount[c]++;

        int l = 0; 
        int need = t.size();
        int have = 0;
        int len = INT_MAX;
        int start = 0;
        for(int r = 0; r< s.size(); r++)
        {
            if(tcount[s[r]] > 0) 
            {
                window[s[r]]++;
                if(window[s[r]] <= tcount[s[r]]) have++;
            }
            while(have == need)
            {
                if (r - l + 1 < len) 
                {
                    len = r - l + 1;
                    start = l;
                }
                if(window[s[l]]>0)
                {
                    window[s[l]]--;
                    if(window[s[l]] < tcount[s[l]]) have--;
                }
                l++;
            }
        } 
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};
