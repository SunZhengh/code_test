/*
 * @Author: hox hox@outlook.com
 * @Date: 2023-07-05 10:51:22
 * @LastEditors: hox sunzhenghao@qq.com
 * @LastEditTime: 2023-07-06 14:42:34
 * @FilePath: \ctest\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://dream.blog.csdn.net/article/details/131510468
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_NUM (1000)
#define MAX_NUMBER_LENGTH       (16)

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int fmid(int *input, int size)
{
    int *chkdata = (int *)malloc(size*sizeof(int));
    int mid = 0;
    if(NULL == chkdata)
    {
        printf("fmid mem fail\r\n");
        return input[0];
    }
    memcpy(chkdata, input, size*sizeof(int));
    qsort(chkdata, size, sizeof(int), cmp);
    mid = chkdata[size / 2];
    printf("get mid : %d\r\n", mid);
    free(chkdata);
    return mid;
}

int get_sum(int *data, int index, int k)
{
    int i = 0, res = data[index];
    for (i = 1; i < k; i++)
    {
        res -= data[index + i];
    }

    return res;
}

int main() {
    char *rawdata = (char *)malloc(MAX_NUM * MAX_NUMBER_LENGTH);
    char *str = (char *)malloc(MAX_NUMBER_LENGTH);
    int nums[MAX_NUM] = {0};
    int k = 0, size = 0, mid = 0, index = 0, min = 0x7FFFFFFF, dist = 0, sum = 0, res = 0;
    if ((NULL == rawdata) || (NULL == str))
    {
        printf("mem alloc fial\r\n");
        return 0;
    }
    memset((char *)rawdata, 0x0, (MAX_NUM * MAX_NUMBER_LENGTH));
    scanf("%s", rawdata);
    sscanf(rawdata, "[%[^]] ],%d", rawdata, &k);
    
    str = strtok(rawdata, ",");
    while(NULL != str)
    {
        nums[size++] = atoi(str);
        str = strtok(NULL, ",");
    }
    mid = fmid(nums, size);

    for (index = 0; index < (size - k + 1); index++)
    {
        sum = get_sum(nums, index, k);
        dist = abs(sum - mid);
        if (min >= dist)
        {
            min = dist;
            res = index;
        }
    }
    printf("res:%d\r\n", res);
    free(rawdata);
    free(str);
    return res;
}

