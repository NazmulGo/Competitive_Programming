#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define dbg(...)
#define debug(...)
#define debugArr(...)
#endif

typedef long long ll;
#define all(v) v.begin(), v.end()

const int N = 1e6 + 12;
vector<int> spf(N + 1, 0);
vector<int> primes;

bool isPrime(int x) {
    if (x < 2) return false;
    return spf[x] == x;
}

void linear_sieve() {
    for (int i = 2; i <= N; ++i) {
        if (spf[i] == 0) spf[i] = i, primes.push_back(i);
        for (int j = 0; i * primes[j] <= N; ++j) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i]) break;
        }
    }
}

vector<ll> primeFactors(ll n) {
    vector<ll> fact;
    for (int i = 0; i < primes.size(); i++) {
        if (1LL * primes[i] * primes[i] > n) break;
        if (n % primes[i] == 0) {
            while (n % primes[i] == 0) {
                n /= primes[i];
                fact.push_back(primes[i]);
            }
        }
    }
    if (n > 1) fact.push_back(n);
    return fact;
}

// ---------------- Added Part ----------------

void gen(int idx, ll cur, vector<pair<ll, int>> &fac, vector<ll> &divs) {
    if (idx == fac.size()) {
        divs.push_back(cur);
        return;
    }

    auto [p, e] = fac[idx];

    ll pw = 1;
    for (int i = 0; i <= e; i++) {
        gen(idx + 1, cur * pw, fac, divs);
        pw *= p;
    }
}

vector<ll> conv(vector<ll> x) {
    vector<pair<ll, int>> fac;
    for (ll p : x) {
        if (fac.empty() || fac.back().first != p) fac.push_back({p, 1});
        else fac.back().second++;
    }

    vector<ll> divisors;
    gen(0, 1, fac, divisors);
    sort(all(divisors));
    return divisors;
}


// --------------------------------------------

void solve() {
    ll n;
    cin >> n;

    vector<ll> x = primeFactors(n);
    vector<ll> divs = conv(x);

    for(auto a : divs) cout << a << " "; cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    linear_sieve();

    ll tc = 1;
    cin >> tc;
    while (tc--) solve();
}
