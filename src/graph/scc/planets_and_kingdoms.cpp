//#define PLANETS_AND_KINGDOMS
#ifdef PLANETS_AND_KINGDOMS

#include <bits/stdc++.h>

using namespace std;
using namespace std::literals;;

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

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>{}), radj(n, vector<int>{});
	for (auto i{ 0 }; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}

	array<bool, MXN> vis{};
	vector<int> st;
	auto dfs1{ yc{[&](auto self, int u) -> void {
		vis[u] = true;
		for (auto const& v : adj[u])
			if (!vis[v])
				self(v);
		st.push_back(u); }} };
	vector<int> who(n, -1);
	auto dfs2{ yc{[&](auto self, int u, int rt) -> void {
		vis[u] = false;
		who[u] = rt;
		for (auto const& v : radj[u])
			if (vis[v])
				self(v, rt); }} };
	for (auto i{ 0 }; i < n; ++i)
		if (!vis[i])
			dfs1(i);
	auto ans{ 0 };
	for (auto i{ n - 1 }; ~i; --i)
		if (vis[st[i]])
			dfs2(st[i], ++ans);
	cout << ans << '\n';
	for (auto const& i : who)
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

#endif

/*

*/
