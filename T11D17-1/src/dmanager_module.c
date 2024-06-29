#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void close_doors(struct door *doors);
void sort_doors(struct door *doors);
void output(struct door *doors);

int main(void) {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    close_doors(doors);
    sort_doors(doors);
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void close_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void sort_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT - i - 1; j++) {
            if (doors[j + 1].id < doors[j].id) {
                struct door temp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = temp;
            }
        }
    }
}

void output(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (i != DOORS_COUNT - 1) {
            printf("%d, %d\n", doors[i].id, doors[i].status);
        } else {
            printf("%d, %d", doors[i].id, doors[i].status);
        }
    }
}