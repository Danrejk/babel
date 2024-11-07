#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <chrono>

using namespace std;

template <typename T>
void bubblesort_for_for_index(T *arr, size_t n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void bubblesort_while_for_index(T* arr, size_t n) {
    int i = 0;
    while (i < n) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        i++;
    }
}

template <typename T>
void bubblesort_while_shorten_for_index(T* arr, size_t n) {
    int i = 0;
    while (i < n) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        i++;
    }
}

template <typename T>
void bubblesort_for_for_pointer(T* arr, size_t n) {
    int* w1, * w2, temp;
    for (int i = 0; i < n; i++) {
        w1 = arr;
        w2 = w1 + 1;
        for (int j = 0; j < n - 1; j++) {
            if (*w1 > *w2) {
                int temp = *w1;
                *w1 = *w2;
                *w2 = temp;
            }
            w1++;
            w2++;
        }
    }
}

template <typename T>
void bubblesort_while_for_pointer(T* arr, size_t n) {
	int* w1, * w2, temp;
	int i = 0;
    while (i < n) {
		w1 = arr;
		w2 = w1 + 1;
        for (int j = 0; j < n - 1; j++) {
            if (*w1 > *w2) {
				int temp = *w1;
				*w1 = *w2;
				*w2 = temp;
			}
			w1++;
			w2++;
		}
		i++;
	}
}

template <typename T>
void bubblesort_while_shorten_for_pointer(T* arr, size_t n) {
	int* w1, * w2, temp;
	int i = 0;
    while (i < n) {
		w1 = arr;
		w2 = w1 + 1;
        for (int j = 0; j < n - 1 - i; j++) {
            if (*w1 > *w2) {
				int temp = *w1;
				*w1 = *w2;
				*w2 = temp;
			}
			w1++;
			w2++;
		}
		i++;
	}
}

template <typename T>
bool is_sorted(T* arr, size_t n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool test_sort_method(T *temp, size_t n, void (*sort_method)(int*, size_t)) {
    int * arr = new int[n];
    copy(temp, temp + n, arr);
	sort_method(arr, n);
    if (is_sorted(arr, n)) {
		return true;
	}
    else {
		return false;
	}
}

int main() {
    srand(time(0));

    // make array
    int const arrLen = 10;
    int arr[arrLen];
    for (int i = 0; i < arrLen; i++) {
		arr[i] = rand() % 100;
	}

    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    // list array
    cout << "Array: ";
    for (int i = 0; i < arrLen; i++) {
        cout << arr[i] << ",";
    }
    cout << "\n";

    cout << "bubblesort for for index: " << test_sort_method(arr, n, bubblesort_for_for_index) << "\n";
    cout << "bubblesort while for index: " << test_sort_method(arr, n, bubblesort_while_for_index) << "\n";
    cout << "bubblesort while shorten for index: " << test_sort_method(arr, n, bubblesort_while_shorten_for_index) << "\n";
    cout << "bubblesort for for pointer: " << test_sort_method(arr, n, bubblesort_for_for_pointer) << "\n";
    cout << "bubblesort while for pointer: " << test_sort_method(arr, n, bubblesort_while_for_pointer) << "\n";
    cout << "bubblesort while shorten for pointer: " << test_sort_method(arr, n, bubblesort_while_shorten_for_pointer) << "\n";

    return 0;
}