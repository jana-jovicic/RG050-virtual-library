# RG050-virtual-library

Virtual library je projekat rađen u okviru kursa Računarska grafika, na Matematičkom fakultetu.

### Preduslovi:
Pored GLUT potrebne su i GLFW i FTGL biblioteke.

```
sudo apt-get install freeglut3 freeglut3-dev
```
```
sudo apt-get install libglfw3-dev libglfw3
```

```
sudo apt-get install ftgl-dev
```

### Pokretanje:
```
git clone https://github.com/MATF-RG17/RG050-virtual-library
```
```
cd RG050-virtual-library
```
```
make
```
```
./main
```

### :books: Kratak opis:
Korisnik se nalazi u biblioteci i može da se kreće kroz nju i prilazi knjigama. Kada priđe dovoljno blizu određenim knjigama i pritisne taster 'o', otvoriće se novi prozor u kome je ispisan odlomak iz te knjige.

| **Komanda** | **Opis** |
| :---  | :--- |
| `w` `s` `a` `d` | Rotacija kamere |
| `↑` `↓` `←` `→`   | Kretanje po prostoriji  |
| `r` | Resetovanje kamere |
| `o` | Otvaranje knjige |

