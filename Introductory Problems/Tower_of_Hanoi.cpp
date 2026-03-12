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
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;

using mii  = map<int,int>;
using mll  = map<ll,ll>;
using si   = set<int>;
using sll  = set<ll>;
using msi  = multiset<int>;

/* -------------------- CONSTANTS -------------------- */
constexpr ll INF = 1e18;
constexpr int MOD = 1e9 + 7;
constexpr char nl = '\n';

/* -------------------- MACROS -------------------- */
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define per(i,a,b) for (int i = (a); i >= (b); --i)
#define each(x,a) for (auto &x : a)

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define YES cout << "YES\n"
#define NO cout << "NO\n"

/* -------------------- SOLUTION -------------------- */
// *
void func(int n, int start, int auxi, int end) {
    if(n == 1) {
        cout << start << " " << end << nl;
        return;
    }

    func(n - 1, start, end, auxi); // start -> auxi using end
    cout << start << " " << end << nl;
    func(n - 1, auxi, start, end); // auxi -> end using start
}
void solve() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << nl;
    func(n, 1, 2, 3);
}

/* -------------------- MAIN -------------------- */
int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}