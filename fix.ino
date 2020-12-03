const int pinPo = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int arr[10];
  int wadah;
  unsigned long int rataRata = 0;
  // Mengambil 10 sample pembacaan
  for (int i = 0; i < 10; i++) {
    arr[i] = analogRead(pinPo);
    delay(10);
  }
  // menyortir anggota arr dari hasil yang diukur berdasarkan ukuran
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (arr[i] > arr[j]) {
        wadah = arr[i];
        arr[i] = arr[j];
        arr[j] = wadah;
      }
    }
  }
  // simpan hasil ke-2 hingga ke-8 untuk
  // variabel tempat rataRata dihitung
  // (hilangkan dua anggota arr di awal
  // dan akhiri untuk akurasi yang lebih baik)
  for (int i = 2; i < 8; i++) {
    rataRata += arr[i];
  }
  // perhitungan nilai pH dari rataRata
  // pengukuran dan konversi ke kisaran 0-14 pH
  float nilaiMentahPH = (float)rataRata * 5.0 / 1024 / 6;
  float hasilUkurPH = -5.70 * nilaiMentahPH + 21.34;        // Ini saya kalkulasi pake rumus umum.. jadi misalnya hasilnya kurang sesuai.. mbanya bisa cari rumusnya pake metode regresi
  // Cetak Hasil ke Serial Monitor
  Serial.print("Nilai pH: ");
  Serial.println(hasilUkurPH);
  // jeda 900 ms sebelum pengukuran baru, yaitu total 1 detik
  delay(900);
}
