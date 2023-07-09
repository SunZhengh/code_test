/*
 * @Author: hox hox@outlook.com
 * @Date: 2023-07-05 10:51:22
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 13:03:40
 * @FilePath: \ctest\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://dream.blog.csdn.net/article/details/131138608
4,5
10,6,9,7,6
9,10,6,7,5
8,10,6,5,10
9,10,8,4,9

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

typedef struct
{
    u32 grade;
    u32 id;
    u32 *grades;
}rate_t;

s32 juder = 0, xx = 0;

int check_seq(rate_t *a, rate_t *b, u32 jud)
{
    u32 i = 0, res = 0;
    for (i = 0; i < jud; i++)
    {
        res += (a->grades[i] > b->grades[i]);
    }
    return (res > (jud/2));
}

int cmp(const void *a, const void *b)
{
    int res = (((rate_t *)b)->grade - ((rate_t *)a)->grade);
    if (0 == res)
    {
        if (check_seq((rate_t *)a, (rate_t *)b, juder))
        {
            return -1;
        }
        return 1;
    }
    return res;
}

int main(void)
{
    s32 rate = 0;
    u32 i = 0, j = 0;
    char *s = NULL;
    scanf("%d %d", &juder, &xx);
    if ((3 > juder) || (3 > xx))
    {
        return -1;
    }

    rate_t *rate_table = (rate_t *)malloc(xx * sizeof(rate_t));
    char *str = (char *)malloc(xx*5);
    if (NULL == rate_table)
    {
        return -1;
    }
    memset(rate_table, 0x0, xx * sizeof(rate_t));
    for (i = 0; i < xx; i++)
    {
        rate_table[i].id = i+1;
        rate_table[i].grades = (u32 *)malloc(sizeof(u32) * juder);
    }
    for (i = 0; i < juder; i++)
    {
        j = 0;
        scanf("%s", str);
        s = strtok(str, ",");
        while(NULL != s)
        {
            rate = atoi(s);
            if ((10 < rate) || (0 > rate))
            {
                return -1;
            }

            rate_table[j].grade += rate;
            rate_table[j].grades[i] = rate;
            j++;
            s = strtok(NULL, ",");
        }
    }
    qsort(rate_table, xx, sizeof(rate_t), cmp);
    printf("%d,%d,%d\r\n", rate_table[0].id, rate_table[1].id, rate_table[2].id);

    for (i = 0; i < xx; i++)
    {
        free(rate_table[i].grades);
    }
    free(rate_table);
    free(str);
    return 0;
}

