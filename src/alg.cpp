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
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == value) count++;
        if ((arr[left] + arr[right]) < value) left++;
        else right--;
    }
    return count;
}
 int binarySearch(int* arr, int el, int len) {
     int low = 0, high = len-1, count=0, i;
     while (low <= high) {
         int mid = low + (high - low) / 2;
         if (arr[mid] == el) {
             count++;
             i = mid + 1;
             while (i < len && arr[i] == el) {
                 count++;
                 i++;
             }
             i = mid - 1;
             while (i >= 0 && arr[i] == el) {
                 count++;
                 i--;
             }
             return count;
         }
         if (arr[mid] < el)
             low = mid + 1;
         else
             high = mid - 1;
     }
     return 0;
 }
int countPairs3(int* arr, int len, int value) {
    int count = 0, i=0, el;
    while (i<len) { 
        el = value - arr[i];
        count += binarySearch(arr, el, len);
        i++;    
    }
    return count/2;
}
