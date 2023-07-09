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
#include <string.h>

int main() {
    char target[100];
    scanf("%s", target);
    int size;
    scanf("%d", &size);
    int flag = 1;
    int targetLength = strlen(target);

    for (int i = 0; i < size; i++) {
        char source[100];
        scanf("%s", source);
        if (strlen(source) >= targetLength && strncmp(source, target, targetLength) == 0) {
            printf("%s\n", source);
            flag = 0;
        }
    }

    if (flag) {
        printf("-1\n");
    }

    return 0;
}




