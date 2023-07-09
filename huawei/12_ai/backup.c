/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 14:37:19
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 16:40:43
 * @FilePath: \ctest\code_test\huawei\02_most_close_time\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int x;
    int y;
    int r;
} Light;

int compareByY(const void* a, const void* b) {
    const Light* lightA = (const Light*)a;
    const Light* lightB = (const Light*)b;
    return lightA->y - lightB->y;
}

int compareByX(const void* a, const void* b) {
    const Light* lightA = (const Light*)a;
    const Light* lightB = (const Light*)b;
    return lightA->x - lightB->x;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    Light* lights = (Light*)malloc(n * sizeof(Light));
    for (int i = 0; i < n; i++) {
        int id, x1, y1, x2, y2;
        scanf("%d %d %d %d %d", &id, &x1, &y1, &x2, &y2);
        int x = (x1 + x2) / 2;
        int y = (y1 + y2) / 2;
        int r = (x2 - x1) / 2;
        lights[i].id = id;
        lights[i].x = x;
        lights[i].y = y;
        lights[i].r = r;
    }

    qsort(lights, n, sizeof(Light), compareByY);

    char* result = (char*)malloc(n * 4 * sizeof(char));
    int resultIndex = 0;
    int rowStartIndex = 0;
    for (int i = 1; i < n; i++) {
        if (lights[i].y - lights[rowStartIndex].y > lights[rowStartIndex].r) {
            qsort(lights + rowStartIndex, i - rowStartIndex, sizeof(Light), compareByX);
            for (int j = rowStartIndex; j < i; j++) {
                resultIndex += sprintf(result + resultIndex, "%d ", lights[j].id);
            }
            rowStartIndex = i;
        }
    }

    qsort(lights + rowStartIndex, n - rowStartIndex, sizeof(Light), compareByX);
    for (int i = rowStartIndex; i < n; i++) {
        resultIndex += sprintf(result + resultIndex, "%d ", lights[i].id);
    }

    printf("%s\n", result);

    free(lights);
    free(result);

    return 0;
}







