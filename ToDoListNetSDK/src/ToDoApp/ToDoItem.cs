namespace ToDoApp;

public class ToDoItem
{
    public int Id { get; set; }
    public string Description { get; set; } = string.Empty;
    public bool IsDone { get; set; }

    public override string ToString()
        => $"[{Id}] {(IsDone ? "[X]" : "[ ]")} {Description}";
}
