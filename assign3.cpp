#include <iostream>
using namespace std;

// Function to count trailing zeroes in x!
int countTrailingZeroes(long long x) {
    int count = 0;
    while (x >= 5) {
        x /= 5;
        count += x;
    }
    return count;
}

// Function to find the smallest number with at least n trailing zeroes
long long findNumber(int n) {
    long long low = 0, high = 5LL * n, ans = -1;
    while (low <= high) {
        long long mid = (low + high) / 2;
        int zeros = countTrailingZeroes(mid);
        if (zeros >= n) {
            ans = mid;
            high = mid - 1; // look for smaller number
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Smallest number with at least " << n << " trailing zeroes in factorial is: ";
    cout << findNumber(n) << endl;
    return 0;
}
