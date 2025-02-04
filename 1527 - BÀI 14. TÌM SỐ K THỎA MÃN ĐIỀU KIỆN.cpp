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

vi v;

set<char> len;
bool check(int n){
	len.clear();
	string s = to_string(n);
	for(int i =0; i <s.sz; i++){
		len.insert(s[i]);
		if(s[i] > '5') return false;
	}
	return s.sz == len.sz;
}
void cal(){
	for(int i =0; i <=100000; i++){
		if(check(i)) v.pb(i);
	}
}
void solve(){
	int l, r; cin >> l >> r;
	int sta = lower_bound(v.begin(), v.end(), l) - v.begin();
	int end = upper_bound(v.begin(), v.end(), r) - v.begin();
	cout << end - sta << endl;
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

