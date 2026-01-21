#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void print_vec(vector<int> &vec, string name){
    cout << name << endl;
    for(auto &v: vec) cout << v << ' ';
    cout << endl;
}

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;

    int n_zeros = 0, n_ones = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') n_zeros++;
        else n_ones++;
    }

    vector<int> prefix_zero(n_zeros + 1, 0);
    vector<int> prefix_ones(n_ones + 1, 0);

    for(int i = 0, z = 0, o = 0; i < n; i++){
        if(s[i] == '0'){
            prefix_zero[z + 1] = prefix_zero[z] + (n - 1 - i);
            z++;
        }else{
            prefix_ones[o + 1] = prefix_ones[o] + (i);
            o++;
        }
    }

    //print_vec(prefix_zero, "prefix_zero");
    //print_vec(prefix_ones, "prefix_ones");


    int n_z = 0, r_z = n_zeros;
    int n_o = 0, l_o = n_ones + 1;
    for(int i = 1; i <= n; i++){
        if(s[n - i] == '1'){
            l_o--;
            n_o++;
            n_z++;
        }else{
            r_z--;
        }

        //cout << "i: " << i << endl;
        //cout << "n_o: " << n_o << " l_o: " << l_o << endl;
        //cout << "n_z: " << n_z << " r_z: " << r_z << endl;
        if(r_z - n_z>= 0){
            ll dis_zeros = prefix_zero[r_z] - prefix_zero[r_z - n_z] - n_z * i;
            //cout << "dis_zeros: " << dis_zeros << endl;
            ll dis_ones = prefix_ones[l_o + n_o - 1] - prefix_ones[l_o - 1] - n_o * (n - 1 - i);
            //cout << "dis_ones: " << dis_ones << endl;
            cout << dis_ones + dis_zeros << ' ';
        }else{
            cout << -1 << ' ';
        }
    }
    cout << endl; 


}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}