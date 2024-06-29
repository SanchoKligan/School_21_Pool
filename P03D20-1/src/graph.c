#include <stdio.h>

#include "compute.h"
#include "tokens_get.h"

#define HEIGHT 25
#define WIDTH 80

void print_graph(const queue *head);  // отрисовка графика

int main(void) {
    char string[100];
    fgets(string, 99, stdin);
    queue *head = tokens_get(string);
    print_graph(head);
    destroy_queue(head);
    return 0;
}

void print_graph(const queue *head) {
    for (int j = HEIGHT; j >= 0; j--) {
        for (double i = 0.0; i <= 4 * M_PI; i += 4 * M_PI / WIDTH) {
            double y = result(head, i);
            if (!(y >= -1 && y <= 1)) {
                printf(".");
            } else {
                int scaled = HEIGHT - (int)round(((y + 1) / 2) * HEIGHT);
                scaled == j ? printf("*") : printf(".");
            }
        }
        printf("\n");
    }
}