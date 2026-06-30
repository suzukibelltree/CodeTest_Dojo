#include <bits/stdc++.h>
# include <iomanip>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int x,y;
    cin >> x>>y;
    double ans=0;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            int sum=i+j;
            int diff = abs(i-j);
            if(sum>=x||diff>=y){
                ans+=1;
            }
        }
    }
    cout << fixed << setprecision(15) << ans/36.0 <<endl;
    return 0;
}
