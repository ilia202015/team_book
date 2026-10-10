#include <bits/stdc++.h>

#include <cassert>

#define ll long long
#define ull unsigned ll
#define ld long double

using namespace std;

namespace rng = std::ranges;
namespace view = rng::views;

namespace qwe0 {
    template<typename T>
    istream& operator>>(istream& in, vector<T>& v) {
        for (T& i : v)
            in >> i;
        return in;
    }

    void f(istream& in, ostream& out) {

    }

    ll number_test = 0;

    template<typename T>
    void __Test(string in_str, string out_str, T& f, string f_str) {
        istringstream in(in_str);
        ostringstream out;
        clock_t time_start = clock();
        f(in, out);
        cout << "test" << number_test++ << "(function: " + f_str + ", in: " + in_str + ", out: " + out.str() + ") complete; time: " << clock() - time_start << "ms\n" << endl;
        if (out_str != "")
            assert(out.str() == out_str);
    }

    std::mutex mut;
    const string c = "D:\\Olympiads\\VSOSH\\mun\\22\\archive-9-11\\5\\";
    const string ct = c + "tests\\";
    ll tests_complete = 0;

    void __TestF(ll i) {
        string si = i < 10 ? '0' + to_string(i) : to_string(i);
        ifstream in(ct + si);
        ofstream out(ct + si + ".out");
        f(in, out);
        in.close();
        out.close();
        {
            lock_guard<std::mutex> lock(mut);
            cout << "Test" << si << "   ";
            system((c + "check.exe " + ct + si + " " + ct + si + ".out " + ct + si + ".a").c_str());
            cout << "tests complete: " << ++tests_complete << endl;
        }
    }

#define test(in_str, out_str, f) __Test(#in_str, out_str, f, #f);

    void tests() {
        cout << "tests start\n\n" << endl;

        //test(, "\n", f);

        //#define _TESTS_F

#ifdef _TESTS_F
        vector<thread> thr_s;
        for (ll i : view::iota((ull)1, (ull)23 + 1))
            thr_s.push_back(thread(__TestF, i));

        for (auto& i : thr_s)
            i.join();
#endif

        cout << "\ntests complete\n" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    using namespace qwe0;
#ifdef _LOCAL
    tests();

    //#define _ST

#ifdef _ST
    namespace view = std::ranges::views;

    for (ll i : view::iota((ll)1e8, (ll)1e9)) {
        cout << i << "\n";

        istringstream in1(to_string(i)), in2(to_string(i));
        ostringstream out1, out2;
        f(in1, out1);
    }

    cout << "end\n";
#endif

    while (true)
#endif
        f(cin, cout);

    return 0;
}