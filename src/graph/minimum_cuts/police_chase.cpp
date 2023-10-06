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
 
constexpr auto MXN{ static_cast<int>(5e2) };
constexpr auto MXM{ static_cast<int>(1e3) };
 
void solve()
{
	struct Edge {
		int u;
		int v;
		int cap;
	};
 
	int n, m;
	cin >> n >> m;
	vector<Edge> e(2 * m);
	array<vector<int>, MXN> adj;
	for (auto i{ 0 }; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		e[2 * i] = { a, b, 1 };
		e[2 * i + 1] = { b, a, 1 };
		adj[a].push_back(2 * i);
		adj[b].push_back(2 * i + 1);
	}
 
	array<int, MXN> par;
	array<bool, MXN> vis;
	auto bfs{ [&] {
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
	while (bfs()) {
		auto u{ n - 1 };
		while (u) {
			e[par[u]].cap -= 1;
			e[par[u] ^ 1].cap += 1;
			u = e[par[u]].u;
		}
	}
	bfs();
	vector<pair<int, int>> ans;
	for (auto& [u, v, cap] : e)
		if (!cap && vis[u] && !vis[v])
			ans.push_back({ u, v });
 
	cout << ans.size() << '\n';
	for (auto& [u, v] : ans)
		cout << u + 1 << ' ' << v + 1 << '\n';
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