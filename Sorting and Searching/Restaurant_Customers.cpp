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

    vector<vi> arr;
    for (int i = 0; i < n; i++) {
        int a;
        int b;

        cin >> a >> b;

        arr.pb({a, 0});
        arr.pb({b, 1});
    }

    sort(all(arr));

    int ans = 0;
    int count = 0;

    rep(i, 0, (int)arr.size()) {
        if(arr[i][1] == 0) {
            count++;
        }
        else {
            count--;
        }

        ans = max(ans, count);
    }

    cout << ans << nl;
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
