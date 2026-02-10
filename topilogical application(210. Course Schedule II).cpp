class Graph{
int v;
list<int> *l;
bool isundir;
public:
Graph(int v,bool isundir=true){
    this->v=v;
    this->isundir=isundir;
    l= new list<int>[v];
}

 void addedge(int u,int v){
    l[u].push_back(v);
    if(isundir){
        l[v].push_back(u);
    }
 }
    bool dfs(int src,vector<bool> &vis,vector<bool>& recpath,stack<int> &s){
         vis[src]=true;
         recpath[src]=true;
         list<int> neg=l[src];
         for(int x: neg){
             if(!vis[x]){
                 if(dfs(x,vis,recpath,s)){
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
         s.push(src);
         return false;
         
     } 
};



class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    Graph g(n,false);
       for(int i=0;i<prerequisites.size();i++){
    g.addedge(prerequisites[i][1], prerequisites[i][0]);
}

        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        stack<int> s;
          for(int i=0;i<n;i++){
            if(!vis[i]){
                if(g.dfs(i,vis,recpath,s)){
                    return {};
                }  
            }
          }
          vector<int> ans;
          while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
          }
          return ans;
    }
};
