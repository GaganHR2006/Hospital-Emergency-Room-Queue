#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    char name[20];
}Patient;

Patient heap[100];
int heapSize = 0;

void swap(Patient *a,Patient *b)
{
    Patient temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i)
{
    return i/2;
}
int leftChild(int i)
{
    return 2*i;
}
int rightChild(int i)
{
    return (2*i)+1;
}
int main() {
    printf("Hello, ER! Program is running.\n");
    return 0;
}