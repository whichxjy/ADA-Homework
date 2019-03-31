#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        arr[i] = num;
    }

    int* L = new int[N];
    L[0] = 1;

    for (int i = 1; i < N; i++) {
        L[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && L[j] + 1 > L[i]) {
                L[i] = L[j] + 1;
            }
        }
    }

    int maxLen = 1, maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (L[i] > maxLen) {
            maxLen = L[i];
            maxIndex = i;
        }
        else if (L[i] == maxLen && arr[i] < arr[maxIndex]) {
            maxIndex = i;
        }
    }

    std::cout << maxLen << " " << arr[maxIndex] << std::endl;

    delete[] arr;
    delete[] L;
}