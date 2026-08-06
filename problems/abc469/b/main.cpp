#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    string s;
    cin >> n;
    cin >> s;
    bool isLeftEmpty = false;
    bool isRightEmpty = false;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        isLeftEmpty = (i != 0 && s[i - 1] == 'o');
        isRightEmpty = (i != n - 1 && s[i + 1] == 'o');
        if (s[i] == 'x' && !isLeftEmpty && !isRightEmpty)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
