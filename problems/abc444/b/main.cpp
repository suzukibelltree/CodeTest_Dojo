#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n,k;
    cin >> n>>k;
    int ans=0;
    for(int i=1;i<=n;i++){
        string num = to_string(i);
        int sum=0;
        int len = size(num);
        for(int j=0;j<len;j++){
            sum+=int(num.at(j)-'0');
        }
        if(sum==k){
            ans++;
        }
    }
    cout << ans<<endl;
    return 0;
}
