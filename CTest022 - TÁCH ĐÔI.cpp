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
#define MOD (ll)1e9 + 7;
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}
void solve(){
	string s; cin >> s;
	if(s.sz % 2 == 1) cout << "INVALID\n";
	else{
		ll half1 = stoll(s.substr(0, s.sz/2));
		ll half2 = stoll(s.substr(s.sz/2, s.sz));
		cout << lcm(half1, half2) << endl;
	}
}

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.inp", "w", stdout);
  	}
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
