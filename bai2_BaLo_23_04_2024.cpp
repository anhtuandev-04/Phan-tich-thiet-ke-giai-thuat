#include<stdio.h>
#include<string.h>

// Cau truc do vat
typedef struct {
    char Ten[30];
    int GiaTri;
    int TrongLuong;
    int SoLuong;
    float DonGia;
} DoVat;
// Cau truc bang luu gia tri va so luong vat
typedef int Bang[50][100];

//// Ham giai thua
//long GiaiThua(int n) {
//    long kq = 1;
//    for(int i = 1; i <= n; i++)
//        kq *= i;
//    return kq;
//}
//
//int Comb_VetCan(int n, int k) {
//    return (GiaiThua(n) / (GiaiThua(k) * GiaiThua(n - k)));
//}
//
//int Comb_ChiaTri(int n, int k) {
//    if(k == 0 || k == n)
//        return 1;
//    return (Comb_ChiaTri(n - 1, k - 1) + Comb_ChiaTri(n - 1, k));
//}
//
//int Comb_QHD(int n, int k) {
//    int C[10][10];
//    C[0][0] = 1;
//    for(int i = 1; i <= n; i++) {
//        C[i][0] = 1;
//        C[i][i] = 1;
//        for(int j = 1; j <= i - 1; j++) {
//            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
//        }
//    }
//    return (C[n][k]);
//}

void NhapDoVat(DoVat Dv[], int SoLoaiDoVat) {
    printf("\nNhap thong tin cho cac loai do vat");
    for(int i = 0; i < SoLoaiDoVat; i++) {
        printf("\nNhap ten do vat thu %d la: ", i + 1);
        fflush(stdin);
        gets(Dv[i].Ten);
        printf("\nNhap trong luong cua do vat thu %d la: ", i + 1);
        scanf("%d", &Dv[i].TrongLuong);
        printf("\nNhap gia tri cua do vat thu %d la: ", i + 1);
        scanf("%d", &Dv[i].GiaTri);
        Dv[i].SoLuong = 0;
        Dv[i].DonGia = 0;
    }
}

void TaoBang_Balo(DoVat Dv[], int n, int w, Bang F, Bang X) {
    int xk, yk, k, FMax, XMax, v;
    // dien gia tri cho dong dau tien
    for(v = 0; v <= w; v++) {
        X[0][v] = v / Dv[0].TrongLuong;
        F[0][v] = X[0][v] * Dv[0].GiaTri;
    }
    for(k = 1; k < n; k++) {
        for(v = 0; v <= w; v++) {
            FMax = 0;
            XMax = 0; 
            yk = v / Dv[k].TrongLuong;
            for(xk = 0; xk <= yk; xk++) {
                if(F[k - 1][v - xk * Dv[k].TrongLuong] + xk * Dv[k].GiaTri > FMax) {
                    FMax = F[k - 1][v - xk * Dv[k].TrongLuong] + xk * Dv[k].GiaTri;
                    XMax = xk;
                }
            }
            X[k][v] = XMax;  
            F[k][v] = FMax;  
        }
    }
}
void TraBang_Balo(DoVat Dv[], int n, int w, Bang F, Bang X) {
    printf("\nBang gia tri va so luong do vat\n");
    
    printf("%8s", "");
    for(int j = 0; j <= w; j++) {
        printf("%4d", j);
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
        printf("%8d", i); 

        for(int j = 0; j <= w; j++) {
            printf("%4d", F[i][j]);
        }
        printf("\n");
    }

    printf("\nBang so luong do vat duoc chon\n");
    printf("%8s", "");
    for(int j = 0; j <= w; j++) {
        printf("%4d", j);
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
        printf("%8d", i);  

        for(int j = 0; j <= w; j++) {
            printf("%4d", X[i][j]);
        }
        printf("\n");
    }
}

int main() {
	Bang F, X;
    int n, k;
    int w, SoLuong;
    DoVat Dv[20];
    int SoLoaiDoVat;
    
//    printf(" CAU 1 TINH TO HOP CHAP K CUA N.\n");
//    printf("Nhap n : "); scanf("%d", &n);
//    do {
//        printf("Nhap k <= n : "); scanf("%d", &k);
//        if (k > n) {
//            printf("Nhap k <= n : "); scanf("%d", &k);
//        }
//    } while (k > n);
    
//    printf("\nTinh to hop chap %dC%d theo thuat toan Chia va Tri : %d\n", n, k, Comb_ChiaTri(n, k));
//    printf("Tinh to hop chap %dC%d theo thuat toan Vet Can : %d\n", n, k, Comb_VetCan(n, k));
//    printf("Tinh to hop chap %dC%d theo thuat toan Quy hoach dong : %d\n", n, k, Comb_QHD(n, k));
    
    printf("\nCAU 2 BAI TOAN CAI BALO.\n");
    printf("Nhap trong luong balo: "); scanf("%d", &w);
    printf("Nhap so loai do vat: "); scanf("%d", &SoLoaiDoVat);
    fflush(stdin);
    
    NhapDoVat(Dv, SoLoaiDoVat);
    TaoBang_Balo(Dv, SoLoaiDoVat, w, F, X);
	TraBang_Balo(Dv, SoLoaiDoVat, w, F, X);
return 0;
}
