#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int priority;
    int value;
} Node;

Node queue[MAX_SIZE];
int rear = -1;

void push(int element, int priority) {
    if (rear >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    rear++;
    queue[rear].value = element;
    queue[rear].priority = priority;
}

int pop() {
    if (rear < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    int i=0;
    int maxPriority = -1;
    int maxIndex = 0;
    for (i = 0; i <= rear; i++) {
        if (queue[i].priority > maxPriority) {
            maxPriority = queue[i].priority;
            maxIndex = i;
        }
    }
    int element = queue[maxIndex].value;
    for (i = maxIndex; i < rear; i++) {
        queue[i] = queue[i + 1];
    }
    rear--;
    return element;
}

void main() {
    push(1, 2);
    push(2, 1);
    push(3, 3);

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

}
