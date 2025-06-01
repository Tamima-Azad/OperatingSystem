// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const char nl = '\n';

// bool check_hit(vector<vector<int>>& arr, int f, int n, int ind, int jind, int num) {
//     for (int i = ind; i < f; ++i) {
//         if (arr[i][jind] == num) {
//             return true;
//         }
//     }
//     return false;
// }

// bool check_faka(vector<vector<int>>& arr, int f, int n, int ind, int jind) {
//     for (int i = ind; i < f; ++i) {
//         if (arr[i][jind] == -1) {
//             return true;
//         }
//     }
//     return false;
// }

// int check_fakai(vector<vector<int>>& arr, int f, int n, int ind, int jind) {
//     for (int i = ind; i < f; ++i) {
//         if (arr[i][jind] == -1) {
//             return i;
//         }
//     }
//     return -1;
// }

// int32_t main() {
//     int n, f;
//     cin >> n >> f;
//     int a[n];
//     for (int i = 0; i < n; ++i) cin >> a[i];
//     cout << endl;

//     vector<vector<int>> arr(f, vector<int>(n, -1));

//     int pagehit = 0, pagefault = 0;
//     for (int j = 0; j < n; ++j) {
//         if (j == 0) {
//             arr[0][j] = a[j];
//             pagefault++;
//             for (int k = 1; k < f; ++k) arr[k][j] = -1;
//             continue;
//         }

//         bool checkhit = check_hit(arr, f, n, 0, j - 1, a[j]);
//         if (checkhit) {
//             pagehit++;
//             for (int k = 0; k < f; ++k) arr[k][j] = arr[k][j - 1];
//             continue;
//         }

//         bool checkfaka = check_faka(arr, f, n, 0, j - 1);
//         if (checkfaka) {
//             int checkfakai = check_fakai(arr, f, n, 0, j - 1);
//             arr[checkfakai][j] = a[j];
//             pagefault++;
//             for (int k = 0; k < f; ++k) {
//                 if (k == checkfakai) continue;
//                 arr[k][j] = arr[k][j - 1];
//             }
//             continue;
//         }

//         vector<int> ele;
//         for (int i = 0; i < f; ++i) ele.push_back(arr[i][j - 1]);

//         vector<pair<int, int>> v;
//         for (int i = 0; i < ele.size(); ++i) {
//             int last_use = -1;
//             for (int k = j - 1; k >= 0; --k) {
//                 if (a[k] == ele[i]) {
//                     last_use = k;
//                     break;
//                 }
//             }
//             v.push_back({last_use, ele[i]});
//         }

//         sort(v.begin(), v.end());
//         int num = v[0].second;

//         for (int i = 0; i < f; ++i) {
//             if (arr[i][j - 1] == num) arr[i][j] = a[j];
//             else arr[i][j] = arr[i][j - 1];
//         }
//         pagefault++;
//     }
//     for (int i = 0; i < f; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (arr[i][j] == -1) cout << "X ";
//             else cout << arr[i][j] << " ";
//         }
//         cout << nl;
//     }
//     cout << "PAGE FAULT = " << pagefault << nl;
//     cout << "PAGE HIT = " << pagehit << nl;
//     cout << "PAGE FAULT RATE = " << (double)pagefault / (pagefault + pagehit) * 100 << "%" << nl;
//     cout << "PAGE HIT RATE = " << (double)pagehit / (pagefault + pagehit) * 100 << "%" << nl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<int>> mat(f, vector<int>(n, -1));
    int pf = 0, ph = 0;

    for (int i = 0; i < n; ++i) {
        bool hit = false;
        if (i > 0)
            for (int j = 0; j < f; ++j) {
                mat[j][i] = mat[j][i - 1];
                if (mat[j][i] == a[i]) hit = true;
            }

        if (!hit) {
            set<int> s;
            int last = -1;
            for (int j = i - 1; j >= 0; --j) {
                s.insert(a[j]);
                if ((int)s.size() == f) {
                    last = a[j];
                    break;
                }
            }
            int idx = 0;
            for (int j = 0; j < f; ++j) {
                if (mat[j][i] == last) {
                    idx = j;
                    break;
                }
            }
            mat[idx][i] = a[i];
            pf++;
        } else ph++;
    }

    for (auto &row : mat) {
        for (int x : row) cout << (x == -1 ? -1 : x) << ' ';
        cout << '\n';
    }
    cout << "Page Faults: " << pf << '\n';
    cout << "Page Hits: " << ph << '\n';
}