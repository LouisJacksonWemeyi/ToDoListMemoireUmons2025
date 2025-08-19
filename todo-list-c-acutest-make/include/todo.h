#ifndef TODO_H
#define TODO_H

#include <stddef.h>

#define MAX_TASKS 100
#define MAX_DESC_LENGTH 256

typedef struct {
    int id;                              /* 1..taskCount, contigu */
    char description[MAX_DESC_LENGTH];
    int completed;                       /* 0 = en cours, 1 = terminée */
} Task;

/* API pure (sans I/O) — testable */
int task_add(Task tasks[], int *taskCount, const char* description);
int task_update(Task tasks[], int taskCount, int id, const char* newdesc);
int task_delete(Task tasks[], int *taskCount, int id);
int task_toggle(Task tasks[], int taskCount, int id);

/* Affichage console */
void task_list_print(const Task tasks[], int taskCount);

#endif /* TODO_H */
