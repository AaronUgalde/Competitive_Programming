#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        string modern;
        modern.push_back(s1[0]);
        modern.push_back(s2[0]);
        modern.push_back(s3[0]);
        cout << modern << endl;
    }
}