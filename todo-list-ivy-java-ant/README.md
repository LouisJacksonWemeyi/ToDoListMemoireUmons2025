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


Utilisation du workflow Ant 
    . CI automatique sur push/PR (build + tests + artefact JAR).
    . CD (tag + release) manuel : va dans Actions → CI/CD - ToDo List → Run workflow, 
    saisis version (ex. v1.0.0) et éventuellement des notes → le workflow :
       1. build & tests
       2. crée/maj le tag v1.0.0
       3. crée la Release et y joint todo-list.jar.
    . CD automatique si tu pousses un tag :
         git tag v1.0.0
         git push origin v1.0.0
    → le job “Create Tag & Release” publie directement la Release avec le JAR.
