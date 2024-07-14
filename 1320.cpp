//To hop so co tong bang x
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define ll long long
int n, x;
int a[25];
vector<vector<int>> res;
vector<int> tmp;
void Try(int bd, int curSum){
	for(int j=bd; j<=n; j++){
		tmp.pb(a[j]);
		if(curSum + a[j] == x){
			res.pb(tmp);
		}
		else if(curSum + a[j] < x){
			Try(j, curSum + a[j]);
		}
		tmp.pop_back();
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		tmp.clear(); res.clear();
		
		cin >> n >> x;
		for(int i=1; i<= n; i++){
			cin >> a[i];
		}
		Try(1, 0);
		if(res.size() == 0) cout << -1 << endl;
		else{
			for(auto x : res){
				cout << "[";
				for(int i=0; i<x.size()-1; i++){
					cout << x[i] << " ";
				}
				cout << x[x.size()-1] << "]";
			}
		}
		cout << endl;
	}
	return 0;
}