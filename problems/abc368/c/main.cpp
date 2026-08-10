#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<long long> H(n);
    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
    }
    long long T = 0;
    int idx = 0;
    while (H[n - 1] > 0)
    {
        if (H[idx] >= 5)
        {
            long long div = H[idx] / 5;
            T += div * 3;
            H[idx] %= 5;
        }
        else
        {
            T++;
            if (T % 3 == 0)
            {
                H[idx] -= 3;
            }
            else
            {
                H[idx] -= 1;
            }
        }
        if (H[idx] <= 0)
        {
            idx++;
        }
        // cout << "T: " << T << " H[idx]: " << H[idx] << endl;
    }
    cout << T << endl;
    return 0;
}
