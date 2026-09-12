class Solution {
public:

    vector<int> solve(vector<vector<int>>& a) {

        int n = a.size();

        // {start, end, weight, original_index}
        vector<array<int,4>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({
                a[i][0],
                a[i][1],
                a[i][2],
                i
            });
        }

        // Sort according to end
        sort(v.begin(), v.end(),
            [](auto &x, auto &y) {
                return x[1] < y[1];
            });

        // dp[i][k] = best answer using first i intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for(int i = 1; i <= n; i++) {

            int start = v[i-1][0];
            int end = v[i-1][1];
            int weight = v[i-1][2];
            int idx = v[i-1][3];

            // Find previous non-overlapping interval
            int l = 0, r = i - 1;
            int pos = 0;

            while(l < r) {
                int mid = (l + r) / 2;

                if(v[mid][1] < start)
                    l = mid + 1;
                else
                    r = mid;
            }

            if(i > 1 && v[l][1] < start)
                pos = l + 1;
            else if(i == 1)
                pos = 0;
            else
                pos = l;

            for(int k = 1; k <= 4; k++) {

                // Don't take current interval
                dp[i][k] = dp[i-1][k];

                // Take current interval
                auto candidate = dp[pos][k-1];

                candidate.first += weight;
                candidate.second.push_back(idx);

                sort(candidate.second.begin(),
                      candidate.second.end());

                if(candidate.first > dp[i][k].first ||
                   (candidate.first == dp[i][k].first &&
                    candidate.second < dp[i][k].second)) {

                    dp[i][k] = candidate;
                }
            }
        }

        return dp[n][4].second;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        return solve(intervals);
    }
};