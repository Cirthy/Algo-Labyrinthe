# LAB ORATOIRE

Introduction here - mettre des jolis screenshots

## Structures utilisées

Notre structure **labyrinthe** est composée de :

* Un tableau de cellules - `unsigned short **grid` :
	* Chaque unsigned short est codé sur 16 bits.
	* Les 4 premiers sont utilisés pour stocker la position des murs autour de la cellule (insérer schéma)
	* Les 12 suivants sont utilisés par les fonctions de recherche de chemin pour stocker la distance de la cellule par rapport à l'entrée. Nos fonctions ne peuvent donc trouver que des chemins de longueur inférieure à **4095** cellules.
* La hauteur et la largeur du labyrinthe - `int height; int width;`
* La position de l'entrée et la sortie du labyrinthe - `position entrance; position exit;`
* La position d'un curseur, qui est utilisé par les fonctions de recherche de chemin pour "se déplacer" dans le labyrinthe - `position cursor`
Nous avons donc également défini une structure **position** contenant deux coordonnées :
```
typedef struct		position
{
	int				x;
	int				y;	
}					position;
```
Ainsi qu'une structure **path** qui représente des chemins dans le labyrinthe :
```
typedef struct		path
{
	char			type; // Contient un code indiquant la provenance de la variable
	int				length;
	position		*cells;
}					path;
```
Avec ces structures, nous avons écrit des fonctions de manipulation élémentaires dans *management.c*, qui nous permettent principalement :
* De lire ou d'écrire des informations dans les cellules du labyrinthe
* De manipuler facilement les positions et les chemins

## Générations de labyrinthe

### Génération aléatoire

Lorsque le labyrinthe est généré de manière aléatoire :
* Des murs sont placés sur le bord du labyrinthe
* La position de l'entrée et de la sortie est choisie complètement aléatoirement : il n'y a pas nécessairement de chemin entre l'entrée et la sortie
* La probabilité de présence de chaque mur au centre du labyrinthe suit une loi de Bernouilli de paramètre 1 / PROB_WALL (défini dans *labyrinthe.h*)

Bien entendu, si une cellule possède un mur en commun avec la cellule placée à sa droite (par exemple), la cellule à droite possèdera nécessairement le même mur commun à sa gauche.

### Génération depuis une interface

Baptiste

### Génération depuis un fichier et export

Léa

## Affichage de labyrinthes et de chemins

Baptiste (On gère le cas où le lab est trop gros en ne l'affichant pas)

## Recherche de chemin

### Recherche en profondeur

`void	browse_maze_DFS(labyrinthe *L, int distance);`

La fonction `browse_maze_DFS` (*pathfinding.c*) parcourt le labyrinthe en profondeur afin de calculer la distance à l'entrée de toutes les cases accessibles sans passer par la sortie. On ne peut pas arrêter la fonction dès qu'on atteint la sortie, le premier chemin trouvé n'est pas nécessairement le plus court !\
Son paramètre *distance* contient la distance par rapport à l'entrée et au chemin étudié. (petit schéma ?)

Cette fonction est appelé dans les conditions suivantes :
* La distance de chaque case du labyrinthe est initialisée à la distance maximale (4095)
* Le curseur est placé sur l'entrée
* Au premier appel, son paramètre *distance* vaut 0

La fonction va regarder toutes les cases accessibles depuis la position du curseur. Il faut vérifier s'il n'y a pas de mur entre les deux cellules, mais aussi qu'on étudie bien le plus court chemin entre l'entrée et la cellule-destination. Afin de vérifier cette deuxième condition, il suffit de vérifier que la variable *distance* de notre fonction (car on se déplace d'une case) est inférieure à la distance stockée sur la case.

### Recherche en largeur

Johanna

### Construction du chemin

Gère le cas où il existe un chemin de longueur DISTANCE_MAX

## Stats - Complexité

Finalement, nous allons évaluer les coûts en calcul de nos algorithmes de recherche de chemin, et mesurer le temps de calcul sur des gros labyrinthes afin de vérifier ces considérations théoriques.

### Coût de l'algorithme de recherche en profondeur

### Coût de l'algorithme de recherche en largeur

### Temps de calcul

