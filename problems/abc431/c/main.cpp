#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> H(n), B(m);
    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    sort(H.begin(), H.end());
    sort(B.begin(), B.end());
    long long robot = 0;
    // ここにロジックを記述
    // for (int i = 0; i < n; i++) // 頭パーツのインデックスを動かしていく
    // {
    //     if (H[i] <= B[body_idx])
    //     {
    //         cout << "Head:" << H[i] << " Body:" << B[body_idx] << endl;
    //         robot++;
    //     }
    //     body_idx++;
    //     if (body_idx == m)
    //     {
    //         break;
    //     }
    // }
    int head_idx = 0;
    int body_idx = 0;
    while (head_idx < n && body_idx < m)
    {
        if (H[head_idx] <= B[body_idx])
        {
            head_idx++;
            body_idx++;
            robot++;
        }
        else
        {
            body_idx++;
        }
    }
    if (robot >= k)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
