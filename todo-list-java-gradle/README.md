# To-Do List (Gradle 8.14.2, Java 24, JUnit 5.10.2) — Exécution avec Gralde

## Commandes
```bash
# (Optionnel) générer le wrapper en 8.14.2 si on utilise un Gradle local
gradle wrapper

# Lister les toolchains détectées/téléchargées
./gradlew -q javaToolchains

# Lancer les tests unitaires JUnit 5.10.2
./gradlew clean test

# Exécuter l’application console
./gradlew run --console=plain

# Nettoyer, tester (JUnit 5.10.2), puis exécuter l’appli
./gradlew clean test run --console=plain
```


# To-Do List (Gradle 8.14.2, Java 24, JUnit 5.10.2) — JAR exécutable

## Construire (Builder) et exécuter
```bash
# Tests (JUnit 5.10.2)
./gradlew test

# Construire le JAR exécutable
./gradlew clean jar

# Lancer (macOS/Linux)
java -Dfile.encoding=UTF-8 -jar build/libs/todo-list-gradle-1.0.0.jar

# Lancer (Windows PowerShell)
chcp 65001 > $null
java -Dfile.encoding=UTF-8 -jar build\libs\todo-list-gradle-1.0.0.jar

# Alternative sans 'java -jar' : scripts
./gradlew installDist
build/install/todo-list-gradle/bin/todo-list-gradle        # macOS/Linux
build\install\todo-list-gradle\bin\todo-list-gradle.bat    # Windows
```