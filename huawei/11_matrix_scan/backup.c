/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 14:37:19
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 16:40:43
 * @FilePath: \ctest\code_test\huawei\02_most_close_time\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int rm[r][c];
    int cm[c][r];

    int rt = 0;
    int rz = c / 2;
    int rzr[r];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int in;
            scanf("%d", &in);
            rm[i][j] = in;
            cm[j][i] = in;
            if (in == 0) {
                rzr[i]++;
            }
        }
        if (rzr[i] >= rz) {
            rt++;
        }
    }

    printf("%d\n", rt);

    int ct = 0;
    rz = r / 2;
    int czr[c];

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (cm[i][j] == 0) {
                czr[i]++;
            }
        }
        if (czr[i] >= rz) {
            ct++;
        }
    }

    printf("%d\n", ct);

    return 0;
}





