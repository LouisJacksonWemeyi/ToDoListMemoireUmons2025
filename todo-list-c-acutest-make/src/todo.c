#include "todo.h"
#include <string.h>
#include <stdio.h>

static void copy_desc(char* dst, const char* src) {
    if (!src) { dst[0] = '\0'; return; }
    strncpy(dst, src, MAX_DESC_LENGTH - 1);
    dst[MAX_DESC_LENGTH - 1] = '\0';
}

int task_add(Task tasks[], int *taskCount, const char* description) {
    if (!taskCount || *taskCount < 0 || *taskCount >= MAX_TASKS) return 0;
    int idx = *taskCount;
    tasks[idx].id = idx + 1;
    tasks[idx].completed = 0;
    copy_desc(tasks[idx].description, description ? description : "");
    (*taskCount)++;
    return 1;
}

int task_update(Task tasks[], int taskCount, int id, const char* newdesc) {
    if (id <= 0 || id > taskCount) return 0;
    int idx = id - 1;
    copy_desc(tasks[idx].description, newdesc ? newdesc : "");
    return 1;
}

int task_delete(Task tasks[], int *taskCount, int id) {
    if (!taskCount || id <= 0 || id > *taskCount) return 0;
    int idx = id - 1;
    for (int j = idx; j < *taskCount - 1; ++j) {
        tasks[j] = tasks[j + 1];
        tasks[j].id = j + 1;            /* renumérotation contiguë */
    }
    (*taskCount)--;
    return 1;
}

int task_toggle(Task tasks[], int taskCount, int id) {
    if (id <= 0 || id > taskCount) return 0;
    int idx = id - 1;
    tasks[idx].completed = !tasks[idx].completed;
    return 1;
}

void task_list_print(const Task tasks[], int taskCount) {
    puts("\n--- Tâches ---");
    for (int i = 0; i < taskCount; ++i) {
        printf("[%d] %s [%s]\n", tasks[i].id, tasks[i].description,
               tasks[i].completed ? "Terminée" : "En cours");
    }
    puts("--------------");
}
