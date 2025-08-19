using System;
using ToDoApp;

Console.WriteLine("=== To-Do List (.NET) ===");
var list = new ToDoList();

while (true)
{
    Console.WriteLine();
    Console.WriteLine("1. Ajouter une tâche");
    Console.WriteLine("2. Lister les tâches");
    Console.WriteLine("3. Modifier une tâche");
    Console.WriteLine("4. Supprimer une tâche");
    Console.WriteLine("5. Marquer/Démarquer comme faite");
    Console.WriteLine("0. Quitter");
    Console.Write("Choix : ");
    var choice = Console.ReadLine()?.Trim();

    switch (choice)
    {
        case "1":
            Console.Write("Description : ");
            var desc = Console.ReadLine() ?? string.Empty;
            if (string.IsNullOrWhiteSpace(desc))
            {
                Console.WriteLine("Description vide. Tâche non ajoutée.");
                break;
            }
            var added = list.Add(desc);
            Console.WriteLine($"Ajouté : {added}");
            break;

        case "2":
            var items = list.GetAll();
            if (items.Count == 0)
            {
                Console.WriteLine("Aucune tâche.");
            }
            else
            {
                Console.WriteLine("-- Tâches --");
                foreach (var it in items)
                    Console.WriteLine(it);
            }
            break;

        case "3":
            Console.Write("ID à modifier : ");
            if (!int.TryParse(Console.ReadLine(), out var idU))
            {
                Console.WriteLine("ID invalide.");
                break;
            }
            Console.Write("Nouvelle description : ");
            var newDesc = (Console.ReadLine() ?? string.Empty).Trim();
            if (string.IsNullOrWhiteSpace(newDesc))
            {
                Console.WriteLine("Description vide. Modification annulée.");
                break;
            }
            Console.WriteLine(list.Update(idU, newDesc)
                ? "Tâche modifiée."
                : "ID introuvable.");
            break;

        case "4":
            Console.Write("ID à supprimer : ");
            if (!int.TryParse(Console.ReadLine(), out var idD))
            {
                Console.WriteLine("ID invalide.");
                break;
            }
            Console.WriteLine(list.Delete(idD)
                ? "Tâche supprimée."
                : "ID introuvable.");
            break;

        case "5":
            Console.Write("ID à (dé)marquer : ");
            if (!int.TryParse(Console.ReadLine(), out var idT))
            {
                Console.WriteLine("ID invalide.");
                break;
            }
            Console.WriteLine(list.ToggleDone(idT)
                ? "État modifié (fait/à faire)."
                : "ID introuvable.");
            break;

        case "0":
            return;

        default:
            Console.WriteLine("Choix invalide.");
            break;
    }
}
