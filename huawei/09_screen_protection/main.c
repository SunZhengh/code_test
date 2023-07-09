/*
 * @Author: hox hox@outlook.com
 * @Date: 2023-07-05 10:51:22
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 15:49:40
 * @FilePath: \ctest\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://dream.blog.csdn.net/article/details/131130161
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
#define DIST(x,max)         ((x > max) ? (2*max - x) : x)

#define SCREEN_HIGH         (600)
#define SCREEN_WIDTH        (800)
#define SPEED               (1)
#define LOGO_LENGTH         (50)
#define LOGO_HIGH           (25)

int main(void)
{
    u32 width_distence = SCREEN_WIDTH - LOGO_LENGTH;
    u32 high_distence = SCREEN_HIGH - LOGO_HIGH;
    u32 t = 0, s_x = 0, s_y = 0;
    scanf("%d %d %d", &s_x, &s_y, &t);

    u32 loss_x = (t + s_x) % (width_distence * 2);
    u32 loss_y = (t + s_y) % (high_distence * 2);

    u32 x = DIST(loss_x, width_distence);
    u32 y = DIST(loss_y, high_distence);

    printf("%d %d\r\n", x, y);
    return 0;
}

