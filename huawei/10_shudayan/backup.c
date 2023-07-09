/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 14:37:19
 * @LastEditors: hox 1510214118@qq.com
 * @LastEditTime: 2023-07-09 16:40:43
 * @FilePath: \ctest\code_test\huawei\02_most_close_time\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <string.h>

int solve_method(const char* quack) {
    const char* base = "quack";
    int states[5] = {0};  // 初始状态数组，长度为 5
    int counts = 0;

    for (int i = 0; i < strlen(quack); i++) {
        char c = quack[i];
        if (c == base[0]) 
        {
            states[0] += 1;
        } 
        else 
        {
            int index = strchr(base, c) - base;
            states[index - 1] -= 1;
            states[index] += 1;
            if (c == base[strlen(base) - 1]) 
            {
                states[strlen(base) - 1] -= 1;
            }
        }

        int sum = 0;
        for (int j = 0; j < 5; j++) 
        {
            printf("%c %d \r\n", c, states[j]);
            sum += states[j];
        }
        counts = (counts > sum) ? counts : sum;

        int found_negative = 0;
        for (int j = 0; j < 5; j++) 
        {
            if (states[j] == -1) {
                found_negative = 1;
                break;
            }
        }
        if (found_negative) 
        {
            return -1;
        }
    }

    int total_sum = 0;
    for (int i = 0; i < 5; i++) {
        total_sum += states[i];
    }
    if (total_sum != 0) {
        return -1;
    }

    return counts;
}

int main() {
    char user_input[100];
    scanf("%s", user_input);
    int ret = solve_method(user_input);
    printf("%d\n", ret);

    return 0;
}



