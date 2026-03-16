#include <stdio.h>
#define SIZE 5

int items[SIZE], front = -1, rear = -1;

// Check if the queue is full
int isFull() {
    if (rear == SIZE - 1) return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    if (front == -1) return 1;
    return 0;
}

// Add an element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        items[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Remove an element
int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = items[front];
        front++;
        if (front > rear) {
            front = rear = -1; // Reset queue
        }
        return item;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    printf("Dequeued: %d\n", dequeue());
    return 0;
}
