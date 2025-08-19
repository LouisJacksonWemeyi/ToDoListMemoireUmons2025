#include <stdio.h>
#include <string.h>
#include "todo.h"

static void flush_stdin_after_scanf(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static void read_line(char* buf, size_t cap) {
    if (!fgets(buf, (int)cap, stdin)) { buf[0] = '\0'; return; }
    buf[strcspn(buf, "\n")] = '\0';
}

int main(void) {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    for (;;) {
        printf("\n--- Menu To-Do List ---\n");
        printf("1. Ajouter une tache\n");
        printf("2. Voir les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Marquer/Démarquer comme faite\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        if (scanf("%d", &choice) != 1) { puts("Entree invalide."); return 1; }
        flush_stdin_after_scanf();

        if (choice == 0) { puts("Au revoir !"); break; }

        if (choice == 1) {
            char desc[MAX_DESC_LENGTH];
            printf("Description de la tache: ");
            read_line(desc, sizeof(desc));
            puts(task_add(tasks, &taskCount, desc) ? "Tache ajoutee." : "Echec: liste pleine.");
        } else if (choice == 2) {
            task_list_print(tasks, taskCount);
        } else if (choice == 3) {
            int id; char desc[MAX_DESC_LENGTH];
            printf("ID a modifier: ");
            if (scanf("%d", &id) != 1) { puts("Entree invalide."); return 1; }
            flush_stdin_after_scanf();
            printf("Nouvelle description: ");
            read_line(desc, sizeof(desc));
            puts(task_update(tasks, taskCount, id, desc) ? "Tache mise a jour." : "ID introuvable.");
        } else if (choice == 4) {
            int id;
            printf("ID a supprimer: ");
            if (scanf("%d", &id) != 1) { puts("Entree invalide."); return 1; }
            flush_stdin_after_scanf();
            puts(task_delete(tasks, &taskCount, id) ? "Tache supprimee." : "ID introuvable.");
        } else if (choice == 5) {
            int id;
            printf("ID a (de)marquer: ");
            if (scanf("%d", &id) != 1) { puts("Entree invalide."); return 1; }
            flush_stdin_after_scanf();
            puts(task_toggle(tasks, taskCount, id) ? "Etat modifie." : "ID introuvable.");
        } else {
            puts("Choix invalide.");
        }
    }
    return 0;
}
