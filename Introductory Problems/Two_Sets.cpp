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

    ll sum = (n * (ll)(n + 1)) / 2;

    if(sum % 2 == 1) {
        cout << "NO" << nl;
    }
    else {
        cout << "YES" << nl;
        
        ll half = sum / 2;
        set<int> st;
        vi a;
        per(i, n, 1) {
            if(i <= half) {
                a.pb(i);
                half -= i;
                st.insert(i);
            }
        }

        int sz = a.size();
        cout << sz << nl; 
        
        rep(i, 0, sz) {
            cout << a[i] << " ";
        }
        cout << nl;

        cout << n - sz << nl;
        per(i, n, 1) {
            if(st.find(i) == st.end()) {
                cout << i << " ";
                half -= i;
            }
        }
        cout << nl;
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
