#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;


    int k = *max_element(arr.begin(), arr.end());


    vector<int> count(k + 1, 0);


    for (int num : arr) {
        count[num]++;
    }


    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }


    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }


    arr = output;
}


int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
