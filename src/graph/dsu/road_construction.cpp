#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e5);

int n, m, ans1, ans2{1}, p[mxn], sz[mxn];

int find(int u)
{
  return u != p[u] ? p[u] = find(p[u]) : u;
}

bool join(int u, int v)
{
  if ((u = find(u)) == (v = find(v)))
    return false;
  p[u] = v;
  sz[v] += sz[u];
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  ans1 = n;
  iota(p, p + n, 0);
  fill(sz, sz + n, 1);
  for (auto i{0}; i < m; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    if (join(a, b)) {
      --ans1;
      ans2 = max(ans2, sz[p[b]]);
    }
    cout << ans1 << ' ' << ans2 << '\n';
  }
}