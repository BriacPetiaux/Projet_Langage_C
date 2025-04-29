#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct {
    char nom[50];
    int score;
    char date[30];
} Joueur;

int affichage(){
    printf("+-----------------------------------+\n|1 : Addition                 "
        "      |\n|2 : Soustraction                   |\n|3 : Multiplication  "
        "               |\n|4 : Tables des multiplications     |\n|5 : "
        "Divisions                      |\n|6 : Addition et multiplication     |"
        "\n|7 : Puissance carre                |\n|8 : aleatoire                      |"
        "\n|0 : Sortir du jeu                 "
        " |\n+-----------------------------------+\n");
        return 0;
}
int gotchar(int *resu) {
    if (scanf("%d", resu) != 1) {
        printf("Erreur : vous devez entrer un entier !\n");
        while (getchar() != '\n');// on vide l'entée si il y a une erreur de type
        return 0; //On retourne 0 si l'entrée n'est pas invalide
    }
    return 1;// On retourne 1 si l'entrée est valide
}


void sauvegarder_score(const char* nom_joueur, int score) {
    FILE* fichier;
    Joueur joueurs[100];
    int nombreJoueurs = 0;
    int joueurTrouve = 0;
    time_t now = time(NULL);
    char date[30];
    strftime(date, 30, "%Y-%m-%d %H:%M:%S", localtime(&now));

    fichier = fopen("scores.txt", "r");
    if (fichier != NULL) {
        while (fscanf(fichier, "%s %d %[^\n]", joueurs[nombreJoueurs].nom, &joueurs[nombreJoueurs].score, joueurs[nombreJoueurs].date) != EOF) {
            nombreJoueurs++;
        }
        fclose(fichier);

        for (int i = 0; i < nombreJoueurs; i++) {
            if (strcmp(joueurs[i].nom, nom_joueur) == 0) {
                joueurs[i].score = score;
                strcpy(joueurs[i].date, date);
                joueurTrouve = 1;
                break;
            }
        }
    }

    if (!joueurTrouve && nombreJoueurs < 100) {
        strcpy(joueurs[nombreJoueurs].nom, nom_joueur);
        joueurs[nombreJoueurs].score = score;
        strcpy(joueurs[nombreJoueurs].date, date);
        nombreJoueurs++;
    }

    fichier = fopen("scores.txt", "w");
    if (fichier != NULL) {
        for (int i = 0; i < nombreJoueurs; i++) {
            fprintf(fichier, "%s %d %s\n", joueurs[i].nom, joueurs[i].score, joueurs[i].date);
        }
        fclose(fichier);
    } 
    else {
        printf("Erreur: Impossible de sauvegarder le score.\n");
    }
}

int lire_score(const char* nom_joueur) {
    FILE* fichier;
    Joueur joueurs[100];
    int nombreJoueurs = 0;

    fichier = fopen("scores.txt", "r");
    if (fichier != NULL) {
        while (fscanf(fichier, "%s %d %[^\n]", joueurs[nombreJoueurs].nom, &joueurs[nombreJoueurs].score, joueurs[nombreJoueurs].date) != EOF) {
            nombreJoueurs++;
        }
        fclose(fichier);

        for (int i = 0; i < nombreJoueurs; i++) {
            if (strcmp(joueurs[i].nom, nom_joueur) == 0) {
                return joueurs[i].score;
            }
        }
    }

    return 0;
}

int addition() {
    int nombre_1, nombre_2, resultat, score = 0, essais = 0;
    nombre_1 = rand() % 101;
    nombre_2 = rand() % 101;
    while (essais < 3) {
        printf("Quel est le resultat de %d + %d ?\n", nombre_1, nombre_2);
        if (gotchar(&resultat)== 0) {
            continue;
        }
        essais++;
        if (resultat == nombre_1 + nombre_2) {
            printf("Bravo !\n");
            if (essais == 1) score = 10;
            else if (essais == 2) score = 5;
            else if (essais == 3) score = 1;
            return score;
        } 
        else {
            printf("Perdu !\n");
        }
    }

    printf("Le resultat etait %d\n", nombre_1 + nombre_2);
    return score;
}

