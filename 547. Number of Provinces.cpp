class Solution {
public:
    void dfs(int src, vector<bool>& vis, vector<vector<int>>& gr) {
        vis[src] = true;

        for(int j = 0; j < gr.size(); j++) {
            if(gr[src][j] == 1 && !vis[j]) {
                dfs(j, vis, gr);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int c = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                c++;
                dfs(i, vis, isConnected);
            }
        }
        return c;
    }
};
