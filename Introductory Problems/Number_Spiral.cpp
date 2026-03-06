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
    ll x, y;
    cin >> x >> y;

    if(x == 1 && y == 1) {
        cout << 1 << nl;
        return;
    }

    if(y >= x) {
        if (y % 2 == 1) {
            cout << (y * y) - (x - 1) << nl;
        }
        else {
            cout << (y - 1)* (y - 1) + x << nl;
        }
    }
    else {
        if(x % 2 == 0) {
            cout << (x * x) - (y - 1) << nl;
        }
        else {
            cout << (x - 1) * (x - 1) + y << nl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
