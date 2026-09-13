class Solution {
public:

    int check(vector<vector<int>>& img1,
              vector<vector<int>>& img2,
              int dr, int dc)
    {
        int n = img1.size();
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x = i + dr;
                int y = j + dc;

                if(x >= 0 && x < n && y >= 0 && y < n)
                {
                    if(img1[i][j] == 1 && img2[x][y] == 1)
                        count++;
                }
            }
        }

        return count;
    }

    int solve(vector<vector<int>>& img1,
              vector<vector<int>>& img2,
              int dr, int dc)
    {
        int n = img1.size();

        if(dr == n)
            return 0;

        if(dc == n)
            return solve(img1, img2, dr + 1, -(n - 1));

        int ans = check(img1, img2, dr, dc);

        ans = max(ans,
                  solve(img1, img2, dr, dc + 1));

        return ans;
    }

    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2)
    {
        int n = img1.size();

        return solve(img1, img2, -(n - 1), -(n - 1));
    }
};