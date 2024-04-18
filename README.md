# Project 1 : Analyse de trames GPS

## Description du Projet
L'intérêt de ce projet est de développer une application de géolocalisation permettant d'analyse des trames GPS du type GPGGA suivant la norme NMEA 0183. Cette appliCation dispose d'un ensemble de fonctions qui permettent à l'utilisateur d'extraire et d'étudier les informations provenant des trames GPS, notamment l'heure de réception, la latitude et la longitude.

**Qu'est-ce que NMEA 0183?**
NMEA 0183 est un protocole de messagerie simple utilisé pour la communication entre l'électornique marine, définie et contrôlée par National Marine Electronics Association (NMEA). Les données de ce protocole sont transmises sous forme de chaînes ASCII dans différents formats en fonction des information qu'elles peuvent fournir. 
La structure générale des trames GPS NMEA 0183 commence par un signe $ et se termine par un retour chariot et un saut de ligne. Chaque champ de données dans la phrase étant séparé par un virgule.
GPGGA est un format NMEA 0183 de base et courant, utilisé pour décrire les données de temps de position et de type fix.

Format GPGGA : 
<img src="https://docs.arduino.cc/static/63d81cb4391da3e616bbcfab7c9d12d8/4ef49/gps-nmea-0183_img01.png" align="center">

## Installation
**Prérequis**
<li>
    <ul>Système d'exploitaiton : cette application est compatible avec Windows, macOS et Linux.</ul>
</li>

**Installation**
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
**Utilisation d'application**
1. Créez un fichier avec vos données stockées dedans, un exemple est donné pour les tests dans le fichier data.txt.
2. Exécutew le programme compilé:
```
./main
```
3. Suivez les instructions pour interagir avec l'application. Vous devez saisir le nom de votre dossier. Les données extraites seront ensuite enregistrées dans un dossier appelé "enregistrements.txt" dans votre répertoire de travail.

## Outils Utilisées
<img align="left" alt="Java" width="30px" style="padding-right:10px;" src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Visual_Studio_Code_1.35_icon.svg/768px-Visual_Studio_Code_1.35_icon.svg.png"/>

**Visual Studio Code (VS Code)**
Pour ce projet nous avons utilisé Visual Studio Code (VS Code) comme environnement de développement intégré (IDE) car il est très polyvalent et personnalisable. Nous avons pu utiliser le terminal ainsi que GitLab car VS Code s'intègre à Git. Cela nous a permis d'avoir une interface utilisateur conviviale, une large gamme d'extensions et un contrôle de cersion efficace dans l'IDE.

**GitLab**
De plus nous avons utilisé GitLab car il nous a permis de suivre les modifications tout au long ce projet et de collaborer avec les membre de l'équipe, ce qui nous a permis de collaborer, de faire des revues de code et de suivre les problèmes de fusion.

**Compilateur GCC**
En ce qui concerne le compilateur, nous avons utilisé gcc, le suite de compilateurs C la plus largement utilisée car elle est open source est disponible gratuitement.

Dans l'ensemble, la combinaison de ces outils offre un environnement de développement complet pour la construction de notre projet de manière efficace en founissant les outils pour promouvoir la qualité du code, la collaboration et la maintenabilité.

## Défis Rencontrés et Fonctionnalités Futures

Tout au long de ce projet, l'un des défis rencontrés a été la gestion des données d'entrée, notamment l'analyse et la conversion des coordonnées géographiques (latitude et longitude) dans différents formats. Cependant, avec les ressources fournies dans le sujet ainsi que d'autres que nous avons répertoriées dans les références, nous avons pu mieux comprendre le sujet.

Nous avons également rencontré des difficultés avec l'utilisation de GitLab sur VS Code car nous sommes assez nouveaux dans ce domaine. Bien que cela ait ralenti notre rythme au début de notre projet, la maîtrise de l'utilisation de GitLab nous a permis de collaborer plus efficacement car nous pouvons travailler virtuellement sur le même projet et fusionner nos codes.

Comme notre projet se concentre uniquement sur l'analyse des trames GPS de type GPGGA, nous espérons à l'avenir pouvoir développer davantage notre application pour pouvoir traiter d'autres formats tels que GPGLL, GPGSA, GPGSV, etc.

# Editing this README

When you're ready to make this README your own, just edit this file and use the handy template below (or feel free to structure it however you want - this is just a starting point!). Thanks to [makeareadme.com](https://www.makeareadme.com/) for this template.

## Visuals
Depending on what you are making, it can be a good idea to include screenshots or even a video (you'll frequently see GIFs rather than actual videos). Tools like ttygif can help, but check out Asciinema for a more sophisticated method.

## Support
Tell people where they can go to for help. It can be any combination of an issue tracker, a chat room, an email address, etc.

## Roadmap
If you have ideas for releases in the future, it is a good idea to list them in the README.

## Contributing
State if you are open to contributions and what your requirements are for accepting them.

For people who want to make changes to your project, it's helpful to have some documentation on how to get started. Perhaps there is a script that they should run or some environment variables that they need to set. Make these steps explicit. These instructions could also be useful to your future self.

You can also document commands to lint the code or run tests. These steps help to ensure high code quality and reduce the likelihood that the changes inadvertently break something. Having instructions for running tests is especially helpful if it requires external setup, such as starting a Selenium server for testing in a browser.

## Authors and acknowledgment
Show your appreciation to those who have contributed to the project.

## License
For open source projects, say how it is licensed.

## Project status
If you have run out of energy or time for your project, put a note at the top of the README saying that development has slowed down or stopped completely. Someone may choose to fork your project or volunteer to step in as a maintainer or owner, allowing your project to keep going. You can also make an explicit request for maintainers.
