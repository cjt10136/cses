#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  if (n * (n + 1) / 2 % 2) {
    cout << "NO";
    return EXIT_SUCCESS;
  }

  cout << "YES\n";
  if (n % 2) {
    cout << n / 2 + 1 << '\n' << 1 << ' ' << 2 << ' ';
    for (auto i{4}; i < n; i += 4)
      cout << i << ' ' << i + 3 << ' ';
    cout << '\n' << n / 2 << '\n' << 3 << ' ';
    for (auto i{5}; i < n; i += 4)
      cout << i << ' ' << i + 1 << ' ';
  }
  else {
    cout << n / 2 << '\n';
    for (auto i{1}; i < n; i += 4)
      cout << i << ' ' << i + 3 << ' ';
    cout << '\n' << n / 2 << '\n';
    for (auto i{2}; i < n; i += 4)
      cout << i << ' ' << i + 1 << ' ';
  }
}