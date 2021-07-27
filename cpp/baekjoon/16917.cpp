#include <vector>
#include <iostream>
#include <limits>


using namespace std;


int main(){
    int ans = numeric_limits<int>::max();
    int a, b, c;
    int x, y;
    cin >> a >> b >> c >> x >> y;
    int m = max(x,y);
    for (int i=0; i<=m; i++){
        ans = min(ans, (c*2)*i + max(0, (x-i)*a) + max(0, (y-i)*b));
    }

    cout << ans << "\n";
    return 0;
}