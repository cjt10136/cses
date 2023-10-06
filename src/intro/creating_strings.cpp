#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
  ios::sync_with_stdio(false);

  cin >> s;
  vector<string> ans;
  sort(begin(s), end(s));
  do
    ans.push_back(s);
  while (next_permutation(begin(s), end(s)));
  cout << size(ans) << '\n';
  for (auto&& i : ans)
    cout << i << '\n';
}