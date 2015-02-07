/*

secmem / blog /
blog - > secmem -> ig ->

blog / secmem ->top
samsung -> current


secmem / samsung
samsung -> secmem -> samsung

-반드시 forward 스택과 backward 스택 필요.
-현재페이지/ 백스택/ 포워스택

VC, GCC에서 사용

*/
#include <string.h>
#include <stdio.h>

static char* BACK = "BACK";
static char* FORWARD = "FORWARD";
static char* VISIT = "VISIT";
static char* QUIT = "QUIT";

char backward[200][100] = { 0, };	//url + 명령 100글자 이하
char forward[200][100] = { 0, };
char page[100] = {"https://secmem.org/"};
int btop = -1;
int ftop = -1;

int excuteCommand(char* cmd){
	if (strcmp(cmd, QUIT) == 0){
		return -1;
	}
	else if (strstr(cmd, VISIT) != NULL){
		strcpy(backward[++btop], page);//현재 페이지 backward stack에 push

		char* url = cmd + 6;
		strcpy(page, url);//현재 페이지로 설정
		printf("%s\n", page);
		ftop = -1;
	}
	else if (strcmp(cmd, BACK) == 0){ //뒤로
		if (btop == -1){	//뒤로 갈수 없을때
			printf("Ignored\n");
		}
		else{
			strcpy(forward[++ftop], page);// 현재 페이지를 forward stack에 push
			strcpy(page, backward[btop--]);//현재 페이지로 설정
			printf("%s\n", page);	
		}
	}
	else if (strcmp(cmd, FORWARD) == 0){// 앞으로
		if (ftop == -1){//앞으로 갈 수 없을때
			printf("Ignored\n");
		}
		else {
			strcpy(backward[++btop], page);// 현재 페이지를 Backward stack에 push
			strcpy(page, forward[ftop--]);//forward stack에서 pop 하여 현재 페이지로 설정
			printf("%s\n", page);
		}
	}
	return 0;
}


int main()
{
	
	char enter;
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	scanf("%c", &enter);

	for (itr = 0; itr<nCount; itr++)
	{
		
		

		char* current = NULL;

		printf("#testcase%d\n", itr + 1);
		
		char cmdBuf[255] = { 0, };
		while (true){
			scanf("%[^\n]s", cmdBuf);
			scanf("%c", &enter);
			if (excuteCommand(cmdBuf) == -1){
				break;
			}
		}
		//초기화
		strcpy(page, "https://secmem.org/");
		btop = -1;
		ftop = -1;

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}