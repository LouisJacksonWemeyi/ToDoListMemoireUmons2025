package todolist;

import todolist.Task;
import java.util.List;

public class TaskView {
    public void displayTasks(List<Task> tasks) {
        if (tasks.isEmpty()) {
            System.out.println("Tâche non trouvée.");
        } else {
            for (Task t : tasks) {
                System.out.println(t);
            }
        }
    }
}
