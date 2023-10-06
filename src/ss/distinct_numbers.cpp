#include <bits/stdc++.h>

using namespace std;

int n;
set<int> s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    s.insert(x);
  }
  cout << size(s);
}
