
<!---banner--->
<h1 align="center">
🚀 Pipex
</h1>

## 📝 Description
Pipex est un projet qui reproduit le comportement des pipes Unix (`|`) en C. Il permet d'exécuter des commandes en chaîne, en redirigeant la sortie d'une commande vers l'entrée d'une autre, tout en gérant les fichiers d'entrée et de sortie.

## 🛠️ Fonctionnalités
- Exécution de commandes en chaîne avec pipes
- Gestion des redirections d'entrée/sortie
- Gestion des erreurs et des permissions
- Support des chemins absolus et relatifs
- Gestion de la mémoire et des ressources

## 📋 Prérequis
- Compilateur GCC
- Make
- Système Unix/Linux

## 🔧 Installation
```bash
git clone https://github.com/votre-username/Pipex.git
cd Pipex
make
```

## 💻 Utilisation
```bash
./pipex file1 cmd1 cmd2 file2
```
- `file1` : fichier d'entrée
- `cmd1` : première commande à exécuter
- `cmd2` : deuxième commande à exécuter
- `file2` : fichier de sortie

### Exemple
```bash
./pipex input.txt "cat" "grep hello" output.txt
```

## 🧪 Tests
Le projet inclut une gestion complète des erreurs pour :
- Fichiers d'entrée/sortie inexistants
- Permissions insuffisantes
- Commandes invalides
- Arguments manquants

## 📚 Structure du Projet
```
.
├── includes/
│   ├── libft/
│   ├── ft_printf/
│   └── get_next_line/
├── src/
│   ├── main.c
│   ├── child.c
│   ├── fork.c
│   ├── error.c
│   └── utils.c
├── Makefile
└── README.md
```

## 🛠️ Technologies et Outils
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white) ![Make](https://img.shields.io/badge/Make-000000?style=for-the-badge&logo=make&logoColor=white) ![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black) ![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)

