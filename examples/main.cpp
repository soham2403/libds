#include <bits/stdc++.h>
using namespace std;
#define MAX 10

void printVector(vector<int> &nums) {
    for (auto it : nums) {
        cout << it << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> nums = {1, 2, 4, 5, 6};
    printVector(nums);
    return 0;
}
