#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << "[" << #x << "] = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    int bits_available = m * 8;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    map<int, int> number_frec;
    for(auto &a : A){
        number_frec[a]++;
    }

    sort(all(A));
    A.erase(unique(all(A)), A.end());

    int bits_needed = log(sz(A)) * n;
    int changued = 0;
    int differents = sz(A);
    int i = 0, j = sz(A) - 1;
    dbg(bits_needed);
    dbg(bits_available);
    while(bits_needed > bits_available){
        if(number_frec[A[i]] < number_frec[A[j]]){
            changued += number_frec[A[i]];
            i++;
        }else{
            changued += number_frec[A[j]];
            j--;
        }
        differents--;
        bits_needed = differents * n;
    }

    cout << changued << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}