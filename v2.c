#define MAX_LEN 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "v.h"


int main() {
        FILE*f=fopen("b.bin","wb");
        if(!f)
                return 0;
        fclose(f);
        f=fopen("b.bin","rb");
fseek(f,0,SEEK_END);
size_t size=ftell(f);
rewind(f);
int  count =size/sizeof(Fragrance);

     Fragrance*items= calloc(count, sizeof(Fragrance));
        fread(items, sizeof(Fragrance), count, f);
        fclose(f);
    int selection;
    do {
        printf("\n=== Парфюмерный магазин ===\n");
        printf("1. Показать товары\n");
        printf("2. Добавить новый товар\n");
        printf("3. Найти товар\n");
        printf("4. Удалить товар\n");
        printf("5. Изменить товар\n");
        printf("6. Выйти\n");
        printf("Введите номер: ");
        while(scanf("%i",&selection)!=1){
                printf("введите цифру\n\n");
                while(getchar() !='\n');
        }
        switch (selection) {
        case 1:
            show();
            break;
        case 2:
            insert();
            break;
        case 3:
            find();
            break;
        case 4:
            remoove();
            break;
        case 5:
            modify();
            break;
        case 6:
            save();
            printf("Выход из программы...\n");
            break;
        default:
            printf("Неверный ввод. Попробуйте снова.\n");
        }
    } while (selection != 6);
    free(items);

    return 0;
}

