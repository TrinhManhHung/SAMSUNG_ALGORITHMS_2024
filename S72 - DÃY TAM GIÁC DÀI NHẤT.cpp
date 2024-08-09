#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n+1];
		for(int i =1; i <=n; i++) cin >> a[i];
		int left[n+1] = {0}; //left[i] do dai day con tang lien tuc tu 1 den i
		int right[n+1] = {0}; // right[i] do dai day con tang lien tuc tu n den i
		
		left[1] = 1; right[n] = 1;
		// process
		for(int i =2; i <=n; i++){
			if(a[i] > a[i-1]) left[i] = left[i-1] + 1;
			else left[i] = 1;
		}
		for(int i =n-1; i >=1; i--){
			if(a[i] > a[i+1]) right[i] = right[i+1] + 1;
			else right[i] = 1;
		}
		// result
		int res = 0;
		for(int i =1; i <=n; i++){
			res = max(res, left[i] + right[i] - 1);
		}
		cout << res << endl;
	}
	return 0;
}
