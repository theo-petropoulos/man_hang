/*
* Code by "chux" https://stackoverflow.com/questions/28574983/fgets-limiting-input-length
*/
int ConsumeExtra(const char *buf, int8_t *i8_i) {
	int found = 0, ch;
	*i8_i = 1;
	if (strchr(buf, '\n') == NULL)
	{
    	// dispose of extra data
		while ( (ch = fgetc(stdin)) != '\n' && ch != EOF )
		{
			found = 1;
	    }
	}
	return found;
}

void add_new_word(char *s_word, FILE *f_file){
	/*
	* Init counter, string to append the file's content, the index we're looking for and the index we will read char by char
	*/
	int32_t i32_i = 0;
	char 	*s_file_content = 0;
	char 	c_find_index = strlen(s_word) + '0';
	char 	c_read_index = '\0';

	while ( !feof(f_file) )
	{
		// Read each character
        fscanf(f_file, "%c", &c_read_index);

		// Increase the string's size and insert char
		i32_i++;
		s_file_content = realloc(s_file_content, i32_i * sizeof(char));
		s_file_content[i32_i - 1] = c_read_index;

		// When the index is found
        if ( c_read_index == c_find_index )
		{
			i32_i++;
			s_file_content = realloc(s_file_content, i32_i * sizeof(char));
			s_file_content[i32_i - 1] = '\n';

			i32_i++;
			s_file_content = realloc(s_file_content, i32_i * sizeof(char));

			for ( int8_t i8_i = 0; i8_i < (int8_t)strlen(s_word); i8_i++, i32_i++ )
			{
				s_file_content = realloc(s_file_content, i32_i * sizeof(char));
				s_file_content[i32_i - 1] = s_word[i8_i];
			}
			i32_i--;
        }
    }

	s_file_content = realloc(s_file_content, i32_i * sizeof(char));
	s_file_content[i32_i - 1] = '\0';

	/*
	* Rewind file, rewrite its content and rewind it again
	*/
	rewind(f_file);
	fprintf(f_file, "%s", s_file_content);
	rewind(f_file);

	free(s_file_content);
}

void delete_word(char *s_word, FILE *f_file){
	/*
	* Init counter, string to append the file's content, the index we're looking for and the index we will read char by char
	*/
	int32_t i32_i = 0;
	int8_t 	i8_i = 0;
	char 	*s_file_content = 0;
	char 	c_read_index = '\0';

	while ( !feof(f_file) )
	{
		i8_i = 0;
		// Read each character
        fscanf(f_file, "%c", &c_read_index);

		// Increase the string's size and insert char
		i32_i++;
		s_file_content = realloc(s_file_content, i32_i * sizeof(char));
		s_file_content[i32_i - 1] = c_read_index;

		// When the index is found
        while(s_word[i8_i] == c_read_index && s_word[i8_i])
		{
			fscanf(f_file, "%c", &c_read_index);
			i8_i++;
			i32_i++;
			s_file_content = realloc(s_file_content, i32_i * sizeof(char));
			s_file_content[i32_i - 1] = c_read_index;
			// If counter reachs word's length, rewind the file parser and cut the content beyond it
			if(i8_i == (int8_t)strlen(s_word) )
			{
				i32_i -= ( i8_i + 1 );
				s_file_content[i32_i] = '\0';
			}
		}
    }

	s_file_content = realloc(s_file_content, i32_i * sizeof(char));
	i32_i--;
	s_file_content[i32_i] = '\0';

	/*
	* Rewind file, shrink it, rewrite its content and rewind it again
	*/
	rewind(f_file);
	ftruncate(fileno(f_file), i32_i);
	fprintf(f_file, "%s", s_file_content);
	rewind(f_file);

	free(s_file_content);
}

