class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        int n = heights.size();
        vector<int> nse(n, n);
        
        vector<int> pse(n, -1);
       
        Nse(heights, nse);
        Pse(heights, pse);

        for (int i = 0; i < heights.size(); i++) {
            
            int area = (nse[i] - pse[i] - 1) * heights[i];
            max_area = max(max_area, area);
        }
        return max_area;
    }
    void Nse(vector<int>& heights, vector<int>& nse) {
        stack<int> st;
        int n = heights.size();
        st.push(n - 1);
        for(int i = heights.size() - 2; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }
    }
    void Pse(vector<int>& heights, vector<int>& pse) {
        stack<int> st;
        int n = heights.size();
        st.push(0);
        for(int i = 1; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }
    }
};
