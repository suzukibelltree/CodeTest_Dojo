#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n,m;
    cin >> n>>m;
    vector<int> wear(n);
    vector<int> clothes(m);
    for(int i=0;i<n;i++){
        cin >> wear[i];
        clothes[wear[i]-1]+=1;
    }
    int iterator=0;
    for(iterator=0;iterator<m;iterator++){
        if(clothes[iterator]>1){
            cout <<"No"<<endl;
            break;
        }
    }
    if(iterator==m){
        cout <<"Yes"<<endl;
    }
    iterator=0;
    for(iterator=0;iterator<m;iterator++){
        if(clothes[iterator]==0){
            cout <<"No"<<endl;
            break;
        }
    }
    if(iterator==m){
        cout <<"Yes"<<endl;
    }
    return 0;
}
