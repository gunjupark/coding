#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 0, 0,-1, 1};
int dy[] = {-1, 1, 0, 0};

int main(){
    int n, m;
    cin >>m >> n;

    vector<vector<char> > A(m , vector<char>(n));

    vector<vector<bool> > check(m, vector<bool>(n,false));

    vector<pair<int,int> > stars;

    for (int i=0; i<m; i++){
        for(int j=0; j< n; j++){
            cin >> A[i][j];
        }
    }
    vector<vector<int> > ans;

    for(int i=0;i <n*m; i++){
        int y = i/n;
        int x = i%n;
        if(A[y][x] != '*') continue;
        stars.push_back(make_pair(y,x));

        int d = min(min(n-1-x,x),min(m-1-y,y));
        

        if(d == 0) continue;
        
        bool flag = true;
        for (int j=1; j <= d; j++){
            for(int k=0; k<4; k++){
                if(A[y+j*dy[k]][x+j*dx[k]] != '*'){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;

            for(int k=0; k < 4; k++){
                check[y+j*dy[k]][x+j*dx[k]] = true;
            }
            check[y][x] = true;

            vector<int> tmp;
            tmp.push_back(y+1);
            tmp.push_back(x+1);
            tmp.push_back(j);
            ans.push_back(tmp);
        }
    }
    
    for (int i=0; i <stars.size(); i++){
        if(!check[stars[i].first][stars[i].second]){
            cout<< "-1\n";
            return 0;    
        }
    }
    
    
    for (int i=0; i<m; i++){
        for(int j=0; j < n; j++){
            if(!check[i][j]) printf("-");
            else printf("*");
        }
        printf("\n");
    }
     
    
    if(ans.size()==0){
        cout<< "-1\n";
        return 0;
    }
    cout<< ans.size() << "\n";
    for (int i=0; i< ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
    }


    return 0;
}