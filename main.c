#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {
    int priority;
    char name[20];
}Patient;
int heapSize = 0;
Patient heap[100];

void heapifyUp(Patient heap[100],int heapSize,int i);

void swap(Patient *a,Patient *b)
{
    Patient temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i)
{
    return (i-1)/2;
}
int leftChild(int i)
{
    return 2*i;
}
int rightChild(int i)
{
    return (2*i)+1;
}

void insertPatient(Patient heap[100])
{
    printf("Enter patient name:\n");
    scanf("%s",heap[heapSize].name);
    printf("Enter the priority:\n");
    scanf("%d",&heap[heapSize].priority);
    heapSize++;
    int i = heapSize - 1;
    while (i > 0 && heap[parent(i)].priority > heap[i].priority) 
    {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }    
}

void heapify(Patient heap[100],int heapSize,int i)
{
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);
    if(left<heapSize && heap[left].priority<heap[smallest].priority)
    {
        smallest = left;
    }
    if(right<heapSize && heap[right].priority<heap[smallest].priority)
    {
        smallest = right;
    }
    if ( smallest != i)
    {
        swap (&heap[smallest],&heap[i]);
        heapify(heap,heapSize,smallest);
    }
}

Patient extractMin()
{
    if(heapSize==0)
    {
        printf("No patients to Call\n");
    }
    Patient temp;
    strcpy(temp.name, heap[0].name);
    temp.priority = heap[0].priority;
    heap[0] = heap[heapSize-1];
    heapSize--;
    heapify(heap,heapSize,0);
    return temp;
}
int main() {
   
    printf("Hello, ER! Program is running.\n");

    insertPatient(heap);
  
    insertPatient(heap);
     
    insertPatient(heap);
    printf("List of patients:\n");
    for (int i=0;i<heapSize;i++)
    {
        printf("%s %d\n",heap[i].name,heap[i].priority);
    }
    Patient temp = extractMin();
    printf("Next patient is %s priority %d\n",temp.name,temp.priority);
    printf("List of patients:\n");
    for (int i=0;i<heapSize;i++)
    {
        printf("%s %d\n",heap[i].name,heap[i].priority);
    }
    return 0;
}