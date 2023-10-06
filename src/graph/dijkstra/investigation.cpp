#include <bits/stdc++.h>

using namespace std;

constexpr int mod(1e9 + 7);
constexpr int mxn(1e5);

int n, m, mn[mxn], mx[mxn];
long p[mxn], r[mxn];
vector<array<int, 2>> adj[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c, --a, --b;
    adj[a].push_back({b, c});
  }
  fill(p + 1, p + n, 1e18);
  r[0] = 1;
  priority_queue<array<long, 2>,
                 vector<array<long, 2>>,
                 greater<array<long, 2>>>
      pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [pu, u]{pq.top()};
    pq.pop();
    if (pu > p[u])
      continue;
    for (auto&& [v, c] : adj[u])
      if (p[v] > pu + c) {
        p[v] = pu + c;
        r[v] = r[u];
        mn[v] = mn[u] + 1;
        mx[v] = mx[u] + 1;
        pq.push({p[v], v});
      }
      else if (p[v] == pu + c) {
        r[v] = (r[v] + r[u]) % mod;
        mn[v] = min(mn[v], mn[u] + 1);
        mx[v] = max(mx[v], mx[u] + 1);
      }
  }
  cout << p[n - 1] << ' ' << r[n - 1] << ' ' << mn[n - 1] << ' ' << mx[n - 1];
}