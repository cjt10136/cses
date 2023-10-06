#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, q, x[mxn + 2];
long ps[mxn + 1], ans[mxn];
vector<array<int, 2>> ha[mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{1}; i <= n; ++i) {
    cin >> x[i];
    ps[i] = ps[i - 1] + x[i];
  }
  x[n + 1] = 1e9;
  for (auto i{0}; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    ha[a].push_back({b, i});
  }
  vector<array<long, 2>> st{{n + 1, 0}};
  for (auto i{n}; i; --i) {
    while (x[i] > x[st.back()[0]])
      st.pop_back();
    st.push_back({i, (st.back()[0] - i) * x[i] + st.back()[1]});
    for (auto&& [b, j] : ha[i]) {
      auto it{upper_bound(rbegin(st),
                          rend(st),
                          array<long, 2>{b, numeric_limits<long>::max()})};
      ans[j] = st.back()[1] - ((*it)[0] - b - 1) * x[(*(it - 1))[0]] - (*it)[1]
               - (ps[b] - ps[i - 1]);
    }
  }
  for (auto i{0}; i < q; ++i)
    cout << ans[i] << '\n';
}