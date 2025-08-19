#include "ToDoList.h"
#include <iostream>
#include <string>

static int readInt(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string line;
        if (!std::getline(std::cin, line)) return 0;
        try {
            size_t pos = 0;
            int v = std::stoi(line, &pos);
            if (pos == line.size()) return v;
        } catch (...) {}
        std::cout << "Entrée invalide. Réessayez.\n";
    }
}

static std::string readLine(const std::string& prompt) {
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    return s;
}

static void menu() {
    std::cout << "\n=== MENU TO-DO LIST ===\n"
              << "1. Ajouter une tâche\n"
              << "2. Lister les tâches\n"
              << "3. Modifier une tâche\n"
              << "4. Supprimer une tâche\n"
              << "5. Marquer/Démarquer comme faite\n"
              << "0. Quitter\n";
}

int main() {
    ToDoList todo;

    while (true) {
        menu();
        int choice = readInt("Choix : ");
        switch (choice) {
            case 1: {
                std::string desc = readLine("Description : ");
                int id = todo.addTask(desc);
                std::cout << "Tâche ajoutée avec ID " << id << ".\n";
                break;
            }
            case 2:
                todo.listTasks();
                break;
            case 3: {
                int id = readInt("ID à modifier : ");
                std::string newDesc = readLine("Nouvelle description : ");
                if (todo.updateTask(id, newDesc)) std::cout << "Tâche modifiée.\n";
                else std::cout << "Tâche non trouvée.\n";
                break;
            }
            case 4: {
                int id = readInt("ID à supprimer : ");
                if (todo.deleteTask(id)) std::cout << "Tâche supprimée.\n";
                else std::cout << "Tâche non trouvée.\n";
                break;
            }
            case 5: {
                int id = readInt("ID à cocher/décocher : ");
                if (todo.toggleComplete(id)) std::cout << "État modifié.\n";
                else std::cout << "Tâche non trouvée.\n";
                break;
            }
            case 0:
                std::cout << "Au revoir !\n";
                return 0;
            default:
                std::cout << "Choix invalide.\n";
        }
    }
}
