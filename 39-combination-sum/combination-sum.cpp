class Solution {
public:

    void find(vector<int>& candidates,
              int target,
              vector<vector<int>>& ans,
              vector<int>& temp,
              int i,
              int n)
    {
        // target complete
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        // candidates khatam
        if(i == n)
        {
            return;
        }

        if(target >= candidates[i])
        {
            temp.push_back(candidates[i]);

            find(candidates,
                 target - candidates[i],
                 ans,
                 temp,
                 i,
                 n);

            
            temp.pop_back();
        }

        find(candidates,
             target,
             ans,
             temp,
             i + 1,
             n);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int n = candidates.size();

        vector<vector<int>> ans;
        vector<int> temp;

        find(candidates, target, ans, temp, 0, n);

        return ans;
    }
};