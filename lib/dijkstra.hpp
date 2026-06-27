#pragma once
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// 始点 start から各頂点への最短距離を返す。
// graph[u] = (v, w) のリスト (uからvへ重みwの辺)
vector<long long> dijkstra(int n, int start, const vector<vector<pair<int, long long>>>& graph) {
    const long long INF = numeric_limits<long long>::max() / 2;
    vector<long long> dist(n, INF);
    dist[start] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
