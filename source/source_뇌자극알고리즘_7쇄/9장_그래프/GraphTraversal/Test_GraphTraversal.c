#include "Graph.h"
#include "GraphTraversal.h"

int main( void )
{
    int          Mode  = 0;
    Graph* graph = CreateGraph();
    
    Vertex* V1 = CreateVertex( 1 );
    Vertex* V2 = CreateVertex( 2 );
    Vertex* V3 = CreateVertex( 3 );
    Vertex* V4 = CreateVertex( 4 );
    Vertex* V5 = CreateVertex( 5 );
    Vertex* V6 = CreateVertex( 6 );
    Vertex* V7 = CreateVertex( 7 );

    AddVertex( graph, V1 );
    AddVertex( graph, V2 );
    AddVertex( graph, V3 );
    AddVertex( graph, V4 );
    AddVertex( graph, V5 );
    AddVertex( graph, V6 );
    AddVertex( graph, V7 );

    /*  ������ ������ �������� �ձ� */
    AddEdge( V1, CreateEdge(V1, V2, 0) );
    AddEdge( V1, CreateEdge(V1, V3, 0) );

    AddEdge( V2, CreateEdge(V2, V4, 0) );
    AddEdge( V2, CreateEdge(V2, V5, 0) );

    AddEdge( V3, CreateEdge(V3, V4, 0) );
    AddEdge( V3, CreateEdge(V3, V6, 0) );

    AddEdge( V4, CreateEdge(V4, V5, 0) );
    AddEdge( V4, CreateEdge(V4, V7, 0) );

    AddEdge( V5, CreateEdge(V5, V7, 0) );

    AddEdge( V6, CreateEdge(V6, V7, 0) );

    printf( "Enter Traversal Mode (0:DFS, 1:BFS) : " );
    scanf(  "%d", &Mode );

    if ( Mode == 0  ) 
    {
        /*  ���� �켱 Ž�� */
        DFS( graph->Vertices );
    }
    else
    {
        LinkedQueue* Queue = LQ_CreateQueue();
    
        /*  �ʺ� �켱 Ž�� */
        BFS(V1, Queue);
        
        LQ_DestroyQueue( Queue );
    }

    DestroyGraph( graph );

    return 0;
}