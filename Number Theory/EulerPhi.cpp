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


// preCalc of phi val
vector<ll> phi(N+1), prephi(N+1);
void prePHI() {
    for(int i=1; i<=N; i++) phi[i] = i;
    for(int i=0; i<primes.size(); i++) {
        for(int j=primes[i]; j<=N; j+=primes[i]) {
            phi[j] /= primes[i];
            phi[j] *= (primes[i]-1);
        }
    }

    for(int i=1; i<=N; i++) prephi[i] = prephi[i-1] + phi[i]; 
}


// Tricks
// • Sum of Coprimes      -> N * phi(N) / 2
// • Count (gcd = d)      -> phi(N / d)
// • Sum of phi(divisors) -> N
