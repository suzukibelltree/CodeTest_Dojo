#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int brockNum = 0;
    int tail_idx = 0;
    int head_idx = 0;
    int L = 0; // K番目の1塊の長さ
    int G = 0; // K-1番目の1塊とK番目の1塊の間にある0の個数
    // S全体を走査してk-1番目の塊の末尾とk番目の塊の先頭を特定する(計算量：0(N))
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            continue;
        }
        // 1の塊が始まる時の処理
        bool isBrockStart = (s[i] == '1' && (i == 0 || s[i - 1] == '0'));
        if (isBrockStart)
        {
            brockNum++;
            if (brockNum == k)
            {
                head_idx = i;
            }
        }
        // 1の塊が終わる時の処理
        bool isBrockEnd = (s[i] == '1' && (i == n - 1 || s[i + 1] == '0'));
        if (isBrockEnd)
        {
            if (brockNum == k - 1)
            {
                tail_idx = i;
            }
            if (brockNum == k)
            {
                L = i - head_idx + 1;
                break;
            }
        }
    }
    G = head_idx - tail_idx - 1;
    // cout << "brockNum: " << brockNum << " tail_idx: " << tail_idx << " head_idx: " << head_idx << " L: " << L << " G: " << G << endl;
    for (int i = 0; i <= tail_idx; i++)
    {
        cout << s[i];
    }
    for (int i = 0; i < L; i++)
    {
        cout << '1';
    }
    for (int i = 0; i < G; i++)
    {
        cout << '0';
    }
    for (int i = head_idx + L; i < n; i++)
    {
        cout << s[i];
    }
    cout << '\n';
    return 0;
}
