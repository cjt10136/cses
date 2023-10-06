#include <bits/stdc++.h>

using namespace std;

long a, b;

long solve(long x)
{
  if (x < 10)
    return x + 1;
  auto s{to_string(x)};
  auto p{ranges::adjacent_find(s) - begin(s) + 2};
  long ans{s[0] + 1 - '0'};
  for (auto i{1}; i < size(s); ++i)
    ans = 9 * ans + 1 + (i < p) * (s[i] - '0' - 9 + (s[i - 1] > s[i]));
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> a >> b, --a;
  cout << solve(b) - solve(a);
}