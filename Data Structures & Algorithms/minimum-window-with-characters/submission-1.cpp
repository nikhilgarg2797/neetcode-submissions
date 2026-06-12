class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;

        int requiredCount = t.size();   // total chars still needed
        int l = 0;
        int min_len = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {
            // If this char is needed, reduce requiredCount
            if (mp[s[r]] > 0) requiredCount--;

            // Decrease count in map regardless
            mp[s[r]]--;

            // If all required chars are covered, try shrinking
            while (requiredCount == 0) 
            {
                if (r - l + 1 < min_len) 
                {
                    min_len = r - l + 1;
                    start = l;
                }
                mp[s[l]]++;
                // If removing this char makes window invalid, stop shrinking
                if (mp[s[l]] > 0) requiredCount++;
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
