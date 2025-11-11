#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){//u-->v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u = 0; u<V; u++){
            list<int> neighbors = l[u];
            cout<<u<<":";
            for(int v : neighbors){
                cout<< v << " ";
            }
            cout<<endl;
        }
    }

    void bfs(){// O(V+E)
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(q.size() > 0){
            int u = q.front();//curr vertex
            q.pop();
            cout<<u<<" ";

            list<int> neighbors = l[u];//u-->v
            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout<<endl;
    }
};

int main() {

    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    graph.bfs();

    return 0;
}