# Project 1 : Analyse de trames GPS

## Description du Projet
L'intérêt de ce projet est de développer une application de géolocalisation permettant d'analyse des trames GPS du **type GPGGA** suivant la norme NMEA 0183. Cette application dispose d'un ensemble de fonctions qui permettent à l'utilisateur d'extraire et d'étudier les informations provenant des trames GPS, notamment l'heure de réception, la latitude et la longitude.

**Qu'est-ce que NMEA 0183?**
<br/>NMEA 0183 est un protocole de messagerie simple utilisé pour la communication entre l'électornique marine, définie et contrôlée par National Marine Electronics Association (NMEA). Les données de ce protocole sont transmises sous forme de chaînes ASCII dans différents formats en fonction des information qu'elles peuvent fournir. 
GPGGA est un format NMEA 0183 de base et courant, utilisé pour décrire les données de temps de position et de type fix.

Format GPGGA : 
<img src="https://docs.arduino.cc/static/63d81cb4391da3e616bbcfab7c9d12d8/4ef49/gps-nmea-0183_img01.png" align="center">

## Installation
1. Clonez le dépôt
```
git clone https://gitlab.info.iut-tlse3.fr/wwl4521a/project-r2.04-tramegps.git
```
2. Naviguez jusqu'au répertoire du projet
```
cd repertoireProjet
```
3. Utilisez le Makefile pour compiler le code source
```
make
```
4. Pour supprimer les fichiers supplémentaires
```
make clean
```
## Utilisation d'application
### Compilation et exécution du programme
Après avoir compilé le code source à l'aide de la commande make executez le programme en tapant:
```
./main
```
### Choix des données d'entrée
Le programme vous demandera de choisir l'une des options suivantes en tapant le numéro correspondant:
* **1** : Saisir manuellement les trames GPS 
* **2** : Lire les trames GPS à partir d'un fichier
* **3** : Quitter l'application

### Saisie manuelle des données
Si vous choisissez de saisir manuellement les données, entrez les trames GPS une par une, suivies par la touche "Entrée". Pour terminer la saisie, tapez "exit".

### Lecture des trames GPS à partir d'un fichier
Si vous choisissez de lire les trames GPS à partir d'un fichier, indiquez le chemin vers votre fichier. Le format des trames GPS dans le fichier doit être comme le suivant:
```
$GPGGA,133519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, ,*42
$GPGGA,123519,4124.8963,N,08151.6838,W,1,08,0.9,545.4,M,46.9,M, ,*42
$GPGGA,235317.000,4003.9039,N,10512.5793,W,1,08,1.6,1577.9,M,-20.7,M,,0000*5F

```
### Enregistrement du résultat dans un fichier
Les résultats des converesions seront enregistrés dans un fichier appelé "enregistrements.txt" situé dans le répertoire du projet.

### Affichage du résultat
Le programme vous demandera ensuite si vous souhaitez afficher les résultats de la conversion dans le terminal. 
* Si vous répondez 1 (oui), les résultats contenus dans le fichier "enregistrements.txt" seront affichés et le programme se terminera.
* Si vous répondez 0 (non), le programme se terminera sans affichage.

## Documentation complète avec Doxygen

Pour accéder à la documentation complète générée avec Doxygen pour ce projet (incluant les fonctions et autres éléments), veuillez suivre ces étapes :

1. Téléchargez le projet dans votre espace de travail.

2. Ouvrez le fichier `index.html` situé dans le répertoire `html/index.html` à l'aide de votre navigateur préféré.

Vous y trouverez une documentation détaillée sur le fonctionnement du projet ainsi que des explications sur les différentes fonctionnalités implémentées.
Dans la navigation de la page de documentation, dans la section "classes", nous pourrons voir les structures utilisées pour le projet, et dans la section "files", nous pourrons voir la documentation sur les fichiers de code avec les fonctions utilisées.

## Comment cet application fonctionne-t-il?
Les données contenant plusieurs trames GPS sont d'abord lues à partir d'un document fourni par l'utilisateur (un exemple du fichier nommé "data.txt" est donné). Les trames sont traitées une par une en vérifiant le type de trame en vérifiant le type de trame et en s'assurant qu'elle comporte au moins 15 champs. Ensuite, les informations pertinentes, à savoir l'heure de réception, la longitude et la latitude, sont extraites et testées pour leur format. Ensuite, la longitude et la latitude sont converties du format décimal au format degré. L'heure de réception est également formatée. Enfine, les informations traitées sont stockées dans un autre fichier nommé "enregistrement.txt".

## Outils Utilisées

**Visual Studio Code (VS Code)**<br/>
Pour ce projet nous avons utilisé Visual Studio Code (VS Code) comme environnement de développement intégré (IDE) car il est très polyvalent et personnalisable. Nous avons pu utiliser le terminal ainsi que GitLab car VS Code s'intègre à Git. Cela nous a permis d'avoir une interface utilisateur conviviale, une large gamme d'extensions et un contrôle de cersion efficace dans l'IDE.

**GitLab**<br/>
De plus nous avons utilisé GitLab car il nous a permis de suivre les modifications tout au long ce projet et de collaborer avec les membre de l'équipe, ce qui nous a permis de collaborer, de faire des revues de code et de suivre les problèmes de fusion.

**Doxygen**
Nous avons également intégré Doxygen à notre flux de travail pour documenter automatiquement notre code source. Cette intégration génère une documentation claire et structurée, ce qui facilite la compréhension du projet pour les membres de l'équipe et les contributeurs externes. En fournissant une vue détaillée des fonctions et des structures de données, Doxygen améliore la lisibilité du code et favorise les bonnes pratiques de programmation.

**Compilateur GCC**<br/>
En ce qui concerne le compilateur, nous avons utilisé gcc, le suite de compilateurs C la plus largement utilisée car elle est open source est disponible gratuitement.
La combinaison de ces outils offre un environnement de développement complet pour la construction de notre projet de manière efficace en founissant les outils pour promouvoir la qualité du code, la collaboration et la maintenabilité.

## Défis Rencontrés et Fonctionnalités Futures
Tout au long de ce projet, l'un des défis rencontrés a été la gestion des données d'entrée, notamment l'analyse et la conversion des coordonnées géographiques (latitude et longitude) dans différents formats. Cependant, avec les ressources fournies dans le sujet ainsi que d'autres que nous avons répertoriées dans les références, nous avons pu mieux comprendre le sujet.

Nous avons également rencontré des difficultés avec l'utilisation de GitLab sur VS Code car nous sommes assez nouveaux dans ce domaine. Bien que cela ait ralenti notre rythme au début de notre projet, la maîtrise de l'utilisation de GitLab nous a permis de collaborer plus efficacement car nous pouvons travailler virtuellement sur le même projet et fusionner nos codes.

Comme notre projet se concentre uniquement sur l'analyse des trames GPS de type GPGGA, nous espérons à l'avenir pouvoir développer davantage notre application pour pouvoir traiter d'autres formats tels que GPGLL, GPGSA, GPGSV, etc.
