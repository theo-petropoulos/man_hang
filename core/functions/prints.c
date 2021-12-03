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

void print_play_game(char *platform, char c_one, char c_two, char c_three, char c_four, char c_five, char c_six, char c_seven, char *s_blind_word, char *s_guessed_letters){
	clear_screen(platform);
	printf("\
		.-=======================-.\n\
		|X|          %c          |X|\n\
		| |         %c%c%c         | |\n\
		| |          %c          | |\n\
		| |         %c %c         | |\n\
		| |                     | |\n\
		| |  Entrez une lettre  | |\n\
		| |     3 - Retour      | |\n\
		x+++++++++++++++++++++++++x\n\n\
		DEVINEZ : %s\n\
		HISTORIQUE : %s\n", c_one, c_two, c_three, c_four, c_five, c_six, c_seven, s_blind_word, s_guessed_letters);
}

void print_play_char(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|          ERREUR         |\n\
		|   Le caractère saisit   |\n\
		|   n'est pas une lettre  |\n\
		|                         |\n\
		|  3 - Retour             |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}

void print_play_defeat(char *platform, char *word){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|         DEFAITE         |\n\
		|  Vous n'avez pas réussi |\n\
		|     à trouver le mot    |\n\
		|  [4-9] - Réessayer      |\n\
		|      3 - Retour         |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n\n\
		Le mot était : %s\n", word);
}

void print_play_victory(char *platform){
	clear_screen(platform);
	printf("\
		x+++++++++++++++++++++++++x\n\
		|                         |\n\
		|         VICTOIRE        |\n\
		|   Vous avez réussi à    |\n\
		|      trouver le mot     |\n\
		|  [4-9] - Réessayer      |\n\
		|      3 - Retour         |\n\
		|                         |\n\
		x+++++++++++++++++++++++++x\n");
}
