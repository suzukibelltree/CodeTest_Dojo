#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int cases;
    cin >> cases;
    long long x_1,y_1,r_1,x_2,y_2,r_2;
    for(int i=0;i<cases;i++){
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
        // 頂点同士の距離
        long long distance = abs(x_1-x_2)*abs(x_1-x_2)+abs(y_1-y_2)*abs(y_1-y_2);
        if(distance>(r_1+r_2)*(r_1+r_2)){
            cout <<"No"<<endl;
        }
        else if((r_1-r_2)*(r_1-r_2)>distance){
            cout <<"No"<<endl;
        }
        else{
            cout <<"Yes"<<endl;
        }
    }
    return 0;
}
