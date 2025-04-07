#include <bits/stdc++.h> // 匯入所有標準函式庫（常用於競賽）
using namespace std;

int main() {
    int n;
    cin >> n; // 讀入數列長度

    int a[n];              // 原始數列
    vector<int> temp;      // 用來記錄 LIS 的中間狀態

    for (int i = 0; i < n; i++) {
        cin >> a[i]; // 讀入數列中的每個數字
    }

    temp.push_back(a[0]); // 初始化：把第一個數放進 temp

    // 從第二個數開始處理
    for (int i = 1; i < n; i++) {
        if (a[i] > temp.back()) {
            // 如果 a[i] 比目前 LIS 的最後一個數還大，表示可以延長 LIS
            temp.push_back(a[i]);
        } else {
            // 否則，在 temp 中找第一個大於等於 a[i] 的數，將它取代為 a[i]
            // 這樣可以保證相同長度的 LIS，其結尾數越小越好，方便未來延長
            *lower_bound(temp.begin(), temp.end(), a[i]) = a[i];
        }
    }

    // 輸出 LIS 的長度（temp 的大小就是最長遞增子序列長度）
    cout << temp.size();
}
