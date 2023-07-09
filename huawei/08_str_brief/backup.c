/*
 * @Author: hox sunzhenghao@qq.com
 * @Date: 2023-07-06 14:37:19
 * @LastEditors: hox sunzhenghao@qq.com
 * @LastEditTime: 2023-07-06 16:40:35
 * @FilePath: \ctest\code_test\huawei\02_most_close_time\backup.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Letter {
    char name;
    int count;
};

int compare(const void* a, const void* b) {
    struct Letter* letterA = (struct Letter*)a;
    struct Letter* letterB = (struct Letter*)b;

    if (letterA->count == letterB->count) {
        return letterB->name - letterA->name;
    }

    return letterB->count - letterA->count;
}

int main() {
    char inputStr[1000];
    fgets(inputStr, sizeof(inputStr), stdin);

    char filteredStr[1000];
    int filteredStrIdx = 0;
    for (int i = 0; inputStr[i] != '\0'; i++) {
        char ch = inputStr[i];
        if (isalpha(ch)) {
            filteredStr[filteredStrIdx++] = ch;
        }
    }
    filteredStr[filteredStrIdx] = '\0';

    int count = 1;
    char currentChar = tolower(filteredStr[strlen(filteredStr) - 1]);
    struct Letter* charList = (struct Letter*)malloc(sizeof(struct Letter) * strlen(filteredStr));
    int charListIdx = 0;
    int charCountMap[26] = {0};

    for (int i = strlen(filteredStr) - 2; i >= 0; i--) 
    {
        char ch = tolower(filteredStr[i]);
        if (currentChar == ch) 
        {
            count++;
        } 
        else 
        {
            if (count == 1) {
                count += charCountMap[currentChar] - 1;
                charCountMap[currentChar] = count + 1;
            } else {
                charCountMap[currentChar] = count;
            }
            struct Letter letter;
            letter.name = currentChar;
            letter.count = count;
            charList[charListIdx++] = letter;
            currentChar = ch;
            count = 1;
        }
        if (i == 0) 
        {
            if (count == 1) {
                count += charCountMap[currentChar] - 1;
            }
            struct Letter letter;
            letter.name = currentChar;
            letter.count = count;
            charList[charListIdx++] = letter;
        }
    }

    qsort(charList, charListIdx, sizeof(struct Letter), compare);

    char result[1000];
    int resultIdx = 0;
    for (int i = 0; i < charListIdx; i++) {
        result[resultIdx++] = charList[i].name;
        result[resultIdx++] = '0' + charList[i].count;
    }
    result[resultIdx] = '\0';

    printf("%s\n", result);

    free(charList);

    return 0;
}

