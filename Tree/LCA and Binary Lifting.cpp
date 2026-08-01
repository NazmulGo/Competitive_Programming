#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(), v.end()

const int N = 3e5 + 9, LG = 21;
vector<vector<ll>> g, up;
vector<ll> dep, sz;
int n;

void dfs(int u, int p) { 
    up[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    
    for (int i = 1; i < LG; i++) up[u][i] = up[ up[u][i - 1] ][i - 1];
    for (auto v : g[u]) {
        if (v != p) {
          dfs(v, u);
          sz[u] += sz[v];
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG-1; k >= 0; k--) if (dep[up[u][k]] >= dep[v]) u = up[u][k];
    if (u == v) return u;

    for (int k = LG-1; k >= 0; k--) if (up[u][k] != up[v][k]) u = up[u][k], v = up[v][k];
    return up[u][0];
}

int kth(int u, int k) {
    assert(k >= 0);
    for(int i=0; i<LG; i++) if((1ll << i) & k) u = up[u][i];
    return u;
}

int dist(int u, int v) {
  int l = lca(u, v);
  return dep[u] + dep[v] - (dep[l] << 1);
}

// kth node from u to v, 0th node is u
int go(int u, int v, int k) {
  int l = lca(u, v);
  int d = dep[u] + dep[v] - (dep[l] << 1);
  if(k > d) return -1; 
  assert(k <= d);
  if (dep[l] + k <= dep[u]) return kth(u, k);
  k -= dep[u] - dep[l];
  return kth(v, dep[v] - dep[l] - k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin >> n;

    g.assign(n+1, vector<ll>()); up.assign(n+1, vector<ll>(LG, 0));
    dep.assign(n+1, 0); sz.assign(n+1, 0);

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
}
