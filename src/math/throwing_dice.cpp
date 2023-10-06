#include <bits/stdc++.h>

using namespace std;

using mat = vector<vector<long>>;

constexpr int mod(1e9 + 7);
constexpr auto mod2{long{mod} * mod};

long n;

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

  cin >> n;
  mat r{{0, 0, 0, 0, 0, 1}};
  mat b{
      {0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 1},
      {0, 0, 1, 0, 0, 1},
      {0, 0, 0, 1, 0, 1},
      {0, 0, 0, 0, 1, 1},
  };
  while (n) {
    if (n % 2)
      r = mult(r, b);
    b = mult(b, b);
    n /= 2;
  }
  cout << r[0][5];
}