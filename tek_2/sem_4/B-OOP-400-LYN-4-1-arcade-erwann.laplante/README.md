Graphical library :

Avant de commencer, vous devez hériter votre class de jeu de la class Idisplay. Les fonctions ci-jointes sont inhérentes à cette classe.


                    	/* ============= Librairie ============= */
        	void clear(void){} : Clear les sprites et textures.
        	void refresh(void){} Recharge les sprites et les textures.
        	void update(std::map<std::string, Sprite> &) {} : Remplace l’ancienne map de sprite par une nouvelle.

        	/* ============= Window =4============ */
        	void createWin(void){} : Créé une nouvelle fenêtre.
        	void deleteWin(void){} : Détruit la fenêtre.

        	bool manageEvent(void){} : Attrape tous les events (clicks, inputs…).
        	void checkCollide(std::map<std::string, Sprite> &){} : Check si les sprites ou textures se touchent.

        	void addSprite(Sprite &){} : Ajoute un sprite à la map.
        	void drawSprites(std::map<std::string, Sprite> &){} : Affiche les sprites étant dans la map de sprite.
        	std::pair<std::string, bool> getKey(void){} : Retourn un pair de la touche et s’il a été appiuyé.
        	std::pair<int, int>getWindowBorders(void){} : Retourne les données des bordures de la fenêtre.

        	/* ============= Extra ============= */
        	std::string getName(void) const{} : Retourne le nom 

GAME LIBRARY :

La classe principale de votre jeu doit hériter de l’interface IGame.hpp présente dans le fichier src/games/IGame.hpp

Toutes les fonctions déclarées ci-dessous doivent être implémentées dans votre classe !

Les attributs nécessaires aux méthodes, doivent être instanciés dans votre classe de jeu.

Pour cette interface, un attribut du type « std::map<std::string, Sprite> » et un autre du type « std::pair<std::string, bool> » sont obligatoire pour le bon fonctionnement du programme.

Voici un descriptif de toutes les méthodes de l’interface Igame.hpp :

    • « virtual ~IGame(void) » : le destructeur par défaut de notre interface
    • « virtual void reset(void) » : permet, notamment, de réinitialiser votre jeu aux valeurs par défaut
    • « virtual void update(void) » : permet de mettre à jour votre environnement de jeu. Tous les changements en cours de jeu (position, score, etc.) doivent être effectués dans cette fonction !
    • « virtual std::map<std::string, Sprite> &getMapSprite(void) » : retourne un dictionnaire comportant une chaine de caractères reliée à une instance de la structure Sprite (détaillée page 2). Cette fonction permet de récupérer l’ensemble des sprites crées et placées dans le dictionnaire.
    • « virtual void setInput(std::pair<std::string, bool>) » : Cette fonction permet de modifier un input grâce à une paire contenant une chaine de caractère symbolisant la touche envoyée par la librairie graphique et un booléen.
L’input doit donc être, au préalable, contenue dans votre classe de jeu en tant qu’attribut.

Présentation de la classe Sprite :
Attributs de la classe Sprite (voir ci-dessus) :
    • _name : nom du sprite
    • _xPos : position X du sprite sur la fenêtre
    • _yPos : position X du sprite sur la fenêtre
    • _texture : texture qui compose le sprite (classe Texture présenté page 3)
    • _collide : détermine avec quelle sprite, elle est en collision (en fonction du nom de celle -ci)
    • _facing : direction du sprite (0 : Left, 1 : Right, 2 : Up, 3 : Down, 4 : Init)
Le constructeur attend les arguments suivants : le 1er de type std::string pour le nom,  le 2ème et 3ème de type int pour respectivement la position x et y du sprite dans la fenêtre de jeu et le dernier de type Texture & pour la texture dont est composée le Sprite,





Présentation de la classe Texture :


Attributs de la classe Texture (voir ci-dessus) :
    • _path : le chemin vers le fichier de la texture
    • _xPos : position X de la texture dans le fichier _path
    • _yPos : position Y de la texture dans le fichier _path
    • _xSize : largeur de la texture dans le fichier _path
    • _ySize : hauteur de la texture dans le fichier _path
    • _symbol : pour les librairies graphique n’utilisant pas de Sprite/Texture, comme la Ncurses, cet attribut permet d’avoir un caractère ou une chaine de caractères pour remplacer la texture.

Le constructeur attend les arguments suivants: un 1er et 2ème de type std ::string pour, respectivement, le nom et le symbole, le 3ème et le dernier de type std::pair<int, int> pour, respectivement, la position (X = 1er élémentde la paire, Y = 2ème élément de la paire) et la taille (X = 1er élémentde la paire, Y = 2ème élément de la paire),

