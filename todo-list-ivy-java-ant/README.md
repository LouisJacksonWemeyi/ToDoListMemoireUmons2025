Crée l’arborescence comme indiqué :
mkdir -p todo-ivy-ant/{src/main/java/todo/{model,controller,view},src/test/java/todo,tools/ivy}

Crée les fichiers suivants avec leur contenu :

    build.xml

    ivy.xml

    ivysettings.xml

    src/main/java/todo/model/Task.java

    src/main/java/todo/controller/TaskController.java

    src/main/java/todo/view/TaskView.java

    src/main/java/todo/Main.java

    src/test/java/todo/TaskControllerTest.java

Télécharger Apache Ivy automatiquement
    La cible bootstrap-ivy du build.xml téléchargera Ivy automatiquement.

Tester le projet :

    ant resolve
    ant test
    ant run

Lance l’appli directement (sans Ant)

# après compilation
ant compile
# exécuter directement la classe main :
java -cp build/classes todo.Main

