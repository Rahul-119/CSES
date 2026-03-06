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

bool comparator(vi &a, vi &b) {
    return a[1] < b[1]; 
}

void solve() {
    int n;
    cin >> n;

    vector<vi> arr(n, vi(2));

    for(int i = 0; i < n; i++) {
        cin >> arr[i][0]; // start time
        cin >> arr[i][1]; // end time
    }

    sort(all(arr), comparator);

    int lastMovieTime = -1;
    int movies = 0;

    rep(i, 0, n) {
        if(arr[i][0] >= lastMovieTime) {
            lastMovieTime = arr[i][1];
            movies++;
        }
    }

    cout << movies << nl;
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
