//Quy hoach dong
#include<stdio.h>

long QH_dong(int n, int k){
	long C[n+1][k+1];
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=i && j<=k;j++){
			if(j==0 || j==i)
				C[i][j] = 1;
			else
				C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	return C[n][k];
}

int main(){
	int n,k;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap k: ");
	scanf("%d", &k);
	
	long long KQ = QH_dong(n,k);
	printf("%dC%d = %d\n",n,k,KQ);
	return 0;
}
