/*
 * @Author: hox hox@outlook.com
 * @Date: 2023-07-05 10:51:22
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 11:30:28
 * @FilePath: \ctest\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://dream.blog.csdn.net/article/details/131283882
 9
[1,4,5,2,0,2]

12
[-1,2,4,9]

9
[1,5,2,0,2,4]


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

#define MAX_COUNT           (10000)
#define MAX_STEP            (10000)
#define STEP_LIMIT          (100000)


typedef struct
{
    u32 first;
    u32 second;
    u32 third;
    u32 min;
}step_t;

u32 main(void)
{
    u32 y = 0, z = 0, x = 0, order = 0;
    u32 target = 0, count = 0;
    s32 *steps = (s32 *)malloc(MAX_STEP * sizeof(s32));
    char *num = NULL;
    char *raw = (char *)malloc(MAX_STEP * 8);
    step_t res = {0};
    res.min = U32_MASK;

    if ((NULL == steps) || (NULL == raw))
    {
        printf("mem fail\r\n");
    }
    memset(steps, 0x0, MAX_STEP * sizeof(s32));

    scanf("%d", &target);
    scanf("%s", raw);
    sscanf(raw, "[%[^]]", raw);
    printf("%s\r\n", raw);
    num = strtok(raw, ",");
    while(NULL != num)
    {
        steps[count++] = atoi(num);
        num = strtok(NULL, ",");
    }

    for (x = 0; x < count; x++)
    {
        for (y = (X + 1); y < count; y++)
        {
            for (z = (y + 1); z < count; z++)
            {
                if (target == (steps[x] + steps[y] + steps[z]))
                {
                    order = x + y + z;
                    if (res.min > order)
                    {
                        res.min = order;
                        res.first = x;
                        res.second = y;
                        res.third = z;
                    }
                }
            }
        }
    }

    printf("[%d,%d,%d]\r\n", steps[res.first], steps[res.second], steps[res.third]);
    free(raw);
    free(steps);
    return 0;
}
