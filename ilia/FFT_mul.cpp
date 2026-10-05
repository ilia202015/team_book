//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")

#ifdef _LOCAL
import std;
#include <assert.h>
#else
#include <bits/stdc++.h>
#include <assert.h>
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

    //const ll MOD = 998244353;
    const ll MOD = 1e9 + 7;

    mt19937 mt;

    void fft(vector<ft>& p, ft w) {
        ll n = p.size();
        if (n == 1)
            return;
        vector<ft> a(n / 2);
        vector<ft> b(n / 2);
        for (ll i : iota((ll)0, n / 2)) {
            a[i] = p[2 * i];
            b[i] = p[2 * i + 1];
        }

        fft(a, w * w);
        fft(b, w * w);

        ft wt = 1;
        for (ll i : iota((ll)0, n / 2)) {
            p[i] = a[i] + wt * b[i];
            p[i + n / 2] = a[i] - wt * b[i];
            wt *= w;
        }
    }

    void main() {
        const int n = 262144 * 4; // 2 ** 18

        bool fm = 0;

        vector<ft> a(n), b(n);
        {
            string sa;
            cin >> sa;
            if (sa[0] == '-') {
                fm ^= 1;
                sa.erase(sa.begin());
            }
            reverse(sa);
            for (ll i : iota(0, (int)sa.size()))
                a[i] = sa[i] - '0';
        }
        {
            string sb;
            cin >> sb;
            if (sb[0] == '-') {
                fm ^= 1;
                sb.erase(sb.begin());
            }
            reverse(sb);
            for (ll i : iota(0, (int)sb.size()))
                b[i] = sb[i] - '0';
        }

        ld w = (ld)2. * acos(-1) / n;

        fft(a, polar((ld)1., w));
        fft(b, polar((ld)1., w));
        vector<ft> p(n);
        for (ll i : iota(0, n))
            p[i] = a[i] * b[i];

        fft(p, polar((ld)1., -w));
        vector<long long> ans(3 * n);
        for (ll i : iota(0, n))
            ans[i] = round(real(p[i]) / n);

        long long add = 0;
        for (ll i : iota(0, 3 * n - 1)) {
            assert(0 <= add && add <= 1e9);
            ans[i] += add % 10;
            add /= 10;
            add += ans[i] / 10;
            ans[i] %= 10;
        }
        assert(0 <= add && add <= 1e9);
        ans.back() += add;

        while (ans.size() && !ans.back())
            ans.pop_back();
        if (ans.empty()) {
            cout << 0;
            return;
        }
        if (fm)
            cout << '-';
        reverse(ans);
        for (ll x : ans)
            cout << x;
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
