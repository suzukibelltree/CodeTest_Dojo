#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int q;
    cin >> q;
    priority_queue<long long, vector<long long>, greater<long long>> queue;
    while (q--)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            int h;
            cin >> h;
            queue.push(h);
            cout << queue.size() << endl;
        }
        else if (num == 2)
        {
            int h2;
            cin >> h2;
            while (!queue.empty() && queue.top() <= h2)
            {
                queue.pop();
            }
            cout << queue.size() << endl;
        }
    }
    return 0;
}
