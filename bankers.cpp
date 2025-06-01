// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     cout << "Enter total number of process: ";
//     int n;
//     cin >> n;

//     cout << "Enter total number of resource: ";
//     int r;
//     cin >> r;

//     int allocation[n][r];
//     cout << "Enter allocation matrix:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < r; j++) {
//             cin >> allocation[i][j];
//         }
//     }
//     int max_need[n][r];
//     cout << "Enter max need matrix:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < r; j++) {
//             cin >> max_need[i][j];
//         }
//     }

//     vector<int> available(r);
//     cout << "Enter available r:\n";
//     for (int i = 0; i < r; i++) {
//         cin >> available[i];
//     }
//     cout << "available r:\n";
//     for (int i = 0; i < r; i++) {
//         cout<<available[i]<<" ";
//     }
//     cout<<endl;
//     int c_need[n][r];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < r; j++) {
//             c_need[i][j] = max_need[i][j] - allocation[i][j];
//         }
//     }
//     vector<int> seq;
//     vector<bool> finish(n, false);
//     int cnt = 0;
//     int x=0;
//     while (cnt<n) { 
//         bool found = false;
//         for (int i = 0; i < n; i++) {
//             if (!finish[i]) {
//                 bool flag = true;
//                 for (int j = 0; j < r; j++) {
//                     if (c_need[i][j] > available[j]) {
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if (flag) {
//                     for (int j = 0; j < r; j++) {
                        
//                         available[j] += allocation[i][j];
//                         cout<<available[j]<<" ";
//                     }
//                     cout<<endl;
//                     seq.push_back(i);
//                     finish[i] = true;
//                     cnt++;
//                     found = true;
//                 }
                
//             }
//         }
//         if (!found) {
//             break;
//         }  
//     }
//    if(cnt==n){
//      cout << "Deadlock is not found\n";
//     cout << "Safe seq is: ";
//     for (int i = 0; i < seq.size(); i++) {
//         cout <<"p" <<seq[i] << " ";
//     }
//     cout << endl;
//    }else cout<<"Deadlock is found\n";
   

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cout << "Enter total number of processes: ";
    cin >> n;

    cout << "Enter total number of resources: ";
    cin >> r;

    // Allocation Matrix
    int allocation[n][r];
    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "For Process P" << i << ": ";
        for (int j = 0; j < r; j++) {
            cin >> allocation[i][j];
        }
    }

    // Maximum Need Matrix
    int max_need[n][r];
    cout << "Enter Max Need Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "For Process P" << i << ": ";
        for (int j = 0; j < r; j++) {
            cin >> max_need[i][j];
        }
    }

    // Available Resources
    vector<int> available(r);
    cout << "Enter Available Resources: ";
    for (int i = 0; i < r; i++) {
        cin >> available[i];
    }

    // Calculate the Need Matrix
    int need[n][r];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }

    vector<bool> finished(n, false); // track finished processes
    vector<int> safe_sequence;       // store the safe sequence
    int completed = 0;
    // Safety Algorithm
    while (completed < n) {
        bool found_process = false;

        for (int i = 0; i < n; i++) {
            if (!finished[i]) {
                bool can_allocate = true;

                // Check if resources can be allocated
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > available[j]) {
                        can_allocate = false;
                        break;
                    }
                }

                // If yes, simulate resource allocation
                if (can_allocate) {
                    for (int j = 0; j < r; j++) {
                        available[j] += allocation[i][j];
                        cout<<available[j]<<" ";
                    }
                    finished[i] = true;
                    safe_sequence.push_back(i);
                    completed++;
                    found_process = true;
                }
            }
        }

        if (!found_process) {
            break; // No safe process found in this round → deadlock
        }
    }

    // Final Output
    if (completed == n) {
        cout << "System is in a safe state.\nSafe Sequence: ";
        for (int i = 0; i < safe_sequence.size(); i++) {
            cout << "P" << safe_sequence[i];
            if (i != safe_sequence.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "Deadlock detected! No safe sequence exists.\n";
    }

    return 0;
}
