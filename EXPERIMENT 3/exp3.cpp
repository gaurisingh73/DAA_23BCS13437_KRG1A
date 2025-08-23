class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        vector<vector<int>> freq;
        map<int, int> m;
        for(int i: arr){
            m[i]++;
        }
        for(auto i: m){
            freq.push_back({i.first, i.second});
        }
        return freq;
    }
};
