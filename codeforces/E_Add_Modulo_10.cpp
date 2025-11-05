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
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    
    int other = -1;
    int five_zero = -1;
    for(auto &a : A){
        if(a % 10 == 0){
            if(five_zero == -1) five_zero = a / 10;
            else if(five_zero != a / 10){
                cout << "No" << endl;
                return;
            }
        }else if(a % 10 == 5){
            if(five_zero == - 1) five_zero = (a + 5) / 10;
            else if(five_zero != (a + 5) / 10){
                cout << "No" << endl;
                return;
            }
        }else if(a % 10 == 7 or a % 10 == 3 or a % 10 == 6 or a % 10 == 9){
            if(other == -1) other = (a / 10 + 1) % 2;
            else if(other != (a / 10 + 1) % 2){
                cout << "No" << endl;
                return;
            }
        }else{
            if(other == -1) other = (a / 10) % 2;
            else if(other != (a / 10) % 2){
                cout << "No" << endl;
                return;
            }
        }
    }

    if(five_zero != -1 and other != -1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}