<h1>Ruangan Kelas</h1>
<h2>Tugas Besar Praktikum Grafik Komputer</h2>
<h2>Kelompok 5</h2>
<ul> Anggota :
  <li>Alamahul Bayan (2306163)</li>
  <li>Agna Fadia (2306145)</li>
  <li>Ramdhani Sulaeman Burhanudin(2306161)</li>
</ul>

  Dalam pembuatan objek 3D ruangan kelas menggunakan OpenGL, dilakukan pemodelan berbagai elemen yang merepresentasikan ruangan kelas, seperti lantai, dinding, pintu, jendela, dan komponen pendukung lainnya. Berikut adalah konsep yang digunakan dalam proses pembuatan:
1. Pemodelan Objek dengan Fungsi Balok <br>
      a.	Fungsi balok() digunakan untuk menggambar objek berbentuk kubus dengan warna, kilauan, dan dimensi yang dapat disesuaikan. Objek ini menjadi dasar dalam membentuk elemen-elemen ruangan seperti dinding, lantai, atap, pintu, dan sebagainya. <br>
      b.	Material objek diatur melalui parameter glMaterialfv() untuk memberikan efek pencahayaan realistis, termasuk warna ambient, diffuse, dan specular. <br>
2. Sistem Pencahayaan <br>
      a.	Fungsi light() mengatur pencahayaan dalam ruangan menggunakan sumber cahaya GL_LIGHT0. Posisi, warna ambient, diffuse, dan specular disesuaikan untuk menciptakan suasana yang lebih realistis. <br>
      b.	Pengguna dapat mengaktifkan atau menonaktifkan lampu menggunakan tombol tertentu. <br>
3. Koordinat Kartesius <br>
      a.	Fungsi drawCartecius() digunakan untuk menampilkan koordinat kartesius sebagai referensi visual dalam pengaturan posisi objek. Sumbu X, Y, dan Z digambarkan menggunakan garis dan teks sebagai penanda. <br>
4. Elemen Ruangan
      a.	Lantai: Dibentuk dengan fungsi lantai(), memanfaatkan objek balok dengan dimensi dan posisi yang sesuai. <br>
      b.	Dinding: Fungsi dinding_kiri(), dinding_kanan(), dinding_belakang(), dan dinding_depan() digunakan untuk membangun struktur dinding ruangan. <br>
      c.	Atap: Dibuat dengan fungsi atap(), memberikan penutup untuk ruangan. <br>
      d.	Pintu: Fungsi pintu() membuat pintu dengan detail seperti daun pintu dan gagang. <br>
5. Komponen Pendukung
      a.	AC: Dibentuk menggunakan fungsi AC(), memanfaatkan balok dengan dimensi dan posisi yang menyerupai unit AC. <br>
      b.	Bor: Fungsi bor() merepresentasikan papan tulis di ruangan kelas. <br>
6. Interaksi Pengguna
      a.	Pengguna dapat mengatur posisi kamera menggunakan tombol navigasi (w, a, s, d, z, x) untuk melihat ruangan dari berbagai sudut. <br>
      b.	Rotasi ruangan diatur dengan tombol q dan e.<br>
      c.	Tombol k digunakan untuk menampilkan koordinat kartesius, sedangkan tombol l untuk mengontrol pencahayaan.<br>
7. Main Loop
      a.	Fungsi main() menginisialisasi jendela OpenGL dengan pengaturan awal seperti mode tampilan, ukuran jendela, dan callback untuk keyboard serta display.<br>
