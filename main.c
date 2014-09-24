#include <stdio.h>

int main( int argc, char** argv )
{
	FILE* program_file;

	if ( argc <= 1 )
	{
		fprintf( stderr, "Error: No source file specified!\nUsage: \"braifui source.bf\"\n" );
		return 1;
	}

	if ( (program_file = fopen( argv[1], "rb" )) == NULL )
	{
		fprintf( stderr, "Not a valid file!\nPlease only feed me .bf or .b files!\n" );
		return 2;
	}
	
	printf( "-> Loaded file: %s\n", argv[1] );

	char instructions[30000] = {0};

	int i;
	char temp;
	for ( i = 0, temp = fgetc( program_file ); temp != EOF; i++, temp = fgetc( program_file )  )
	{
		instructions[i] = temp;
		printf( "Temp: %c\nInstructions[%d]: %c\n", temp, i, instructions[i] );
	}

	printf( "%s", instructions );

	fclose( program_file );

	return 0;
}
