#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    int med = s.size() / 2;
    string front = s.substr(0, med);
    string back = s.substr(med);
    bool isSame_front = std::all_of(front.begin(), front.end(), [first = front[0]](char c)
                                    { return c == first; });
    bool isSame_back = std::all_of(back.begin(), back.end(), [first = back[0]](char c)
                                   { return c == first; });
    if (!isSame_front || !isSame_back)
    {
        return false;
    }
    // cout << "front: " << front << " back: " << back << endl;
    if (front.empty() || back.empty())
    {
        return false;
    }
    std::string diff(front.size(), '1');
    if (std::stoi(back) - std::stoi(front) == std::stoi(diff))
    {
        return true;
    }
    return false;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    string s;
    cin >> s;
    long long size = s.size();
    long long ans = 0;
    for (long long i = 0; i < size - 1; i++)
    {
        long long idx_front = i;
        long long idx_back = i + 1;
        while (idx_front >= 0 && idx_back < size)
        {
            string substr = s.substr(idx_front, idx_back - idx_front + 1);
            if (check(substr))
            {
                ans++;
                // cout << "substr: " << substr << endl;
            }
            idx_front--;
            idx_back++;
        }
    }
    cout << ans << endl;
    return 0;
}

// |T|は偶数
// 折り返しの位置に着目して左右に広げていけばO(|S|log|S|)で間に合う？