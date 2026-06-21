//Chia de tri
#include<stdio.h>

long long CVT(int n, int k){
	if(k == 0 || k == n) return 1;
	else 
		return CVT(n-1, k-1) + CVT(n-1, k);
}

int main(){
	int n,k;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap k: ");
	scanf("%d", &k);
	
	long long KQ = CVT(n,k);
	printf("%dC%d = %d\n",n,k,KQ);
	return 0;
}
