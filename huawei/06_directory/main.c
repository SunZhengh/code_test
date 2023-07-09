/*
 * @Author: hox hox@outlook.com
 * @Date: 2023-07-05 10:51:22
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 11:55:29
 * @FilePath: \ctest\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://dream.blog.csdn.net/article/details/131205223

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

int main(void)
{
    u32 count = 0, i = 0, slen = 0, tlen = 0;
    char *s = (char *)malloc(32);
    char *direc = (char *)malloc(32);
    scanf("%s", s);
    scanf("%d", &count);
    slen = strlen(s);
    for (i = 0; i < count; i++)
    {
        scanf("%s", direc);
        tlen = strlen(direc);
        if (slen > tlen)
        {
            continue;
        }
        if (0 == strncmp(s, direc, slen))
        {
            printf("%s\r\n", direc);
        }
    }
    return 0;
}

