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

void getStrings(set<string> &st, vector<bool> &check, string str, string s, int n) {
    if(str.size() == n) {
        st.insert(str);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!check[i]) {
            check[i] = true;
            str += s[i];
            getStrings(st, check, str, s, n);
            str.pop_back();
            check[i] = false;
        }
    }
}
void solve() {
    string s;
    cin >> s;

    int n = s.size();
    set<string> st;
    vector<bool> check(n, false);

    getStrings(st, check, "", s, n);
    
    int size = st.size();
    cout << size << nl;
    
    for(auto &it : st) {
        cout << it << nl;
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
