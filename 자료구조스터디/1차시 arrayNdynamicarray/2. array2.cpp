#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int a[3];
	int i;
	
	a[0] = 11;
	a[1] = 22;
	a[2] = 33;
	
	printf("size = %d\n",sizeof(a)); // 사이즈를 직접 지정. 한번 지정하면 바꿀 수 없다. 
	for(i=0;i<3;++i)
		printf("%d\n",a[i]);
	return 0;
}
