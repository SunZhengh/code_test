/*
 * @Author: hox hox@outlook.com
 * @Date: 2023-07-05 10:51:22
 * @LastEditors: hox sunzhenghao@qq.com
 * @LastEditTime: 2023-07-07 11:51:21
 * @FilePath: \ctest\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://dream.blog.csdn.net/article/details/131398927
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
#define STR_LEN_MAX         (200 + 4)
#define NUM_MAX             (1000)
#define NUM_TYPE_NUM        (10)
#define C_TO_I(c)           (c - '0')

u32 orig_char_map[NUM_TYPE_NUM] = {0};

void debug_map(u32 *map)
{
    u8 i = 0;
    printf("map: ");
    for (i = 0; i < NUM_TYPE_NUM; i++)
    {
        printf("%d ", map[i]);
    }
    printf("\r\n");
}

void gen_num_map(char *str, u32 *map)
{
    char c = str[0];
    u32 index = 0;
    u32 type = 0;
    
    while(('0' <= c) && ('9' >= c))
    {
        type = C_TO_I(c);
        printf("%c %d\r\n", c, type);
        map[type]++;
        c = str[++index];
    }
    debug_map(map);
}

void gen_num_map_int(u32 num, u32 *map)
{
    u32 i = 0;
    if (0 == num)
    {
        map[0]++;
    }
    while(0 != num)
    {
        map[num%10]++;
        num /= 10;
    }
}

void gen_num_map_int_loop(u32 base, u32 num, u32 *map)
{
    u32 i = 0;
    for (i = 0; i < num; i++)
    {
        gen_num_map_int((base + i), map);
    }
    debug_map(map);
}

void num_map_clean(u32 *map)
{
    u32 i = 0;
    for(i = 0; i < NUM_TYPE_NUM; i++)
    {
        map[i] = 0;
    }
}

bool num_map_cmp(u32 *map_orig, u32 *map)
{
    u32 type = 0;
    for (type = 0; type < NUM_TYPE_NUM; type++)
    {
        if (map[type] != map_orig[type])
        {
            return false;
        }
    }
    return true;
}

u32 get_dec_from_bit(u32 bitnum)
{
    u32 i = 0;
    u32 res = 1;
    for(i = 0; i < bitnum; i++)
    {
        res = res*10;
    }
    return res;
}

int main(void)
{
    u32 count = 0, str_len = 0, i = 0;
    u32 test_char_map[NUM_TYPE_NUM] = {0};
    char *orig = (char *)malloc(STR_LEN_MAX);
    if (NULL == orig)
    {
        printf("MEM fail\r\n");
        return 0;
    }
    memset(orig, 0, STR_LEN_MAX);
    scanf("%s", orig);
    scanf("%d", &count);
    printf("get %s - %d\r\n", orig, count);
    str_len = strlen(orig);
    gen_num_map(orig, &orig_char_map[0]);
    printf("strlen: %d\r\n", str_len);
    for (i = 0; i < NUM_MAX - count + 1; i++)
    {
        num_map_clean(test_char_map);
        gen_num_map_int_loop(i, count, test_char_map);
        if (num_map_cmp(test_char_map, orig_char_map))
        {
            printf("get %d\r\n", i);
            return i;
        }
    }

    return 0;
}