int soustraction() {
    int nombre_1, nombre_2, resultat, permut, score = 0, essais = 0;
    nombre_1 = rand() % 101;
    nombre_2 = rand() % 101;
    if (nombre_1 - nombre_2 < 0) {
        permut = nombre_1;
        nombre_1 = nombre_2;
        nombre_2 = permut;
    }
    while (essais < 3) {
        printf("Quel est le resultat de %d - %d ?\n", nombre_1, nombre_2);
        if (gotchar(&resultat)== 0) {
            continue;
        }
        essais++;
        if (resultat == nombre_1 - nombre_2) {
            printf("Bravo !\n");
            if (essais == 1) score = 10;
            else if (essais == 2) score = 5;
            else if (essais == 3) score = 1;
            return score;
        } 
        else {
            printf("Perdu !\n");
        }
    }

    printf("Le resultat etait %d\n", nombre_1 - nombre_2);
    return score;
}
int multiplication() {
    int nombre_1, nombre_2, resultat, score = 0, essais = 0;
    nombre_1 = rand() % 11;
    nombre_2 = rand() % 11;
    while (essais < 3) {
        printf("Quel est le resultat de %d x %d ?\n", nombre_1, nombre_2);
        if (gotchar(&resultat)== 0) {
            continue;
        }   
        essais++;
        if (resultat == nombre_1 * nombre_2) {
            printf("Bravo !\n");
            if (essais == 1) score = 10;
            else if (essais == 2) score = 5;
            else if (essais == 3) score = 1;
            return score;
        } 
        else {
            printf("Perdu !\n");
        }
    }
    printf("Le resultat etait %d\n", nombre_1 * nombre_2);
    return score;
}


int Tables_des_multiplications() {
    int resultat, score = 0, table;
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }
    printf("Quelle table de multiplication voulez-vous travailler ?\n");
    while (scanf("%d", &table) != 1 || table < 1 || table > 10) {
        printf("Entree invalide ! Veuillez entrer un entier entre 1 et 10 : ");
        while (getchar() != '\n');
    }
    for (int i = 1; i < 11; i++) {
        int essais = 0;
        while (essais < 3) {
            printf("%d x %d = ", table, i);
            if (gotchar(&resultat)== 0) {
                continue;
            }
            essais++;
            if (resultat == table * i) {
                printf("Bravo !\n");
                if (essais == 1) score += 10;
                else if (essais == 2) score += 5;
                else if (essais == 3) score += 1;
                break;
            } 
            else {
                printf("Perdu !\n");
            }
        }
        if (essais == 3 && resultat != table * i) {
            printf("Le resultat etait %d\n", table * i);
        }
    }
    return score;
}

int Division() {
    int nombre_1, nombre_2, trouve, trouve2, score = 0, essais = 0;
    nombre_1 = rand() % 101;
    nombre_2 = rand() % 11;
    while (essais < 3) {
        printf("Quel est le quotient de la division euclidienne de %d par %d ?\n", nombre_1, nombre_2);
        if(gotchar(&trouve)== 0) {
            continue;
        }
        essais++;
        if (nombre_1 / nombre_2 == trouve) {
            printf("Bravo !\n");
            if (essais == 1) score = 10;
            else if (essais == 2) score = 5;
            else if (essais == 3) score = 1;
            break;
        } 
        else {
            printf("Perdu !\n");
        }
    }
    if (essais == 3 && nombre_1 / nombre_2 != trouve) {
        printf("Le resultat etait %d\n", nombre_1 / nombre_2);
    }

    essais = 0;
    while (essais < 3) {
        printf("Quel est le reste de la division de %d par %d ?\n", nombre_1, nombre_2);
        if (gotchar(&trouve2)== 0) {
            continue;
        }
        essais++;
        if (nombre_1 % nombre_2 == trouve2) {
            printf("Bravo !\n");
            if (essais == 1) score += 10;
            else if (essais == 2) score += 5;
            else if (essais == 3) score += 1;
            break;
        } 
        else {
            printf("Perdu !\n");
        }
    }
    if (essais == 3 && nombre_1 % nombre_2 != trouve2) {
        printf("Le resultat etait %d\n", nombre_1 % nombre_2);
    }

    return score;
}

