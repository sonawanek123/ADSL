#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& arr) {
    int profit = 0;
    int N = arr.size();

    for (int i = 1; i < N; i++) {
        if (arr[i] > arr[i - 1]) {
            profit += arr[i] - arr[i - 1];
        }
    }
    return profit;
}

int main() {
    vector<int> arr = {1, 5, 3, 8, 12};
    cout << "Maximum Profit: " << maxProfit(arr) << endl;
    return 0;
}
