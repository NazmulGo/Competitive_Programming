ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll modInverse(ll a, ll mod) {
    ll x, y;
    ll g = extended_gcd(a, mod, x, y);
    if (g != 1) return -1;  // Inverse doesn't exist
    x = (x % mod + mod) % mod;
    return x;
}

 // Modular Inverse: modInverse(a, mod);

// GCD:
// ll x, y;
// ll g = extended_gcd(a, b, x, y);
// Now: a*x + b*y = g
