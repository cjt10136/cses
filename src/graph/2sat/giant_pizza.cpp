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

constexpr auto MXM{ static_cast<int>(1e5) };

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(2 * m, vector<int>{}), radj(2 * m, vector<int>{});
	for (auto i{ 0 }; i < n; ++i) {
		char c1, c2;
		int u1, u2;
		cin >> c1 >> u1 >> c2 >> u2, --u1, --u2;
		u1 *= 2;
		u2 *= 2;
		if (c1 == '-')
			u1 ^= 1;
		if (c2 == '-')
			u2 ^= 1;
		adj[u1 ^ 1].push_back(u2);
		radj[u2].push_back(u1 ^ 1);
		adj[u2 ^ 1].push_back(u1);
		radj[u1].push_back(u2 ^ 1);
	}

	array<bool, 2 * MXM> vis{};
	vector<int> st;
	auto dfs1{ yc{[&](auto self, int u) -> void {
		vis[u] = true;
		for (auto const& v : adj[u])
			if (!vis[v])
				self(v);
		st.push_back(u); }} };
	for (auto i{ 0 }; i < 2 * m; ++i)
		if (!vis[i])
			dfs1(i);
	vector<int> who(2 * m, -1);
	auto dfs2{ yc{[&](auto self, int u, int rt) -> void {
		vis[u] = false;
		who[u] = rt;
		for (auto const& v : radj[u])
			if (vis[v])
				self(v, rt); }} };
	for (auto i{ 2 * m - 1 }; ~i; --i)
		if (vis[st[i]])
			dfs2(st[i], i);
	vector<char> ans;
	ans.reserve(m);
	for (auto i{ 0 }; i < m; ++i) {
		if (who[2 * i] == who[2 * i + 1]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
		ans.push_back(who[2 * i] < who[2 * i + 1] ? '+' : '-');
	}

	for (auto const& i : ans)
		cout << i << ' ';
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

/*

*/
