package todo.view;

import todo.model.Task;
import java.util.List;

public class TaskView {
    public void displayTasks(List<Task> tasks) {
        if (tasks.isEmpty()) {
            System.out.println("Liste vide.");
        } else {
            for (Task t : tasks) {
                System.out.println(t);
            }
        }
    }
}
