#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct node* SeqStack;
typedef char ElementType;
struct node {
    ElementType data[MaxSize];
    int top;  //标记栈顶数据  
};
//初始化
void InitNode(SeqStack *L) {
    (*L) = (SeqStack)malloc(sizeof(struct node));
    (*L)->top = -1;
}
//进栈
void PushStack(SeqStack L, ElementType x) {
    if (L->top == MaxSize - 1) {
        printf("满了");
    }
    else {
        L->top++;  //入栈所以加1
        L->data[L->top] = x;
    }
}
//出栈
void PopStack(SeqStack L, ElementType *x) {
    if (L->top == -1) {
        printf("空的");
    }
    else {
        *x = L->data[L->top];
        L->top--;
    }
}
//遍历输出
void PrintNode(SeqStack L) {
    for (int i = 0; i <= L->top; i++) {
        printf("%c", L->data[i]);
    }
    printf("\n");
}
int main() {
    SeqStack s;
    ElementType c;
    ElementType* y;
    y = &c;  //y指向c，为了出栈用
    InitNode(&s);
    printf("输入入栈数据");
    scanf("%c", &c);
    while (c != &apos;\n&apos;) {
        PushStack(s, c);
        scanf("%c", &c);
    }
    PrintNode(s);
    PopStack(s, y);
    printf("出栈元素是%c\n", *y);
    PrintNode(s);
}
