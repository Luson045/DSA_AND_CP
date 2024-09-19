#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long max_subarray_sum(const vector<int>& arr){
    long long max_ending_here = 0, max_so_far = 0;
    for(int num : arr){
        max_ending_here = max(0LL, max_ending_here + num);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int min_operations(vector<int>& arr) {
    long long max_sum = max_subarray_sum(arr);
    if (max_sum == 0) return 0;
    int n = arr.size();
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    int operations = 0;
    long long current_max = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            long long subarray_sum = prefix_sum[j + 1] - prefix_sum[i];
            if (subarray_sum == max_sum) {
                for (int k = 0; k < i; ++k) {
                    if (arr[k] != 0) ++operations;
                }
                for (int k = j + 1; k < n; ++k) {
                    if (arr[k] != 0) ++operations;
                }
                return operations;
            }
        }
    }
    return operations;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<int> array(N);
        for (int i = 0; i < N; ++i) {
            cin >> array[i];
        }
        cout << min_operations(array) << "\n";
    }

    return 0;
}
