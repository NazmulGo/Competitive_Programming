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

vector<ll> conv(vector<ll> &x) {
     sort(all(x));
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
