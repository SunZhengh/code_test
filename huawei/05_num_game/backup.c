/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 14:37:19
 * @LastEditors: hox sunzhenghao@qq.com
 * @LastEditTime: 2023-07-06 16:40:35
 * @FilePath: \ctest\code_test\huawei\02_most_close_time\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main() {
    while (1) {
        int n, m;
        if (scanf("%d %d", &n, &m) != 2)
            break;

        int ints[MAX_SIZE];
        for (int i = 0; i < n; i++) {
            scanf("%d", &ints[i]);
        }

        int preSum = 0;
        bool isTrue = false;
        int remainders[MAX_SIZE] = {0};
        for (int i = 0; i < n; i++) {
            preSum = (preSum + ints[i]) % m;
            if (remainders[preSum] == 1) {
                isTrue = true;
                break;
            }
            remainders[preSum] = 1;
        }

        printf("%d\n", isTrue ? 1 : 0);
    }

    return 0;
}


