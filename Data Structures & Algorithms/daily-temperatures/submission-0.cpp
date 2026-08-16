class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            

            while (!st.empty()) {
                if (t[st.top()] > t[i]) {
                    res[i] = st.top() - i;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if (st.empty()) {
                res[i] = 0;
                
            }
            st.push(i);
        }

        return res;
    }
};
