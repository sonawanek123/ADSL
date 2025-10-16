#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int minWorkPerDay(vector<int>& task, int D) {
    int N = task.size();
    int totalWork = accumulate(task.begin(), task.end(), 0);
    int maxTask = *max_element(task.begin(), task.end());
    int dailyLimit = maxTask; // Start with the largest single task

    // Greedily increase the limit until all tasks fit in D days
    while (true) {
        int days = 1, currentWork = 0;
        for (int t : task) {
            if (currentWork + t <= dailyLimit) {
                currentWork += t;
            } else {
                days++;
                currentWork = t;
            }
        }
        if (days <= D) break;  // Found the minimum daily work
        dailyLimit++;
    }
    return dailyLimit;
}

int main() {
    vector<int> task = {3, 2, 4, 7, 2, 5};
    int D = 4;

    cout << "Minimum work per day required: " 
         << minWorkPerDay(task, D) << endl;

    return 0;
}
