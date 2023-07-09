/*
 * @Author: hox 1510214118@qq.com
 * @Date: 2023-07-09 15:54:10
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 17:05:00
 * @FilePath: \code_test\huawei\10_shudayan\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
5 3
-1 0 1
0 0 0
-1 0 0
0 -1 0
0 0 0
10

 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned char bool;
typedef int s32;
typedef short s16;
typedef char s8;

#define U32_MASK            (0xFFFFFFFF)
#define false               (0)
#define true                (1)



int main() {
    u32 m = 0, n = 0, i = 0, j = 0;
    scanf("%d %d", &m, &n);
    s32 mat[100][100] = {0};
    u8 cnt_x[100] = {0};
    u8 cnt_y[100] = {0};
    u32 x_num = 0, y_num = 0;


    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
            if (0 == mat[i][j])
            {
                cnt_x[i]++;
                cnt_y[j]++;
            }
        }
    }

    for (i = 0; i < m; i++)
    {
        if ((m/2) < cnt_x[i])
        {
            x_num++;
        }
    }
    for (j = 0; j < n; j++)
    {
        if ((n/2) < cnt_y[j])
        {
            y_num++;
        }
    }

    printf("%d %d", x_num, y_num);

    return 0;
}

