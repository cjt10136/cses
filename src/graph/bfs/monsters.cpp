#include <bits/stdc++.h>
#include <vector>

using namespace std;

constexpr int di[4]{-1, 1, 0, 0}, dj[4]{0, 0, -1, 1};
constexpr char dc[4]{'U', 'D', 'L', 'R'};

constexpr int mxn(1e3);

int n, m, si, sj, ti{-1}, tj{-1}, d1[mxn][mxn], d2[mxn][mxn], p[mxn][mxn];
bool vis[mxn][mxn];
string s[mxn];
vector<array<int, 2>> a1, a2;

bool e(int i, int j)
{
  return 0 <= i && i < n && 0 <= j && j <= m && s[i][j] == '.' && !vis[i][j];
}

void bfs(vector<array<int, 2>>& a, int d[mxn][mxn], int p[mxn][mxn])
{
  for (auto i{0}; i < n; ++i)
    for (auto j{0}; j < m; ++j) {
      d[i][j] = 1e9;
      vis[i][j] = false;
    }
  queue<array<int, 2>> qu;
  for (auto&& [i, j] : a) {
    d[i][j] = 0;
    vis[i][j] = true;
    qu.push({i, j});
  }
  while (!qu.empty()) {
    auto [ui, uj]{qu.front()};
    qu.pop();
    for (auto k{0}; k < 4; ++k) {
      auto ni{ui + di[k]}, nj{uj + dj[k]};
      if (e(ni, nj)) {
        d[ni][nj] = d[ui][uj] + 1;
        p[ni][nj] = k;
        vis[ni][nj] = true;
        qu.push({ni, nj});
      }
    }
  }
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
        a1.push_back({i, j});
      }
      else if (s[i][j] == 'M') {
        s[i][j] = '.';
        a2.push_back({i, j});
      }
  }
  bfs(a2, d2, p);
  bfs(a1, d1, p);
  for (auto i{0}; i < n; ++i)
    if (d1[i][0] < d2[i][0])
      ti = i, tj = 0;
    else if (d1[i][m - 1] < d2[i][m - 1])
      ti = i, tj = m - 1;
  for (auto j{0}; j < m; ++j)
    if (d1[0][j] < d2[0][j])
      ti = 0, tj = j;
    else if (d1[n - 1][j] < d2[n - 1][j])
      ti = n - 1, tj = j;
  if (~ti) {
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