#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod (ll)(1e9 + 7)
#define endl "\n"
void findMin(int n, int s){
	int mi[n+1] = {0};
	mi[1] = 1;
	s--;
	int idx = n;
	while(s >0){
		if(s > 9){
			mi[idx] = 9;
			s -= 9;
		}
		else {
			mi[idx] += s;
			s = 0;
		}
		idx--;
	}
	for(int i =1; i <=n; i++) cout << mi[i];
	cout << " ";	
}

void findMax(int n, int s){
	int ma[n+1] = {0};
	int idx = 1;
	while(s >0){
		if(s > 9){
			ma[idx] = 9;
			s -= 9;
		}
		else {
			ma[idx] = s;
			s = 0;
		}
		idx++;
	}
	for(int i =1; i <=n; i++) cout << ma[i];
}
int main(){
	int n, s; cin >> n >> s;
	if(s > 9*n || s < 0 || (s == 0 && n >1)){
		cout << "-1 -1";
	}
	else{
		findMin(n, s); findMax(n, s);
	}
	return 0;
}
