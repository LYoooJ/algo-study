#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    // 담을 원소의 개수 계산
    int count = num_list_len - n + 1;
    
    // 결과 배열 메모리 할당
    int* answer = (int*)malloc(sizeof(int) * count);
    
    // n-1 번 인덱스부터 끝까지 복사
    for (int i = 0; i < count; i++) {
        answer[i] = num_list[(n - 1) + i];
    }
    
    return answer;
}