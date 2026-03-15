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
void solve() {
    int n;
    cin >> n;

    vi dp(n + 1, 0); 

    dp[0] = 1;
    for(int sum = 1; sum <= n; sum++) {
        for(int i = 1; i <= 6; i++) {
            if(i <= sum) {
                dp[sum] = (dp[sum] + dp[sum - i]) % MOD;
            }
        }
    }
    
    cout << dp[n] <<  nl;
}

/* -------------------- MAIN -------------------- */
int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}