//Di chuyen trong me cung 1
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n; 
int a[15][15];
set<string> res;
void Try(int i, int j, string s){
	if(i == n && j == n){
		res.insert(s);
	}
	else{
		if(i + 1 <= n && j <= n && a[i+1][j] == 1){
			Try(i+1, j, s + "D");
		}
		if(i <= n && j+1 <= n && a[i][j+1] == 1){
			Try(i, j+1, s + "R");
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		res.clear();
		cin >> n;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cin >> a[i][j];
			}
		}
		if(a[1][1] == 0) cout << -1 << endl;
		else{
			Try(1, 1, "");
			if(res.size() == 0) cout << -1 << endl;
			else{
				for(auto x : res) cout << x << ' ';
				cout << endl;
			}
		}
	}
	return 0;
}
