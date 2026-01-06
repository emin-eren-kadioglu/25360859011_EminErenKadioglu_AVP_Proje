#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define GEZEGEN_SAYISI 8
#define PI 3.14159265358979323846

const double g_sabitleri[GEZEGEN_SAYISI] = {3.70, 8.87, 9.807, 3.71, 24.79, 10.44, 8.69, 11.15};
const char gezegen_isimleri[GEZEGEN_SAYISI][10] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};

void serbest_dusme(const double *g_ptr, const char (*isim_ptr)[10]);
void yukari_atis(const double *g_ptr, const char (*isim_ptr)[10]);
void agirlik_hesapla(const double *g_ptr, const char (*isim_ptr)[10]);
void potansiyel_enerji(const double *g_ptr, const char (*isim_ptr)[10]);
void hidrostatik_basinc(const double *g_ptr, const char (*isim_ptr)[10]);
void arsimet_kaldirma(const double *g_ptr, const char (*isim_ptr)[10]);
void basit_sarkac(const double *g_ptr, const char (*isim_ptr)[10]);
void ip_gerilmesi(const double *g_ptr, const char (*isim_ptr)[10]);
void asansor_deneyi(const double *g_ptr, const char (*isim_ptr)[10]);

double mutlak_deger_al(double deger) {
    return (deger < 0) ? -deger : deger;
}

int main() {
    char bilim_insani[50];
    int secim = 0;

    printf("------------------------------------------------\n");
    printf("BURSA TEKNIK UNIVERSITESI UZAY SIMULATORU\n");
    printf("------------------------------------------------\n");
    printf("Lutfen bilim insani adinizi giriniz: ");
    fgets(bilim_insani, 50, stdin);

    while (secim != -1) {
        printf("\n================================================\n");
        printf("Sn. %s Lutfen Deney Seciniz:\n", bilim_insani);
        printf("================================================\n");
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkac Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n");
        printf("CIKIS ICIN -1 GIRINIZ\n"); 
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: serbest_dusme(g_sabitleri, gezegen_isimleri); break;
            case 2: yukari_atis(g_sabitleri, gezegen_isimleri); break;
            case 3: agirlik_hesapla(g_sabitleri, gezegen_isimleri); break;
            case 4: potansiyel_enerji(g_sabitleri, gezegen_isimleri); break;
            case 5: hidrostatik_basinc(g_sabitleri, gezegen_isimleri); break;
            case 6: arsimet_kaldirma(g_sabitleri, gezegen_isimleri); break;
            case 7: basit_sarkac(g_sabitleri, gezegen_isimleri); break;
            case 8: ip_gerilmesi(g_sabitleri, gezegen_isimleri); break;
            case 9: asansor_deneyi(g_sabitleri, gezegen_isimleri); break;
            case -1: printf("Simulasyon sonlandiriliyor...\n"); break;
            default: printf("Gecersiz secim! Lutfen tekrar deneyiniz.\n");
        }
    }

    return 0;
}

// 1. Serbest Düşme Deneyi 
void serbest_dusme(const double *g_ptr, const char (*isim_ptr)[10]) {
    double t, h;
    printf("\n--- Serbest Dusme Deneyi ---\n");
    printf("Sureyi (t) saniye cinsinden giriniz: ");
    scanf("%lf", &t);
    t = mutlak_deger_al(t);

    printf("\nSonuclar (t = %.2f saniye icin):\n", t);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        h = 0.5 * g * t * t; // Formül (1)
        printf("%-10s -> Dusulen Yukseklik (h): %.2f m\n", (char *)(isim_ptr + i), h);
    }
}

// 2. Yukarı Atış Deneyi
void yukari_atis(const double *g_ptr, const char (*isim_ptr)[10]) {
    double v0, h_max;
    printf("\n--- Yukari Atis Deneyi ---\n");
    printf("Firlatma hizini (v0) m/s cinsinden giriniz: ");
    scanf("%lf", &v0);
    v0 = mutlak_deger_al(v0);

    printf("\nSonuclar (v0 = %.2f m/s icin):\n", v0);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        h_max = (v0 * v0) / (2 * g); // Formül (2)
        printf("%-10s -> Maksimum Yukseklik (h_max): %.2f m\n", (char *)(isim_ptr + i), h_max);
    }
}

// 3. Ağırlık Deneyi 
void agirlik_hesapla(const double *g_ptr, const char (*isim_ptr)[10]) {
    double m, G;
    printf("\n--- Agirlik Deneyi ---\n");
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);
    m = mutlak_deger_al(m);

    printf("\nSonuclar (m = %.2f kg icin):\n", m);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        G = m * g; // Formül (3)
        printf("%-10s -> Agirlik (G): %.2f N\n", (char *)(isim_ptr + i), G);
    }
}

