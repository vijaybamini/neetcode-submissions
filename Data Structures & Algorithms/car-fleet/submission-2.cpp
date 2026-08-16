class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ds;
        int fleets = 0;
        float  max_time  = 0.0f;
        for (int i = 0; i < position.size(); i++) {
            ds.push_back({position[i], speed[i]});
        }
        auto comp = [](const auto& a, const auto& b) { return a.first > b.first; };
        sort(ds.begin(), ds.end(), comp);
        for (int i = 0; i < ds.size(); i++) {
            float time = (float)(target - ds[i].first) / (ds[i].second);
            if ( max_time < time) {
                max_time = time;
                fleets++;
            }
        }
        return fleets;
    }
};
