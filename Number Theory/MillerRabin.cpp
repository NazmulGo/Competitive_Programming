using int64 = long long;
using u64 = uint64_t;
using u128 = __uint128_t;
u64 mod_mul(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}

u64 mod_pow(u64 a, u64 d, u64 mod) {
    u64 res = 1;
    while (d) {
        if (d & 1) res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        d >>= 1;
    }
    return res;
}

bool isPrime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n % p == 0) return n == p;
    }

    u64 d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (u64 a : {2,325,9375,28178,450775,9780504,1795265022}) {
        if (a % n == 0) continue;

        u64 x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool ok = false;
        for (u64 r = 1; r < s; r++) {
            x = mod_mul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}
