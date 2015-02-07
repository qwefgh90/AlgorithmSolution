#include "Huffman.h"
#include <string.h>

int main( void )
{
    char* Source  = "http://www.seanlab.net";
    char* Decoded = "";

    HuffmanNode* Tree = NULL;
    BitBuffer    Encoded = {NULL, 0};
    HuffmanCode  CodeTable[MAX_CHAR];
    
    memset ( &CodeTable, 0, sizeof(HuffmanCode) * MAX_CHAR );
    
    Huffman_Encode( &Tree, Source, &Encoded, CodeTable );
    
    printf("Original Size:%d Encoded Size:%d\n", 
        (strlen(Source) + 1) * sizeof(char) * 8, Encoded.Size);

    Decoded = (char*)malloc(sizeof(char) * (strlen(Source) + 1));
    Huffman_Decode( Tree, &Encoded, Decoded );

    printf("Original : %s\n", Source );
    printf("Encoded  : ");
    
    Huffman_PrintBinary( &Encoded );

    printf("\n");

    printf("Decoded  : %s\n", Decoded );

    Huffman_DestroyTree( Tree );
    free( Decoded );

    return 0;
}