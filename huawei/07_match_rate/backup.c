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

typedef struct {
    int id;
    int total;
    int* scores;
} Person;

int checkCount(int* list, int size, int count) {
    int cou = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] == count) {
            cou++;
        }
    }
    return cou;
}

int comparePersons(const void* a, const void* b) {
    Person* personA = (Person*)a;
    Person* personB = (Person*)b;
    if (personB->total != personA->total) {
        return personB->total - personA->total;
    } else {
        for (int i = 10; i > 0; i--) {
            int ipl = checkCount(personB->scores, personA->total, i);
            int ith = checkCount(personA->scores, personA->total, i);
            if (ith != ipl) {
                return ith - ipl;
            }
        }
    }
    return 0;
}

int main() {
    int jiaolian, xuanshou;
    scanf("%d,%d", &jiaolian, &xuanshou);
    if (jiaolian > 10 || jiaolian < 3 || xuanshou > 100 || xuanshou < 3) {
        printf("-1\n");
        return 0;
    }

    int** myList = (int**)malloc(jiaolian * sizeof(int*));
    for (int i = 0; i < jiaolian; i++) {
        myList[i] = (int*)malloc(xuanshou * sizeof(int));
        for (int j = 0; j < xuanshou; j++) {
            scanf("%d,", &myList[i][j]);
        }
    }

    Person* persons = (Person*)malloc(xuanshou * sizeof(Person));
    for (int i = 0; i < xuanshou; i++) {
        int total = 0;
        int* scoreList = (int*)malloc(jiaolian * sizeof(int));
        for (int j = 0; j < jiaolian; j++) {
            int score = myList[j][i];
            if (score < 0 || score > 10) {
                printf("-1\n");
                return 0;
            }
            scoreList[j] = score;
            total += score;
        }
        persons[i].id = i;
        persons[i].total = total;
        persons[i].scores = scoreList;
    }

    qsort(persons, xuanshou, sizeof(Person), comparePersons);

    for (int i = 0; i < 3; i++) {
        if (i == 2) {
            printf("%d\n", persons[i].id + 1);
        } else {
            printf("%d,", persons[i].id + 1);
        }
    }

    for (int i = 0; i < jiaolian; i++) {
        free(myList[i]);
    }
    free(myList);

    for (int i = 0; i < xuanshou; i++) {
        free(persons[i].scores);
    }
    free(persons);

    return 0;
}





