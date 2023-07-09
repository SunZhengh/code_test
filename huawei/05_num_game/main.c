/*
 * @Author: hox hox@outlook.com
 * @Date: 2023-07-05 10:51:22
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 11:42:01
 * @FilePath: \ctest\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://dream.blog.csdn.net/article/details/131232619
6 7
2 12 6 3 5 5
10 11
1 1 1 1 1 1 1 1 1 1

1
0


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

#define MAX_NUM             (1000)

u32 get_sum(int *data, u32 base, u32 count)
{
    u32 i = 0, res = 0;
    for (i = 0; i < count; i++)
    {
        res += data[base + i];
    }
    return res;
}

int main(void)
{
    u32 count = 0, target = 0, i = 0, base = 0, sum = 0;
    int data[MAX_NUM] = {0};
    scanf("%d %d", &count, &target);
    for (i = 0; i < count; i++)
    {
        scanf("%d", &data[i]);
    }

    for (base = 0; base < count; base++)
    {
        for (i = 1; i < (count - base); i++)
        {
            sum = get_sum(data, base, i);
            if (0 == (sum % target))
            {
                printf("%d", 1);
                return 0;
            }
        }
        
    }
    printf("%d", 0);
    return 0;
}

