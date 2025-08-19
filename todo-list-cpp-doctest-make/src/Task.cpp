#include "Task.h"

Task::Task(int id, const std::string& description)
    : id(id), description(description), completed(false) {}

int Task::getId() const { return id; }
const std::string& Task::getDescription() const { return description; }
bool Task::isCompleted() const { return completed; }

void Task::setDescription(const std::string& newDescription) {
    description = newDescription;
}

void Task::toggleCompleted() {
    completed = !completed;
}

void Task::display() const {
    std::cout << "[" << id << "] "
              << (completed ? "[X] " : "[ ] ")
              << description << std::endl;
}
