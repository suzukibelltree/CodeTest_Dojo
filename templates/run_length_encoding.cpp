#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    // ランレングス圧縮: 同じ文字が連続する部分を (文字, 連続個数) の列にまとめる
    vector<pair<char, long long>> runs;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[j] == s[i]) {
            ++j;
        }
        runs.push_back({s[i], j - i});
        i = j;
    }

    // runs[k] = (文字, 連続個数)
    // ここに runs を使ったロジックを書く
    // 例: 隣り合うrun同士を比較する場合
    // for (size_t k = 0; k + 1 < runs.size(); ++k) {
    //     char c1 = runs[k].first, c2 = runs[k + 1].first;
    //     long long cnt1 = runs[k].second, cnt2 = runs[k + 1].second;
    // }

    return 0;
}
