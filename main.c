#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {
    int priority;
    char name[20];
}Patient;
int heapSize = 0;
Patient heap[100];

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
    printf("Patient %s with priority %d added to the queue\n",heap[heapSize].name,heap[heapSize].priority);
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

int extractMin()
{
    if(heapSize==0)
    {
        printf("No patients to Call\n");
        return 0;

    }
    Patient temp;
    strcpy(temp.name, heap[0].name);
    temp.priority = heap[0].priority;
    printf("Next patient is %s priority %d\n",temp.name,temp.priority);
    heap[0] = heap[heapSize-1];
    heapSize--;
    heapify(heap,heapSize,0);
}
int main() {
    int choice;
    Patient p;
   while(1)
   {
    printf("1.Add Patient\n");
    printf("2.Call Next Patient\n");
    printf("3.Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insertPatient(heap);
        
        break;
    case 2:
        extractMin();
        
        break;
    case 3:
        return 0;
    default:
        printf("Invalid choice\n");
        break;
    }
   }
    return 0;
}