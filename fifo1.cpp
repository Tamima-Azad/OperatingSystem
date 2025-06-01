// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int main(){
    
//     string s; cin >> s;
//     int frame, sz = s.size();
//     cin >> frame;
//     char ar[frame][sz];
//     for(int i = 0; i < frame; i++){
//         for(int j = 0; j < sz; j++){
//             ar[i][j] = ' ';
//         }
//     }

//     bool arr[frame+1];
//     for(int i = 1; i <= frame; i++){
//         arr[i] = false;
//     }
//     vector<char>v;
//     map<char,int>mp;
//     for(int i = 0; i < sz; i++){
//         bool paisi = false;
//         if(mp[s[i]]==0){
//             v.push_back('M');
//             if(i > 0){
//                 for(int j = 0; j < frame; j++){
//                     ar[j][i] = ar[j][i-1];
//                     if(ar[j][i] != ' '){
//                         mp[ar[j][i]]++;
//                     }
//                 }
//             }
//             else {
//                 ar[i][i] = s[i];
//                 mp[s[i]]++;
//             }
//             for(int j = 1; j <= frame; j++){
//                 if(arr[j]==false and !paisi){
//                     ar[j-1][i] = s[i];
//                     arr[j] = true;
//                     paisi = true;
//                 }
//             }
//             if(!paisi){
//                 int mx = 0;
//                 char mxc;
//                 for(auto i: mp){
//                     if(i.second > mx)mx = i.second, mxc = i.first;
                    
//                 }
//                 for(int j = 0; j < frame; j++){
//                     if(ar[j][i-1] != ' '){
//                         ar[j][i] = ar[j][i-1];
//                         mp[ar[j][i]]++;
//                     }
//                 }
//                 for(int j = 0; j < frame; j++){
//                     if(ar[j][i]==mxc){
//                         ar[j][i] = s[i];
//                         mp[mxc] = 0;
//                     }
//                 }
//             }
//         }
//         else {
//             v.push_back('H');
//             for(int j = 0; j < frame; j++){
//                 ar[j][i] = ar[j][i-1];
//                 mp[ar[j][i]]++;
//             }
//         }
//     }
//     cout << endl;
//     for(int i = 0; i < frame; i++){
//         for(int j = 0; j < sz; j++){
//             cout << (ar[i][j]) << " ";
//         }
//         cout << endl;
//     }
//     int h = 0, m = 0;
//     for(auto i: v){
//         cout << i << " ";
//         if(i=='H')h++;
//         else m++;
//     }
//     cout << endl;
//     cout << "Number of Miss = " << m << endl;
//     cout << "Number of Hits = " << h << endl;
//     double hr = h/float(sz), mr = m/float(sz);
//     cout << "Hit Ratio = " << float(hr) << endl;
//     cout << "Miss Ratio = " << mr << endl;
// return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<int>> mat(f, vector<int>(n, -1));
    int faults = 0, hits = 0, pos = 0;
    vector<char> status(n); 
    for (int i = 0; i < n; i++) {
        bool hit = false;
        if(i > 0){
            for(int j = 0; j < f; j++){
                mat[j][i] = mat[j][i-1];
                if(mat[j][i]==a[i])hit = true;
            }
        }
        if(!hit){
            mat[pos][i] = a[i];
            pos = (pos + 1) % f;
            faults++;
            status[i] = 'M'; // Miss
        }
        else {
            hits++;
            status[i] = 'H'; // Hit
        }

    }
    for (auto &row : mat) {
        for (int x : row) cout << (x == -1 ? -1 : x) << ' ';
        cout << '\n';
    }
    //cout << "Status: ";
    for (char s : status) cout << s << ' ';
    cout << '\n';
    cout << "Page Faults: " << faults << '\n';
    cout << "Page Hits: " << hits << '\n';
}