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

    struct Stack {
        ll x = 0, s = 0;
        Stack* p = 0;

        Stack* push(ll x) {
           return new Stack(x, s + 1, this);
        }

        Stack* pop() {
            return p;
        }

        ll top() {
            return x;
        }
    };

    struct Queue {
        Stack l, lt, r, rt, s;

        ll rc = 0, tc = 0, cp = 0;

        Queue* recopy() {
            ll td = 3;

            // r -> s
            Stack* rn = &r;
            Stack* sn = &s;
            ll cpn = cp;
            while (!cp && td && rn->p) {
                sn = sn->push(rn->top());
                rn = rn->pop();
                --td;
            }

            // l -> r
            Stack* ln = &l;
            while (td && ln->p) {
                cpn = 1;
                rn = rn->push(ln->top());
                ln = ln->pop();
                --td;
            }

            // s -> r
            ll tcn = tc;
            while (td && sn->p) {
                if (tcn) {
                    rn = rn->push(sn->top());
                    --tcn;
                }
                sn = sn->pop();
                --td;
            }

            Stack* ltn = &lt;
            if (!sn->p)
                swap(ln, ltn);

            return new Queue(*ln, *ltn, *rn, rt, *sn, (bool)sn->p, tcn, cpn);
        }

        Queue* normal() {
            if (l.s > r.s)
                return (new Queue(l, lt, r, r, s, 1, r.s, 0))->recopy();
            else
                return new Queue(l, lt, r, rt, s, 0, tc, cp);
        }

        Queue* push(ll x) {
            Queue* nq = new Queue(*this);
            if (!rc) {
                nq->l = *l.push(x);
                return nq->normal();
            }

            nq->lt = *lt.push(x);
            return nq->recopy();
        }

        pair<Queue*, ll> pop() {
            Queue* nq = new Queue(*this);
            if (!rc) {
                nq->r = *r.pop();
                return { nq->normal(), r.top() };
            }

            ll x = rt.top();
            nq->rt = *rt.pop();
            if (tc) {
                --nq->tc;
            } else {
                nq->r = *r.pop();
                x = r.top();
            }
            return { nq->recopy(), x };
        }
    };

    void main() {
        ll n;
        cin >> n;

        vector<Queue*> vs{ new Queue() };
        while (n--) {
            ll q;
            cin >> q;
            if (q == 1) {
                ll v, x;
                cin >> v >> x;
                vs.push_back(vs[v]->push(x));
            } else {
                ll v;
                cin >> v;
                auto [nq, x] = vs[v]->pop();
                vs.push_back(nq);
                cout << x << '\n';
            }
        }
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
