#include <stdio.h>
#include <string.h>

typedef struct {
    char ten[30];
    int gia;
    int soto;
} Tien;

void nhapThongTin(Tien toGiay[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Nhap ten cua to giay bac thu %d: ", i + 1);
        scanf("%s", toGiay[i].ten);
        printf("Nhap gia tri cua to giay bac %s: ", toGiay[i].ten);
        scanf("%d", &toGiay[i].gia);
        toGiay[i].soto = 0;
    }
}

void sapXep(Tien toGiay[], int n) {
    int i, j;
    Tien temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (toGiay[i].gia < toGiay[j].gia) {
                temp = toGiay[i];
                toGiay[i] = toGiay[j];
                toGiay[j] = temp;
            }
        }
    }
}

void rutTienATM(Tien toGiay[], int n, int soTien) {
    int i;

    for (i = 0; i < n; i++) {
        if (soTien >= toGiay[i].gia) {
            toGiay[i].soto = soTien / toGiay[i].gia;
            soTien = soTien % toGiay[i].gia;
        }
    }

    if (soTien != 0) {
        printf("Không the rut dung so tien yeu cau.\n");
    } else {
        printf("So tien can rut:\n");
        for (i = 0; i < n; i++) {
            if (toGiay[i].soto > 0) {
                printf("%d to %s\n", toGiay[i].soto, toGiay[i].ten);
            }
        }
    }
}

int main() {
    int soTien = 1290000;
    Tien toGiay[4];
    int n = 4;

    nhapThongTin(toGiay, n);
    sapXep(toGiay, n);
    rutTienATM(toGiay, n, soTien);

    return 0;
}
