#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue {
    char data[100];
    struct queue *next;
} queue;

queue *init_queue(char data[]);            // инициализация очереди
void push_back(queue *head, char data[]);  // добавление элемента в конец очереди
void destroy_queue(queue *head);           // удаление очереди

#endif