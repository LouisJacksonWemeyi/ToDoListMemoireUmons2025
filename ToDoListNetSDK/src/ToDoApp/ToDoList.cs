using System.Collections.Generic;
using System.Linq;

namespace ToDoApp;

public class ToDoList
{
    private readonly List<ToDoItem> _items = new();
    private int _nextId = 1;

    public ToDoItem Add(string description)
    {
        var item = new ToDoItem { Id = _nextId++, Description = description.Trim(), IsDone = false };
        _items.Add(item);
        return item;
    }

    public IReadOnlyList<ToDoItem> GetAll() => _items.OrderBy(i => i.Id).ToList();

    public bool Update(int id, string newDescription)
    {
        var item = _items.FirstOrDefault(i => i.Id == id);
        if (item is null) return false;
        item.Description = newDescription.Trim();
        return true;
    }

    public bool ToggleDone(int id)
    {
        var item = _items.FirstOrDefault(i => i.Id == id);
        if (item is null) return false;
        item.IsDone = !item.IsDone;
        return true;
    }

    public bool Delete(int id)
    {
        var item = _items.FirstOrDefault(i => i.Id == id);
        if (item is null) return false;
        _items.Remove(item);
        return true;
    }
}
