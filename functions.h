#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int dot(const int *arr1, const int *arr2) {
    int result = 0;
    int size = sizeof(arr1) / sizeof(arr1[0]);

    for (int i = 0; i < size; i++) {
        result += arr1[i] * arr2[i];
    }

    return result;
}

#endif