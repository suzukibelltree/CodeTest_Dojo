#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    string s, t;
    cin >> s;
    cin >> t;
    int m = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
        {
            m++; // 答えの要素数
        }
    }
    cout << m << endl;
    for (int i = 0; i <= m; i++)
    {
        if (s[i] != t[i])
        {
            s[i] = t[i];
            cout << s << endl;
        }
        else
        {
            i++;
        }
    }
    return 0;
}
