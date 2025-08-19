#include "ToDoList.h"
#include <iostream>

int ToDoList::findIndexById(int id) const {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].getId() == id) return static_cast<int>(i);
    }
    return -1;
}

int ToDoList::addTask(const std::string& description) {
    int id = nextId++;
    tasks.emplace_back(id, description);
    return id;
}

bool ToDoList::updateTask(int id, const std::string& newDesc) {
    int idx = findIndexById(id);
    if (idx < 0) return false;
    tasks[idx].setDescription(newDesc);
    return true;
}

bool ToDoList::deleteTask(int id) {
    int idx = findIndexById(id);
    if (idx < 0) return false;
    tasks.erase(tasks.begin() + idx);
    return true;
}

bool ToDoList::toggleComplete(int id) {
    int idx = findIndexById(id);
    if (idx < 0) return false;
    tasks[idx].toggleCompleted();
    return true;
}

const std::vector<Task>& ToDoList::getTasks() const { return tasks; }

const Task* ToDoList::getTaskById(int id) const {
    int idx = findIndexById(id);
    return (idx < 0) ? nullptr : &tasks[idx];
}

size_t ToDoList::size() const { return tasks.size(); }

void ToDoList::listTasks() const {
    if (tasks.empty()) {
        std::cout << "📭 Liste vide.\n";
        return;
    }
    for (const auto& t : tasks) t.display();
}
