#define MAX_LEN 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char title[MAX_LEN];
    float cost;
    char label[MAX_LEN];
} Fragrance;
void show();
void insert();
void save();
void find();
void remoove();
void modify();

