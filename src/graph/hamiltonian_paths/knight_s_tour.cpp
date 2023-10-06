//#define KNIGHT_S_TOUR
#ifdef KNIGHT_S_TOUR

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

constexpr array<pair<int, int>, 8> d8{
	{{-1, -2}, { 1,  2}, {-2, -1}, { 2,  1},
	 {-2,  1}, { 2, -1}, {-1,  2}, { 1, -2}} };

void solve()
{
	int x, y;
	cin >> x >> y, --x, --y;
	array<array<int, 8>, 8> vis{};
	auto dfs{ yc{[&](auto self, int r, int c, int a) -> void {
		vis[r][c] = a;
		if (a == 64) {
			for (auto i{ 0 }; i < 8; ++i) {
				for (auto j{ 0 }; j < 8; ++j)
					cout << vis[i][j] << ' ';
				cout << '\n';
			}
			exit(EXIT_SUCCESS);
		}
		vector<pair<int, int>> p;
		auto e{ [&](int r, int c) {
				return 0 <= r && r < 8 && 0 <= c && c < 8 && !vis[r][c]; } };
		for (auto const& [dr, dc] : d8)
			if (e(r + dr, c + dc))
				p.push_back({ r + dr, c + dc });
		auto deg{ [&](auto p) {
			auto const& [r, c] { p };
			auto d{ 0 };
			for (auto const& [dr, dc] : d8)
				d += e(r + dr, c + dc);
			return d; } };
		sort(begin(p), end(p), [&](auto const& lhs, auto const& rhs) {
			return deg(lhs) < deg(rhs); });
		for (auto const& [r, c] : p)
			self(r, c, a + 1);
		vis[r][c] = 0; }} };
	dfs(y, x, 1);
}

int main()
{
	ios::sync_with_stdio(true);
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
