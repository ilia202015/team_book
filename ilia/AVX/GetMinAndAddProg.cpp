#include <immintrin.h>
#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#pragma GCC target("avx2")
#endif

using ui = unsigned int;
using ui8 = ui __attribute__((vector_size(32)));
using i256 = __m256i;

unsigned GetMin(const ui*a, int n) {
    ui ans = a[0];
    i256 mn = _mm256_set1_epi32(a[0]);
    int i = 0;
    for(; i + 8 <= n; i += 8)
        mn = _mm256_min_epu32(mn, _mm256_loadu_si256((const i256*)(a + i)));
    for(; i < n; ++i)
        ans = min(ans, a[i]);
    ui8 x = (ui8)mn;
    for (int i = 0; i < 8; ++i)
        ans = min(ans, x[i]);
    return ans;
}

void AddProg(ui *b, int n, ui k) {
    alignas(32) ui* a = b;

    i256 add = _mm256_setr_epi32(k, 2 * k, 3 * k, 4 * k, 5 * k, 6 * k, 7 * k, 8 * k);
    i256 d = _mm256_set1_epi32(8 * k);
    int i = 0;
    for (; i + 8 <= n; i += 8) {
         _mm256_storeu_si256((i256*)(a + i), _mm256_add_epi32(_mm256_loadu_si256((i256*)(a + i)), add));
         add = _mm256_add_epi32(add, d);
    }
    ui c = ((ui8)add)[0] - k;
    for(; i < n; ++i)
        *(a + i) += c += k;
}
