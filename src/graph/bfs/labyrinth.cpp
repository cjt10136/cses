#include <bits/stdc++.h>

using namespace std;

constexpr int di[4]{-1, 1, 0, 0}, dj[4]{0, 0, -1, 1};
constexpr char dc[4]{'U', 'D', 'L', 'R'};

constexpr int mxn(1e3);

int n, m, si, sj, ti, tj, p[mxn][mxn];
string s[mxn];

bool e(int i, int j)
{
  return 0 <= i && i < n && 0 <= j && j < m && s[i][j] == '.';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < n; ++i) {
    cin >> s[i];
    for (auto j{0}; j < m; ++j)
      if (s[i][j] == 'A') {
        si = i, sj = j;
        s[i][j] = '#';
      }
      else if (s[i][j] == 'B') {
        ti = i, tj = j;
        s[i][j] = '.';
      }
  }
  for (auto i{0}; i < n; ++i)
    for (auto j{0}; j < m; ++j)
      p[i][j] = -1;
  queue<array<int, 2>> qu;
  qu.push({si, sj});
  while (!qu.empty()) {
    auto [ui, uj]{qu.front()};
    qu.pop();
    for (auto k{0}; k < 4; ++k) {
      auto ni{ui + di[k]}, nj{uj + dj[k]};
      if (e(ni, nj)) {
        p[ni][nj] = k;
        s[ni][nj] = '#';
        qu.push({ni, nj});
      }
    }
  }
  if (~p[ti][tj]) {
    cout << "YES\n";
    string ans;
    while (ti != si || tj != sj) {
      auto&& k{p[ti][tj]};
      ans += dc[k];
      ti -= di[k], tj -= dj[k];
    }
    cout << size(ans) << '\n';
    for (auto i{size(ans) - 1}; ~i; --i)
      cout << ans[i];
  }
  else
    cout << "NO";
}