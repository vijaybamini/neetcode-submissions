class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ds;
        int fleets = 0;
        stack<float> st;
        for (int i = 0; i < position.size(); i++) {
            ds.push_back({position[i], speed[i]});
        }
        auto comp = [](const auto& a, const auto& b) { return a.first > b.first; };
        sort(ds.begin(), ds.end(), comp);
        for (int i = 0; i < ds.size(); i++) {
            float time = (float)(target - ds[i].first) / (ds[i].second);
            if (st.empty() || st.top() < time) {
                st.push(time);
                fleets++;
            }
        }
        return fleets;
    }
};
