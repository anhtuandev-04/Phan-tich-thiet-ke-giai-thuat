#include<stdio.h>

int min(int n, int m, int d[], int num[]) {
    int i, j, min;
    int dp[n + 1];
    int Use[n + 1][m];

    dp[0] = 0;

    for(i = 1; i <= n; i++) {
        dp[i] = 99999;  
    }

    for(i = 0; i <= n; i++) {
        for(j = 0; j < m; j++) {
            Use[i][j] = 0;
        }
    }

    for(i = 0; i < m; i++) {
        for(j = d[i]; j <= n; j++) {
            if(dp[j - d[i]] + 1 < dp[j]) {
                dp[j] = dp[j - d[i]] + 1;
                Use[j][i] = Use[j - d[i]][i] + 1;
            }
        }
    }

    printf("\nMenh gia   So to tien\n");
    for(i = 0; i < m; i++) {
        printf("%8d %8d\n", d[i], Use[n][i]);
    }

    return dp[n];
}

int main() {
    int n, m;
    int d[10];  
    int num[10];  

    printf("Nhap so tien can doi: "); scanf("%d", &n);
    printf("Nhap so loai menh gia: "); scanf("%d", &m);
    
    printf("Nhap cac menh gia tien:\n");
    for(int i = 0; i < m; i++) {
    	printf("Menh gia thu %d :",i+1);
        scanf("%d", &d[i]);
    }

    int KQ = min(n, m, d, num);

    printf("\nSo to tien it nhat can dung la: %d\n", KQ);

    return 0;
}
