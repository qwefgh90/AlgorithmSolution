#include <stdio.h>
#include <string.h>

/*
https://algospot.com/judge/problem/read/WEEKLYCALENDAR
*/

enum YOIL{MON,TUES,WEN,THUR,FRI,SATUR,SUN};
int printDateFromNumber(int month, int day, int offset);
int getDayFromDate(int month, int day, YOIL yoil);
int main(){
	int caseCount = 0;
	int month = 0;
	int day = 0;
	char yoil[15]={0,};	
	scanf("%d",&caseCount);
	for(int count=0; count < caseCount; count++){
		scanf("%d %d %s",&month,&day,yoil);
		if(strcmp(yoil,"Sunday")==0){
			getDayFromDate(month,day,SUN);	
			printf("\n");			
		}else if(strcmp(yoil,"Monday")==0){

			getDayFromDate(month,day,MON);	
			printf("\n");			
		}else if(strcmp(yoil,"Tuesday")==0){

			getDayFromDate(month,day,TUES);	
			printf("\n");			
		}else if(!strcmp(yoil,"Wednesday")){

			getDayFromDate(month,day,WEN);	
			printf("\n");			
		}else if(!strcmp(yoil,"Thursday")){

			getDayFromDate(month,day,THUR);	
			printf("\n");			
		}else if(!strcmp(yoil,"Friday")){

			getDayFromDate(month,day,FRI);	
			printf("\n");			
		}else if(!strcmp(yoil,"Saturday")){

			getDayFromDate(month,day,SATUR);	
			printf("\n");			
		}
	}
	return 0;
}


inline int printDateFromNumber(int month, int day, int offset){
	int newday = day + offset;
	switch(month){
		case 1://31
			if(newday<1){
				month = 12;//31
				newday = newday+31; // 0 -> 31
			}else if(newday>31){
				month = 2;
				newday = newday-31; //32 -> 01老
			}else{
				//nope
			}
			break;
		case 2://28
			if(newday<1){
				month = 1;//31
				newday = newday +31;
			}else if(newday>28){
				month =3;
				newday = newday -28;
			}
			break;
		case 3://31
			if(newday<1){
				month = 2;//28
				newday = newday +28;
			}else if(newday>31){
				month =4;
				newday =newday -31;
			}
			break;
		case 4:
			if(newday<1){
				month =3;//31
				newday= newday +31;
			}else if(newday>30){
				month = 5;
				newday = newday - 30;
			}
			break;
		case 5://31
			if(newday<1){
				month = 4;//30
				newday = newday + 30;
			}else if(newday>31){
				month = 6;
				newday = newday -31;
			}
			break;
		case 6://30
			if(newday<1){
				month = 5;//31
				newday = newday + 31;
			}else if(newday>30){
				month = 7;
				newday = newday - 30;
			}
			break;
		case 7:	//31老
			if(newday<1){
				month = 6;	//30老
				newday = newday + 30;	
			}else if(newday>31){	
				month = 8; //
				newday = newday-31;
			}else{
				//nope
			}
			break;
		case 8://31老
			if(newday<1){
				month = 7;	//31老
				newday = newday +  31;
			}else if(newday>31){
				month = 9;
				newday = newday - 31;
			}
			break;
		case 9://30老
			if(newday<1){
				month = 8; //31
				newday = newday +31;
			}else if(newday>30){
				month = 10;
				newday = newday  -30;
			}
			break;
		case 10://31
			if(newday<1){
				month = 9; //30
				newday = newday + 30;
			}else if(newday>31){
				month = 11; //30
				newday = newday - 31;
			}
			break;
		case 11://30
			if(newday<1){
				month = 10;//31
				newday = newday + 31;
			}else if(newday>30){
				month = 12;
				newday = newday - 30;
			}
			break;
		case 12:
			if(newday<1){
				month = 11;//30老
				newday = newday+30;

			}else if(newday>31){
				month =1;
				newday = newday -31;
			}else{
				//nope;
			}
			break;
	
	}


		printf("%d ",newday);
}


int getDayFromDate(int month, int day, YOIL yoil){
	switch(yoil){

		case SUN:
			for(int i=0 ; i < 7 ; i++){
				printDateFromNumber(month,day,i);
			}
			break;
				 
				 
		case MON:{
			for(int i=0 ; i < 7 ; i++){
				printDateFromNumber(month,day,i-1);
			}
			break;
				 }
		case TUES:{
			for(int i=0 ; i < 7 ; i++){
				printDateFromNumber(month,day,i-2);
			}
			break;
				 }
		case WEN:{
			for(int i=0 ; i < 7 ; i++){
				printDateFromNumber(month,day,i-3);
			}
			break;
				 }
		case THUR:{
			for(int i=0 ; i < 7 ; i++){
				printDateFromNumber(month,day,i-4);
			}
			break;
				 }
		case FRI:{
			for(int i=0 ; i < 7 ; i++){
				printDateFromNumber(month,day,i-5);
			}
			break;
				 }
		case SATUR:{	
			for(int i=0 ; i < 7 ; i++){
				printDateFromNumber(month,day,i-6);
			}
			break;
				 }
	}

}
