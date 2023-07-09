/*
 * @Author: hox hox@outlook.com
 * @Date: 2023-07-05 10:51:22
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 15:28:14
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

#define LET_NUM             (26)
#define MAX_LENGTH          (1200)
typedef struct
{
    char letter;
    u32 count;
}let_t;

int cmp_num(const void *a, const void *b)
{
    let_t *before = (let_t *)a;
    let_t *after = (let_t *)b;
    int res = (after->count - before->count);
    if (0 == res)
    {
        res = (before->letter - after->letter);
    }
    return res;
}


s32 letter_to_num(char letter)
{
    s32 num = letter - 'a';
    if (0 > num)
    {
        num = letter - 'A';
    }

    return (num % LET_NUM);
}

u8 same_letter(char a, char b)
{
    if (letter_to_num(a) == letter_to_num(b))
    {
        return true;
    }
    return false;
}

int main(void)
{
    u32 len = 0, index = 0, seq_cnt = 0;
    int i = 0;
    u32 let_count[LET_NUM] = {0};
    let_t *letable = (let_t *)malloc(MAX_LENGTH * sizeof(let_t));
    char *str = (char *)malloc(MAX_LENGTH);
    if (NULL == str)
    {
        return -1;
    }
    memset(letable, 0x0, MAX_LENGTH * sizeof(let_t));
    memset(str, 0x0, MAX_LENGTH);
    scanf("%s", str);
    len = strlen(str);

    letable[index].letter = str[len - 1];
    let_count[letter_to_num(str[len - 1])]++;

    for (i = (len - 2); i >= 0; i--)
    {
        let_count[letter_to_num(str[i])]++;
        if (same_letter(letable[index].letter, str[i]))
        {
            seq_cnt++;
        }
        else
        {
            if (0 == seq_cnt)
            {
                letable[index].count = let_count[letter_to_num(letable[index].letter)] - 1;
            }
            else
            {
                letable[index].count = seq_cnt + 1;
            }
            index++;
            letable[index].letter = str[i];
            letable[index].count++;
            seq_cnt = 0;
        }

        if (0 == i)
        {
            if (0 == seq_cnt)
            {
                letable[index].count = let_count[letter_to_num(letable[index].letter)] - 1;
            }
            else
            {
                letable[index].count = seq_cnt + 1;
            }
        }
        
    }
    printf("fuck %d\r\n", index);
    qsort(letable, (index+1), sizeof(let_t), cmp_num);
    for (i = 0; i <= index; i++)
    {
        printf("%c%d", letable[i].letter, letable[i].count);
    }

    return 0;
}

