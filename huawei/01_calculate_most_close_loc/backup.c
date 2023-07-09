/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 12:31:10
 * @LastEditors: hox sunzhenghao@qq.com
 * @LastEditTime: 2023-07-06 14:05:56
 * @FilePath: \ctest\code_test\huawei\01_calculate_most_close_loc\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int compare(const void* a, const void* b) {
    return (*(int*)a - * (int*)b);
}
int findMedian(int* nums, int size) {
    int* sortedNums = (int*)malloc(size * sizeof(int));
    memcpy(sortedNums, nums, size * sizeof(int));
    qsort(sortedNums, size, sizeof(int), compare);
    int mid = sortedNums[size / 2];
    free(sortedNums);
    return mid;
}



int main() {
    char input[] = "[1,2,3,3],2";
    int nums[100];
    int N = 0;
    int K = 0;
    int i = 0;
    int j = 0;
    int mid = 0;
    int min = INT_MAX;
    int index = -1;

    sscanf(input, "[%[^]]],%d", input, &K);
    char* token = strtok(input, ",");
    while (token != NULL) {
        nums[N++] = atoi(token);
        token = strtok(NULL, ",");
    }

    mid = findMedian(nums, N);

    for (i = 0; i <= N - K; i++) {
        int count = nums[i];
        for (j = i + 1; j < i + K; j++) {
            count -= nums[j];
        }
        int distance = abs(count - mid);
        if (distance < min) {
            min = distance;
            index = i;
        }
    }

    printf("%d\n", index);

    return 0;
}

