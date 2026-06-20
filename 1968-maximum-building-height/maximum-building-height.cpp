class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

    
        restrictions.push_back({1, 0});

       
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();
        for (int i = 1; i < m; i++) {

            long long dist =
                restrictions[i][0] -
                restrictions[i - 1][0];

            restrictions[i][1] =
                min(
                    restrictions[i][1],
                    (int)(restrictions[i - 1][1] + dist)
                );
        }
        for (int i = m - 2; i >= 0; i--) {

            long long dist =
                restrictions[i + 1][0] -
                restrictions[i][0];

            restrictions[i][1] =
                min(
                    restrictions[i][1],
                    (int)(restrictions[i + 1][1] + dist)
                );
        }

        long long ans = 0;
        for (int i = 1; i < m; i++) {

            long long id1 = restrictions[i - 1][0];
            long long h1  = restrictions[i - 1][1];

            long long id2 = restrictions[i][0];
            long long h2  = restrictions[i][1];

            long long dist = id2 - id1;

            long long peak =
                (h1 + h2 + dist) / 2;

            ans = max(ans, peak);
        }
        long long lastId =
            restrictions.back()[0];

        long long lastH =
            restrictions.back()[1];

        ans =
            max(
                ans,
                lastH + (n - lastId)
            );

        return (int)ans;
    }
};