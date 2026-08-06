#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    long long n, y;
    cin >> n >> y; // n枚のお札で合計y円はありえるか？
    int a, b, c;
    for (a = 0; a <= n; a++)
    {
        for (b = 0; b <= n - a; b++)
        {
            int sum = 0;
            c = n - a - b;
            sum = 1000 * a + 5000 * b + 10000 * c;
            if (sum == y)
            {
                cout << c << " " << b << " " << a << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}
