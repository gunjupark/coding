#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(std::pair<int, bool> p1, std::pair<int,bool > p2) {
    return p1.first<p2.first;
}


int solution(vector<int> priorities, int location) {
    int answer = 0;
    // pair< int, bool > : prior , 추적대상 여부
    deque<pair<int, bool>> dq;
    
    
    for (int i=0; i<priorities.size(); i++){
        if(i == location)
            dq.push_back(make_pair(priorities[i], true));
        else
            dq.push_back(make_pair(priorities[i], false));
    }
    
    int max_val = *max_element(priorities.begin(), priorities.end());
    
    int temp_a;
    bool temp_b;
    while(true){
        if(dq.front().first == max_val){
            if(dq.front().second)
                return ++answer;
            else {
                answer++;
                dq.pop_front();
                const auto max_item = max_element(dq.begin(),dq.end(),compare);
                max_val = max_item->first;
            }
        }
        else {
            temp_a = dq.front().first;
            temp_b = dq.front().second;
            dq.push_back(make_pair(temp_a,temp_b));
            dq.pop_front();
        }
    }
    
    return answer;
}


int main() {


}
