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
	
	printf("size = %d\n",sizeof(a)); // ����� ���� ����. �ѹ� �����ϸ� �ٲ� �� ����. 
	for(i=0;i<3;++i)
		printf("%d\n",a[i]);
	return 0;
}
