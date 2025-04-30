Dans ce projet, nous avons travailler sur un jeu de mathématiques. Pour cela nous avons réaliser plusieurs jeux différent, ils sont numérotés de 1 à 8. Le premier jeux se porte sur les additions, le second sur les soustractions, le troisième sur les multiplications, le quatrième sur les tables de multiplications, le cinquième sur la division euclidienne, le sixième sur des additions et des multiplications, le septième sur les puissances et pour finir le dernier lance n'importe quel jeux aléatoirement. Le but du jeu est de réussir le calcul demmandé du premier coup, vous avez plusieurs chance au bout de trois essais échoués vous n'avez aucun point et la réponse s'affiche. Vous pouvez vous reconnecter et récupérer votre score que vous avez réussi précédemment. La liste des score se trouve dans score.txt. (Pour vous connectez il suffit de mettre votre prénom et vous reconnecter remettre votre prénom à l'identique). 

Les instructions d'installation et de configuration: Nous avons réaliser ce projet sur Visual Studio Code et avons utilisé MinGW comme compilateur.
Attention a avoir toutes les extensions nécéssaire au langage C sur VSCode.

Les instructions d'utilisation pour les joueurs: Pour bien démarrer le jeu il faut commencer par compiler le programme correctement. Puis vous allez inscrire votre nom, si aucun score n'est présent un nouveau fichier score.txt va se créer, sinon le programme va vérifier si vous avez déjà joué ou non. Vous pouvez jouer à 8 jeux différents, pour arréter de jouer il suffit d'écrire 0 après la question "Quel est votre choix?". Pour éviter toutes erreurs, nous avons réussi à créer une fonction qui à chaque réponses érifie le type de la réponse et redemmande la question si la réponse n'est pas un entier.

Des informations pour les développeurs souhaitant contribuer au projet: Nous pouvons rajouter d'autres jeux pour ceux qui aiment les défis, sinon le programme est assez complet et nous pensons avoir vérifier chaque possible erreurs et il n'y est plus censer en avoir.

Arborescence: 
-output
|----scores.txt
-Projet.c

Ce projet a été réaliser en collobaration avec docXaline et BriacPetiaux.
