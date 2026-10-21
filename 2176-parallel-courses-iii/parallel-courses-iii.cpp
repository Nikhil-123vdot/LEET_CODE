class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n];

        for(int i = 0; i < relations.size(); i++)
        {
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }

        vector<int> store(n, 0);
        vector<int> indegree(n, 0);

        for(int i = 0; i < relations.size(); i++)
        {
            indegree[relations[i][1]-1]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                store[i] = time[i];
            }
        }

        int ans = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            ans = max(ans, store[node]);

            for(int j = 0; j < adj[node].size(); j++)
            {
                int next = adj[node][j];

                store[next] = max(store[next], store[node] + time[next]);

                indegree[next]--;

                if(indegree[next] == 0)
                    q.push(next);
            }
        }

        return ans;
    }
};