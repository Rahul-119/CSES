#include <bits/stdc++.h>
using namespace std;

/* -------------------- TYPES -------------------- */
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vvi  = vector<vector<int>>;
using vvll = vector<vector<ll>>;

using mii  = map<int,int>;
using mll  = map<ll,ll>;
using mci  = map<char,int>;

using si   = set<int>;
using sll  = set<ll>;

using usi  = unordered_set<int>;
using umii = unordered_map<int,int>;
using umll = unordered_map<ll,ll>;

using msi  = multiset<int>;
using msll = multiset<ll>;

/* -------------------- CONSTANTS -------------------- */
constexpr ll INF = 1e18;
constexpr int MOD = 1e9 + 7;
constexpr char nl = '\n';

/* -------------------- MACROS -------------------- */
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define out(x) cout << (x) << '\n'

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define per(i,a,b) for (int i = (a); i >= (b); --i)

#define read2d(mat, n, m) \
    for(int i = 0; i < (n); i++) \
        for(int j = 0; j < (m); j++) \
            cin >> mat[i][j];

#define print2d(mat) \
    for(auto &row:mat){ \
        for(auto &x:row) cout<<x<<" "; \
        cout<<nl; \
    }

#define each(x,a) for (auto &x : a)

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define contains(c,x) ((c).find(x) != (c).end())

#define YES cout << "YES\n"
#define NO cout << "NO\n"

/* -------------------- DEBUG -------------------- */
#ifdef dsawithbazinga

#define debug(x) cerr << #x << " = "; _print(x); cerr << nl;

void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template<class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template<class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(unordered_set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(unordered_map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

#else
#define debug(x)
#endif

/* -------------------- SOLUTION -------------------- */
bool isValid(int newRow, int newCol, int n, int m) {
    return newRow >= 0 && newCol >= 0 && newRow < n && newCol < m;
}

pair<int, string> bfs(vector<vector<char>> &a, vector<vector<bool>> &vis, int i, int j, int n, int m) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    vector<char> moves = {'U', 'R', 'D', 'L'};

    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));
    vector<vector<char>> dir(n, vector<char>(m));

    string ways = "";
    bool found = false;

    while(!q.empty() && !found) {
        auto p = q.front();
        int row = p.first;
        int col = p.second;

        q.pop();

        rep(i, 0, 4) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(isValid(newRow, newCol, n, m) && a[newRow][newCol] == '.' && !vis[newRow][newCol]) {
                q.push({newRow, newCol});
                vis[newRow][newCol] = true;
                par[newRow][newCol] = {row, col};
                dir[newRow][newCol] = moves[i];
            }
            else if(isValid(newRow, newCol, n, m) && a[newRow][newCol] == 'B') {
                found = true;
                par[newRow][newCol] = {row, col};
                dir[newRow][newCol] = moves[i];

                auto coord = make_pair(newRow, newCol);

                while(a[coord.first][coord.second] != 'A') {
                    ways += dir[coord.first][coord.second];
                    coord = par[coord.first][coord.second];
                }

                reverse(ways.begin(), ways.end());
                break;
            }
        }

        if(found) break;
    }

    return {ways.size(), ways};
}

void solve() { // TC: O(n * m), SC: O(n * m) 
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char> (m, '#'));
    
    rep(i, 0, n) {
        string s;
        cin >> s;

        rep(j, 0, m) {
            a[i][j] = s[j];
        }
    }

    vector<vector<bool>> vis(n, vector<bool> (m, false));
    int dist = 0;
    string way = "";
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(a[i][j] == 'A') {
                auto ans = bfs(a, vis, i, j, n, m);
                dist = ans.first;
                way = ans.second;
            }
        }   
    }

    if(dist != 0) {
        YES;
        out(dist);
        out(way);
    }
    else {
        NO;
    }
}

/* -------------------- MAIN -------------------- */
int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}