#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    iota(a.begin(), a.end(), 1); // a = {1, 2, ..., n}

    // n! 通りの順列を辞書順に全探索する
    // 開始時点で a が昇順（辞書順最小）になっている必要がある
    do {
        // a に対応する評価値を計算し、答えを更新する
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}
