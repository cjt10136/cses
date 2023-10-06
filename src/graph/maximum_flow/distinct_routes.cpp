//#define DISTINCT_ROUTES
#ifdef DISTINCT_ROUTES

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

constexpr auto MXN{ static_cast<int>(5e2) };

void solve()
{
	struct Edge {
		int u;
		int v;
		bool cap;
	};
	
	int n, m;
	cin >> n >> m;
	array<vector<int>, MXN> adj;
	vector<Edge> e;
	e.reserve(m * 2);
	for (auto i{ 0 }; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		e.push_back({ a, b, true });
		e.push_back({ b, a, false });
		adj[a].push_back(2 * i);
		adj[b].push_back(2 * i + 1);
	}

	array<int, MXN> par;
	array<bool, MXN> vis;
	fill(begin(vis), begin(vis) + n, false);
	auto bfs{ [&] {
		array<bool, MXN> vis;
		fill(begin(vis), begin(vis) + n, false);
		vis[0] = true;
		queue<int> qu;
		qu.push(0);
		while (!qu.empty()) {
			auto u{ qu.front() };
			qu.pop();
			for (auto i : adj[u])
				if (e[i].cap && !vis[e[i].v]) {
					vis[e[i].v] = true;
					par[e[i].v] = i;
					qu.push(e[i].v);
				}
		}
		return vis[n - 1]; } };
	auto ans1{ 0 };
	while (bfs()) {
		++ans1;
		auto u{ n - 1 };
		while (u) {
			e[par[u]].cap ^= 1;
			e[par[u] ^ 1].cap ^= 1;
			u = e[par[u]].u;
		}
	}

	cout << ans1 << '\n';
	vector<int> ans2;
	auto dfs{ yc{[&](auto self, int u = 0) -> void {
		ans2.push_back(u);
		if (u == n - 1)
			return;
		for (auto i : adj[u])
			if (~i & 1 && !e[i].cap) {
				e[i].cap = true;
				self(e[i].v);
				return;
			}}} };
	while (ans1--) {
		dfs();
		cout << ans2.size() << '\n';
		for (auto i : ans2)
			cout << i + 1 << ' ';
		cout << '\n';
		ans2.clear();
	}
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
