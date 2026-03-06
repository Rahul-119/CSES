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
void solve() {
    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<ll> arr(n, 0);

    arr[0] = x;

    rep(i, 1, n) {
        arr[i] = ((arr[i - 1] * a) + b) % c;
    }

    int left = 0;
    int right = 0;
    
    vector<ll> store;
    ll xorr = 0;

    while(right < n) {
        xorr ^= arr[right];
        
        while(right - left + 1 > k) {
            xorr ^= arr[left];
            left++;
        }
        
        if(right - left + 1 == k) {
            store.pb(xorr);
        }

        right++; 
    }

    ll xr = 0;

    rep(i, 0, sz(store)) {
        xr ^= store[i];
    }

    cout << xr << nl;
}

/* -------------------- MAIN -------------------- */
int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}