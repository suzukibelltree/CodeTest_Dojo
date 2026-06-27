#pragma once
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par, rnk, sz;

    UnionFind(int n) : par(n), rnk(n, 0), sz(n, 1) {
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
        sz[x] += sz[y];
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return sz[find(x)]; }
};
