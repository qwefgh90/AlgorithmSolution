#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char matrix[100][100]= {0,};

void findStar(int x,int y, int maxHeight,int &count){
	matrix[y][x] = 0;
	count++;
	if(x+1<maxHeight){
		if(matrix[y][x+1]==1){
			//matrix[y][x+1] = 0;
			findStar(x+1,y,maxHeight,count);
			//return;
		}
	}
	if(y+1<maxHeight){
		if(matrix[y+1][x]==1){
			//matrix[y+1][x] = 0;
			findStar(x,y+1,maxHeight,count);
			//return;
		}
	}
	if(y-1>=0){
		if(matrix[y-1][x]==1){
			//matrix[y-1][x] = 0;
			findStar(x,y-1,maxHeight,count);
			//return;
		}
	}
	if(x-1>=0){
		if(matrix[y][x-1]==1){
			//matrix[y][x-1] = 0;
			findStar(x-1,y,maxHeight,count);
			//return;
		}
	}
}


int main(){
	int testCase=0;
	char line[1000]={0,};
	scanf("%d",&testCase);
	while(testCase--){
		int startAreaCount = 0;
		int result = 0;
		memset(matrix,0,sizeof(matrix));
		int width = 0;
		scanf("%d",&width);
		getchar();
		//rewind(stdin);
		for(int i =0; i<width ;i++){
			for(int col=0; col<width ;col++){
				scanf("%d",&matrix[i][col]);
			}
			/*scanf("%[^\n]s",line);
			rewind(stdin);
			char *temp=NULL;
			int col=0;
			if(temp = strtok(line," ")){
				matrix[i][col++] = temp[0]-'0';
				while(temp = strtok(NULL," ")){
					matrix[i][col++] = temp[0]-'0';
				}
			}*/
		}
		for (int i=0; i<width ; i++){
			for(int j=0; j<width;j++){
				if(matrix[i][j]==1){
					startAreaCount++;
					int count=0;
					findStar(j,i,width,count);
					if(count >result){
						result = count;
					}
				}
			}
		}
		printf("%d %d\n",startAreaCount,result);
	}
	return 0;
}