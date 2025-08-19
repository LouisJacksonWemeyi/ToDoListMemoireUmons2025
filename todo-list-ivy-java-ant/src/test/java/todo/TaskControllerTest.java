package todo;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import todo.controller.TaskController;
import todo.model.Task;

import static org.junit.jupiter.api.Assertions.*;

class TaskControllerTest {

    private TaskController controller;

    @BeforeEach
    void setUp() {
        controller = new TaskController();
    }

    @Test
    void addTask_incrementsSizeAndIds() {
        Task t1 = controller.addTask("A");
        Task t2 = controller.addTask("B");
        assertEquals(2, controller.getAllTasks().size());
        assertEquals(1, t1.getId());
        assertEquals(2, t2.getId());
    }

    @Test
    void updateTask_existing_returnsTrueAndChangesDescription() {
        Task t = controller.addTask("Old");
        boolean ok = controller.updateTask(t.getId(), "New");
        assertTrue(ok);
        assertEquals("New", controller.getAllTasks().get(0).getDescription());
    }

    @Test
    void updateTask_missing_returnsFalse() {
        assertFalse(controller.updateTask(42, "x"));
    }

    @Test
    void deleteTask_existing_removesIt() {
        Task t = controller.addTask("X");
        assertTrue(controller.deleteTask(t.getId()));
        assertTrue(controller.getAllTasks().isEmpty());
    }

    @Test
    void deleteTask_missing_returnsFalse() {
        assertFalse(controller.deleteTask(999));
    }

    @Test
    void toggleCompletion_flipsState() {
        Task t = controller.addTask("Toggle");
        assertFalse(t.isCompleted());
        assertTrue(controller.toggleTaskCompletion(t.getId()));
        assertTrue(controller.getAllTasks().get(0).isCompleted());
        assertTrue(controller.toggleTaskCompletion(t.getId()));
        assertFalse(controller.getAllTasks().get(0).isCompleted());
    }
}
