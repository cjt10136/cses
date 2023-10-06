#include <bits/stdc++.h>

using namespace std;

constexpr int mxx(1e6);

int n, ans[mxx + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (auto i{1}; i <= mxx; ++i)
    for (auto j{i}; j <= mxx; j += i)
      ++ans[j];
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    cout << ans[x] << '\n';
  }
}