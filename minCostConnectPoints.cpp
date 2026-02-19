class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int v=points.size();
        vector<bool> vis(v,false);
        int src=0;
        pq.push({0,src});
        int ans=0;
        while(pq.size()>0){
            int u=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(!vis[u]){
                vis[u]=true;
                ans+=wt;
                for(int V=0;V<v;V++){
                    if(u!=V){
                        int wt=abs(points[u][0]-points[V][0])+ abs(points[u][1]-points[V][1]);
                       pq.push({wt,V});
                    }
                }
            }
        }

    return ans;

        
    }
};
