#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* f = fopen("MushroomMonsterSmallInput.txt", "r");
	FILE* output = fopen("output.txt", "w");

	int testcase;
	fscanf(f, "%d", &testcase);

	for (int j = 0; j < testcase; j++){


		fprintf(stdout, "Case #%d: %d %d\n");
	}


	fclose(f);
	fclose(output);
	return 0;

}

