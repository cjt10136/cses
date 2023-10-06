#include <bits/stdc++.h>

using namespace std;

using mat = vector<vector<long>>;

constexpr int mod(1e9 + 7);
constexpr auto mod2{long{mod} * mod};

int n, m, k;

mat cn(int n, int m)
{
  return mat(n, vector<long>(m));
}

mat mult(mat const& a, mat const& b)
{
  auto c{cn(size(a), size(b[0]))};
  for (auto i{0}; i < size(a); ++i)
    for (auto k{0}; k < size(b); ++k)
      for (auto j{0}; j < size(b[0]); ++j) {
        c[i][j] += a[i][k] * b[k][j];
        if (c[i][j] >= mod2)
          c[i][j] -= mod2;
      }
  for (auto&& i : c)
    for (auto&& j : i)
      j %= mod;
  return c;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  auto b{cn(n, n)};
  for (auto i{0}; i < m; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    ++b[u][v];
  }
  auto r{cn(n, n)};
  for (auto i{0}; i < n; ++i)
    r[i][i] = 1;
  while (k) {
    if (k % 2)
      r = mult(r, b);
    b = mult(b, b);
    k /= 2;
  }
  cout << r[0][n - 1];
}