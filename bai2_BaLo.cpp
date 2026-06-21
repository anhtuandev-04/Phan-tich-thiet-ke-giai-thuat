#include <stdio.h>

typedef struct {
    char ten;
    int trongLuong;
    int giaTri;
} DoVat;

void sapXepTheoTiLe(DoVat dv[], int n) {
    float tiLe[n];
    int i, j;
    DoVat temp;

    for (i = 0; i < n; i++) {
        tiLe[i] = (float)dv[i].giaTri / dv[i].trongLuong;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (tiLe[i] < tiLe[j]) {
                temp = dv[i];
                dv[i] = dv[j];
                dv[j] = temp;

                float tempTiLe = tiLe[i];
                tiLe[i] = tiLe[j];
                tiLe[j] = tempTiLe;
            }
        }
    }
}

void caiBaLo(DoVat dv[], int n, int W) {
    int soLuong[n];  
    int giaTriTong = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        if (dv[i].trongLuong <= W) {
            soLuong[i] = W / dv[i].trongLuong;
            W -= soLuong[i] * dv[i].trongLuong;
            giaTriTong += soLuong[i] * dv[i].giaTri;
        }
    }

    for (i = 0; i < n; i++) {
        printf("So do vat %c duoc lay la: %d\n", dv[i].ten, soLuong[i]);
    }
    printf("Tong gia tri cua balo la: %.2f\n", (float)giaTriTong);
}

int main() {
    int W;
    int n = 4;
    DoVat dv[n];
    int i;

    printf("--Bai Toan Cai Ba Lo--\n");
    printf("Nhap Trong luong cai balo: ");
    scanf("%d", &W);
    
    for (i = 0; i < n; i++) {
        printf("Nhap Ten Do Vat Thu %d: ", i + 1);
        scanf(" %c", &dv[i].ten);
        printf("Nhap trong luong do vat thu %d: ", i + 1);
        scanf("%d", &dv[i].trongLuong);
        printf("Nhap gia tri do vat thu %d: ", i + 1);
        scanf("%d", &dv[i].giaTri);
    }

    sapXepTheoTiLe(dv, n);
    caiBaLo(dv, n, W);

    return 0;
}
