#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e5);

int n, m, k;
vector<long> p[mxn];
vector<array<long, 2>> adj[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for (auto i{0}; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c, --a, --b;
    adj[a].push_back({b, c});
  }
  priority_queue<array<long, 2>,
                 vector<array<long, 2>>,
                 greater<array<long, 2>>>
      pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [pu, u]{pq.top()};
    pq.pop();
    if (size(p[u]) >= k)
      continue;
    p[u].push_back(pu);
    for (auto&& [j, c] : adj[u])
      pq.push({pu + c, j});
  }
	for (auto&& i : p[n - 1])
    cout << i << ' ';
}