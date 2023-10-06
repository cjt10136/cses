#include <bits/stdc++.h>

using namespace std;

constexpr int mxx(1e6);

int n, c[mxx + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
  for (auto i{0}; i < n; ++i) {
    int x;
    cin >> x;
    ++c[x];
  }
	for (auto i{mxx}; i; --i) {
    auto r{0};
    for (auto j{i}; j <= mxx; j += i)
      r += c[j];
    if (r > 1) {
      cout << i;
      return EXIT_SUCCESS;
    }
  }
}
