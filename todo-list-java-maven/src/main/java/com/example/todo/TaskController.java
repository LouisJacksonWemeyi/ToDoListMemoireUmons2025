package com.example.todo;

import com.example.todo.Task;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TaskController {
    private final List<Task> tasks = new ArrayList<>();
    private int nextId = 1;

    public Task addTask(String description) {
        Task t = new Task(nextId++, description);
        tasks.add(t);
        return t;
    }

    public List<Task> getAllTasks() {
        return Collections.unmodifiableList(tasks);
    }

    public boolean updateTask(int id, String newDescription) {
        for (Task t : tasks) {
            if (t.getId() == id) {
                t.setDescription(newDescription);
                return true;
            }
        }
        return false;
    }

    public boolean deleteTask(int id) {
        return tasks.removeIf(t -> t.getId() == id);
    }

    public boolean toggleTaskCompletion(int id) {
        for (Task t : tasks) {
            if (t.getId() == id) {
                t.setCompleted(!t.isCompleted());
                return true;
            }
        }
        return false;
    }

    public void clearAll() {
        tasks.clear();
    }
}

