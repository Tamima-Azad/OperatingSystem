// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to find the page to replace
// int findPageToReplace(const vector<int>& frames, const vector<int>& pages, int currentIndex) {
//     int farthestIndex = -1, replaceIndex = -1;

//     for (int i = 0; i < frames.size(); i++) {
//         int j;
//         for (j = currentIndex + 1; j < pages.size(); j++) {
//             if (frames[i] == pages[j]) {
//                 if (j > farthestIndex) {
//                     farthestIndex = j;
//                     replaceIndex = i;
//                 }
//                 break;
//             }
//         }
//         if (j == pages.size()) {
//             return i; // Page not used in the future
//         }
//     }
//     return (replaceIndex == -1) ? 0 : replaceIndex;
// }

// // Function to simulate the Optimal Page Replacement algorithm
// void optimalPageReplacement(const vector<int>& pages, int frameCount) {
//     vector<int> frames; // Stores the pages in memory
//     int pageFaults = 0;

//     for (int i = 0; i < pages.size(); i++) {
//         // Check if the page is already in memory (page hit)
//         bool pageHit = false;
//         for (int frame : frames) {
//             if (frame == pages[i]) {
//                 pageHit = true;
//                 break;
//             }
//         }

//         if (!pageHit) {
//             // Page fault occurs
//             pageFaults++;
//             if (frames.size() < frameCount) {
//                 // Add the page if there is space
//                 frames.push_back(pages[i]);
//             } else {
//                 // Replace a page using the optimal strategy
//                 int replaceIndex = findPageToReplace(frames, pages, i);
//                 frames[replaceIndex] = pages[i];
//             }
//         }
//     }

//     cout << "Total Page Faults: " << pageFaults << endl;
// }

// int main() {
//     int n, frameCount;
//    // cout << "Enter the number of pages: ";
//     cin >> n;

//     vector<int> pages(n);
//    // cout << "Enter the page reference string: ";
//     for (int i = 0; i < n; i++) {
//         cin >> pages[i];
//     }

//    // cout << "Enter the number of frames: ";
//     cin >> frameCount;

//     optimalPageReplacement(pages, frameCount);

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
    int faults = 0, hits = 0;

    for (int i = 0; i < n; ++i) {
        bool hit = false;
        if (i > 0)
            for (int j = 0; j < f; ++j)
                mat[j][i] = mat[j][i - 1], hit |= (mat[j][i] == a[i]);

        if (!hit) {
            faults++;
            int idx = -1, farthest = -1;

            for (int j = 0; j < f; ++j) {
                int next = n;
                for (int k = i + 1; k < n; ++k)
                    if (mat[j][i] == a[k]) { next = k; break; }
                if (next > farthest)
                    farthest = next, idx = j;
            }

            if (i < f && mat[i][i] == -1) idx = i;
            mat[idx][i] = a[i];
        } else hits++;
    }

    for (auto &row : mat) {
        for (int x : row) cout << x << ' ';
        cout << '\n';
    }
    cout << "Page Faults: " << faults << '\n';
    cout << "Page Hits: " << hits << '\n';
}