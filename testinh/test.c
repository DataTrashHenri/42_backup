#include<unistd.h>
void fizzbuzz()
{
	for (int i = 1; i <= 100; i++)
	{
		char c1 = (i/10) + 48;
		char c2 = (i%10) + 48;

		if (i%3 == 0 && i%5 == 0)
			write(1,"fizzbuzz",9);	
		else if (i%3 == 0)
			write(1,"fizz",5);
		else if (i%5 == 0)
			write(1,"buzz",5);
		else
		{
			if(i>9)
				write(1,&c1,1);
			write(1,&c2,1);
		}
		write(1,"\n",1);
	}
	
}

int main()
{
	fizzbuzz();
}