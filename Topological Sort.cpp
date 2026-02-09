

class Graph{
    int v;
    list<int> *l;
    bool isundir;
    public:
    Graph(int v, bool isundir=true){
        this->v=v;
        l=new list<int> [v];
        this->isundir=isundir;
    }
  void addedge(int u,int v){
      l[u].push_back(v);
      if(isundir){
          l[v].push_back(u);
      }
      }
     
     void dfs(int src,vector<bool> &vis,stack<int> &s){
         vis[src]=true;
       
         list<int> neg=l[src];
         for(int x: neg){
             if(!vis[x]){
                 dfs(x,vis,s);
               
                 
             }}
          s.push(src);  
      
     }
};
class Solution {
  public:
    vector<int> topoSort(int v, vector<vector<int>>& edges) {
       Graph g(v,false);
       vector<bool> vis(v,false);
       stack<int> s;
       vector<int> ans;
       for(int i=0;i<edges.size();i++){
           g.addedge(edges[i][0],edges[i][1]);
       }
      for(int i=0;i<v;i++){
    if(!vis[i]) {
        g.dfs(i, vis, s);
    }}
     

       while(!s.empty()){
           ans.push_back(s.top());
           s.pop();
       }
        return ans;
    }
};
