#include <bits/stdc++.h>

using namespace std;
using namespace std::literals;

template<typename F>
struct yc {
	F f;
	template<typename... Ts>
	decltype(auto) operator()(Ts&&... args) const
	{
		return f(*this, forward<Ts>(args)...);
	}
};
template<typename F>
yc(F)->yc<F>;

constexpr auto MXN{ static_cast<int>(1e5) };

void solve()
{
	int n, m;
	cin >> n >> m;
	array<vector<int>, MXN> adj;
	for (auto i{ 0 }; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> ans(n, -1);
	auto dfs{ yc{[&](auto self, int u, int c = 0) -> void {
		ans[u] = c;
		for (auto v : adj[u])
			if (~ans[v]) {
				if (ans[v] == c) {
					cout << "IMPOSSIBLE\n";
					exit(EXIT_SUCCESS);
				}
			}
			else
				self(v, c ^ 1); }} };
	for (auto i{ 0 }; i < n; ++i)
		if (!~ans[i])
			dfs(i);
	for (auto i : ans)
		cout << i + 1 << ' ';
}

int main()
{
	ios::sync_with_stdio(false);

	auto t{ 1 };
	// cin >> t;
	while (t--) {
		solve();
	}
}
