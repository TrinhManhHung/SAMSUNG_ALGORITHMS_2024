/*
https://www.spoj.com/PTIT/problems/PTIT018E/
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        
        bool found = false;
        // Ki?m tra nhanh: n?u có ph?n t? trùng l?p, ta có hai t?p con g?m ph?n t? dó
        unordered_map<int, int> freq;
        for (int i = 0; i < N; i++){
            freq[A[i]]++;
            if(freq[A[i]] >= 2){
                found = true;
                break;
            }
        }
        if(found){
            cout << "YES" << "\n";
            continue;
        }
        
        unordered_set<int> sums;  // luu các t?ng dã g?p
        int total = 1 << N;       // t?ng s? t?p con (bao g?m t?p con r?ng, nhung ta b? qua mask = 0)
        
        for (int mask = 1; mask < total; mask++){
            int sum = 0;
            // Duy?t qua t?ng bit d? xác d?nh các ph?n t? thu?c t?p con
            for (int i = 0; i < N; i++){
                if(mask & (1 << i))
                    sum += A[i];
            }
            // N?u t?ng dã xu?t hi?n, ta có 2 t?p con khác nhau có t?ng b?ng nhau
            if(sums.count(sum)){
                found = true;
                break;
            }
            sums.insert(sum);
        }
        
        cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}
