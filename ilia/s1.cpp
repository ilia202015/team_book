#pragma GCC optimize("O3")
#include <vector>

#pragma GCC target("avx2")
#include <iostream>
#include <fstream>
#include <math.h>
#include <functional>
#include <numeric>
#include <string>
#include <assert.h>
#include <set>
#include <map>
#include <random>
#include <stack>
#include <queue>
#include <array>
#include <deque>
#include <algorithm>


using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define ld long double

#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define vvpll vector<vpll>

#define pb emplace_back

#define all(v) v.begin(), v.end()

#define forlr(i, l, r) for (ll i = (l); i < (r); ++i)
#define forn(i, n) forlr(i, 0, n)
#define forin(i, v) for (auto& i : v)

#define cinv(v) for (auto& i : v) cin >> i;

const ll MOD = 998244353;
//const ll MOD = 1e9 + 7;
//const ll MOD = 1e9 + 9;

void main0() {

}

void tests() {
	mt19937 mt;

	ll t;
	cin >> t;

	if (t < 0) {

		return;
	}

	ll mx;
	cin >> mx;

	while (t--) {

	}

	cout << "\nend\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	while (cin)
		//tests();
#else
#endif // _DEBUG
	{
		ll t = 1;
		cin >> t;
		while (t--) {
			main0();
			cout << endl;
		}
	}
}
