#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int length = s.size();
    if (s.at(0) == s.at(1))
    {
        cout << s.at(length - 1) << endl;
    }
    else
    {
        cout << s.at(0) << endl;
    }
    return 0;
}
