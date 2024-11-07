#include <iostream>

void bubble_sort_for_for_index(int n, int* Tab) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (Tab[j] > Tab[j+1]) {
                int tmp = Tab[j + 1];
                Tab[j + 1] = Tab[j];
                Tab[j] = tmp;
            }
        }
    }
}

void bubble_sort_while_for_index(int n, int* Tab) {
    bool zamiana = true;
    while(zamiana) {
        zamiana = false;
        for (int j = 0; j < n - 1; j++) {
            if (Tab[j] > Tab[j + 1]) {
                int tmp = Tab[j + 1];
                Tab[j + 1] = Tab[j];
                Tab[j] = tmp;
                zamiana = true;
            }
        }
    }
}


void bubble_sort_while_shorter_for_index(int n, int* Tab) {
    bool zamiana = true;
    while (zamiana) {
        zamiana = false;
        for (int j = 0; j < n - 1; j++) {
            if (Tab[j] > Tab[j + 1]) {
                int tmp = Tab[j + 1];
                Tab[j + 1] = Tab[j];
                Tab[j] = tmp;
                zamiana = true;
            }

        }
    }
}
int main()
{
    int list[10] = { 10, 9, 8, 6, 7,8, 9, 3,2, 1 };
    bubble_sort_while_for_index(10, list);
    for (int i = 0; i < 10; i++) {
        std::cout << list[i] << std::endl;
    }
    
}
