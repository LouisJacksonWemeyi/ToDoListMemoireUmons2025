#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.h"
#include <vector>

class ToDoList {
private:
    std::vector<Task> tasks;
    int nextId = 1;

    int findIndexById(int id) const;

public:
    // CRUD
    int  addTask(const std::string& description);       // retourne l'ID créé
    bool updateTask(int id, const std::string& newDesc);
    bool deleteTask(int id);
    bool toggleComplete(int id);

    // Accès
    const std::vector<Task>& getTasks() const;
    const Task* getTaskById(int id) const;
    size_t size() const;

    // I/O console
    void listTasks() const;
};

#endif
