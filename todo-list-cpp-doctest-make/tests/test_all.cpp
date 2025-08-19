#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Task.h"
#include "../include/ToDoList.h"
#include "../third_party/doctest/doctest.h"

// --- Tests Task ---
TEST_CASE("Task basics") {
    Task t(1, "demo");
    CHECK(t.getId() == 1);
    CHECK(t.getDescription() == std::string("demo"));
    CHECK_FALSE(t.isCompleted());

    t.toggleCompleted();
    CHECK(t.isCompleted());

    t.setDescription("new");
    CHECK(t.getDescription() == std::string("new"));
}

// --- Tests ToDoList CRUD ---
TEST_CASE("ToDoList CRUD") {
    ToDoList l;

    // Create
    CHECK(l.size() == 0);
    int id1 = l.addTask("acheter du pain");
    int id2 = l.addTask("faire du sport");
    CHECK(l.size() == 2);
    CHECK(id2 == id1 + 1);

    // Read
    const Task* t1 = l.getTaskById(id1);
    REQUIRE(t1 != nullptr);
    CHECK(t1->getDescription() == std::string("acheter du pain"));
    CHECK_FALSE(t1->isCompleted());

    // Update
    CHECK(l.updateTask(id1, "acheter du pain (bio)"));
    CHECK(l.getTaskById(id1)->getDescription() == std::string("acheter du pain (bio)"));
    CHECK_FALSE(l.updateTask(999, "nope"));

    // Toggle
    CHECK(l.toggleComplete(id2));
    CHECK(l.getTaskById(id2)->isCompleted());
    CHECK(l.toggleComplete(id2));
    CHECK_FALSE(l.getTaskById(id2)->isCompleted());
    CHECK_FALSE(l.toggleComplete(999));

    // Delete
    CHECK(l.deleteTask(id1));
    CHECK(l.size() == 1);
    CHECK_FALSE(l.deleteTask(id1));
    CHECK_FALSE(l.deleteTask(999));

    // Id monotone après delete
    int id3 = l.addTask("lire un livre");
    CHECK(id3 == id2 + 1);
}

