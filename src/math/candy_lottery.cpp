#include <bits/stdc++.h>

using namespace std;

constexpr auto mxk{100};

int n, k;
double ans1[mxk + 1], ans2;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (auto i{1}; i <= k; ++i) {
    ans1[i] = 1;
    for (auto j{0}; j < n; ++j)
      ans1[i] *= double(i) / k;
  }
  for (auto i{1}; i <= k; ++i)
    ans2 += i * (ans1[i] - ans1[i - 1]);
  cout << fixed << setprecision(6) << ans2;
}