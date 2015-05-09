#include <stdio.h>
#include <stdlib.h>
#include "intstack.h"

int main(void)
{
	Tintstack stack;
	char input;
	int sum=0,nro;
	
	initialize_int_stack (&stack);
	
	while(1)
	{
		puts("Anna yksinumeroinen luku tai +,-, = tai L: ");
		scanf("%c", &input);
		getchar();
		if(input=='L')
		{
			print_int_stack(&stack);
			initialize_int_stack (&stack);
			if(is_empty_int_stack(&stack))
				puts("Tyhjennys onnistui!");
			else
				puts("Tyhjennys meni vikaan!");
			break;
		}
		else if(input=='0'||input=='1'||input=='2'||input=='3'||input=='4'||input=='5'||input=='6'||input=='7'||input=='8'||input=='9')
		{
			input=input-'0';
			input=(int)input;
			push_int(&stack, input);
		}
		else if(input=='+'||input=='-'||input=='=')
		{
			if(input=='+')
			{
				sum=0;
				pop_int(&stack, &nro);
				sum+=nro;
				pop_int(&stack, &nro);
				sum+=nro;
				push_int(&stack, sum);
			}
			else if(input=='-')
			{
				sum=0;
				pop_int(&stack, &nro);
				sum+=nro;
				pop_int(&stack, &nro);
				sum-=nro;
				push_int(&stack, sum);
			}
			else
			{
				pop_int(&stack, &nro);
				printf("Tulos: %d\n", nro);
				push_int(&stack, nro);
			}
		}
		else
		{
			puts("Virheellinen syöte!");
		}
	}
	#if defined(WIN32)||defined(_WIN32)
	system("pause");
	return 0;
	#else
	return 0;
	#endif
}