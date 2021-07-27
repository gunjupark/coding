#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int ans = 100000000;

bool check[10000] = {false,};

void dfs(int k, int cnt, int idx, vector<vector<int> > &A ){
    if(idx == A.size()) return;
    if(cnt == k){
        

        return;
    }

    

    
}



int solution(int k, vector<int> num, vector<pair<int,int> > links){

    int answer;

    // 양방향 그래프로 트리 연결 리스트 만들기

    vector<vector<int> > A(num.size(), vector<int>());

    for(int i=0; i< links.size(); i++){
        if(links[i].first != -1){
            A[i].push_back(links[i].first);
        }
        if(links[i].second != -1){
            A[i].push_back(links[i].second);
        }
    }




    
    
    
    



    return answer;
}