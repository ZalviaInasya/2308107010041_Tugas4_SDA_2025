Nama : Zalvia Inasya Zulna
NPM  : 2308107010041

Penjelasan Tugas 4 Struktur Data dan Algoritma
1. Tujuan Tugas
Tugas ini bertujuan untuk melakukan analisis mendalam serta perbandingan performa dari berbagai algoritma pengurutan (sorting) dengan mempertimbangkan dua aspek utama, yaitu waktu eksekusi dan penggunaan memori. Analisis ini dilakukan dengan menerapkan algoritma-algoritma sorting tersebut pada dataset yang memiliki variasi dalam hal ukuran (jumlah data) serta tipe data (angka dan kata). Dengan membandingkan hasil pengujian dari berbagai skenario, diharapkan dapat diperoleh pemahaman yang lebih komprehensif mengenai efisiensi dan efektivitas masing-masing algoritma sorting, sehingga dapat ditentukan algoritma mana yang paling optimal untuk digunakan pada kondisi atau kebutuhan tertentu.

2. Deskripsi Program  
Program ini melakukan perbandingan performa dari enam algoritma sorting yang berbeda (Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort, dan Shell Sort) dalam mengurutkan dua jenis data: angka dan kata. Perbandingan dilakukan berdasarkan waktu eksekusi dan penggunaan memori, dengan melakukan pengujian pada dataset dengan ukuran bervariasi yaitu mulai dari 10.000, 50.000, 100.000, 250.000, 500.000, 1.000.000, 1.500.000, hingga 2.000.000.

3. Algoritma yang Diimplementasikan 
   - Bubble Sort    : Membandingkan elemen bersebelahan dan menukarnya jika urutannya salah.
   - Selection Sort : Mencari elemen terkecil dan menukarnya dengan elemen pertama, kedua, dst.
   - Insertion Sort : Menyisipkan elemen ke posisi yang tepat dalam bagian array yang sudah terurut.
   - Merge Sort     : Membagi array, mengurutkan rekursif, lalu menggabungkan kembali.
   - Quick Sort     : Memilih pivot dan mempartisi array menjadi elemen yang < pivot dan > pivot.
   - Shell Sort     : Pengembangan dari Insertion Sort dengan perbandingan elemen berjauhan.

4. Hasil Pengujian
   - Algoritma dengan kompleksitas O(n²) (Bubble, Selection, Insertion Sort) menunjukkan performa yang sangat buruk pada dataset besar.
   - Algoritma dengan kompleksitas O(n log n) (Merge, Quick, Shell Sort) memiliki performa jauh lebih baik.
   - Sorting data kata konsisten membutuhkan waktu lebih lama dan memori lebih besar dibandingkan data angka.
   - Semua algoritma menunjukkan pola penggunaan memori yang identik yang meningkat secara linear dengan ukuran data.

5. Kesimpulan
Pemilihan algoritma sorting yang tepat bergantung pada karakteristik data dan kebutuhan aplikasi. Quick Sort dan Merge Sort adalah pilihan optimal untuk dataset besar, dengan Quick Sort unggul dalam kecepatan eksekusi. Tipe data mempengaruhi performa algoritma secara signifikan, dengan data kata membutuhkan waktu dan memori lebih besar. Penggunaan memori meningkat secara linear dengan ukuran data dan hampir identik untuk semua algoritma, sehingga pemilihan algoritma lebih ditentukan oleh kebutuhan waktu eksekusi.
