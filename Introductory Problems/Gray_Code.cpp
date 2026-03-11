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
void func(vector<string> &arr, int n) {
    if(n == 1) {
        arr.pb("0");
        arr.pb("1");

        return;
    }

    func(arr, n - 1);

    int len = sz(arr);

    per(i, len - 1, 0) {
        arr.pb('1' + arr[i]);
    }
    rep(i, 0, len) {
        arr[i] = '0' + arr[i];
    }
}
void solve() {
    int n;
    cin >> n;
    vector<string> arr;
    func(arr, n);

    each(x, arr) out(x);
}

/* -------------------- MAIN -------------------- */
int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}

// Unorthodox Approach
// void func(string s, int idx, int ones, int n) {
//     if(idx == n) {
//         out(s);
//         return;
//     }

//     if(ones % 2 == 0) {
//         func(s + '0', idx + 1, ones, n);
//         func(s + '1', idx + 1, ones + 1, n);
//     }
//     else {
//         func(s + '1', idx + 1, ones + 1, n);
//         func(s + '0', idx + 1, ones, n);
//     }
// } 

// The solution works because the parity of the number of 1s determines the order of recursion. 
// When the count of 1s is even we explore 0 → 1, and when it is odd we explore 1 → 0. 
// This flips the traversal direction at certain points, which implicitly performs the reflection 
// used in Gray code construction. As a result, consecutive generated strings differ by exactly one bit, 
// satisfying the Gray code condition.