#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(), v.end()

ll n, m;
vector<ll> v;

const int N = 1e6 + 12;
vector<int> spf(N + 1, 0);
vector<int> primes;

bool isPrime(int x) {
    return x >= 2 && spf[x] == x;
}

void linear_sieve() {
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) spf[i] = i, primes.push_back(i);
        for (int j = 0; j < (int)primes.size() && 1LL * i * primes[j] <= N; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i]) break;
        }
    }
}


ll MOD(ll l, ll mod) {
    if(l < mod) return l;
    return (l % mod) + mod;
}

ll bigmod(ll a, ll b, ll mod) {
   ll ans = MOD(1, mod);
   while(b) {
   if(b & 1) ans = MOD((ans * a), mod);
      a = MOD(a * a, mod);
      b >>= 1;
   }
   return ans;
}

// Phi value of N
ll phi(ll n) {
    ll ans = n;
    for(int i=0; i<primes.size(); i++) {
        if(1ll * primes[i] * primes[i] > n) break;
        if(n % primes[i] == 0) {
            while(n % primes[i] == 0) n /= primes[i];
            ans /= primes[i];
            ans *= (primes[i]-1);
        }
    } 

    if(n > 1) ans /= n, ans *= (n-1);
    return ans;
}


ll go(ll l, ll r, ll m) {
    if(l == r) return MOD(v[l], m); 
    if(m == 1) return MOD(1, m);

    return bigmod(v[l], go(l+1, r, phi(m)), m);
}

void solve() {
    cin >> n >> m;
    v.assign(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];

    ll q; cin >> q;
    while(q--) {
        ll l, r; cin >> l >> r;
        l--, r--;

        cout << go(l, r, m)  % m << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    linear_sieve();

    ll tc = 1; // cin >> tc;
    while (tc--)  solve();
}

// https://codeforces.com/contest/906/problem/D
