#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<int> D(n);
    vector<int> Sum(n);
    for(int i=1;i<n;i++){
        cin >> D[i];
    }
    // 累積和を計算する
    Sum[1]=D[1];
    for(int i=1;i<n;i++){
        Sum[i]=D[i]+Sum[i-1];
    }
    // 解答の出力
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int ans = Sum[j-1]-Sum[i-1];
            cout << ans<<" ";
        }
        cout <<endl;
    }
    return 0;
}
