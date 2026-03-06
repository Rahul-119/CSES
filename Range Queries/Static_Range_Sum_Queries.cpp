#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
using vi  = vector<int>;
using vll = vector<long long>;

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr char nl = '\n';

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define each(x, a) for (auto &x : a)
#define pb push_back

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vi> queries(q, vi(2, 0));

    rep(i, 0, q) {
        cin >> queries[i][0];
        cin >> queries[i][1];
    }

    vll pref(n + 1, 0);
    pref[1] = a[1];
    rep(i, 1, n + 1) {
        pref[i] = pref[i - 1] + a[i];
    }
     
    rep(i, 0, q) {
        ll leftVal = pref[queries[i][0] - 1]; 
        ll rightVal = pref[queries[i][1]];

        cout << rightVal - leftVal << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
