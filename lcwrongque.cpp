class Solution {
public:
    int getpivot(vector<int>& arr, int n){
        int s = 0;
        int e = n - 1;
        while(s < e) {
            int mid = s + (e - s) / 2;
            
            // Check if the pivot is on the right side
            if (arr[mid] > arr[e]) {
                s = mid + 1;
            }
            else {
                e = mid;
            }
        }
        return s;
    }

    int binarySearch(vector<int>& arr, int s, int e, int key){
        int start = s;
        int end = e;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (arr[mid] == key) {
                return mid;
            }
            if (key > arr[mid]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;
    }

    int Search(vector<int>& arr, int n, int k) {
        int pivot = getpivot(arr, n);
        
        if (k >= arr[pivot] && k <= arr[n - 1]) {
            return binarySearch(arr, pivot, n - 1, k);
        }
        else {
            return binarySearch(arr, 0, pivot - 1, k);
        }
    }
};
