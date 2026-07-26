//SOD
ll SumOfDivisors(ll n) {
    ll ans = 1;
    for(int i=0; i<primes.size(); i++) {
        if(1LL * primes[i] * primes[i] > n) break;
        if(n % primes[i] == 0) {
            ll pwr = 1, sum = 1;
            while(n % primes[i] == 0) {
                n /= primes[i];
                pwr *= primes[i];
                sum += pwr;
            }
            ans *= sum;
        }
    }
    if(n > 1) ans *= (n+1);
    return ans;

}


// NOD
ll NOD(ll n) {
    ll ans = 1;
    for(int i=0; i<primes.size(); i++) {
        if(1LL * primes[i] * primes[i] > n) break;
        if(n % primes[i] == 0) {
            ll ct = 0;
            while(n % primes[i] == 0) {
                n /= primes[i];
                ct++;
            }
            ans *= (ct+1);
        }
    }
    if(n > 1) ans *= 2;
    return ans;
}


//SNOD
ll SNOD(ll n) {
    ll score = 0;
    for(ll i=1; i*i <= n; i++) {
        ll contri_i = (n/i)-i;
        score += contri_i;
    }
    score * 2;
    score += sqrtl(n);
    return score;
}
