//#define PLANETS_QUERIES_I
#ifdef PLANETS_QUERIES_I

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

constexpr auto MXN{ static_cast<int>(2e5) };
constexpr auto LGK{ 30 };

void solve()
{
	int n, q;
	cin >> n >> q;
	
	array<array<int, MXN>, LGK> t;
	for (auto i{ 0 }; i < n; ++i)
		cin >> t[0][i], --t[0][i];

	for (auto i{ 1 }; i < LGK; ++i)
		for (auto j{ 0 }; j < n; ++j)
			t[i][j] = t[i - 1][t[i - 1][j]];

	while (q--) {
		int x, k;
		cin >> x >> k, --x;
		for (auto i{ 0 }; i < LGK; ++i)
			if (k >> i & 1)
				x = t[i][x];
		cout << x + 1 << '\n';
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
2^30 > 1e9
*/

