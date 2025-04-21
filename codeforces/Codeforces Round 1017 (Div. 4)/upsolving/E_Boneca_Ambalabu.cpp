#include <bits/stdc++.h>
using namespace std;

const int BITS = 30;

void solve(int testcase){
    long long n; cin >> n;
    
    vector<long long> numbers(n);
    vector<int> ones(BITS, 0);

    for(int i = 0; i<n; i++){
        long long a; cin >> a;
        numbers[i] = a;
        for(int j = 0; j < BITS; j++){
            if(a & (1 << j)) ones[j]++;
        }
    }

    long long maxSum = 0;

    for(int i = 0; i<n; i++){
        long long sum = 0;
        for(int j = 0; j<BITS; j++){
            if (numbers[i] & (1LL << j)) {
                sum += ( (long long)(n - ones[j]) << j );
            } else {
                sum += ( (long long)ones[j] << j );
            }
        }
        maxSum = max(maxSum, sum);
    }
    
    cout << maxSum << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}