// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0, right = len - 1;
    while (arr[right] > value) {
        right--;
    }
    for (int i=0; i< right; i++) {
        for (int j = right; j > i; j--) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return count;
}
int binarySearch(int* arr, int el, int len) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == el) {
            count++;
            int temp = mid;
            while (temp > left && arr[temp - 1] == el) {
                count++;
                temp--;
            }
            temp = mid;
            while (temp < right && arr[temp + 1] == el) {
                count--;
                temp++;
            }
            return count;
        } else if (arr[mid] < el) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0, i=0, el;
    while (i<len) {
        el = value - arr[i];
        count += binarySearch(arr, el, len);
        i++;
    }
    return count;
}
