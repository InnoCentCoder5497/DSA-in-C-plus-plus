#include<iostream>
#define N_INF -9999
using namespace std;

struct sums {
    int left;
    int right;
    int lrsum;
};

sums find_max_crossing_subarray(int[], int, int, int);
sums find_maximum_subarray(int[], int, int);

int main() {
    int arr[17] = {100, 113, 110, 85, 105, 
                    102, 86, 63, 81, 101, 94, 
                    106, 101, 79, 94, 90, 97};

    int change[17];
    int i;

    sums check;

    change[0] = 0;

    for(i = 1; i < 17; i++){
        change[i] = arr[i] - arr[i-1];
    }

    check = find_maximum_subarray(change, 1, 17);

    cout << "Maximum subarray : " << endl;
    cout << "Left index : " << check.left << endl;
    cout << "Right index : " << check.right << endl;
    cout << "Total Sum : " << check.lrsum << endl;

    return 0;
}

sums find_maximum_subarray(int arr[], int low, int high){
    sums left_s;
    sums right_s;
    sums cross_s;
    sums r;
    int mid;

    if(high == low){
        r.left = low;
        r.right = high;
        r.lrsum = arr[low];
        return r;
    }
    else{
        mid = (low + high) / 2;
        left_s = find_maximum_subarray(arr, low, mid);
        right_s = find_maximum_subarray(arr, mid + 1, high);
        cross_s = find_max_crossing_subarray(arr, low, mid, high);

        if(left_s.lrsum >= right_s.lrsum && left_s.lrsum >= cross_s.lrsum)
            return left_s;
        else if(right_s.lrsum >= left_s.lrsum && right_s.lrsum >= cross_s.lrsum)
            return right_s;
        else
            return cross_s;
    }

}


sums find_max_crossing_subarray(int arr[], int low, int mid, int high){
    int left_sum = N_INF;
    int right_sum = N_INF;
    int max_left;
    int max_right;
    int sum;
    int i, j;
    
    sums r;

    sum = 0;
    for(i = mid; i >= low; i--){
        sum = sum + arr[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for(j = mid + 1; j <= high; j++){
        sum += arr[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    r.left = max_left;
    r.right = max_right;
    r.lrsum = left_sum + right_sum;
    return r;
}