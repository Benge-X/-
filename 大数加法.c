#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 函数声明
char* addBigNumbers(const char* num1, const char* num2);
void removeLeadingZeros(char* str);
void reverseString(char* str);
int isValidNumber(const char* str);

int main() {
    char num1[1000], num2[1000];
    
    printf("Enter a number");
    scanf("%999s", num1);
    
    // 验证输入是否为有效数字
    if (!isValidNumber(num1)) {
        printf("Error\n");
        return 1;
    }
    
    printf("Enter a number ");
    scanf("%999s", num2);
    
    // 同上
    if (!isValidNumber(num2)) {
        printf("Error\n");
        return 1;
    }
    
    // 移除前导零
    removeLeadingZeros(num1);
    removeLeadingZeros(num2);
    
    // 如果所有字符都是零，则保留一个零
    if (strlen(num1) == 0) strcpy(num1, "0");
    if (strlen(num2) == 0) strcpy(num2, "0");
    
   

    char* result = addBigNumbers(num1, num2);
    
    printf("Result: %s\n", result);
    
   
    free(result);
    
    return 0;
}

// 大数加法函数
char* addBigNumbers(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    
    // 分配结果字符串内存
    char* result = (char*)malloc(maxLen + 2);
    if (result == NULL) {
        printf("Error!\n");
        exit(1);
    }
    
    int i = len1 - 1, j = len2 - 1, k = 0;
    int jinwei= 0, sum;
    
    // 从右到左逐位相加
    while (i >= 0 || j >= 0 || jinwei) {
        int digit1 = (i >= 0) ? (num1[i--] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j--] - '0') : 0;
        
        sum = digit1 + digit2 + jinwei;
      jinwei = sum / 10;
        result[k++] = (sum % 10) + '0';
    }
    result[k] = '\0';
    
    // 反转结果字符串0
    reverseString(result);/
    
    return result;
}

// 移除前导零
void removeLeadingZeros(char* str) {
    int i = 0;
    int len = strlen(str);
    
    // 找到第一个非零字符的位置
    while (i < len - 1 && str[i] == '0') {
        i++;
    }
    
    // 移动剩余部分到字符串开头
    if (i > 0) {
        int j = 0;
        while (i <= len) {
            str[j++] = str[i++];
        }
    }
}

// 反转字符串
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// 验证字符串是否只包含数字字符
int isValidNumber(const char* str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }
    

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    
    return 1;
}