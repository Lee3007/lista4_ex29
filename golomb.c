#include<stdio.h>

int golomb( int n ){
	if(n == 1)
		return 1;

	return 1 + golomb( n - golomb( golomb(n-1) ) );

}

int main(void){
	int input_arr[256];
	int input = 1, i=0;
		
	for( scanf("%d", &input) ; input!=0 ; scanf("%d", &input)){
		input_arr[i++] = input;
	}

	for( int j=0 ; j<i ; j++){
		printf("%d\n", golomb(input_arr[j]) );
	}
		
	return 0;
}