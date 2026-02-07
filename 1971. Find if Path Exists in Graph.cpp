class graph{
    int v;
    list<int> *l;
    public:
    graph(int v){
        this->v=v;
        l=new list<int> [v];

    }
    void addedge(int u,int v){
        l[u].push_back(v);
         l[v].push_back(u);
    }
    bool helper(int s,int d,vector<bool> &vis){
        queue<int> q;
        q.push(s);
        vis[s]=true;
        while(q.size()>0){
            int z=q.front();
            q.pop();
            list<int> a=l[z];
            for(int x: a){
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
          return vis[d];
    }
    bool dfs(int s,int d){
       vector<bool> vis(v,false);
       return helper(s,d,vis);
    }
};



class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        graph g(n);
       for(int i=0;i<edges.size();i++){
    g.addedge(edges[i][0],edges[i][1]);
}

        return g.dfs(source,destination);
        
    }
};
