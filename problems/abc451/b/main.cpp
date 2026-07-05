#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n,m;
    cin >> n>>m;
    vector<int> A(n+1),B(n+1);
    vector<int> ans(m+1);
    for(int i=1;i<=n;i++){
        cin >> A[i]>> B[i];
        ans[A[i]]-=1;
        ans[B[i]]+=1;

    }
    for(int i=1;i<=m;i++){
        cout << ans[i]<<endl;
    }
    return 0;
}
