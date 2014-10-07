#include "algorithm.h"
namespace CAlgorithm{
	int fibo(int* fibo_array, int fibo_size){
		int result = 0;
		//ERROR
		if (fibo_size <= 0){
			result = -1;
		}else if (fibo_size == 1){
			result = 1;
			fibo_array[fibo_size - 1] = result;
		}
		else if (fibo_size == 2){
			result = 1;
			fibo_array[fibo_size - 2] = result;
			fibo_array[fibo_size - 1] = result;
		}
		else{
			result = fibo(fibo_array, fibo_size - 2) + fibo(fibo_array, fibo_size - 1);
			fibo_array[fibo_size - 1] = result;
		}
		return result;
	}
}