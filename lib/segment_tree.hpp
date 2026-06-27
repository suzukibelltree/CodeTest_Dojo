#pragma once
#include <vector>
#include <functional>
using namespace std;

// 汎用セグメント木 (点更新・区間取得)
// 使用例:
//   SegmentTree<long long> seg(n, 0LL, [](long long a, long long b){ return a + b; }); // 区間和
//   SegmentTree<long long> seg(n, LLONG_MAX, [](long long a, long long b){ return min(a, b); }); // 区間最小値
template <typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T identity;
    function<T(T, T)> op;

    SegmentTree(int n_, T identity_, function<T(T, T)> op_)
        : identity(identity_), op(op_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2 * n, identity);
    }

    void update(int i, T val) {
        i += n;
        data[i] = val;
        while (i > 1) {
            i /= 2;
            data[i] = op(data[2 * i], data[2 * i + 1]);
        }
    }

    // 半開区間 [l, r) に対する集約結果を返す
    T query(int l, int r) {
        T resL = identity, resR = identity;
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) resL = op(resL, data[l++]);
            if (r & 1) resR = op(data[--r], resR);
            l /= 2;
            r /= 2;
        }
        return op(resL, resR);
    }
};
