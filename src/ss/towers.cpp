#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    auto p{upper_bound(begin(ans), end(ans), k)};
    if (p != end(ans))
      *p = k;
    else
      ans.push_back(k);
  }
  cout << size(ans);
}