#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<int> A(n+1),B(n+1);
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    for(int i=1;i<=n;i++){
        cin >> B[i];
    }
    for(int i=1;i<=n;i++){
        if(B[A[i]]!=i){
            cout <<"No"<<endl;
            return 0;
        }
    }
    cout <<"Yes"<<endl;
    return 0;
}
