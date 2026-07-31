#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int q;
    cin >> q;
    int volume = 0;
    bool isplaying = false;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            volume++;
        }
        else if (a == 2 && volume > 0)
        {
            volume--;
        }
        else if (a == 3)
        {
            isplaying = !isplaying;
        }

        if (volume >= 3 && isplaying)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
