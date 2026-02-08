
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
     
     bool dfs(int src,vector<bool> &vis,vector<bool>& recpath){
         vis[src]=true;
         recpath[src]=true;
         list<int> neg=l[src];
         for(int x: neg){
             if(!vis[x]){
                 if(dfs(x,vis,recpath)){
                     return true;
                 }
             }
             else{
                 if(recpath[x]){
                     return true;
                 }
             }
         }
         recpath[src]=false;
         return false;
     } 
};

class Solution {
  public:
    bool isCyclic(int v, vector<vector<int>> &edges) {
 Graph g(v,false);

        for(auto &e : edges){
            g.addedge(e[0], e[1]);
        }

        vector<bool> vis(v, false);
        vector<bool> recpath(v, false);

        for(int i = 0; i < v; i++){
            if(!vis[i]){
                if(g.dfs(i, vis, recpath))
                    return true;
            }
        }
        return false;
        
    }
};
