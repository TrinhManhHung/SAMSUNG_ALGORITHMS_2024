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
vector<string> lp;

void cal(){
	for(int i =0; i <=1000000; i++){
		ll tmp = 1ll * pow(i, 3);
		lp.pb(to_string(tmp));
	}
}

bool check(string s, string tmp){
	int l = 0;
	for(int i =0; i <s.sz; i++){
		if(s[i] == tmp[l]) l++;
		if(l == tmp.sz) return true;
	}
	return false;
}
void solve(){
	string s; cin >> s;
	
	for(int i =lp.sz-1; i >=0; i--){
		if(s.sz < lp[i].sz) continue;
		if(check(s, lp[i])){
			cout << lp[i] << endl;
			return;
		}
	}
	cout << -1 << endl;
}	

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.inp", "w", stdout);
  	}
  	cal();
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
