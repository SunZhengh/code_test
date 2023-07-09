/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 14:37:19
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 17:21:51
 * @FilePath: \ctest\code_test\huawei\02_most_close_time\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int dpMethod(int *nums, int length) {
    int dp[length];
    dp[0] = nums[0];

    for (int i = 1; i < length; i++) {
        if (i == 1) 
        {
            dp[i] = nums[i] > dp[i - 1] ? nums[i] : dp[i - 1];
        } 
        else 
        {
            dp[i] = nums[i] + dp[i - 2] > dp[i - 1] ? nums[i] + dp[i - 2] : dp[i - 1];
        }
    }

    return dp[length - 1];
}

int main() {
    int ints[] = {2, 3};
    int length = sizeof(ints) / sizeof(ints[0]);

    if (length == 1) {
        printf("%d\n", ints[0]);
    } else {
        int numsStart[length];
        int numsEnd[length];
        
        for (int i = 0; i < length; i++) 
        {
            int num = ints[i];
            if (i == 0) 
            {
                numsStart[i] = num;
            } 
            else if (i == length - 1) 
            {
                numsEnd[i - 1] = num;
                break;
            } 
            else 
            {
                numsStart[i] = num;
                numsEnd[i - 1] = num;
            }
        }

        int res = dpMethod(numsStart, length) > dpMethod(numsEnd, length - 1) ? dpMethod(numsStart, length) : dpMethod(numsEnd, length - 1);

        printf("%d\n", res);
    }

    return 0;
}










