void countingSort(std::vector<int>& arr, int exp) {
    const int n = arr.size();
    std::vector<int> output(n, 0);
    std::vector<int> count(10, 0);

    // Count occurrences of digits at the current place value
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // Modify count array to store the position of elements
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr) {
    const int maxNum = 1000000000-1;

    // Perform counting sort for every digit
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}
