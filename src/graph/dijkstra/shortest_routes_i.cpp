#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int mxn(1e5);
 
int n, m;
long l[mxn];
vector<array<long, 2>> adj[mxn];
 
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
  fill(l + 1, l + n, 1e18);
  priority_queue<array<long, 2>,
                 vector<array<long, 2>>,
                 greater<array<long, 2>>>
      pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [lu, u]{pq.top()};
    pq.pop();
    if (lu > l[u])
      continue;
    for (auto&& [v, c] : adj[u])
      if (l[v] > lu + c) {
        l[v] = lu + c;
        pq.push({l[v], v});
      }
  }
  for (auto i{0}; i < n; ++i)
    cout << l[i] << ' ';
}