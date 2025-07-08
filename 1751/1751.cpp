#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        if (n == 0) return 0;
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> ends;
        for (int i = 0; i < n; i++) {
            ends.push_back(events[i][1]);
        }
        vector<int> prev_index(n, -1);
        for (int i = 0; i < n; i++) {
            int start_i = events[i][0];
            auto it = lower_bound(ends.begin(), ends.begin() + i, start_i);
            prev_index[i] = it - ends.begin() - 1;
        }

        vector<int> dp_prev(n, 0);
        int ans = 0;

        for (int j_val = 1; j_val <= k; j_val++) {
            vector<int> M_prev = dp_prev;
            for (int i = 1; i < n; i++) {
                M_prev[i] = max(M_prev[i], M_prev[i-1]);
            }

            vector<int> dp_curr(n, 0);
            for (int i = 0; i < n; i++) {
                int take = events[i][2];
                if (prev_index[i] != -1) {
                    take += M_prev[prev_index[i]];
                }
                int skip = (i > 0) ? dp_curr[i-1] : 0;
                dp_curr[i] = max(take, skip);
            }
            ans = max(ans, dp_curr.back());
            dp_prev = dp_curr;
        }

        return ans;
    }
};