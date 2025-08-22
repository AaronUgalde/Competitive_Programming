#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

bool ignore_x(vector<int> &A, int n, int x){
    int i = 0, j = n-1;
    while(i <= j){
        while(A[i] == x) i++;
        while(A[j] == x) j--;
        if(A[i] == A[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    int x_1 = INT_MAX, x_2 = INT_MAX;
    for(int i = 0; i<n/2; i++){
        if(A[i] != A[n-1-i]){
            x_1 = A[i];
            x_2 = A[n-1-i];
            break;
        }
    }

    if(x_1 == INT_MAX){
        cout << "YES" << endl;
        return;
    }

    cout <<(ignore_x(A, n, x_1) || ignore_x(A, n, x_2) ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}