char * get_random_word(FILE *f_file, int8_t i8_level){
	int32_t	i32_i = 0;
	char 	c_find_index = i8_level + '0';
	char 	c_end_index = ( i8_level + 1 ) + '0';
	char 	c_read_index = '\0';
	char 	*play_word = {0};
	char 	**pp_words_array = 0;

	while ( !feof(f_file) )
	{
		// Read each character
		fscanf(f_file, "%c", &c_read_index);

		// When the index is found
		if ( c_read_index == c_find_index )
		{
			// When index is reached, jump to the next first letter ( skip '\n') and begin processing the word
			fscanf(f_file, "%c", &c_read_index);
			fscanf(f_file, "%c", &c_read_index);

			// Process words while the next index isn't reached
			while ( c_read_index != c_end_index )
			{
				int8_t i8_i = 0;
				pp_words_array = (char **) realloc(pp_words_array, (i32_i + 1) * sizeof(*pp_words_array));
				pp_words_array[i32_i] = (char *)malloc(i8_level * sizeof(char));
				while ( c_read_index != '\n' && c_read_index != c_end_index )
				{
					pp_words_array[i32_i][i8_i] = c_read_index;
					fscanf(f_file, "%c", &c_read_index);
					i8_i++;
				}
				fscanf(f_file, "%c", &c_read_index);
				i32_i++;
			}
		}
	}

	int32_t 	i32_rand = rand() % i32_i;
	play_word = pp_words_array[i32_rand];

	for(int8_t i8_j = 0; i8_j < i32_i; i8_j++)
	{
		if(i8_j != i32_rand)
			free(pp_words_array[i8_j]);
	}
	free(pp_words_array);

	return play_word;
}

int is_in_word(char c_guess, char *word, char *s_blind_word)
{
	int8_t i8_i = 0, i8_found = 0;
	while(word[i8_i])
	{
		if(word[i8_i] == c_guess)
		{
			s_blind_word[i8_i] = c_guess;
			i8_found = 1;
		}
		i8_i++;
	}
	return i8_found;
}

void play_game(char *platform, char *word, int8_t i8_level)
{
	int8_t 	i8_i = 0, i8_counter = 0, i8_wrong_guesses = 0;
	char 	c_one = ' ', c_two = ' ', c_three = ' ', c_four = ' ', c_five = ' ', c_six = ' ', c_seven = ' ';
	char 	c_guess = '\0';
	char 	*s_blind_word = malloc(i8_level * sizeof(char));
	char 	*s_guessed_letters = (char *)malloc(i8_counter * sizeof(char));

	while(word[i8_i] != '\0')
	{
		s_blind_word[i8_i] = '?';
		s_guessed_letters[i8_i] = ' ';
		i8_i++;
	}

	print_play_game(platform, c_one, c_two, c_three, c_four, c_five, c_six, c_seven, s_blind_word, s_guessed_letters);

	do
	{
		while ( ( c_guess = getchar() ) == '\n');

		if(isalpha(c_guess))
		{
			s_guessed_letters[i8_counter] = c_guess;
			i8_counter++;
			s_guessed_letters = (char *)realloc(s_guessed_letters, i8_counter * sizeof(char));
			if(!is_in_word(c_guess, word, s_blind_word))
			{
				i8_wrong_guesses++;
				if ( c_one == ' ' ) c_one = '|';
				else if ( c_three == ' ' ) c_three = 'o';
				else if ( c_two == ' ' ) c_two = '_';
				else if ( c_four == ' ' ) c_four = '_';
				else if ( c_five == ' ' ) c_five = '|';
				else if ( c_six == ' ' ) c_six = '/';
				else if ( c_seven == ' ' ) c_seven = '\\';
			}
			print_play_game(platform, c_one, c_two, c_three, c_four, c_five, c_six, c_seven, s_blind_word, s_guessed_letters);
			printf("%s - %s - %d", word, s_blind_word, strcmp(word, s_blind_word));
		}
		else
			print_play_char(platform);
		if ( c_guess == 3)
		{
			free(s_blind_word);
			free(s_guessed_letters);
			break;
		}
		else if ( strcmp(word, s_blind_word) == 0 )
		{
			print_play_victory(platform);
			free(s_blind_word);
			free(s_guessed_letters);
			break;
		}
		else if ( i8_wrong_guesses >= 7 )
		{
			print_play_defeat(platform, word);
			free(s_blind_word);
			free(s_guessed_letters);
			break;
		}
	} while ( c_guess != '3' || strcmp(word, s_blind_word) == 0 || i8_counter >= i8_level );

}
