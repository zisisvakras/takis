#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PersonBalance* Personptr;

struct PersonBalance {
    char code[8];
    double balance;
    char *name;
};

Personptr ReadBalance(void) {
    Personptr new = malloc(sizeof(struct PersonBalance));
    if (new == NULL) exit(1);
    if (scanf("%8s", new->code) != 1) exit(1);
    if (scanf(" %lf", &new->balance) != 1) exit(1);
    char* buffer = malloc(100 * sizeof(char));
    if (scanf("%99[^\n]s", buffer) != 1) exit(1);
    new->name = malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(new->name, buffer);
    free(buffer);
    return new;
}

void PrintBalance(Personptr p) {
    printf("%s %4.2f %s\n", p->code, p->balance, p->name);
}

int main(void) {
    int count = 0;
    if (scanf("%d", &count) != 1) return 1;
    if (count <= 0) return 1;
    Personptr* persons = malloc(count * sizeof(Personptr));
    for (int i = 0 ; i < count ; ++i) {
        persons[i] = ReadBalance();
    }
    char temp[8];
    while (scanf("%7s", temp) == 1) {
        for (int i = 0 ; i < count ; ++i) {
            if (!strcmp(temp, persons[i]->code)) {
                PrintBalance(persons[i]);
                break;
            }
        }
    }
    // cleanup
    for (int i = 0 ; i < count ; ++i) {
        free(persons[i]->name);
        free(persons[i]);
    }
    free(persons);
    return 0;
}