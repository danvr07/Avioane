#include "./utils.h"

#define cod_size 5
#define AVION_SIZE 13
// Verifica daca obstacolul se afla intr o arie dreptunghiulara
int is_inside_rect1(int x, int y, int x1, int y1, int x2, int y2) {
  return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}
int is_inside_rect2(int x, int y, int x1, int y1, int size_x, int size_y) {
  return x >= x1 && x <= (x1 + size_x) && y >= y1 && y <= (y1 + size_y);
}

void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *y, int *x, int N) {
  int nr_avioane_trecute = 0;
  unsigned short lin = 0, col = 0;
  unsigned char dir = 0, tip = 0;
  void *idx = info;
// Iterarea prin avioane
  for (int p = 0; nr_avioane--; p += AVION_SIZE) {
    lin = *((unsigned short *)(idx + p + 0));
    col = *((unsigned short *)(idx + p + 2));
    dir = *((unsigned char *)(idx + p + 4));
    tip = *((unsigned char *)(idx + p + cod_size));
// Iterarea prin obstacole
    int nr_obstacole_lovite = 0;
    for (int i = 0; i < nr_obstacole; i++) {
      switch (dir) {
        case 'N': {
          if (tip == '1') {
            if ((is_inside_rect1(x[i], y[i], col - 2, 0, col + 2, lin + 1) ||
                 is_inside_rect2(x[i], y[i], col - 1, lin + 2, 2, 1))) {
              nr_obstacole_lovite++;
            }
          } else {
            if ((is_inside_rect1(x[i], y[i], col - 3, 0, col + 3, lin + 2) ||
                 is_inside_rect2(x[i], y[i], col - 2, lin + 3, 4, 1))) {
              nr_obstacole_lovite++;
            }
          }
          break;
        }
        case 'S': {
          if (tip == '1') {
            if ((is_inside_rect1(x[i], y[i], col - 2, lin - 1, col + 2, N - 1) ||
                 is_inside_rect2(x[i], y[i], col - 1, lin - 3, 2, 1))) {
              nr_obstacole_lovite++;
            }
          } else {
            if ((is_inside_rect1(x[i], y[i], col - 3, lin - 2, col + 3, N - 1) ||
                 is_inside_rect2(x[i], y[i], col - 2, lin - 4, 4, 1))) {
              nr_obstacole_lovite++;
            }
          }
          break;
        }
        case 'E': {
          if (tip == '1') {
            if ((is_inside_rect1(x[i], y[i], col - 1, lin - 2, N - 1, lin + 2) ||
                 is_inside_rect2(x[i], y[i], col - 3, lin - 1, 1, 2))) {
              nr_obstacole_lovite++;
            }
          } else {
            if ((is_inside_rect1(x[i], y[i], col - 2, lin - 3, N - 1, lin + 3) ||
                 is_inside_rect2(x[i], y[i], col - 4, lin - 2, 1, 4))) {
              nr_obstacole_lovite++;
            }
          }
          break;
        }
        case 'W': {
          if (tip == '1') {
            if ((is_inside_rect1(x[i], y[i], 0, lin - 2, col + 1, lin + 2) ||
                 is_inside_rect2(x[i], y[i], col + 2, lin - 1, 1, 2))) {
              nr_obstacole_lovite++;
            }
          } else {
            if ((is_inside_rect1(x[i], y[i], 0, lin - 3, col + 2, lin + 3) ||
                 is_inside_rect2(x[i], y[i], col + 3, lin - 2, 1, 4))) {
              nr_obstacole_lovite++;
            }
          }
          break;
        }
      }
    }
    nr_avioane_trecute += nr_obstacole_lovite == 0;
  }
  // Se afiseaza numarul de avioane trecute
  printf("%d\n", nr_avioane_trecute);
}
