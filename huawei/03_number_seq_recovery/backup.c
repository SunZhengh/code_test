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

void updateCharMap(char *num, int length, int *charMap, int isAdd) {
    for (int i = 0; i < length; i++) {
        char c = num[i];
        charMap[c] += isAdd ? 1 : -1;
    }
}

int compareCharMaps(const int *map1, const int *map2) {
    for (int i = 0; i < 256; i++) {
        if (map1[i] != map2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char inputStr[1001];
    int length;

    scanf("%s", inputStr);
    scanf("%d", &length);

    int originCharMap[256] = {0};
    int windowCharMap[256] = {0};

    int inputStrLength = strlen(inputStr);
    for (int i = 0; i < inputStrLength; i++) {
        char c = inputStr[i];
        originCharMap[(unsigned char)c]++;
    }

    for (int i = 1; i <= length; i++) {
        char num[5];
        sprintf(num, "%d", i);
        updateCharMap(num, strlen(num), windowCharMap, 1);
    }

    if (compareCharMaps(originCharMap, windowCharMap)) {
        printf("0\n");
        return 0;
    }

    for (int i = 2; i <= 1000 - length + 1; i++) {
        char remove[5];
        sprintf(remove, "%d", i - 1);
        updateCharMap(remove, strlen(remove), windowCharMap, 0);

        char add[5];
        sprintf(add, "%d", i + length - 1);
        updateCharMap(add, strlen(add), windowCharMap, 1);

        if (compareCharMaps(originCharMap, windowCharMap)) {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}


