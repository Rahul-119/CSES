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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    ll median = 0;

    if (n & 1) {
        median = a[n / 2];
    }
    else {
        median = (a[n / 2 - 1] + a[n / 2]) / 2;
    }

    ll cost = 0;

    rep(i, 0, n) {
        cost += abs(a[i] - median);
    }

    cout << cost << nl;
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


// JAVA Solution:

/* import java.io.*;
import java.util.*;

public class Stick_Lengths {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        long[] arr = new long[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(arr);

        long median;
        if (n % 2 == 1) {
            median = arr[n / 2];
        } else {
            median = arr[n / 2 - 1]; 
        }

        long cost = 0;
        for (int i = 0; i < n; i++) {
            cost += Math.abs(arr[i] - median);
        }

        System.out.println(cost);
    }
} */
