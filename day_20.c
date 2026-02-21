/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero*/
#include <stdio.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefix_sum = 0;
    long long count = 0;

   
    long long sum[MAX];
    long long freq[MAX];
    int size = 0;

    // insert prefix sum = 0 initially
    sum[size] = 0;
    freq[size] = 1;
    size++;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        int found = -1;

        // search prefix_sum in stored sums
        for(int j = 0; j < size; j++) {
            if(sum[j] == prefix_sum) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            count += freq[found];
            freq[found]++;
        } else {
            sum[size] = prefix_sum;
            freq[size] = 1;
            size++;
        }
    }

    printf("%lld\n", count);
    return 0;
}