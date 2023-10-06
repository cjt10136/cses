#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  vector<string> ans{"0", "1"};
  ans.reserve(1 << n);
  for (auto i{2}; i < 1 << n; i <<= 1) {
    for (auto j{i - 1}; ~j; --j)
      ans.push_back(ans[j]);
    for (auto j{0}; j < i; ++j)
      ans[j] = '0' + ans[j];
    for (auto j{i}; j < i << 1; ++j)
      ans[j] = '1' + ans[j];
  }
  for (auto&& i : ans)
    cout << i << '\n';
}