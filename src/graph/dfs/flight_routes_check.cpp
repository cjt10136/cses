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

using namespace std;
using namespace std::literals;

constexpr auto MXN{ static_cast<int>(1e5) };

void solve()
{
	int n, m;
	cin >> n >> m;
	array<vector<int>, MXN> adj, radj;
	for (auto i{ 0 }; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}

	array<bool, MXN> vis;
	fill(begin(vis), begin(vis) + n, false);
	auto dfs{ [&, b = true] (auto& adj, auto& vis) mutable {
		auto d{ yc{[&](auto self, int u) -> void {
			vis[u] = b;
			for (auto v : adj[u])
				if (vis[v] ^ b)
					self(v); }} };
		d(0);
		b ^= 1;
		auto iter{ find(begin(vis), begin(vis) + n, b) };
		if (iter != begin(vis) + n) {
			array<int, 2> o{ 1, static_cast<int>(iter - begin(vis) + 1) };
			cout << "NO\n" << o[b] << ' ' << o[!b] << '\n';
			exit(EXIT_SUCCESS);
		}} };
	dfs(adj, vis);
	dfs(radj, vis);
	cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto t{ 1 };
	while (t--) {
		solve();
	}
}