class Solution {
public:
    int splitArray(vector<int>& a, int k) {
        int n = a.size();
        int lo = -1, hi = 1e9+1;
        while(hi - lo > 1){
            int m = midpoint(lo, hi);
            int cnt = 1;
            bool ok = true;
            for(int i = 0, sm = 0; i < n && ok; i++){
                if(a[i] > m) ok = false;
                sm += a[i];
                if(sm > m) cnt++, sm = a[i];
            }
            if(cnt > k) ok = false;
            if(ok) hi = m;
            else lo = m;
        }
        return hi;
    }
};
