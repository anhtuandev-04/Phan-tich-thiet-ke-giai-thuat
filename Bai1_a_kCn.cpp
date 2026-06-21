//Ky thuat vet can
#include<stdio.h>

int GT(int n){
	if(n == 0 || n == 1) return 1;
	else 
		return n * GT(n-1);
}

long long HS_NT(int n, int k){
	return GT(n) / (GT(k) * GT(n-k));
}

int main(){
	int n,k;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap k: ");
	scanf("%d", &k);
	
	int KQ = HS_NT(n,k);
	printf("%dC%d = %d\n",n,k,KQ);
	return 0;
}
