#include <bits/stdc++.h>
using namespace std;

bool check(const string &s)
{
    int size = s.size();
    // 長さは奇数でなければならない
    if (size % 2 == 0)
        return false;

    int mid = size / 2; // 中央（'/' の位置）

    for (int i = 0; i < size; i++)
    {
        if (i < mid && s[i] != '1')
            return false; // 前半はすべて '1'
        if (i == mid && s[i] != '/')
            return false; // 中央は '/'
        if (i > mid && s[i] != '2')
            return false; // 後半はすべて '2'
    }

    return true;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    string s;
    cin >> s;
    int max_length = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            string substr = s.substr(i, j);
            // cout << substr << endl;
            if (check(substr))
            {
                max_length = max(max_length, (int)substr.size());
            }
        }
    }
    cout << max_length << endl;
    return 0;
}
