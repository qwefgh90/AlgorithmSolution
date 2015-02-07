#include "Chaining.h"

HashTable* CHT_CreateHashTable( int TableSize )
{
    HashTable* HT = (HashTable*)malloc( sizeof(HashTable) );
    HT->Table     = (List*)malloc( sizeof(Node) * TableSize);

    memset(HT->Table, 0, sizeof(List) * TableSize );

    HT->TableSize = TableSize;

    return HT;
}

Node* CHT_CreateNode( KeyType Key, ValueType Value )
{
    Node* NewNode = (Node*) malloc( sizeof(Node) );

    NewNode->Key = (char*)malloc( sizeof(char) * ( strlen(Key) + 1 ));
    strcpy( NewNode->Key,   Key );

    NewNode->Value = (char*)malloc( sizeof(char) * ( strlen(Value) + 1 ));
    strcpy( NewNode->Value, Value );
    NewNode->Next = NULL;

    return NewNode;
}

void CHT_DestroyNode( Node* TheNode )
{
    free( TheNode->Key );
    free( TheNode->Value );
    free( TheNode );
}

void CHT_Set( HashTable* HT, KeyType Key, ValueType Value )
{
    int Address = CHT_Hash( Key, strlen(Key), HT->TableSize );
    Node* NewNode = CHT_CreateNode( Key, Value );

    /*  �ش� �ּҰ� ��� �ִ� ��� */
    if ( HT->Table[Address] == NULL )
    {
        HT->Table[Address] = NewNode;
    } 
    /*  �ش� �ּҰ� ��� ���� ���� ��� */
    else
    {    
        List L = HT->Table[Address];
        NewNode->Next         = L;
        HT->Table[Address] = NewNode;

        printf("Collision occured : Key(%s), Address(%d)\n", Key, Address );
    }
}

ValueType CHT_Get( HashTable* HT, KeyType Key )
{
    /*  �ּҸ� �ؽ��Ѵ�. */
    int Address = CHT_Hash( Key, strlen(Key), HT->TableSize );

    /*  �ؽ��� �ּҿ� �ִ� ��ũ�� ����Ʈ�� �����´�. */
    List TheList = HT->Table[Address];
    List Target  = NULL;

    if ( TheList == NULL )
        return NULL;

    /*  ���ϴ� ���� ã�� ������ ���� Ž��. */
    while ( 1 )
    {
        if ( strcmp( TheList->Key, Key ) == 0 ) 
        {
            Target = TheList;
            break;
        }
        
        if ( TheList->Next == NULL )
            break;
        else
            TheList = TheList->Next;
    }

    return Target->Value;
}

void CHT_DestroyList( List L )
{
    if ( L == NULL )
        return;

    if ( L->Next != NULL )
        CHT_DestroyList( L->Next );

    CHT_DestroyNode( L );
}

void CHT_DestroyHashTable( HashTable* HT)
{
    /*  1. �� ��ũ�� ����Ʈ�� ���� ����ҿ��� �����ϱ� */
    int i = 0;
    for ( i=0; i<HT->TableSize; i++ )
    {
        List L = HT->Table[i];
        
        CHT_DestroyList( L );    
    }

    /*  2, �ؽ� ���̺��� ���� ����ҿ��� �����ϱ�. */
    free ( HT->Table );
    free ( HT );
}

int CHT_Hash( KeyType Key, int KeyLength, int TableSize )
{
    int i=0;
    int HashValue = 0;

    for ( i=0; i<KeyLength; i++ )
    {
        HashValue = (HashValue << 3) + Key[i];
    }

    HashValue = HashValue % TableSize;

    return HashValue;
}
                              