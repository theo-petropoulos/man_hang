#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

int main ( int argc, char *argv[] )
{
	// Init menus inputs
	char 	c_main_menu_input = '\0', c_words_menu_input = '\0';
	// Open text file
	FILE 	*words = fopen("assets/words.txt", "r+");

	if ( !words )
	{
		printf("Une erreur est survenue pendant l'ouverture ou la lecture du fichier.\n");
		return 0;
	}

	while ( c_main_menu_input != '3' )
	{
		// Print menu screen
		print_main_menu(PLATFORM_NAME);

		// Reset words menu input
		c_words_menu_input = '\0';

		// Remove line feed from input
		while ( ( c_main_menu_input = getchar() ) == '\n');

		switch ( c_main_menu_input )
		{
			// Words menu
			case '1':
				// Reset main menu input
				c_main_menu_input = '\0';

				while ( c_words_menu_input != '3' )
				{
					// Refresh screen
					if ( c_words_menu_input != '1' && c_words_menu_input != '2' )
						print_word_menu(PLATFORM_NAME);

					// Remove line feed from input
					while ( ( c_words_menu_input = getchar() ) == '\n');

					switch ( c_words_menu_input )
					{
						// Add a new word
						case '1':
							// Reset words menu input
							c_words_menu_input = '\0';
							{
								char 	s_new_word[10] = {0}, c_new_letter = '\0';
								int8_t 	i8_init = 0;
								print_add_menu(PLATFORM_NAME);

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
											print_add_menu_error_length(PLATFORM_NAME);
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
												c_main_menu_input = '1';
												c_new_letter = 'X';
											}
											// Else show error
											else{
												print_add_menu_error_chars(PLATFORM_NAME);
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
										print_add_menu_success(PLATFORM_NAME);
										add_new_word(s_new_word, words);
										c_new_letter = '\0';
									}
								}
								break;
							}

						// Delete a word
						case '2':
							printf("THERE TWO\n");
							break;
						case '3':
							printf("THERE THREE\n");
							break;
						default:
							printf("THERE DEFAULT");
							while ( ( c_words_menu_input = getchar() ) == '\n');
							break;
					}
				}
				break;
			case '2':
				printf("MAIN TWO\n");
				break;
			case '3':
				clear_screen(PLATFORM_NAME);
				fclose(words);
				return 0;
				break;
			default:
				printf("MAIN DEFAULT %d\n", c_main_menu_input);
				while ( ( c_main_menu_input = getchar() ) == '\n');
				break;
		}
		printf("main menu => %c -- word menu => %c\n", c_main_menu_input, c_words_menu_input);
	}

	fclose(words);
	return 0;
}
