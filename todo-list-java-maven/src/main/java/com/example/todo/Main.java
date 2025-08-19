package com.example.todo;

import com.example.todo.TaskController;
import com.example.todo.TaskView;
import java.util.Objects;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        TaskController controller = new TaskController();
        TaskView view = new TaskView();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nTo-Do List:");
            System.out.println("1. Ajouter une tâche");
            System.out.println("2. Lister les tâches");
            System.out.println("3. Modifier une tâche");
            System.out.println("4. Supprimer une tâche");
            System.out.println("5. Marquer/Démarquer comme faite");
            System.out.println("0. Quitter");
            System.out.print("Choix : ");
            while (!scanner.hasNextInt()) { scanner.next(); }
            choice = scanner.nextInt();
            scanner.nextLine(); // clear buffer

            switch (choice) {
                case 1 -> {
                    System.out.print("Entrer la description d'une tâche : ");
                    String desc = scanner.nextLine();
                    if (Objects.nonNull(controller.addTask(desc)));
                        System.out.println("Tâche ajoutée.");
                }
                case 2 -> view.displayTasks(controller.getAllTasks());
                case 3 -> {
                    System.out.print("ID de la tâche à modifier : ");
                    int id = scanner.nextInt(); scanner.nextLine();
                    System.out.print("Nouvelle description : ");
                    String newDesc = scanner.nextLine();
                    if (!controller.updateTask(id, newDesc)){
                        System.out.println("Tâche non trouvée.");
                    }else{
                        System.out.println("Tâche modifiée.");
                    }
                }
                case 4 -> {
                    System.out.print("ID de la tâche à supprimer : ");
                    int id = scanner.nextInt();
                    if (!controller.deleteTask(id)){
                        System.out.println("Tâche non trouvée.");
                    }else{
                        System.out.println("Tâche supprimée.");
                    }
                }
                case 5 -> {
                    System.out.print("ID de la tâche à marquer/démarquer : ");
                    int id = scanner.nextInt();
                    if (!controller.toggleTaskCompletion(id)){
                        System.out.println("Tâche non trouvée.");
                    }else{
                        System.out.println("État modifié.");
                    }
                }
                case 0 -> System.out.println("Au revoir !");
                default -> System.out.println("Choix invalide.");
            }

        } while (choice != 0);

        scanner.close();
    }
}