#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, k, x[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (auto i{0}; i < n; ++i)
    cin >> x[i];
  multiset<int> s(x, x + k);
  auto m{next(begin(s), (k - 1) / 2)};
  cout << *m << ' ';
  for (auto i{k}; i < n; ++i) {
    s.insert(x[i]);
    if (x[i] < *m)
      --m;
    if (x[i - k] <= *m)
      ++m;
    s.erase(s.find(x[i - k]));
    cout << *m << ' ';
  }
}