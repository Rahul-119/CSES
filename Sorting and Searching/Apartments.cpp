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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n); // applicants
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m); // apartments
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));
    
    int count = 0;
    int left = 0;
    int right = 0;

    while(left < n && right < m) {
        if(a[left] >= b[right] - k && a[left] <= b[right] + k) {
            count++;
            left++;
            right++;
        }
        else if(a[left] > b[right] + k) {
            right++;
        }
        else if(a[left] < b[right] - k) {
            left++;
        }
    }
    

    cout << count << nl;
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
