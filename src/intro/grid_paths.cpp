#include <bits/stdc++.h>

using namespace std;

string s;
bool vis[7][7];
auto ans{0};

void dfs(int i = 0, int j = 0, int a = 0)
{
  if (i == 6 && j == 0) {
    ans += a == 48;
    return;
  }
  auto q{s[a] == '?'}, u{i > 0 && !vis[i - 1][j]}, d{i < 6 && !vis[i + 1][j]},
      l{j > 0 && !vis[i][j - 1]}, r{j < 6 && !vis[i][j + 1]};
  if ((u && d && !l && !r) || (!u && !d && l && r))
    return;
  vis[i][j] = true;
  if (u && (q || s[a] == 'U'))
    dfs(i - 1, j, a + 1);
  if (d && (q || s[a] == 'D'))
    dfs(i + 1, j, a + 1);
  if (l && (q || s[a] == 'L'))
    dfs(i, j - 1, a + 1);
  if (r && (q || s[a] == 'R'))
    dfs(i, j + 1, a + 1);
  vis[i][j] = false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  dfs();
  cout << ans;
}