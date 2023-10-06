#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e5);

int n, m;
long ans(1e18), p1[mxn], p2[mxn];
vector<array<long, 2>> adj1[mxn], adj2[mxn];

void ds(int u, vector<array<long, 2>> adj[mxn], long p[mxn])
{
  fill(p, p + n, 1e18);
  p[u] = 0;
  priority_queue<array<long, 2>,
                 vector<array<long, 2>>,
                 greater<array<long, 2>>>
      pq;
  pq.push({0, u});
  while (!pq.empty()) {
    auto [pu, u]{pq.top()};
    pq.pop();
    if (pu > p[u])
      continue;
    for (auto&& [v, c] : adj[u])
      if (p[v] > pu + c) {
        p[v] = pu + c;
        pq.push({p[v], v});
      }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c, --a, --b;
    adj1[a].push_back({b, c});
    adj2[b].push_back({a, c});
  }
  ds(0, adj1, p1);
  ds(n - 1, adj2, p2);
  for (auto i{0}; i < n; ++i)
    for (auto&& [j, c] : adj1[i])
      ans = min(ans, p1[i] + p2[j] + c / 2);
  cout << ans;
}