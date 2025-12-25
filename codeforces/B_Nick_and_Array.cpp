#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n + 1);
    A[n] = INT_MIN;
    int max_element_index = n;
    for(int i = 0; i < n; i++){
        int &a = A[i];
        cin >> a;
        if(a >= 0) a = -a - 1;
        if(abs(a) >= abs(A[max_element_index]) and a != -1){
            max_element_index = i;
        }
    }

    if(max_element_index == n) max_element_index = n - 1;

    if(n % 2 != 0){
        A[max_element_index] = -A[max_element_index] - 1; 
    }

    for(int i = 0; i < n; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}
