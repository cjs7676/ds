#include<iostream>
#include<conio.h>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minindex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
    }
}

int main() {
    
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    selection_sort(arr, n);
    
    std::cout << "selection sort: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    
    return 0;
}
