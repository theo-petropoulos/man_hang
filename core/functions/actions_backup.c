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

void get_random_word(FILE *f_file, int8_t i8_level, char **play_word){
	int32_t	i32_i = 0;
	char 	c_find_index = i8_level + '0';
	char 	c_end_index = ( i8_level + 1 ) + '0';
	char 	c_read_index = '\0';
	char 	**pp_words_array;
	pp_words_array = malloc(i32_i * sizeof(*pp_words_array));
	pp_words_array[i32_i] = malloc(i8_level * sizeof(char));

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
				while ( c_read_index != '\n' && c_read_index != c_end_index )
				{
					pp_words_array[i32_i][i8_i] = c_read_index;
					fscanf(f_file, "%c", &c_read_index);
					i8_i++;
				}
				printf("word => %s\n", pp_words_array[i32_i]);
				fscanf(f_file, "%c", &c_read_index);

				if ( !isdigit(c_read_index) )
				{
					i32_i++;
					pp_words_array = realloc(pp_words_array, i32_i * sizeof(*pp_words_array));
					pp_words_array[i32_i] = malloc(i8_level * sizeof(char));

				}
			}
		}
	}

	*play_word = pp_words_array[0];

	free(pp_words_array);
}
