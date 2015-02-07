#include "LinkedQueue.h"

LinkedQueue* LQ_CreateQueue()
{
    LinkedQueue* Queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    /*  ť�� ��������ҿ� ���� */
    
    Queue->Front = NULL;
    Queue->Rear  = NULL;
    Queue->Count = 0;

    return Queue;
}

void LQ_DestroyQueue(LinkedQueue* Queue)
{
    while ( !LQ_IsEmpty(Queue) )
    {
        Node* Popped = LQ_Dequeue(&Queue);
        LQ_DestroyNode(Popped);    
    }

    /*  ť�� ���� ����ҿ��� ���� */
    free(Queue);
}

Node* LQ_CreateNode(Vertex* V)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = V;

    NewNode->NextNode = NULL; /*  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. */

    return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

void  LQ_DestroyNode(Node* _Node)
{
    free(_Node->Data);
    free(_Node);
}

void LQ_Enqueue(LinkedQueue** Queue, Node* NewNode)
{
    if ( (*Queue)->Front == NULL ) 
    {        
        (*Queue)->Front = NewNode;
        (*Queue)->Rear  = NewNode;
        (*Queue)->Count++;
    } 
    else
    {
        (*Queue)->Rear->NextNode = NewNode;
        (*Queue)->Rear = NewNode;
        (*Queue)->Count++;
    }
}

Node* LQ_Dequeue(LinkedQueue** Queue)
{
    Node* Front = (*Queue)->Front;

    if ( (*Queue)->Front->NextNode == NULL )
    {
        (*Queue)->Front = NULL;
        (*Queue)->Rear  = NULL;
    }
    else
    {
        (*Queue)->Front = (*Queue)->Front->NextNode;
    }

    (*Queue)->Count--;

    return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue)
{
    return (Queue->Front == NULL);
}