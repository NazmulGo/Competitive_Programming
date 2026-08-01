#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;

vector<ll> g[N]; 
vll lvl;

void g_clear(int n){
    for(int i=0; i<=n; i++) g[i].clear();
    lvl.assign(n+1, 0);
}

void dfs(ll u, ll p) {
    for(auto v : g[u]) {
        if(v != p) {
            lvl[v] = 1 + lvl[u];
            dfs(v, u);
        }
    }
}

pll diameter(ll n) {

    dfs(1, 0);
    ll d1 = max_element(all(lvl)) - lvl.begin();
    lvl.assign(n+1, 0);
    dfs(d1, 0);
    ll d2 = max_element(all(lvl)) - lvl.begin();

    return {d1, d2};
}

void solve() {
    ll n; cin >> n;
    g_clear(n);
    for(int i=1; i<n; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

   auto x = diameter(n);
   cout << x.first << " " << x.second << endl;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1;  cin >> tc;
    while(tc--) {
        solve();
    }
}
