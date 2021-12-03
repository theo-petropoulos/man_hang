void clear_screen(char *platform){
	if(strcmp(platform, "windows") == 1)
		system("cls");
	else
		system("clear");
}

void print_main_menu(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|       HANGMAN GAME      |\n\
		|                         |\n\
		|  1 - Gérer les mots     |\n\
		|  2 - Lancer une partie  |\n\
		|  3 - Quitter            |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_word_menu(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|       DICTIONNAIRE      |\n\
		|                         |\n\
		|  1 - Ajouter un mot     |\n\
		|  2 - Supprimer un mot   |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_add_menu(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|      AJOUTER UN MOT     |\n\
		|     de 4 à 9 lettres    |\n\
		|                         |\n\
		|                         |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_del_menu(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|     SUPPRIMER UN MOT    |\n\
		|     de 4 à 9 lettres    |\n\
		|                         |\n\
		|                         |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_menu_error_chars(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|          ERREUR         |\n\
		|   Le mot contient des   |\n\
		|  caractères non valides |\n\
		|                         |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_menu_error_length(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|          ERREUR         |\n\
		|   La longueur du mot    |\n\
		|       est invalide      |\n\
		|                         |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_menu_error_digits(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|          ERREUR         |\n\
		|   Le niveau saisi est   |\n\
		|         invalide        |\n\
		|                         |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_add_menu_success(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|          SUCCES         |\n\
		|    Le mot a bien été    |\n\
		|  ajouté au dictionnaire |\n\
		|                         |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_del_menu_success(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|          SUCCES         |\n\
		|    Le mot a bien été    |\n\
		|         supprimé        |\n\
		|                         |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_play_menu(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|          JOUER          |\n\
		| Saisissez la difficulté |\n\
		|     de 4 à 9 lettres    |\n\
		|                         |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}
