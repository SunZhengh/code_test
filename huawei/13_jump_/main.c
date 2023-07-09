/*
 * @Author: hox 1510214118@qq.com
 * @Date: 2023-07-09 17:11:56
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 17:49:44
 * @FilePath: \code_test\huawei\13_jump_\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 1 2 3 1

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
    u32 id;
    u32 num;
}step_t;

int cmp(const void *a, const void *b)
{
    return (((step_t *)b)->num - ((step_t *)a)->num);
}

int get_prev(u32 id, u32 num)
{
    if(0 == id)
    {
        return num-1;
    }
    return id - 1;
}
int get_next(u32 id, u32 num)
{
    if ((num-1) == id)
    {
        return 0;
    }
    return id + 1;
}

int main() 
{
    u32 i = 0, num = 0, sum = 0, j = 0, max = 0;
    u8 step_point[100] = {0};
    step_t *table = (step_t *)malloc(100 * sizeof(step_t));
    char *raw = (char *)malloc(100 * 1000);
    char *s = NULL;
    scanf("%[^\n]", raw);
    s = strtok(raw, " ");
    while(NULL != s)
    {
        table[i].id = i;
        table[i].num = atoi(s);
        s = strtok(NULL, " ");
        i++;
    }
    num = i;
    qsort(table, num, sizeof(step_t), cmp);
    
    for (j = 0; j < num; j++)
    {
        for (i = j; i < num; i++)
        {
            if (step_point[get_prev(table[i].id, num)] || step_point[get_next(table[i].id, num)])
            {
                continue;
            }
            sum += table[i].num;
            step_point[table[i].id] = true;
        }
        if (max < sum)
        {
            max = sum;
        }
        sum = 0;
        memset(step_point, 0, 100);
    }
    printf("%d", max);

    return 0;
}

