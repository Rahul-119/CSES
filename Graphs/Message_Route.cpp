#include <bits/stdc++.h>
using namespace std;

/* -------------------- TYPES -------------------- */
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vvi  = vector<vector<int>>;
using vvll = vector<vector<ll>>;

using mii  = map<int,int>;
using mll  = map<ll,ll>;
using mci  = map<char,int>;

using si   = set<int>;
using sll  = set<ll>;

using usi  = unordered_set<int>;
using umii = unordered_map<int,int>;
using umll = unordered_map<ll,ll>;

using msi  = multiset<int>;
using msll = multiset<ll>;

/* -------------------- CONSTANTS -------------------- */
constexpr ll INF = 1e18;
constexpr int MOD = 1e9 + 7;
constexpr char nl = '\n';

/* -------------------- MACROS -------------------- */
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define out(x) cout << (x) << '\n'

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define per(i,a,b) for (int i = (a); i >= (b); --i)

#define read2d(mat, n, m) \
    for(int i = 0; i < (n); i++) \
        for(int j = 0; j < (m); j++) \
            cin >> mat[i][j];

#define print2d(mat) \
    for(auto &row:mat){ \
        for(auto &x:row) cout<<x<<" "; \
        cout<<nl; \
    }

#define each(x,a) for (auto &x : a)

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define contains(c,x) ((c).find(x) != (c).end())

#define YES cout << "YES\n"
#define NO cout << "NO\n"

/* -------------------- DEBUG -------------------- */
#ifdef dsawithbazinga

#define debug(x) cerr << #x << " = "; _print(x); cerr << nl;

void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template<class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template<class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(unordered_set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(unordered_map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

#else
#define debug(x)
#endif

/* -------------------- SOLUTION -------------------- */
void bfs(vvi &adjList, vi &dist, vi &parent) {
    queue<pii> q;

    q.push({1, 0});

    while(!q.empty()) {
        auto p = q.front();
        q.pop();

        int node = p.first;
        int d = p.second;

        for(int &adjNode : adjList[node]) {
            if(dist[adjNode] > d + 1) {
                dist[adjNode] = d + 1;
                parent[adjNode] = node;
                q.push({adjNode, dist[adjNode]});
            }
        }
    }
}

void solve() { // O(V + E)
    int n, m;
    cin >> n >> m;

    vvi edges(m, vi(2));
    rep(i, 0, m) {
        rep(j, 0, 2) {
            cin >> edges[i][j];
        }
    }
    vvi adjList(n + 1);
    rep(i, 0, m) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    vi dist(n + 1, 1e9);
    dist[1] = 0;
    
    vi parent(n + 1);
    rep(i, 0, n) {
        parent[i] = i;
    }

    bfs(adjList, dist, parent);

    if(dist[n] == 1e9) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }

    cout << dist[n] + 1 << nl;

    vi path;
    int i = n;
    while(parent[i] != i) {
        path.pb(i);
        i = parent[i];
    }

    path.pb(1);
    reverse(all(path));

    each(x, path) {
        cout << x << " ";
    }
}

/* -------------------- MAIN -------------------- */
int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}