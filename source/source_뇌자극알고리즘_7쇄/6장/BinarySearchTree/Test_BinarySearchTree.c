#include "BinarySearchTree.h"

int main( void )
{
    /*  ��� ���� */
    BSTNode* Tree = BST_CreateNode(123);
    BSTNode* Node = NULL;

    /*  Ʈ���� ��� �߰� */
    BST_InsertNode( Tree, BST_CreateNode(22) );
    BST_InsertNode( Tree, BST_CreateNode(9918) );
    BST_InsertNode( Tree, BST_CreateNode(424) );
    BST_InsertNode( Tree, BST_CreateNode(17) );
    BST_InsertNode( Tree, BST_CreateNode(3) );

    BST_InsertNode( Tree, BST_CreateNode(98) );
    BST_InsertNode( Tree, BST_CreateNode(34) );

    BST_InsertNode( Tree, BST_CreateNode(760) );
    BST_InsertNode( Tree, BST_CreateNode(317) );
    BST_InsertNode( Tree, BST_CreateNode(1) );
    
	Node =  BST_SearchNode(Tree, 17 );
    if(Node != NULL)
        printf("%d \n", Node->Data);
    else
        puts("�׷� ��� �����");

    /*  Ʈ�� ��� */
    BST_InorderPrintTree( Tree );
    printf( "\n");

    /*  Ư�� ��� ���� */
    printf( "Removing 98...\n");

    Node = BST_RemoveNode( Tree, NULL, 98 );
    BST_DestroyNode( Node );

    BST_InorderPrintTree( Tree );
    printf( "\n");

    /*  �� ��� ���� */
    printf( "Inserting 111...\n");

    BST_InsertNode( Tree, BST_CreateNode(111) );
    BST_InorderPrintTree( Tree );
    printf( "\n");

    /*  Ʈ�� �Ҹ��Ű�� */
    BST_DestroyTree( Tree );

    return 0;
}