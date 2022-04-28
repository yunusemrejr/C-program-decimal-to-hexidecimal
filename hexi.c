#include <stdio.h>
#include <stdlib.h>


void hexi(int* array, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%08x ",array[i]);
		
	}
}

int main(int argc, char *argv[]){
	
	printf ("\n\n Welcome to decimal to hexi. I convert decimal values to hexidecimal.");
		printf ("\n\n\n" " I need 5 different decimal values and here they are: 12,13,14,15,16");
				printf ("\n\n\n" " Example: 12,13,14,15 and 16 will be :");
		int array[]={12,13,14,15,16};
hexi(array , 5);
				printf ("\n\n\n" " in hexidecimal." "\n" "\n");

				printf ("\n\n\n" " If you want to calculate with different decimals, change the array in the source code and compile again." "\n" "\n");
								printf ("\n\n\n" " -YUNUS EMRE VURGUN 2022" "\n" "\n");


return 0;
	
	
		

}
