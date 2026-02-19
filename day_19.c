/*Problem: Given an array of integers, find two elements whose sum is closest to zero.
 Input: - First line: integer n - Second line: n space-separated integers
 Output: - Print the pair of elements whose sum is closest to zero*/
#include <stdio.h>
#include <stdlib.h>

// function for sorting (used by qsort)
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Step 1: sort array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int min_sum = 1000000000;
    int a, b;

    // Step 2: two pointer search
    while(left < right)
    {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            a = arr[left];
            b = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    // Output
    printf("%d %d", a, b);

    return 0;
}
