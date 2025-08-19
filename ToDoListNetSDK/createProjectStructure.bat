mkdir ToDoListNetSDK
cd ToDoListNetSDK

dotnet new sln -n ToDoListNetSDK

dotnet new console -n ToDoApp -o src/ToDoApp
dotnet new xunit   -n ToDoApp.Tests -o tests/ToDoApp.Tests

dotnet sln add src/ToDoApp/ToDoApp.csproj
dotnet sln add tests/ToDoApp.Tests/ToDoApp.Tests.csproj