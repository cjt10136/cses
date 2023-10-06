//#define HAMILTONIAN_FLIGHTS
#ifdef HAMILTONIAN_FLIGHTS

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

constexpr auto MXN{ 20 };
constexpr auto MOD{ static_cast<int>(1e9) + 7 };

void solve()
{
	int n, m;
	cin >> n >> m;
	array<array<int, MXN>, MXN> adj{};
	for (auto i{ 0 }; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		++adj[a][b];
	}

	array<array<long long, MXN>, 1 << MXN> dp{};
	dp[1][0] = 1;
	for (auto i{ 3 }; i < 1 << n; i += 2) {
		if (i + 1 != 1 << n && i >> n - 1 & 1)
			continue;
		for (auto j{ 0 }; j < n; ++j)
			if (i & 1 << j) {
				auto i2{ i ^ 1 << j };
				for (auto k{ 0 }; k < n; ++k)
					if (i2 & 1 << k && adj[k][j])
						dp[i][j] += dp[i2][k] * adj[k][j];
				dp[i][j] %= MOD;
			}
	}
	cout << dp[(1 << n) - 1][n - 1] << '\n';
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
