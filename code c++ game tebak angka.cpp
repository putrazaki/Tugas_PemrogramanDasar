#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // Diperlukan untuk std::numeric_limits

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Inisialisasi seed untuk random
    char lagi;

    do {
        int angkaRahasia = std::rand() % 100 + 1; // Angka rahasia antara 1 dan 100
        int tebakan;
        int jumlahTebakan = 0;

        std::cout << "Selamat datang di permainan Tebak Angka!" << std::endl;
        std::cout << "Saya sudah memilih angka antara 1 dan 100." << std::endl;

        do {
            std::cout << "Masukkan tebakan Anda: ";
            while (!(std::cin >> tebakan)) {
                std::cout << "Input tidak valid. Silakan masukkan angka: ";
                std::cin.clear(); // Menghapus kesalahan
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Mengabaikan input yang salah
            }
            jumlahTebakan++;

            if (tebakan > angkaRahasia) {
                std::cout << "Tebakan Anda terlalu tinggi. Coba lagi!" << std::endl;
            } else if (tebakan < angkaRahasia) {
                std::cout << "Tebakan Anda terlalu rendah. Coba lagi!" << std::endl;
            } else {
                std::cout << "Selamat! Anda berhasil menebak angka " << angkaRahasia 
                          << " dalam " << jumlahTebakan << " tebakan!" << std::endl;
            }

            // Mengabaikan sisa input (newline)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } while (tebakan != angkaRahasia);

        std::cout << "Apakah Anda ingin bermain lagi? (y/n): ";
        std::cin >> lagi;
        // Mengabaikan newline setelah input karakter
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (lagi == 'y' || lagi == 'Y');

    std::cout << "Terima kasih telah bermain!" << std::endl;

    return 0;
}

