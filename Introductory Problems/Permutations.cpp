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
    int n;
    cin >> n;

    if(n == 3 || n == 2) {
        cout << "NO SOLUTION" << nl;
        return;
    }

    rep(i, 2, n + 1) {
        if(i % 2 == 0) {
            cout << i << " ";
        }
    }
    rep(i, 1, n + 1) {
        if(i % 2 == 1) {
            cout << i << " " ;
        }
    }
    
    cout << nl;
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
