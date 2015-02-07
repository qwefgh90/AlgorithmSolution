#include "CircularDoublyLinkedList.h"

int main( void )
{
    int   i       = 0;
    int   Count   = 0;
    Node* List    = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    /*  ��� 5�� �߰� */
    for ( i = 0; i<5; i++ )
    {
        NewNode = CDLL_CreateNode( i );
        CDLL_AppendNode( &List,NewNode );
    }

    /*  ����Ʈ ��� */
    Count = CDLL_GetNodeCount( List );
    for ( i = 0; i<Count; i++ )
    {
        Current = CDLL_GetNodeAt( List, i );
        printf( "List[%d] : %d\n", i, Current->Data );
    }

    /*  ����Ʈ�� ����° ĭ �ڿ� ��� ���� */
    printf( "\nInserting 3000 After [2]...\n\n" );

    Current = CDLL_GetNodeAt( List, 2 );
    NewNode = CDLL_CreateNode( 3000 );
    CDLL_InsertAfter( Current, NewNode );

    printf( "\nRemoving Node at 2...\n" );
    Current = CDLL_GetNodeAt( List, 2 );
    CDLL_RemoveNode( &List, Current );
    CDLL_DestroyNode( Current );

    /*  ����Ʈ ���  */
    /*  (��� ���� 2�踸ŭ ������ ���� ȯ������ Ȯ���Ѵ�.) */
    Count = CDLL_GetNodeCount( List );
    for ( i = 0; i<Count*2; i++ )
    {
        if ( i == 0 )
            Current = List;
        else
            Current = Current->NextNode;
        
        printf( "List[%d] : %d\n", i, Current->Data );
    }

    /*  ��� ��带 �޸𸮿��� ����     */
    printf( "\nDestroying List...\n" );

    Count = CDLL_GetNodeCount( List );

    for ( i = 0; i<Count; i++ )
    {
        Current = CDLL_GetNodeAt( List, 0 );

        if ( Current != NULL ) 
        {
            CDLL_RemoveNode( &List, Current );
            CDLL_DestroyNode( Current );
        }
    }

    return 0;
}
