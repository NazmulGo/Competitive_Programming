// Graph Girth - min len of a cycle in graph

// Created on: 2026-01-15 02:51
// By the hand of: Nazmul_Huda

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;
const ll INF = 100000000;

vector<ll> g[N]; 
vector<bool> vis;
vll par, lvl;
ll n, m; 

void g_clear(int n){
    par.assign(n+1, -1);
    lvl.assign(n+1, 0);
    vis.assign(n+1, false);
}

ll bfs(int s) {
    g_clear(n);
    queue<int> q;
    q.push(s);
    vis[s] = true, lvl[s] = 1, par[s] = s;

    ll score = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true, lvl[v] = lvl[u] + 1, par[v] = u;
                q.push(v);
            }
            else if(vis[v] && v != par[u]) {
                score = min(score, lvl[u] + lvl[v] - 1);
            }
        }
    }
    return score;
}

void solve() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = INF;
    for(int i=1; i<=n; i++) {
        ans = min(ans, bfs(i));
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; // cin >> tc;
    while(tc--) {
        solve();
    }
}
