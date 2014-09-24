#include <stdio.h>
#include <string.h>

#define TOKENS "><+-.,[]"

void tokenize( FILE* file, char* tokenized_instructions )
{
	char temp;
	int i = 0;
	while ( (temp = fgetc( file )) != EOF )
	{
		int j;
		for ( j = 0; j < strlen( TOKENS ); j++ )
		{
			if ( temp == TOKENS[j] )
			{
				tokenized_instructions[i] = temp;
				break;
			}
			else if ( j >= strlen( TOKENS )-1 )
			{
				i--;
			}
		}
		i++;
	}
	tokenized_instructions[i+1] = '\0';
}

int main( int argc, char** argv )
{
	FILE* program_file;

	if ( argc <= 1 )
	{
		fprintf( stderr, "Error: No source file specified!\nUsage: \"braifui source.bf\"\n" );
		return 1;
	}

	if ( (program_file = fopen( argv[1], "r" )) == NULL )
	{
		fprintf( stderr, "Not a valid file!\nPlease only feed me .bf or .b files!\n" );
		return 2;
	}
	
	printf( "-> Loaded file: %s\n", argv[1] );

	char instructions[30000];
	tokenize( program_file, instructions );

	printf( "%s\n", instructions );

	fclose( program_file );

	return 0;
}
