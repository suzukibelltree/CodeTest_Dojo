#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    // 2^n 通りの部分集合を全探索する
    for (int bit = 0; bit < (1 << n); ++bit) {
        // 各要素 i が選ばれているか判定
        for (int i = 0; i < n; ++i) {
            if ((bit >> i) & 1) {
                // i 番目の要素が選ばれている場合の処理
            }
        }
        // bit に対応する評価値を計算し、答えを更新する
    }

    return 0;
}
