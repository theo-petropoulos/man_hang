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

void print_add_menu_error_chars(char *platform){
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

void print_add_menu_error_length(char *platform){
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

/*
* Code by "chux" https://stackoverflow.com/questions/28574983/fgets-limiting-input-length
*/
int ConsumeExtra(const char *buf, int8_t *i8_i) {
  int found = 0;
  *i8_i = 1;
  if (strchr(buf, '\n') == NULL) {
    int ch;
    // dispose of extra data
    while ( (ch = fgetc(stdin)) != '\n' && ch != EOF )
	{
      found = 1;
    }
  }
  return found;
}

int add_new_word(char *s_word, FILE *f_file){
	char 	c_find_index = strlen(s_word) + '0';
	char 	c_read_index = '\0';

	printf("FIND => %c\n", c_find_index);
	while ( !feof(f_file) )
	{
        fscanf(f_file, "%c", &c_read_index);

		printf("FOUND => %c\n", c_read_index);

        if ( c_read_index == c_find_index )
		{
			printf(" HERE HERE HERE ");
            fprintf(f_file, "\n%s", s_word);
        }
    }
	return 0;
}
