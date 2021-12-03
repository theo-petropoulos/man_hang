#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/types.h>

#include "header.h"

int main ( )
{
	srand(time(NULL));
	// Init menus inputs
	char 	c_main_menu_input = '\0', c_words_menu_input = '\0', c_play_menu_input = '\0';
	// Open text file
	FILE 	*f_words = fopen("assets/words.txt", "r+");

	if ( !f_words )
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
								menu_add_word(PLATFORM_NAME, f_words, &c_main_menu_input);
							}
							break;

						// Delete a word
						case '2':
							c_words_menu_input = '\0';
							{
								menu_del_word(PLATFORM_NAME, f_words, &c_main_menu_input);
							}
							break;
						case '3':
							break;
						default:
							while ( ( c_words_menu_input = getchar() ) == '\n');
							break;
					}
				}
				break;
			case '2':
				// Reset main menu input
				c_main_menu_input = '\0';

				while ( c_play_menu_input != 3 )
				{
					// Refresh screen
					if( c_play_menu_input == '\0')
						print_play_menu(PLATFORM_NAME);

					// Remove line feed from input
					while ( ( c_play_menu_input = getchar() ) == '\n');

					c_play_menu_input = c_play_menu_input - '0';

					if( c_play_menu_input >= 4 && c_play_menu_input <= 9)
					{
						printf("HERE\n");
						menu_play_game(PLATFORM_NAME, f_words, c_play_menu_input);
						printf("END GAME\n");

					}
					else
					{
						print_menu_error_digits(PLATFORM_NAME);
					}
				}
				break;
			case '3':
				clear_screen(PLATFORM_NAME);
				fclose(f_words);
				return 0;
				break;
			default:
				while ( ( c_main_menu_input = getchar() ) == '\n');
				break;
		}
	}

	fclose(f_words);
	return 0;
}
