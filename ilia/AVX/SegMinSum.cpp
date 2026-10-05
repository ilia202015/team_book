#include <immintrin.h>
#include <bits/stdc++.h>

using namespace std;

//#pragma GCC target("avx2")

using u32 = unsigned;
using u32x8 = u32 __attribute__((vector_size(32)));
using i256 = __m256i;

unsigned SegMinSum(unsigned int*a, unsigned int*b, int n) {
    u32 ans = 0;
    int i = 0;
    i256 sum = _mm256_setzero_si256();
    for (; i + 8 <= n; i += 8){
        i256 x = _mm256_loadu_si256((const i256*)(a + i));
        i256 y = _mm256_loadu_si256((const i256*)(b + i));
        sum = _mm256_add_epi32(_mm256_min_epi32(x, y), sum);
    }
    for(; i < n; ++i)
        ans += min(a[i], b[i]);

    u32x8 x = (u32x8)sum;
    for(u32 i = 0; i < 8; ++i)
        ans += x[i];
    return ans;
}
