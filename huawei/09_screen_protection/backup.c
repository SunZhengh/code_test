/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 14:37:19
 * @LastEditors: hox sunzhenghao@qq.com
 * @LastEditTime: 2023-07-06 16:40:35
 * @FilePath: \ctest\code_test\huawei\02_most_close_time\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>

int main() {
    int x, y, t;
    scanf("%d %d %d", &x, &y, &t);

    int x_dir = 1;
    int y_dir = 1;
    int width = 800;
    int height = 600;
    int xBoundary = width - 50;
    int yBoundary = height - 25;

    for (int i = 0; i < t; i++) {
        x += x_dir;
        y += y_dir;

        if (x == 0 || x == xBoundary) {
            x_dir *= -1;
        }
        if (y == 0 || y == yBoundary) {
            y_dir *= -1;
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}

