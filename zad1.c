// liczy ile jest jedynek w rozwinieciu dwojkowym 

#include <stdio.h>

int main(){

	int x = 2018;
	int y = 0;

	asm volatile(
		".intel_syntax noprefix;"

		"mov eax,%1;"
		"mov ebx,0;"
		"mov ecx,0;"

		"petla:"
			"shl eax;"
			"jnc skok;"
				"add ebx, 1;"
			"skok:" 
				"add ecx,1;"
				"cmp ecx,32;"  // compare - porownuje (odejmowanie bez zapisu wartosci)
				"jnz petla;"
				"mov %0,ebx;"

		".att_syntax prefix;"

		:"=r" (y)
		:"r" (x)
		:"eax", "ebx", "ecx"
	);
	printf("Y = %i\n",y);
	return 0;
}
