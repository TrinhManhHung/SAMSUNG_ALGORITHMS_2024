#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 300000;

void solve() {
	int X, Y; cin >> X >> Y;
	ll res = 0;
	FOR(x, 0, X){
		FOR(y, 0, Y){
			int mina = max(-x, -y); 
			int maxa = min(X-x, Y-y);
			int minb = max(x-X, -y);
			int maxb = min(x, Y-y);
			
			int cntA = maxa - mina + 1;
			int cntB = maxb - minb + 1;
			res += cntA * cntB - 1;
		}
	}
	cout << res << endl; 
}

int main() {
    faster();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}