/*
https://www.spoj.com/PTIT/problems/PTIT018D/
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

int val(string s){
	int res = 0;
	FOR(i, 0, s.sz-1){
		res += s[i] - 'A';
	}
	return res;
}
char rotate(char x, int val){
	char res = (char)((x-'A'+val) % 26 + 'A');
	return res;
}

void solve(){
	string s; cin >> s;
	string s1 = "", s2 = "";
	FOR(i, 0, s.sz/2 -1){
		s1 += s[i];
		s2 += s[i+s.sz/2];
	}

	int val1 = val(s1);
	int val2 = val(s2);
	string s11 = "", s22 = "";
	FOR(i, 0, s1.sz-1){
		s11 += rotate(s1[i], val1);
		s22 += rotate(s2[i], val2);
	}
	
//	SHOW2(s11, s22);
	string res = "";
	FOR(i, 0, s1.sz-1){
		res += rotate(s11[i], s22[i]-'A');
	}
	
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

