#include<list>
#include <iostream>
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
        
};


int main()
{
    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
      graph.print();
    return 0;
}
