#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    long long q;
    cin >> q;
    queue<long long> queue;
    while (q--)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            long long c, x;
            cin >> c >> x;
            for (int i = 0; i < c; i++)
            {
                queue.push(x);
            }
        }
        else if (num == 2)
        {
            long long k;
            long long ans = 0;
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                ans += queue.front();
                queue.pop();
            }
            cout << ans << endl;
        }
    }
    return 0;
}
