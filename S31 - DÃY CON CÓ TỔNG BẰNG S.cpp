#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n; 
ll sum;
ll a[35];
ll X[35];
int res;
void Try(int i, int bd, int cursum){
	for(int j =bd; j <=n; j++){
		X[i] = j;
		cursum += a[j];
		if(cursum == sum){
			res = min(res, i);
		}
		if(cursum < sum){
			Try(i+1, j+1, cursum);
		}
		cursum -= a[j];
	}
}

int main(){
	res = 40;
	cin >> n >> sum;
	for(int i =1; i <=n; i++){
		cin >> a[i];
	}
	
	Try(1, 1, 0);
	if(res == 40){
		cout << -1;
	}
	else
		cout << res;
	return 0;
}
