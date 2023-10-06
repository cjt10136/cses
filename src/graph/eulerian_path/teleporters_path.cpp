//#define TELEPORTERS_PATH
#ifdef TELEPORTERS_PATH

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
yc(F) -> yc<F>;

constexpr auto MXN{ static_cast<int>(1e5) };
constexpr auto MXM{ static_cast<int>(2e5) };

void solve()
{
	int n, m;
	cin >> n >> m;
	array<int, MXN> ind{}, out{};
	array<vector<int>, MXN> adj;
	array<int, MXM> eu, ev;
	for (auto i{ 0 }; i < m; ++i) {
		cin >> eu[i] >> ev[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(i);
		++ind[ev[i]];
		++out[eu[i]];
	}

	if (ind[0] + 1 != out[0] || ind[n - 1] != out[n - 1] + 1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (auto i{ 1 }; i < n - 1; ++i)
		if (ind[i] != out[i]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	vector<int> ans;
	ans.reserve(m);
	array<bool, MXM> used{};
	auto dfs{ yc{[&](auto self, int u) -> void {
		while (!adj[u].empty()) {
			auto e{ adj[u].back() };
			adj[u].pop_back();
			if (!used[e]) {
				used[e] = true;
				self(eu[e] ^ ev[e] ^ u);
				ans.push_back(u);
			}
		}}} };
	dfs(0);
	if (size(ans) != m) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	reverse(begin(ans), end(ans));
	for (auto const& i : ans)
		cout << i + 1 << ' ';
	cout << n << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto t{ 1 };
	//cin >> t;
	while (t--) {
		solve();
	}
}

#endif

/*

*/
