#include "acutest.h"
#include <string.h>

#include "todo.h"

void test_add(void) {
    Task tasks[MAX_TASKS]; int n = 0;
    TEST_CHECK(task_add(tasks, &n, "Acheter du pain") == 1);
    TEST_CHECK(n == 1);
    TEST_CHECK(tasks[0].id == 1);
    TEST_CHECK(tasks[0].completed == 0);
    TEST_CHECK(strcmp(tasks[0].description, "Acheter du pain") == 0);
}

void test_toggle(void) {
    Task tasks[MAX_TASKS]; int n = 0;
    task_add(tasks, &n, "A");
    TEST_CHECK(task_toggle(tasks, n, 1) == 1);
    TEST_CHECK(tasks[0].completed == 1);
    TEST_CHECK(task_toggle(tasks, n, 1) == 1);
    TEST_CHECK(tasks[0].completed == 0);
    TEST_CHECK(task_toggle(tasks, n, 2) == 0); /* id invalide */
}

void test_update(void) {
    Task tasks[MAX_TASKS]; int n = 0;
    task_add(tasks, &n, "Ancien");
    TEST_CHECK(task_update(tasks, n, 1, "Nouveau") == 1);
    TEST_CHECK(strcmp(tasks[0].description, "Nouveau") == 0);
}

void test_delete_and_renumber(void) {
    Task tasks[MAX_TASKS]; int n = 0;
    task_add(tasks, &n, "T1");
    task_add(tasks, &n, "T2");
    task_add(tasks, &n, "T3");
    TEST_CHECK(n == 3);
    TEST_CHECK(task_delete(tasks, &n, 2) == 1);
    TEST_CHECK(n == 2);
    TEST_CHECK(tasks[0].id == 1);
    TEST_CHECK(strcmp(tasks[0].description, "T1") == 0);
    TEST_CHECK(tasks[1].id == 2);                  /* ex-T3 devient id=2 */
    TEST_CHECK(strcmp(tasks[1].description, "T3") == 0);
    TEST_CHECK(task_delete(tasks, &n, 3) == 0);    /* id invalide */
}

void test_capacity(void) {
    Task tasks[MAX_TASKS]; int n = 0;
    for (int i = 0; i < MAX_TASKS; ++i) {
        TEST_CHECK(task_add(tasks, &n, "X") == 1);
    }
    TEST_CHECK(n == MAX_TASKS);
    TEST_CHECK(task_add(tasks, &n, "Y") == 0);     /* plein */
}

/* Déclare la liste des tests à exécuter (Acutest fournit main()). */
TEST_LIST = {
    { "Ajout de taches",              test_add },
    { "Toggle termine/en cours",      test_toggle },
    { "Mise a jour description",      test_update },
    { "Suppression + renumerotation", test_delete_and_renumber },
    { "Capacite MAX_TASKS",           test_capacity },
    { NULL, NULL }
};