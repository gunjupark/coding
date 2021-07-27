#include <iostream>
#include <vector>
#include <queue>


using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<int> > g(n+1, vector<int>());

    for(int i=0; i < n-1; i++){
        int node, edge;
        cin >> node >> edge;
        g[node].push_back(edge);
    }

    vector<int> test(n);
    vector<bool> chk(n+1, false);

    vector<int> parents(n+1);

    for (int i=0; i< n; i++){
        cin >> test[i];
    }

    queue<int> q;

    if(test[0] != 1) {
        printf("0\n");
        return 0;
    }

    //init 
    q.push(1);
    chk[1] = true;
    int idx = 1;

    for (int i=0; i<n; i++){
        if(q.empty()) {
            printf("0\n");
            return 0;
        }

        int cur = q.front(); q.pop();

        if (cur != test[i]) {
            printf("0\n");
            return 0;
        }

        int cnt = 0;

        for (int k =0; k < g[cur].size(); k++){
            if (!chk[g[cur][k]]){
                parents[g[cur][k]] = cur;
                cnt+= 1;
            }
        }

        for (int j=0; j<cnt; j++){
            if(parents[test[idx+j]] != cur || idx+j >= n){
                printf("0\n");
                return 0;
            }

            q.push(test[idx+j]); 
            chk[test[idx+j]] = true;
        }

        idx += cnt;
    }

    printf("1\n");

    return 0;
}