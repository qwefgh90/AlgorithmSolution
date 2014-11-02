#include "algorithm.h"

long fibonachi(int index){
	long result=0;

	if(index<1){
		result=0;
	}else if(index==1){
		result=1;
	}else if(index==2){
		result=1;
	}else{
		long ppreValue=1;
		long preValue=1;
		result = 1;
		for(int i=0; i<index-2; i++){
			//for operation
			ppreValue = preValue;
			preValue = result;

			result = ppreValue + preValue;
		} 
	}
	return result;
}