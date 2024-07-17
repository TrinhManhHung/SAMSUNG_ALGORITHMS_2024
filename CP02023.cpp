// ĐẢO DẤU

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n, k; cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i =0; i <n; i++){
        int x; cin >> x;
        q.push(x);
    }
    while(k--){
        int tmp = q.top();
        q.pop();
        q.push(-tmp);
    }
    ll sum = 0;
    while(!q.empty()){
        sum += q.top(); q.pop();
    }
    cout << sum << endl;
    return 0;
}