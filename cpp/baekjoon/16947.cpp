#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>



using namespace std;

int start=0;

bool check[3001] = {false};

bool circuit[3001] = {false};

int dist[3001] = {0};

bool dfs(int cur, vector< vector<int> > & g){
    check[cur] = true;
    
    for (int next : g[cur]){
        if(check[next] && next == start) return true;
        if(!check[next]){
            if( dfs(next, g)) return true;
        }
    }
    
    return false;
}

int bfs_short(int node, vector< vector<int> > &g){
    if(circuit[node]) return 0;
       
    queue<int> q;
    q.push(node); check[node] = true;
    dist[node] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (int s : g[cur]){
            q.push(s); check[s] = true;
            dist[s] = dist[cur]+1;
            
            if (circuit[s]) return dist[s];
            
        }
        
    }
    
    return 0;
}


int main(){
    int N;
    cin >> N;
    
    vector< vector<int> > graph(N+1, vector<int>());
    for (int i=0; i<N; i++){
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    
    for (int i=0; i<N; i++){
        start = i;
        circuit[i] = dfs(i,graph);
        memset(check, false, sizeof(check));
    }
    
    
    for (int i=0; i<N; i++){
        cout << bfs_short(i, graph);
        memset(dist, 0, sizeof(dist));
    }
    cout << endl;
    
    
    return 0;
}
