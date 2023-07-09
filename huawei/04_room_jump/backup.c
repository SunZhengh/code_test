/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 14:37:19
 * @LastEditors: hox sunzhenghao@qq.com
 * @LastEditTime: 2023-07-06 16:40:35
 * @FilePath: \ctest\code_test\huawei\02_most_close_time\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int count = 9;
int minIndexSum = INT_MAX;
int* resList = NULL;

void printResult();

void dfs(const int* nums, int remaining, int* combination, int* indices, int index) {
    if (remaining == 0) {
        int total = 0;
        int indexSumTemp = 0;
        for (int i = 0; i < 3; i++) {
            total += combination[i];        // 计算组合的元素总和
            indexSumTemp += indices[i];      // 计算索引总和
        }
        if (total == count && indexSumTemp < minIndexSum) {   // 满足条件时更新结果
            minIndexSum = indexSumTemp;
            if (resList) {
                free(resList);
            }
            resList = (int*)malloc(3 * sizeof(int));
            for (int i = 0; i < 3; i++) {
                resList[i] = combination[i];
            }
        }
    } else {
        for (int i = index; i < 6; i++) {
            combination[3 - remaining] = nums[i];    // 添加元素到组合
            indices[3 - remaining] = i;              // 添加索引
            dfs(nums, remaining - 1, combination, indices, i + 1);   // 递归调用
        }
    }
}

void printResult() {
    printf("[");
    for (int i = 0; i < 3; i++) {
        printf("%d", resList[i]);
        if (i != 2) {
            printf(",");
        }
    }
    printf("]\n");
}

int main() {
    int nums[] = {1, 5, 2, 0, 2, 4};
    int combination[3];
    int indices[3];
    dfs(nums, 3, combination, indices, 0);

    printResult();

    if (resList) {
        free(resList);
    }

    return 0;
}

