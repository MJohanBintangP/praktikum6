#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct StackNode {
  DataType data;
  struct StackNode *next;
} StackNode;

typedef struct Stack {
  StackNode *top;
} Stack;

void push(Stack *stack, DataType data);
DataType pop(Stack *stack);
int isEmpty(Stack *stack);

int isBalanced(char *str) {
  Stack stack;
  stack.top = NULL;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
      push(&stack, str[i]);
    } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
      if (isEmpty(&stack)) {
        return 0;
      }

      char poppedChar = pop(&stack);

      if ((poppedChar == '(' && str[i] != ')') ||
          (poppedChar == '{' && str[i] != '}') ||
          (poppedChar == '[' && str[i] != ']')) {
        return 0;
      }
    }
  }

  if (!isEmpty(&stack)) {
    return 0;
  }

  return 1;
}

void push(Stack *stack, DataType data) {
  StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}

DataType pop(Stack *stack) {
  if (isEmpty(stack)) {
    return '\0';
  }

  StackNode *temp = stack->top;
  DataType data = temp->data;
  stack->top = temp->next;
  free(temp);

  return data;
}

int isEmpty(Stack *stack) {
  return stack->top == NULL;
}

int main() {
  char str[100];
  scanf("%s", str);

  if (isBalanced(str)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}