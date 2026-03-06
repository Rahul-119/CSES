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

void makeString(string& str, char ch, int freq) {
    for(int i = 0; i < freq; i++) {
        str += ch;
    }
}
void solve() {
    string s;
    cin >> s;

    int n = s.size();
    map<char, int> mp;

    rep(i, 0, n) {
        mp[s[i]]++;
    }
    
    char ch = '#';

    for(auto &it : mp) {
        if(it.second % 2 == 1 && ch != '#') {
            cout << "NO SOLUTION" << nl;
            return;
            
        } else if(it.second % 2 == 1) {
            ch = it.first;
        } 
    }

    string first = "";
    string second = "";
    for(auto &it : mp) {
        char c = it.first;
        int freq = it.second;
        
        makeString(first, c, freq / 2);
        makeString(second, c, freq / 2);
    }

    if(ch != '#') {
        makeString(first, ch, 1);
    }

    reverse(second.begin(), second.end());

    cout << first + second <<  nl;
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