// 4. Kütleçekimsel Potansiyel Enerji Deneyi 
void potansiyel_enerji(const double *g_ptr, const char (*isim_ptr)[10]) {
    double m, h, Ep;
    printf("\n--- Kutlecekimsel Potansiyel Enerji Deneyi ---\n");
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);
    m = mutlak_deger_al(m);
    
    printf("Yuksekligi (h) metre cinsinden giriniz: ");
    scanf("%lf", &h);
    h = mutlak_deger_al(h);

    printf("\nSonuclar (m = %.2f kg, h = %.2f m icin):\n", m, h);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        Ep = m * g * h; // Formül (4)
        printf("%-10s -> Potansiyel Enerji (Ep): %.2f J\n", (char *)(isim_ptr + i), Ep);
    }
}

// 5. Hidrostatik Basınç Deneyi
void hidrostatik_basinc(const double *g_ptr, const char (*isim_ptr)[10]) {
    double rho, h, P;
    printf("\n--- Hidrostatik Basinc Deneyi ---\n");
    printf("Sivinin yogunlugunu (rho) kg/m^3 cinsinden giriniz: ");
    scanf("%lf", &rho);
    rho = mutlak_deger_al(rho);

    printf("Derinligi (h) metre cinsinden giriniz: ");
    scanf("%lf", &h);
    h = mutlak_deger_al(h);

    printf("\nSonuclar (rho = %.2f kg/m^3, h = %.2f m icin):\n", rho, h);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        P = rho * g * h; // Formül (5)
        printf("%-10s -> Hidrostatik Basinc (P): %.2f Pa\n", (char *)(isim_ptr + i), P);
    }
}

// 6. Arşimet Kaldırma Kuvveti Deneyi
void arsimet_kaldirma(const double *g_ptr, const char (*isim_ptr)[10]) {
    double rho, V, Fk;
    printf("\n--- Arsimet Kaldirma Kuvveti Deneyi ---\n");
    printf("Sivinin yogunlugunu (rho) kg/m^3 cinsinden giriniz: ");
    scanf("%lf", &rho);
    rho = mutlak_deger_al(rho);

    printf("Cismin batan hacmini (V) m^3 cinsinden giriniz: ");
    scanf("%lf", &V);
    V = mutlak_deger_al(V);

    printf("\nSonuclar (rho = %.2f kg/m^3, V = %.4f m^3 icin):\n", rho, V);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        Fk = rho * g * V; // Formül (6)
        printf("%-10s -> Kaldirma Kuvveti (Fk): %.2f N\n", (char *)(isim_ptr + i), Fk);
    }
}

// 7. Basit Sarkaç Periyodu Deneyi
void basit_sarkac(const double *g_ptr, const char (*isim_ptr)[10]) {
    double L, T;
    printf("\n--- Basit Sarkac Periyodu Deneyi ---\n");
    printf("Sarkacin uzunlugunu (L) metre cinsinden giriniz: ");
    scanf("%lf", &L);
    L = mutlak_deger_al(L);

    printf("\nSonuclar (L = %.2f m icin):\n", L);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        T = 2 * PI * sqrt(L / g); // Formül (7)
        printf("%-10s -> Periyot (T): %.2f s\n", (char *)(isim_ptr + i), T);
    }
}

// 8. Sabit İp Gerilmesi Deneyi
void ip_gerilmesi(const double *g_ptr, const char (*isim_ptr)[10]) {
    double m, T;
    printf("\n--- Sabit Ip Gerilmesi Deneyi ---\n");
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);
    m = mutlak_deger_al(m);

    printf("\nSonuclar (m = %.2f kg icin):\n", m);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        T = m * g; // Formül (8)
        printf("%-10s -> Ip Gerilmesi (T): %.2f N\n", (char *)(isim_ptr + i), T);
    }
}

// 9. Asansör Deneyi
void asansor_deneyi(const double *g_ptr, const char (*isim_ptr)[10]) {
    double m, a, N;
    int durum;

    printf("\n--- Asansor Deneyi ---\n");
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);
    m = mutlak_deger_al(m);

    printf("Asansorun ivmesini (a) m/s^2 cinsinden giriniz: ");
    scanf("%lf", &a);
    a = mutlak_deger_al(a);

    printf("Hareket yonunu seciniz:\n");
    printf("1. Yukari Hizlanan veya Asagi Yavaslayan (g + a)\n");
    printf("2. Asagi Hizlanan veya Yukari Yavaslayan (g - a)\n");
    printf("Secim: ");
    scanf("%d", &durum);

    printf("\nSonuclar:\n");
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        
        // Formül (9) ve (9.1)
        if (durum == 1) {
            N = m * (g + a);
        } else {
            N = m * (g - a);
        }
        
        printf("%-10s -> Etkin Agirlik (N): %.2f N\n", (char *)(isim_ptr + i), N);
    }
}



