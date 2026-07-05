#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    while(true){
        string s=to_string(n);
        int size=s.size();
        int new_n=0;
        for(int i=0;i<size;i++){
            new_n+=int(s.at(i)-'0')*int(s.at(i)-'0');
        }
        if(new_n==1){
            cout <<"Yes"<<endl;
            return 0;
        }
        else if(new_n>=n){
            cout <<"No"<<endl;
            return 0;
        }
        n=new_n;
    }
    return 0;
}
