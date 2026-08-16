#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// index_list_len은 배열 index_list의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int index_list[], size_t index_list_len) {
    // 결과 문자열 메모리 할당 (널 문자 포함)
    char* answer = (char*)malloc(sizeof(char) * (index_list_len + 1));
    
    // index_list의 인덱스에 맞춰 my_string의 문자를 복사
    for (size_t i = 0; i < index_list_len; i++) {
        answer[i] = my_string[index_list[i]];
    }
    
    // 문자열 끝에 널 문자 추가
    answer[index_list_len] = '\0';
    
    return answer;
}