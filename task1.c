#include "./utils.h"

#define cod_size 5

void SolveTask1(void *info, int nr_avioane) {
    unsigned short lin = 0, col = 0;
    unsigned char dir = 0, cod[cod_size];
    unsigned int viteza = 0;
    void *idx = info;
    // Scoatem informatiile despre avioane din vector
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
    // Afisam infomatiile despre avioane
        printf("(%hu, %hu)\n", lin, col);
        printf("%c\n", dir);
        printf("%s\n", cod);
        printf("%u\n\n", viteza);
    }
}
