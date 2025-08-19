Commandes (build, tests, exécution)
1. Vérifier les versions (doit afficher exactement Maven 3.9.10 et Java 24.0.1 grâce à Enforcer + Toolchains) :
  mvn -version

Compiler + lancer les tests (phase test avec JUnit 5.10.2 via Surefire 3.5.3) :
  mvn -DskipTests=false clean test
Le but exécuté est surefire:test pendant la phase test du cycle Maven ; les rapports sont dans target/surefire-reports/.Le but exécuté est surefire:test pendant la phase test du cycle Maven ; les rapports sont dans target/surefire-reports/.

Packager le JAR exécutable :
mvn -DskipTests=false clean package

Lancer l’application :
java -jar target/todo-list-1.0.0.jar
