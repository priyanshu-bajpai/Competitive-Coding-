# include <stdio.h>

int main()
{
	float a, b, c;

	while(1)
	{
		scanf("%f %f %f",&a,&b,&c);
		if(a==0&&b==0&&c==0)
			break;

		if((b-a) == (c-b))
		{
			int answer =c + (c-b);
			printf("AP %d\n",answer);
		}
		if((c/b)==(b/a)){
			int answer = c * (c/b);
			printf("GP %d\n",answer);
		}
	}
return 0;
}