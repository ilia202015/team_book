#pragma GCC optimize("O3")
//#include <vector>
#pragma GCC target("avx2")
#include <bits/stdc++.h>

#include <cassert>

using namespace std;

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

#define pb emplace_back

#define all(v) v.begin(), v.end()

#define forlr(i, l, r) for (ll i = (l); i < (r); ++i)
#define forn(i, n) forlr(i, 0, n)
#define forin(i, v) for (auto& i : v)

const ll MOD = 998244353;
//const ll MOD = 1e9 + 7;
//const ll MOD = 1e9 + 9;

namespace rng = std::ranges;
namespace view = rng::views;

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
    return out;
}

template <class T>
ostream& operator<<(ostream& out, vector<T>&& c) {
    for (auto& x : c)
        out << x << ' ';
    return out;
}

ll number_test = 0;

bool __EQ(string a, string b){
    istringstream in1(a);
    istringstream in2(b);

    while (in1 && in2) {
        string s1, s2;
        in1 >> s1;
        in2 >> s2;
        if (s1 != s2)
            return false;
    }
    return !in1 && !in2;
}

template<typename T>
void __Test(string in_str, string out_str, T& f, string f_str) {
    istringstream in(in_str);
    ostringstream out;
    clock_t time_start = clock();
    f(in, out);
    
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";

    if (out_str == "" || __EQ(out.str(), out_str))
        cout << GREEN << "OK";
    else
        cout << RED << "WA";

	cout << ": test" << number_test++;
	if (f_str != "main0")
		cout << " (function: " << f_str << ")";
	cout << "\nin:\n" << in_str << "\nout:\n" << out.str();

    if (out_str != "" && !__EQ(out.str(), out_str))
        cout << "\nbest out:\n" << out_str;

	cout << "\ntime: " << clock() - time_start << "ms" << '\n' << RESET << endl;
}

#define testf(in_str, out_str, f) __Test(#in_str, #out_str, f, #f);
#define test(in_str, out_str) testf(in_str, out_str, main0);

void main0(istream& cin, ostream& cout) {
    ll n;
	cin >> n;
	vll a(n);
	cin >> a;

	cout << accumulate(all(a), 0) << '\n';
	cout << a;
}

void tests() {
    cout << "tests start\n\n" << endl;

	test(3
	1 2 3 , 6
1 2 3);
	
	test(2 5 4, 9 5 4);

	test(3 
		1 
		2 
		3, 
		4
		5
		6);

	test(1 3, 3);

    cout << "\ntests complete\n" << endl;
}

void stress_tests() {
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

#ifdef _LOCAL
	tests();
	while (cin)
        //stress_tests();
#else
#endif // _LOCAL
	{
		ll t = 1;
		//cin >> t;
		while (t--) {
			main0(cin, cout);
			cout << endl;
		}
	}
}
