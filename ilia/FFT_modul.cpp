//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")

#ifdef _LOCAL
import std;
#include <assert.h>
#else
#include <bits/stdc++.h>
#endif // _LOCAL

using namespace std;

namespace rng = std::ranges;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pll = pair<ll, ll>;
using pi = pair<ll, ll>;

using vll = vector<ll>;
using vvll = vector<vll>;

using vi = vector<ll>;
using vvi = vector<vi>;

using vpll = vector<pll>;
using vvpll = vector<vpll>;

using vpi = vector<pi>;
using vvpi = vector<vpi>;

using vb = vector<bool>;
using vvb = vector<bool>;

using ft = complex<ld>;

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

    void fft(vll& p, ll w) {
        ll n = p.size();
        if (n == 1)
            return;
        vll a(n / 2);
        vll b(n / 2);
        for (ll i : iota((ll)0, n / 2)) {
            a[i] = p[2 * i];
            b[i] = p[2 * i + 1];
        }

        fft(a, w * w % MOD);
        fft(b, w * w % MOD);

        ll wt = 1;
        for (ll i : iota((ll)0, n / 2)) {
            p[i] = (a[i] + wt * b[i]) % MOD;
            p[i + n / 2] = (a[i] + MOD - wt * b[i] % MOD) % MOD;
            wt = wt * w % MOD;
        }
    }

    ll pow(ll a, ll n) {
        if (n == 1)
            return a;
        if (n % 2)
            return a * pow(a, n - 1) % MOD;
        return pow(a * a % MOD, n / 2);
    }

    void main() {
        ll n;
        cin >> n;
        ++n;

        ll m = 1ll << n;
        ll w = pow(31, pow(2, 23 - n));

        vll a(m / 2), b(m / 2);
        cin >> a >> b;
        a.resize(m);
        b.resize(m);

        fft(a, w);
        fft(b, w);

        vll c(m);
        for (ll i : iota(0, m))
            c[i] = a[i] * b[i] % MOD;

        fft(c, pow(w, MOD - 2));

        ll om = pow(m, MOD - 2);
        for (ll& x : c)
            x = x * om % MOD;

        for (ll x : c)
            cout << x << ' ';
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

        while (t--)
            Solve::main();
    }
}
