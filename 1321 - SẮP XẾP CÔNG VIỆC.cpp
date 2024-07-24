//SẮP XẾP CÔNG VIỆC

#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.se == b.se){
		return a.fi < b.fi;
	}
	return a.se < b.se;
}
void Solve(){
	int n; cin >> n;
	pair<int, int> a[n+1];
	for(int i=1; i<=n; i++){
		cin >> a[i].fi;
	}
	for(int i=1; i<=n; i++){
		cin >> a[i].se;
	}
	sort(a+1, a+n+1, cmp);
	int res = 1;
	int lastEnd = a[1].se;
	for(int i=2; i<=n; i++){
		if(a[i].fi >= lastEnd){
			res++;
			lastEnd = a[i].se;
		}
	}
	cout << res << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}