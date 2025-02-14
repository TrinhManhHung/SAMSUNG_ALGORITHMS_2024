/*
https://www.spoj.com/PTIT/problems/PTIT018C/
*/
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
const int maxn = 1e6;

ll cal(string a, int m){
	int res = 0;
	FOR(i, 0, a.sz-1){
		res = res * 10 + (a[i]-'0');
		res %= m;
	}
	return res;
}

ll powMod(ll a, ll b, ll m){
	if(b == 0) return 1;
	if(b == 1) return a;
	int half = powMod(a, b/2, m);
	if(b % 2 == 0){
		return (half % m * half % m) % m;
	}
	else{
		return ((half % m * half % m) % m * a) % m;
	}
}
void solve(){
	string a;
	ll b, m;
	cin >> a >> b >> m;
	ll amodm = cal(a, m);
	ll res = powMod(amodm, b, m);
	cout << res << endl;
}

int main(){
    faster();
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/** HungLam

	  (\(\
	 ( 0.0)
	o_(")(")
**/

