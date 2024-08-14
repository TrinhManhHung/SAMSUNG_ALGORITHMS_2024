#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod (ll)(1e9 + 7)
#define endl "\n"
int n, k; 
int a[20];
int X[20];

void Display(){
	for(int i =1; i <=k; i++){
		cout << a[X[i]] << " ";
	}
	cout << "\n";
}

void Try(int i){
	for(int j = X[i-1] +1; j <=n; j++){
		X[i] = j;
		if(i == k){
			Display();
		}
		else Try(i + 1);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i =1; i <=n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		X[0] = 0;
		Try(1);
	}
	return 0;
}
