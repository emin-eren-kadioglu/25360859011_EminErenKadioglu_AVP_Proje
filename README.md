# Konsol Tabanlı Uzay Simülasyonu 🚀🪐

Bu proje, **Bursa Teknik Üniversitesi Bilgisayar Mühendisliği Bölümü** 2025-2026 Güz Dönemi **Algoritmalar ve Programlama** dersi kapsamında geliştirilmiş, C dili ile yazılmış bir fizik simülasyonu uygulamasıdır.

## 📝 Proje Hakkında

Program, bir bilim insanı senaryosu üzerinden Güneş Sistemi'ndeki 8 farklı gezegende temel fiziksel olayların (serbest düşme, potansiyel enerji, basınç vb.) nasıl gerçekleştiğini simüle eder. Kullanıcıdan alınan veriler (kütle, uzunluk, hız vb.) her gezegenin yerçekimi ivmesine ($g$) göre işlenir ve karşılaştırmalı sonuçlar sunulur.

### 👨‍💻 Geliştirici Bilgileri
* **Adı Soyadı:** Emin Eren KADIOĞLU
* **Öğrenci No:** 25360859011
* **Bölüm:** Bilgisayar Mühendisliği

---

## 🌟 Özellikler

* **9 Farklı Fizik Deneyi:** Mekanik ve akışkanlar mekaniği konularını kapsayan geniş simülasyon yelpazesi.
* **8 Gezegen Desteği:** Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs ve Neptün için özel yerçekimi sabitleri.
* **Dinamik Menü Sistemi:** Kullanıcı çıkış yapana kadar devam eden döngüsel yapı.
* **Hata Yönetimi:** Negatif girilen fiziksel büyüklüklerin (kütle, uzunluk vb.) otomatik düzeltilmesi.
* **Teknik Yetkinlik:**
    * İleri seviye bellek yönetimi (Pointer Aritmetiği).
    * Modüler fonksiyon yapısı.
    * Koşullu operatör (Ternary) kullanımı.

---

## 🧪 Mevcut Deneyler

Simülasyon kapsamında aşağıdaki deneyler yapılabilmektedir:

1.  **Serbest Düşme Deneyi:** Belirli bir sürede düşülen mesafenin ($h$) hesabı.
2.  **Yukarı Atış Deneyi:** İlk hızla fırlatılan cismin çıkabileceği maksimum yükseklik ($h_{max}$).
3.  **Ağırlık Deneyi:** Kütlenin farklı gezegenlerdeki ağırlık ($G$) karşılığı.
4.  **Kütleçekimsel Potansiyel Enerji Deneyi:** Konuma bağlı enerji ($E_p$) hesabı.
5.  **Hidrostatik Basınç Deneyi:** Sıvıların derinliğe bağlı basınç ($P$) değişimi.
6.  **Arşimet Kaldırma Kuvveti Deneyi:** Sıvı içindeki cisme etki eden kuvvet ($F_k$).
7.  **Basit Sarkaç Periyodu Deneyi:** Sarkacın salınım süresi ($T$).
8.  **Sabit İp Gerilmesi Deneyi:** Asılı kütlenin ipte oluşturduğu gerilme.
9.  **Asansör Deneyi:** İvmeli hareket eden sistemlerdeki "etkin ağırlık" simülasyonu.

---

## ⚙️ Teknik Detaylar (Kod Yapısı)

Proje, dersin teknik gereksinimlerini tam olarak karşılayacak şekilde tasarlanmıştır:

* **Pointer Aritmetiği:** Dizilere erişim standart indeksleme (`dizi[i]`) yerine, bellek adresleri üzerinden pointer aritmetiği (`*(dizi + i)`) ile sağlanmıştır.
* **Ternary Operatörü:** Kullanıcı hatalarını önlemek için `if-else` blokları yerine ternary yapısı (`koşul ? doğru : yanlış`) kullanılarak negatif değer kontrolü yapılmıştır.
* **Modülerlik:** Her deney `void` tipinde ayrı bir fonksiyon olarak yazılmış, ana fonksiyondan parametre (pointer) geçirilerek çağrılmıştır.

---

## 🚀 Kurulum ve Çalıştırma

Projeyi yerel makinenizde çalıştırmak için aşağıdaki adımları izleyebilirsiniz:

1.  **Repoyu Klonlayın:**
    ```bash
    git clone [https://github.com/emin-eren-kadioglu/25360859011_EminErenKadioglu_AVP_Proje.git](https://github.com/emin-eren-kadioglu/25360859011_EminErenKadioglu_AVP_Proje.git)
    ```
2.  **Derleyin (GCC Örneği):**
    Projeyi zipten çıkarıldıktan sonra matematik kütüphanesi (`math.h`) kullandığı için `-lm` bayrağı ile derlenmelidir.
    ```bash
    gcc main.c -o space_sim -lm
    ```
3.  **Çalıştırın:**
    ```bash
    ./space_sim
    ```

---

## 📸 Ekran Görüntüleri

<img width="854" height="279" alt="image" src="https://github.com/user-attachments/assets/0d674341-e2e6-42e3-8af5-13031de6c852" />
<img width="847" height="380" alt="image" src="https://github.com/user-attachments/assets/e835f5a5-ebe8-4b1b-95a3-fe99750c8db6" />

---

**© 2026 Emin Eren KADIOĞLU - Bursa Teknik Üniversitesi**
