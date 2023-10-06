#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(true);

  cin >> n;
  for (auto i{1l}; i <= n; ++i)
    cout << i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << '\n';
}