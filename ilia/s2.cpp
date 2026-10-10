#ifdef _LOCAL
import std;
#include <assert.h>
#else
#pragma GCC optimize("O3")
#include <vector>
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#endif // _LOCAL

using namespace std;

namespace rng = std::ranges;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pll = pair<ll, ll>;
using pi = pair<int, int>;

using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vvvvll = vector<vvvll>;
using vvvvvll = vector<vvvvll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;
using vvvvvi = vector<vvvvi>;

using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vvvpll = vector<vvpll>;
using vvvvpll = vector<vvvpll>;
using vvvvvpll = vector<vvvvpll>;

using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vvvpi = vector<vvpi>;
using vvvvpi = vector<vvvpi>;
using vvvvvpi = vector<vvvvpi>;

using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vvvvb = vector<vvvb>;
using vvvvvb = vector<vvvvb>;

using ft = complex<ld>;

template <class T, class C>
istream& operator>>(istream& in, pair<T, C>& a) {
    in >> a.first >> a.second;
    return in;
}

template <class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v)
        in >> x;
    return in;
}

template <class T>
ostream& operator<<(ostream& out, vector<T>& c) {
    for (auto& x : c)
        out << x << ' ';
    out << '\n';
    return out;
}

template <class T>
ostream& operator<<(ostream& out, vector<T>&& c) {
    for (auto& x : c)
        out << x << ' ';
    out << '\n';
    return out;
}

template <rng::range C>
ll sum(C& c) {
    return accumulate(c.begin(), c.end(), 0ll);
}

#ifdef _LOCAL
ll __lg(unsigned long long n) {
    return 63 - countl_zero(n);
}
#endif // _LOCAL

namespace Solve {
    using rng::sort;
    using rng::find;
    using rng::unique;
    using rng::reverse;
    using rng::count;
    using rng::upper_bound;
    using rng::lower_bound;
    using rng::max_element;
    using rng::min_element;
    using rng::views::iota;

    const ll MOD = 998244353;
    //const ll MOD = 1e9 + 7;

    mt19937 mt;

    void main() {

    }

    void tests() {
        mt19937 mt;
        ll t;
        cin >> t;

        if (t == -1) {
            main();
            return;
        }

        ll n, k, m, mx;
        cin >> n >> k >> m >> mx;

        while (t--) {
        }
        cout << "end\n\n";
    }
} // namespace Solve

using namespace Solve;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef _LOCAL
    while (1)
        //tests();
#endif // _LOCAL
    {
        ll t = 1;
        //cin >> t;

        while (t--) {
            Solve::main();
            cout << endl;
        }
    }
}
