#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, m, p[mxn + 2], x[mxn + 1], ans{1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{1}; i <= n; ++i) {
    cin >> x[i];
    p[x[i]] = i;
  }
  p[n + 1] = n + 1;
  for (auto i{2}; i <= n; ++i)
    ans += p[i] < p[i - 1];
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (x[b] - x[a] == 1) {
      ans += b > a ? 1 : -1;
      ans += (b < p[x[a] - 1]) - (a < p[x[a] - 1]);
      ans += (p[x[b] + 1] < a) - (p[x[b] + 1] < b);
    }
    else if (x[a] - x[b] == 1) {
      ans += a > b ? 1 : -1;
      ans += (a < p[x[b] - 1]) - (b < p[x[b] - 1]);
      ans += (p[x[a] + 1] < b) - (p[x[a] + 1] < a);
    }
    else {
      ans += (a < p[x[b] - 1]) - (b < p[x[b] - 1]);
      ans += (b < p[x[a] - 1]) - (a < p[x[a] - 1]);
      ans += (p[x[a] + 1] < b) - (p[x[a] + 1] < a);
      ans += (p[x[b] + 1] < a) - (p[x[b] + 1] < b);
    }
    swap(x[a], x[b]);
    swap(p[x[a]], p[x[b]]);
    cout << ans << '\n';
  }
}
