#include "./utils.h"

#define cod_size 5
  struct Avion {
  unsigned short lin, col;
  unsigned char dir;
  unsigned char cod[cod_size];  //  marimea variablei cod este cu 1 mai mare pentru terminator de sir.
  unsigned int viteza;
  };
  //  Functia de comparare
int cmp(const void* a_, const void* b_) {
  //  Se dereferentiaza parametrii
  struct Avion* a = (struct Avion *) a_;
  struct Avion* b = (struct Avion *) b_;
  int comp_val = strcmp(a->cod + 1, b->cod + 1);
//  Evalueaza pe rand fiecare criteriu
  if (a->cod[0] > b->cod[0])
    return 1;

  if (a->cod[0] == b->cod[0] && comp_val  < 0)
    return 1;

  if (a->cod[0] == b->cod[0] && comp_val == 0 && a->viteza > b->viteza)
    return 1;

  return 0;
}

void SolveTask3(void *info, int nr_avioane) {
  struct Avion* avioane = (struct Avion *) calloc(nr_avioane, sizeof(struct Avion));
  void *idx = info;
// Se citesc elementele avioanelor
  for (int i = 0; i < nr_avioane; i++) {
        avioane[i].lin = *(unsigned short*)idx;
        idx += sizeof(unsigned short);
        avioane[i].col = *(unsigned short*)idx;
        idx += sizeof(unsigned short);
        avioane[i].dir = *(unsigned char*)idx;
        idx += sizeof(unsigned char);
        strncpy(avioane[i].cod, (unsigned char*)idx, 4);
        idx += 4 * sizeof(unsigned char);
        avioane[i].viteza = *(unsigned int*)idx;
        idx += sizeof(unsigned int);
  }
  //  Se sorteaza avioanele dupa criteriile din functia de comparare
  qsort(avioane, nr_avioane, sizeof(struct Avion), cmp);
  //  Afisarea datelor despre avioane in ordinea sortata
  for (int i = 0; i < nr_avioane; i++) {
    printf("(%hu, %hu)\n", avioane[i].lin, avioane[i].col);
    printf("%c\n", avioane[i].dir);
    printf("%s\n", avioane[i].cod);
    printf("%u\n\n", avioane[i].viteza);
  }
  free(avioane);
}
