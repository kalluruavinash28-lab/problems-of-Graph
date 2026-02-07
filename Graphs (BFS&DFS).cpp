#include<list>
#include <iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph{
  int v;
  list<int> *l;
  public:
  
  Graph(int v){
          this->v=v;
          l= new list<int> [v];
  }
        
        void addEdge(int u,int v){
                l[u].push_back(v);
                l[v].push_back(u);
        }
        void print(){
                for(int i=0;i<v;i++){
                        list<int> neighbors=l[i];
                        cout<<i<<":";
                        for(int v:neighbors){
                                cout<<v;
                        }
                        cout<<endl;
                }
        }
        void bfs(){
                queue<int> q;
                vector<bool> visited(v,false);
                q.push(0);
                visited[0]=true;
                while(q.size()>0){
                        int u=q.front();
                        q.pop();
                        cout<<u<<" ";
                        list<int> neighbors=l[u];
                        for(int x: neighbors){
                                if(!visited[x]){
                                        visited[x]=true;
                                        q.push(x);
                                }
                        }
                }
        }
        void dfsHelper(int u,vector<bool> &vis){
                vis[u]=true;
                cout<<u<<" ";
                list<int> neighbors=l[u];
                for(int z:neighbors){
                        if(!vis[z]){
                                dfsHelper(z,vis);
                        }
                }
        }
        void dfs(){
                vector<bool> vis(v,false);
                dfsHelper(0,vis);
        }
        
};


int main()
{
    Graph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
//       graph.print();
      graph.dfs();
    return 0;
}
