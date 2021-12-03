void menu_add_word(char *platform, FILE *f_file, char *c_main_menu_input){
	char 	s_new_word[10] = {0}, c_new_letter = '\0';
	int8_t 	i8_init = 0;
	print_add_menu(platform);

	while ( c_new_letter == '\0' )
	{
		// Prompt user and continue while word's length < 4 && > 9
		do
		{
			// Get user's input
			fgets(s_new_word, 10, stdin);
			// Show error on attempt
			if ( i8_init != 0 )
			{
				print_menu_error_length(platform);
			}
		} while ( ConsumeExtra(s_new_word, &i8_init) || ( (int)strlen(s_new_word) < 5 && s_new_word[0] != '3' ) );

		// Remove line feed from user's input
		while ( s_new_word[strlen(s_new_word) - 1] == '\n' )
			s_new_word[strlen(s_new_word) - 1] = '\0';

		// Parse the word and check if every character is alphabetical
		for ( int8_t i8_i = 0; i8_i < (int8_t)strlen(s_new_word); i8_i++ )
		{
			// If a character isn't a letter
			if ( !isalpha(s_new_word[i8_i]) )
			{
				// If the character is 3 ( return input )
				if ( s_new_word[i8_i] == '3' )
				{
					*c_main_menu_input = '1';
					c_new_letter = 'X';
				}
				// Else show error
				else{
					print_menu_error_chars(platform);
					c_new_letter = '\0';
					i8_i = (int8_t)strlen(s_new_word);
				}
			}
			// Else break the loop
			else
			{
				c_new_letter = s_new_word[i8_i];
			}
		}

		// Insert the new word inside the words list
		if ( c_new_letter != '\0' && c_new_letter != 'X' )
		{
			print_add_menu_success(platform);
			add_new_word(s_new_word, f_file);
			c_new_letter = '\0';
		}
	}
}

void menu_del_word(char *platform, FILE *f_file, char *c_main_menu_input){
	char 	s_del_word[10] = {0}, c_del_letter = '\0';
	int8_t 	i8_init = 0;
	print_del_menu(platform);

	while ( c_del_letter == '\0' )
	{
		// Prompt user and continue while word's length < 4 && > 9
		do
		{
			// Get user's input
			fgets(s_del_word, 10, stdin);
			// Show error on attempt
			if ( i8_init != 0 )
			{
				print_menu_error_length(platform);
			}
		} while ( ConsumeExtra(s_del_word, &i8_init) || ( (int)strlen(s_del_word) < 5 && s_del_word[0] != '3' ) );

		// Remove line feed from user's input
		while ( s_del_word[strlen(s_del_word) - 1] == '\n' )
			s_del_word[strlen(s_del_word) - 1] = '\0';

		// Parse the word and check if every character is alphabetical
		for ( int8_t i8_i = 0; i8_i < (int8_t)strlen(s_del_word); i8_i++ )
		{
			// If a character isn't a letter
			if ( !isalpha(s_del_word[i8_i]) )
			{
				// If the character is 3 ( return input )
				if ( s_del_word[i8_i] == '3' )
				{
					*c_main_menu_input = '1';
					c_del_letter = 'X';
				}
				// Else show error
				else{
					print_menu_error_chars(platform);
					c_del_letter = '\0';
					i8_i = (int8_t)strlen(s_del_word);
				}
			}
			// Else break the loop
			else
			{
				c_del_letter = s_del_word[i8_i];
			}
		}

		// Insert the new word inside the words list
		if ( c_del_letter != '\0' && c_del_letter != 'X' )
		{
			print_del_menu_success(platform);
			delete_word(s_del_word, f_file);
			c_del_letter = '\0';
		}
	}
}

void menu_play_game(char *platform, FILE *f_file, int c_play_menu_input){
	int8_t 	i8_t = c_play_menu_input;
	char 	*play_word = malloc(i8_t * sizeof(char));
	play_word = get_random_word(f_file, i8_t);
	play_game(platform, play_word, i8_t);
	free(play_word);
}
