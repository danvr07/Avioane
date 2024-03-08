#include "./utils.h"

#define cod_size 5

#define AVION1_NS_SIZE_X 7
#define AVION1_NS_SIZE_Y 4
#define AVION1_EW_SIZE_X 4
#define AVION1_EW_SIZE_Y 7

#define AVION2_NS_SIZE_X 9
#define AVION2_NS_SIZE_Y 5
#define AVION2_EW_SIZE_X 5
#define AVION2_EW_SIZE_Y 9

void SolveTask2(void* info, int nr_avioane, int N, char** mat) {
  //  Salvam forma avioanelor in variabile locale
char avion1_N[AVION1_NS_SIZE_Y][AVION1_NS_SIZE_X + 1] = {
  "...*...",
  ".*****.",
  "...*...",
  "..***..",
};
char avion1_S[AVION1_NS_SIZE_Y][AVION1_NS_SIZE_X + 1] = {
  "..***..",
  "...*...",
  ".*****.",
  "...*...",
};
char avion1_E[AVION1_EW_SIZE_Y][AVION1_EW_SIZE_X + 1] = {
  "....",
  "..*.",
  "*.*.",
  "****",
  "*.*.",
  "..*.",
  "....",
};
char avion1_W[AVION1_EW_SIZE_Y][AVION1_EW_SIZE_X + 1] = {
  "....",
  ".*..",
  ".*.*",
  "****",
  ".*.*",
  ".*..",
  "....",
};

char avion2_N[AVION2_NS_SIZE_Y][AVION2_NS_SIZE_X + 1] = {
  "....*....",
  "...***...",
  ".*******.",
  "....*....",
  "..*****..",
};
char avion2_S[AVION2_NS_SIZE_Y][AVION2_NS_SIZE_X + 1] = {
  "..*****..",
  "....*....",
  ".*******.",
  "...***...",
  "....*....",
};
char avion2_E[AVION2_EW_SIZE_Y][AVION2_EW_SIZE_X + 1] = {
  ".....",
  "..*..",
  "*.*..",
  "*.**.",
  "*****",
  "*.**.",
  "*.*..",
  "..*..",
  ".....",
};
char avion2_W[AVION2_EW_SIZE_Y][AVION2_EW_SIZE_X + 1] = {
  ".....",
  "..*..",
  "..*.*",
  ".**.*",
  "*****",
  ".**.*",
  "..*.*",
  "..*..",
  ".....",
};
  //  Umple matricea cu puncte
  for (int i = 0; i < N; i++) {
    memset(mat[i], '.', N);
  }
    unsigned short lin = 0, col = 0;
    unsigned char dir = 0, cod[cod_size];
    unsigned int viteza = 0;
    void *idx = info;
  //  Se itereaza prin avioane
  for (int i = 0; i < nr_avioane; i++) {
        lin = *(unsigned short*)idx;
        idx += sizeof(unsigned short);
        col = *(unsigned short*)idx;
        idx += sizeof(unsigned short);
        dir = *(unsigned char*)idx;
        idx += sizeof(unsigned char);
        strncpy(cod, (unsigned char*)idx, 4);
        idx += 4 * sizeof(unsigned char);
        viteza = *(unsigned int*)idx;
        idx += sizeof(unsigned int);
// In dependenta de tipul si directia avionului copiaza forma vionului in matrice.
    if (cod[0] == '1') {
      switch (dir) {
        case 'N': {
          for (int i = 0; i < AVION1_NS_SIZE_Y; i++)
            for (int j = 0; j < AVION1_NS_SIZE_X; j++)
              if (avion1_N[i][j] == '*')
                mat[lin + i][col - AVION1_NS_SIZE_X/2 + j] = avion1_N[i][j];
          break;
        }
        case 'S': {
          for (int i = 0; i < AVION1_NS_SIZE_Y; i++)
            for (int j = 0; j < AVION1_NS_SIZE_X; j++)
              if (avion1_S[i][j] == '*')
                mat[lin - AVION1_NS_SIZE_X/2 + i][col - AVION1_NS_SIZE_X/2 + j] = avion1_S[i][j];
          break;
        }
        case 'E': {
          for (int i = 0; i < AVION1_EW_SIZE_Y; i++)
            for (int j = 0; j < AVION1_EW_SIZE_X; j++)
              if (avion1_E[i][j] == '*')
                mat[lin - AVION1_EW_SIZE_Y/2 + i][col - AVION1_EW_SIZE_Y/2 + j] = avion1_E[i][j];
          break;
        }
        case 'W': {
          for (int i = 0; i < AVION1_EW_SIZE_Y; i++)
            for (int j = 0; j < AVION1_EW_SIZE_X; j++)
              if (avion1_W[i][j] == '*')
                mat[lin - AVION1_EW_SIZE_Y/2 + i][col + j] = avion1_W[i][j];
          break;
        }
      }
    } else {
      switch (dir) {
        case 'N': {
          for (int i = 0; i < AVION2_NS_SIZE_Y; i++)
            for (int j = 0; j < AVION2_NS_SIZE_X; j++)
              if (avion2_N[i][j] == '*')
                mat[lin + i][col - AVION2_NS_SIZE_X/2 + j] = avion2_N[i][j];
          break;
        }
        case 'S': {
          for (int i = 0; i < AVION2_NS_SIZE_Y; i++)
            for (int j = 0; j < AVION2_NS_SIZE_X; j++)
              if (avion2_S[i][j] == '*')
                mat[lin - AVION2_NS_SIZE_X/2 + i][col - AVION2_NS_SIZE_X/2 + j] = avion2_S[i][j];
          break;
        }
        case 'E': {
          for (int i = 0; i < AVION2_EW_SIZE_Y; i++)
            for (int j = 0; j < AVION2_EW_SIZE_X; j++)
              if (avion2_E[i][j] == '*')
                mat[lin - AVION2_EW_SIZE_Y/2 + i][col - AVION2_EW_SIZE_Y/2 + j] = avion2_E[i][j];
          break;
        }
        case 'W': {
          for (int i = 0; i < AVION2_EW_SIZE_Y; i++)
            for (int j = 0; j < AVION2_EW_SIZE_X; j++)
              if (avion2_W[i][j] == '*')
                mat[lin - AVION2_EW_SIZE_Y/2 + i][col + j] = avion2_W[i][j];
          break;
        }
      }
    }
  }
  //  Se afiseaza matricea cu avioanele in ea
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c", mat[i][j]);
    }
    printf("\n");
  }
}
