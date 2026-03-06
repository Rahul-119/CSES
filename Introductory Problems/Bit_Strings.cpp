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

long long calcPow(long long base, int power) {
    if(power == 0) {
        return 1;
    }

    if(power & 1) {
        return ((base % MOD) * calcPow(base, power - 1) % MOD) % MOD;
    }

    return calcPow(((base % MOD) * (base % MOD)) % MOD, power / 2) % MOD;
}
void solve() {
    int n;
    cin >> n;

    cout << calcPow(2, n) << nl;
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
