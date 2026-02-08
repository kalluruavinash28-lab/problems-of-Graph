#include <bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int> *l;

public:
    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool dfs(int src, vector<bool> &vis, int p){
        vis[src] = true;

        list<int> &neg = l[src];  

        for(int x : neg){
            if(!vis[x]){
                if(dfs(x, vis, src)){
                    return true;
                }
            }
            else if(x != p){
                return true;       
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isCycle(int v, vector<vector<int>>& edges) {
        graph g(v);

        for(auto &e : edges){
            g.addedge(e[0], e[1]);
        }

        vector<bool> vis(v, false);

        for(int i = 0; i < v; i++){
            if(!vis[i]){
                if(g.dfs(i, vis, -1))
                    return true;
            }
        }
        return false;
    }
};
