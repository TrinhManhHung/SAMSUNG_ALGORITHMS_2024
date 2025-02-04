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
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
int n, k; 
int tong, res;
int a[20];

void solve(){
	string s; cin >> s;
	if(s.sz == 1){
		cout << s << endl;
		return;
	}
	int du = 0;
	for(int i =s.sz-1; i >=1; i--){
		if((s[i]-'0') + du >= 5){
			du = 1;
		}
		else du = 0;
		s[i] = '0';
	}
	if(du == 1){
		int tmp = (s[0]-'0') + du;
		if(tmp <= 9) s[0] = tmp + '0';
		else{
			s[0] = '0';
			s = "1" + s;
		} 
	}
	cout << s << endl;
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
7
15
14
5
99
12345678
44444445
1445
	  (\(\
	 ( 0.0)
	o_(")(")
**/
