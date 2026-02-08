class Solution {
public:
    void dfs(int src,int d,vector<bool> &vis,vector<vector<int>>& graph,vector<vector<int>>&ans,vector<int> path){
        
        path.push_back(src);
        if(src==d){
          ans.push_back(path);
          return;
        }
         vis[src]=true;
     
     for(int i: graph[src]){
        if(!vis[i]){
           dfs(i,d,vis,graph,ans,path);
        }
     }
     path.pop_back();
     vis[src]=false;

   

    }    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<vector<int>> ans;
      int n=graph.size();  
        vector<bool>vis(n,false);
        vector<int> path;
        dfs(0,n-1,vis,graph,ans,path);
        return ans;
    }
};
