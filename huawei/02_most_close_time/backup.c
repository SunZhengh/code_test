/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 14:37:19
 * @LastEditors: hox sunzhenghao@qq.com
 * @LastEditTime: 2023-07-06 14:37:50
 * @FilePath: \ctest\code_test\huawei\02_most_close_time\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>

void solveMethod(char *time, char *result) {
    int nums[6] = {0};
    int h, m;
    int lst[1000] = {0};
    int lstSize = 0;

    // 收集时间字符串中的数字字符
    int i = 0, j = 0;
    while (time[i]) {
        if (time[i] != ':') {
            nums[j++] = time[i] - '0';
        }
        i++;
    }

    // 分离出小时和分钟部分
    sscanf(time, "%d:%d", &h, &m);

    // 生成所有可能的有效时间组合
    for (int i = 0; i < j; i++) {
        for (int k = 0; k < j; k++) {
            if (nums[i] <= 5) {
                lst[lstSize++] = nums[i] * 10 + nums[k];
            }
        }
    }

    // 按升序排序
    for (int i = 0; i < lstSize - 1; i++) {
        for (int j = 0; j < lstSize - i - 1; j++) {
            if (lst[j] > lst[j + 1]) {
                int temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
            }
        }
    }

    // 查找下一个大于给定分钟数的时间组合
    for (int i = 0; i < lstSize; i++) {
        if (lst[i] <= m) {
            continue;
        }
        sprintf(result, "%02d:%02d", h, lst[i]);
        return;
    }

    // 如果小时不是23，则查找下一个大于给定小时数的时间组合
    if (h != 23) {
        for (int i = 0; i < lstSize; i++) {
            if (lst[i] <= h) {
                continue;
            }
            if (lst[i] <= 23) {
                sprintf(result, "%02d:%02d", lst[i], lst[0]);
                return;
            }
        }
    }

    sprintf(result, "%02d:%02d", lst[0], lst[0]);
}

int main() {
    char time[10];
    scanf("%s", time);
    char result[10];
    solveMethod(time, result);
    printf("%s\n", result);

    return 0;
}

