/*
 * @Author: hox hox@outlook.com
 * @Date: 2023-07-05 10:51:22
 * @LastEditors: hox sunzhenghao@qq.com
 * @LastEditTime: 2023-07-06 16:16:45
 * @FilePath: \ctest\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://dream.blog.csdn.net/article/details/131470023
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef short s16;
typedef char s8;
#define U32_MASK            (0xFFFFFFFF)


typedef union
{
    u8 keys[4];
    u32 config;
}key_data_u;


#define false               (0)
#define true                (1)
#define MAX_DATE_LENGTH     (32)
#define TIME_LIMIT_MIN      (60)
#define TIME_LIMIT_HOUR     (24)
#define TIME_VALID(hour, min)   (((TIME_LIMIT_HOUR <= hour) || (TIME_LIMIT_MIN <= min) || (0 > hour) || (0 > min)) ? false : true)
#define TIME_TO_MIN(hour, min)  (hour * TIME_LIMIT_MIN + min)
#define LOOP(i, limit)          for(i = 0; i < limit; i++)
#define DAY_MIN             (TIME_LIMIT_HOUR * TIME_LIMIT_MIN)
#define DEC_GEN(h, l)      (h * 10 + l)


void get_keys(key_data_u *key, u32 hour, u32 min)
{
    key->keys[0] = hour / 10;
    key->keys[1] = hour % 10;
    key->keys[2] = min / 10;
    key->keys[3] = min % 10;
}

u32 get_min(u32 hour_h, u32 hour_l, u32 min_h, u32 min_l)
{
    u32 hour = hour_h * 10 + hour_l;
    u32 min = min_h * 10 + min_l;
    if (!TIME_VALID(hour, min))
    {
        return 0xFFFFFFFF;
    }
    return TIME_TO_MIN(hour, min);
}

int main(void)
{
    u32 min = 0, hour = 0;
    u32 raw_min = 0, temp = 0;
    key_data_u key = {0};
    key_data_u min_key = {0};
    u32 i = 0, j = 0, x = 0, y = 0;
    u32 dist = 0, min_min = 0xFFFFFFFF;
    min_key.config = 0xFFFFFFFF;

    scanf("%d:%d", &hour, &min);
    if(!TIME_VALID(hour, min))
    {
        printf("invalid input %d %d\r\n", hour, min);
        return 0;
    }
    raw_min = TIME_TO_MIN(hour, min);
    get_keys(&key, hour, min);
    LOOP(i, 4)
    {
        LOOP(j, 4)
        {
            LOOP(x, 4)
            {
                LOOP(y, 4)
                {
                    temp = get_min(key.keys[i], key.keys[j], key.keys[x], key.keys[y]);
                    if ((0xFFFFFFFF == temp) || (raw_min == temp))
                    {
                        continue;
                    }

                    dist = temp + (DAY_MIN * (temp < raw_min)) - raw_min;
                    
                    if((min_min >= dist) && (0 != dist))
                    {
                        min_min = dist;
                        min_key.config = (key.keys[i]) | (key.keys[j] << 8) | (key.keys[x] << 16) | (key.keys[y] << 24);
                    }
                }
            }
        }
    }
    printf("%1d%1d:%1d%1d\r\n", min_key.keys[0], min_key.keys[1], min_key.keys[2], min_key.keys[3]);
    return 0;
}

