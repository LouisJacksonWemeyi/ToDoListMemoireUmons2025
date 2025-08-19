#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    Task(int id, const std::string& description);

    int getId() const;
    const std::string& getDescription() const;
    bool isCompleted() const;

    void setDescription(const std::string& newDescription);
    void toggleCompleted();

    void display() const;
};

#endif
