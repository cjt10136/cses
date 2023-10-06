//#define DOWNLOAD_SPEED
#ifdef DOWNLOAD_SPEED
 
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
 
struct Edge {
	int u;
	int v;
	int cap;
};
 
constexpr auto MXN{ static_cast<int>(5e2) };
constexpr auto MXM{ static_cast<int>(1e3) };
 
void solve()
{
	int n, m;
	cin >> n >> m;
 
	array<Edge, MXM * 2> e;
	array<vector<int>, MXN> adj;
	for (auto i{ 0 }; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		e[2 * i] = { a, b, c };
		e[2 * i + 1] = { b, a, 0 };
		adj[a].push_back(2 * i);
		adj[b].push_back(2 * i + 1);
	}
 
	auto ans{ 0ll };
	array<int, MXN> par;
	auto bfs{ [&] {
		array<bool, MXN> vis;
		fill(begin(vis), begin(vis) + n, false);
		queue<int> qu;
		qu.push(0);
		while (!qu.empty()) {
			auto u{ qu.front() };
			qu.pop();
			for (auto i : adj[u]) {
				if (e[i].cap && !vis[e[i].v]) {
					vis[e[i].v] = true;
					par[e[i].v] = i;
					qu.push(e[i].v);
				}
			}
		}
		return vis[n - 1]; } };
	while (bfs()) {
		auto f{ numeric_limits<int>::max() };
		auto u{ n - 1 };
		while (u) {
			f = min(f, e[par[u]].cap);
			u = e[par[u]].u;
		}
		ans += f;
		u = n - 1;
		while (u) {
			e[par[u]].cap -= f;
			e[par[u] ^ 1].cap += f;
			u = e[par[u]].u;
		}
	}
	cout << ans << '\n';
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
 