int additionmult(){
    int nombre_1, nombre_2, nombre_3, nombre_4, resultat, score = 0, essais = 0;
        nombre_1 = rand() % 11;
        nombre_2 = rand() % 11;
        nombre_3 = rand() % 11;
        nombre_4 = rand() % 11;

        while (essais < 3) {
            printf("Quel est le resultat de (%d + %d) * (%d + %d) ?\n", nombre_1, nombre_2, nombre_3, nombre_4);
            if (gotchar(&resultat)== 0) {
                continue;
            }
            essais++;
            if (resultat == (nombre_1 + nombre_2)*(nombre_3 + nombre_4)){
                printf("Bravo !\n");
                if (essais == 1) score = 35;
                else if (essais == 2) score = 25;
                else if (essais == 3) score = 15;
                return score;
            }
            else {
                printf("Perdu !\n");
            }
        }
        printf("Le resultat etait %d\n", (nombre_1 + nombre_2)*(nombre_3 + nombre_4));
        return score;
}
int puissance_carre() {
    int score = 0, valeur, resultat, joueur;
    for (int i = 1; i < 11; i++) {
        valeur = (int)pow(2, i); 
        printf("2 puissance %d = %d\n", i, valeur);
    }
    printf("\nA vous de jouer !\n");
    for (int i = 1; i < 11; i++) {
        resultat = (int)pow(2, i);
        int essais = 0;
        while (essais < 3) {
            printf("2 puissance %d = ? ", i);
            if (gotchar(&joueur) == 0) {
                continue;
            }
            essais++;
            if (joueur == resultat) {
                printf("Bravo !\n");
                if (essais == 1) score += 10;
                else if (essais == 2) score += 5;
                else if (essais == 3) score += 1;
                break;
            } else {
                printf("Mauvaise réponse !\n");
            }
        }
        if (essais == 3 && joueur != resultat) {
            printf("La bonne réponse était : %d\n", resultat);
        }
    }

    return score;
}


int main() {
    char nom_joueur[50];
    printf("Entrez votre prenom: ");
    scanf("%s", nom_joueur);
    int compteur = lire_score(nom_joueur);
    printf("Bonjour %s, vous avez un score de %d points.\n", nom_joueur, compteur);
    int choix = 1000;
    while (choix != 0) {
        affichage();
        printf("Quelle est votre choix? \n");
        if (gotchar(&choix) == 0) {
            continue;
        }
        if (choix < 0 || choix > 8) {
            printf("Erreur : vous devez entrer un entier et une valeur entre 0 et 8 !\n");
            continue;
        }
        if (choix == 8){
            srand(time(NULL));
            choix = (rand()%6)+1;
        }
        switch (choix) {
        case 0:
            printf("Merci de votre visite\n");
            break;
        case 1:
            printf("Addition\n");
            srand(time(NULL));
            compteur = compteur + addition();
            printf("Vous avez un score de %d points \n", compteur);
            sauvegarder_score(nom_joueur, compteur);
            break;
        case 2:
            printf("Soustraction\n");
            srand(time(NULL));
            compteur = compteur + soustraction();
            printf("Vous avez un score de %d points \n", compteur);
            sauvegarder_score(nom_joueur, compteur);
            break;
        case 3:
            printf("Multiplication\n");
            srand(time(NULL));
            compteur = compteur + multiplication();
            printf("Vous avez un score de %d points \n", compteur);
            sauvegarder_score(nom_joueur, compteur);
            break;
        case 4:
            printf("Tables des multiplications\n");
            srand(time(NULL));
            compteur = compteur + Tables_des_multiplications();
            printf("Vous avez un score de %d points \n", compteur);
            sauvegarder_score(nom_joueur, compteur);
            break;
        case 5:
            printf("Division\n");
            srand(time(NULL));
            compteur = compteur + Division();
            printf("Vous avez un score de %d points \n", compteur);
            sauvegarder_score(nom_joueur, compteur);
            break;
        case 6:
            printf("Addition et multiplication\n");
            srand(time(NULL));
            compteur = compteur + additionmult();
            printf("Vous avez un score de %d points.\n",compteur);
            sauvegarder_score(nom_joueur, compteur);
            break;
        case 7:
            printf("Puissance Carre \n");
            srand(time(NULL));
            compteur = compteur + puissance_carre();
            printf("Vous avez un score de %d points.\n",compteur);
            sauvegarder_score(nom_joueur, compteur);
            break;
        default:
            printf("Erreur, saisissez un entier entre 0 et 8\n");
            break;
        }
    }
    return 0;
}