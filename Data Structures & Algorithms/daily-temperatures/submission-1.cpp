class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> res(n, 0);
        for(int i = 0; i< n; i++)
        {
            int temp = temperatures[i];
            while(!st.empty() && st.top().first < temp)
            {
                auto t = st.top();
                res[t.second] = i-t.second;
                st.pop();
            }
            st.push({temp,i});
        }
        return res;
    }
};
