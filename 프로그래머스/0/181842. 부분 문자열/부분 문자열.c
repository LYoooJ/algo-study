#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* str1, const char* str2) {
    // str2 안에 str1이 존재하는지 검사
    if (strstr(str2, str1) != NULL) {
        return 1;
    }
    return 0;
}