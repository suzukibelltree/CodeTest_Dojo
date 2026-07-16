#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    vector<long long> fibo(10);
    cin >> fibo[0] >> fibo[1];
    for (int i = 2; i < 10; i++)
    {
        long long sum = fibo[i - 1] + fibo[i - 2];
        string s = to_string(sum);
        reverse(s.begin(), s.end());
        fibo[i] = stoll(s);
    }
    cout << fibo[9] << endl;
    return 0;
}
