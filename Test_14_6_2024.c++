
#include <iostream>

int main() {
    // C?p phát b? nh? d?ng cho m?t bi?n int
    int* ptr = new int;
    int n;
    // Gán giá tr? cho bi?n dó
    *ptr = 100;
    // In ra giá tr? c?a bi?n
    std::cout << "Gia tri: " << *ptr << std::endl;
    
    // Gi?i phóng b? nh? dã c?p phát
    delete ptr;

    // C?p phát b? nh? d?ng cho m?t m?ng int
    int* mang = new int[n];
    std::cout<<"Nhap so phan tu: ";
    std::cin>>n;
    std::cout<<std::endl;
    // Gán giá tr? cho các ph?n t? c?a m?ng
    for(int i = 0; i < n; ++i) {
        mang[i] = i * 10;
    }

    // In ra giá tr? c?a các ph?n t? trong m?ng
    std::cout << "Mang gia tri: " << std::endl;
    for(int i = 0; i < n; ++i) {
        std::cout << mang[i] << " ";
        if(mang[i] < n*10 && mang[i] > 0)
        {
            std::cout<<"Yes"<<std::endl;
        }
        else 
        {
            std::cout<<"No"<<std::endl;
        }
    }
    std::cout << std::endl;

    // Gi?i phóng b? nh? dã c?p phát cho m?ng
    delete[] mang;

    return 0;
}
