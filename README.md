# Tic Tac Toe

Basit bir C++ Tic Tac Toe oyunu. İki oyuncu sırasıyla X ve O işaretlerini koyar ve üç aynı işareti yatay, dikey veya çapraz çizgide tamamlayan oyuncu kazanır.

## Dosyalar

- `ttt.cpp` - oyunun ana kaynağı.
- `.gitignore` - derleme çıktısı ve yerel ayarların Git deposuna dahil edilmemesi için.
- `LICENSE` - MIT lisansı.

## Gereksinimler

- C++ derleyicisi (örneğin `g++`, `clang++`, Visual Studio `cl`).

## Derleme

Windows için örnek:

```powershell
cd "c:\Users\ismet\OneDrive\Masaüstü\Tum_Yazilim_Dilleri\C++\tic-tac-toe"
g++ ttt.cpp -o ttt.exe
```

Linux / macOS için örnek:

```bash
g++ ttt.cpp -o ttt
```

## Çalıştırma

Windows:

```powershell
./ttt.exe
```

Linux / macOS:

```bash
./ttt
```

## Oyun Kullanımı

- Oyunculardan isimleri istenir.
- Sayıları 1-9 arasında seçip tahtadaki karşılık gelen hücreye işaret koyarsınız.
- Hücre doluysa ya da yanlış bir sayı girildiyse tekrar sorulur.
- Oyun bitince kazanan veya beraberlik durumu ekrana yazdırılır.

## Notlar

- `a.exe` veya diğer derleme çıktıları Git deposuna dahil edilmemelidir.
- `__MACOSX` gibi geçici veya sistem dosyaları da depoya eklenmemelidir.
