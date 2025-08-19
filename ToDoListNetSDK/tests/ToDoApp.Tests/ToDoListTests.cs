using FluentAssertions;
using ToDoApp;
using Xunit;

namespace ToDoApp.Tests;

public class ToDoListTests
{
    [Fact]
    public void Add_ShouldAssignIncrementalId_AndStoreItem()
    {
        var list = new ToDoList();
        var a = list.Add("First");
        var b = list.Add("Second");

        a.Id.Should().Be(1);
        b.Id.Should().Be(2);
        list.GetAll().Should().HaveCount(2);
    }

    [Fact]
    public void Update_ShouldChangeDescription_WhenIdExists()
    {
        var list = new ToDoList();
        var item = list.Add("Old");
        var ok = list.Update(item.Id, "New");

        ok.Should().BeTrue();
        list.GetAll().First(i => i.Id == item.Id).Description.Should().Be("New");
    }

    [Fact]
    public void ToggleDone_ShouldFlipState()
    {
        var list = new ToDoList();
        var item = list.Add("Task");
        item.IsDone.Should().BeFalse();

        list.ToggleDone(item.Id).Should().BeTrue();
        list.GetAll().First(i => i.Id == item.Id).IsDone.Should().BeTrue();

        list.ToggleDone(item.Id).Should().BeTrue();
        list.GetAll().First(i => i.Id == item.Id).IsDone.Should().BeFalse();
    }

    [Fact]
    public void ToggleDone_ShouldReturnFalse_WhenIdNotFound()
    {
        var list = new ToDoList();
        list.ToggleDone(999).Should().BeFalse();
    }

    [Fact]
    public void Delete_ShouldRemoveItem_WhenIdExists()
    {
        var list = new ToDoList();
        var item = list.Add("To delete");
        list.Delete(item.Id).Should().BeTrue();
        list.GetAll().Should().BeEmpty();
    }
}
