#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool isUndir;
public:
    Graph(int V, bool isUndir=true){
        this->V = V;
        l = new list<int> [V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){//u-->v
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }

    bool directedHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;

        list<int> neighbors = l[src];
        for(int v : neighbors){
            if(!vis[v]){
                if(directedHelper(v, vis, recPath)){
                    return true;
                }
            }else{
                    if(recPath[v]){
                        return true;
                    }
                }
            recPath[src] = false;
        }

        return false;
    }

    bool isCycleDir(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        //for disconnected components
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(directedHelper(i, vis, recPath)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    //directed Graph
    Graph graph(4, false);

    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);

    cout<<graph.isCycleDir()<<endl;
    return 0;
}