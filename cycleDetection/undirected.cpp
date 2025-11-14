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

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool undirCycleHelper(int src, int par, vector<bool> &vis){
        vis[src] = true;

        list<int> neighbors = l[src];
        for(int v : neighbors){
            if(!vis[v]){
                if(undirCycleHelper(v, src, vis)){
                    return true;
                }
            }else{
                if(v!=par){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir(){
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }
};

int main() {
    return 0;
}