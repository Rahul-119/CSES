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

    vector<vi> a(n + 1, vi(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if(ch == '*') {
                a[i][j] = 1;
            }
        }
    }

    vector<vi> prefix(n + 1, vi(n + 1));
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            int sum = a[i][j];

            sum += prefix[i - 1][j];
            sum += prefix[i][j - 1];
            sum -= prefix[i - 1][j - 1];

            prefix[i][j] = sum;
        }
    }

    while(q--) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;

        int val = prefix[x2][y2];

        val -= prefix[x1 - 1][y2];
        val -= prefix[x2][y1 - 1];
        val += prefix[x1 - 1][y1 - 1];

        cout << val << nl;
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
