#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 10
//用栈实现括号匹配的代码
bool bracketCheck(char str[], int length) {
    char data[MaxSize] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };//用char数组来模拟堆栈
    int top = -1;
    for (int i = 0; i < length; i++) {
        //遍历char数组
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            //如果是左括号，就入栈。
            data[++top] = str[i];
        }
        else {
            if (data[0] == '0') {
                //如果在匹配右括号栈空的情况下就返回false
                return false;
            }
            //如果栈非空就让栈顶元素出栈

            //初始化栈顶元素
            char topElem = '0';
            topElem = data[top];
            data[top--] = '0';
            if (str[i] == ')' && topElem != '(') {
                return false;
            }
            if (str[i] == '}' && topElem != '{') {
                return false;
            }
            if (str[i] == ']' && topElem != '[') {
                return false;
            }

        }
    }
    return data[0] = '0' ? true : false;
}
void main() {
    printf("编译成功\n");
    system("pause");

    char str[6] = { '{', '[', '(', ')' ,']' ,'}'};
    if (bracketCheck(str, 6)) {
        printf("匹配成功\n");
    }
    else {
        printf("匹配失败\n");
    }

}