#define MAX_LEN 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "v.h"

Fragrance*items;



void show(int count) {
    if (count == 0) {
        printf("База данных пуста.\n");
        return;
    }
else{
    printf("\n=== Список товаров ===\n");
    for (int i = 0; i < count; i++) {
        printf("Товар %d:\n", i + 1);
        printf("  Название: %s\n", items[i].title);
        printf("  Цена: %.2f\n", items[i].cost);
        printf("  Марка: %s\n\n", items[i].label);
}
}
}

void insert(int *count) {
int sss=* count;
 Fragrance*temp= realloc(items, (sss + 1) * sizeof(Fragrance));
items=temp;

    if (!temp) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    printf("\nВведите название товара: ");
    scanf(" %99[^\n]", items[sss].title);
    printf("Введите цену товара: ");
    scanf("%f", &items[sss].cost);
    printf("Введите марку товара: ");
    scanf(" %99[^\n]", items[sss].label);
    (*count)++;
    printf("Товар успешно добавлен!\n\n");
}
void save(int count) {
    FILE* f = fopen("b.bin", "wb");
    if (!f) {
        printf("Ошибка при открытии файла для записи!\n");
        return;
    }
    fwrite(items, sizeof(Fragrance), count, f);

    fclose(f);
    printf("Данные успешно сохранены в файл.\n");

}
void find(int count) {
    char search_title[MAX_LEN];
    char search_label[MAX_LEN];
    int found = 0;

    printf("\nВведите название товара для поиска (0 что бы пропустить): ");
    scanf(" %99[^\n]", search_title);
    printf("Введите марку товара для поиска (0 что бы пропустить): ");
    scanf(" %99[^\n]", search_label);

    printf("\n=== Результаты поиска ===\n");

    int result1 = strcmp(search_label, "0");
    int result2 = strcmp(search_title, "0");

    if (result1 == 0 && result2 != 0)
    {
        for (int i = 0; i < count; i++) {
            if (strcmp(items[i].title, search_title) == 0)
            {
                printf("Товар %d:\n", i + 1);
                printf("  Название: %s\n", items[i].title);
                printf("  Цена: %.2f\n", items[i].cost);
                printf("  Марка: %s\n\n", items[i].label);
                found = 1;
            }
        }
    }
    if (result1 != 0 && result2 == 0)
    {
        for (int i = 0; i < count; i++) {
            if (strcmp(items[i].label, search_label) == 0) {
                printf("Товар %d:\n", i + 1);
                printf("  Название: %s\n", items[i].title);
                printf("  Цена: %.2f\n", items[i].cost);
                printf("  Марка: %s\n\n", items[i].label);
                found = 1;
            }
        }
    }
    if (result1 != 0 && result2 != 0)
    {
        for (int i = 0; i < count; i++) {
            if ((strcmp(items[i].title, search_title) == 0) &&
                (strcmp(items[i].label, search_label) == 0)) {
                printf("Товар %d:\n", i + 1);
                printf("  Название: %s\n", items[i].title);
                printf("  Цена: %.2f\n", items[i].cost);
                printf("  Марка: %s\n\n", items[i].label);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Товар не найден.\n\n");
    }
}
void remoove(int *count) {
    int n;
    printf("\nВведите номер товара для удаления (1-%d): ", (*count));
        while(scanf("%i",&n)!=1){
                printf("введите цифру\n\n");
                while(getchar() !='\n');
        }

    if (n < 1 || n > (*count)) {
        printf("Неверный номер товара.\n");
        return;
    }

    for (int i = n - 1; i < (*count) - 1; i++) {
        items[i] = items[i + 1];
    }

    (*count)--;


    items = realloc(items, (*count) * sizeof(Fragrance));


    if (!items && (*count) > 0) {
        printf("Ошибка перераспределения памяти.\n");
        return;
    }

    printf("Товар успешно удален.\n");
}
void modify(int count) {
    int n;

    printf("\nВведите номер товара для редактирования (1-%d): ", count);
        while(scanf("%i",&n)!=1){
                printf("введите цифру\n\n");
                while(getchar() !='\n');
        }

    if (n < 1 || n > count) {
        printf("Неверный номер товара.\n");
        return;
    }

    n--;
    printf("Текущие данные товара:\n");
    printf("  Название: %s\n", items[n].title);
    printf("  Цена: %.2f\n", items[n].cost);
    printf("  Марка: %s\n\n", items[n].label);

    printf("\nВведите новые данные (0 оставить без изменений):\n");
    printf("Новое название: ");
    char new_title[MAX_LEN];
    scanf(" %99[^\n]", new_title);
    if (strcmp(new_title, "0") != 0) {
        strcpy(items[n].title, new_title);
    }

    printf("Новая цена (0 оставить без изменений): ");
    float new_cost;
    scanf("%f", &new_cost);
    if (new_cost > 0) {
        items[n].cost = new_cost;
    }

    printf("Новая марка (0 оставить без изменений): ");
    char new_label[MAX_LEN];
    scanf(" %99[^\n]", new_label);
    if (strcmp(new_label, "0") != 0) {
        strcpy(items[n].label, new_label);
    }

    printf("Товар успешно отредактирован.\n\n");
}
