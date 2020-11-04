/**********************[ Sorting words ]*********
*
*	Serge Bash 2013
*
*******************************************
*
*	Algorithm sorting the words
*
*******************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


// swap words
void swap( char *w[], int x, int y )
{
    char *t;
    t = w[x];
    w[x ]= w[y];
    w[y] = t;
}


// compare chars in the two words
// if chars equal then compare next chars
// else swap words
void ch_cmp( char *words[], int cur_word, int next_word, int ch )
{
    if ( ch > strlen(words[cur_word]) )
        return;

    if ( words[cur_word][ch] > words[next_word][ch] )
    {
        swap(words, cur_word, next_word);
        return;
    }

    if ( words[cur_word][ch] == words[next_word][ch] )
    {
        ch_cmp( words, cur_word, next_word, ch+1 );
    }

    return;
}


// sorting words
void sort_words( char *words[],  int *size )
{
    int ch = 0;
    int cur_word;
    int next_word;

    for (cur_word = 0; cur_word < *size-1; cur_word++)
    {
        for (next_word = cur_word+1; next_word < *size; next_word++)
        {
            if ( words[cur_word][ch] > words[next_word][ch] )
            {
                swap(words, cur_word, next_word);
            }

            if ( words[cur_word][ch] == words[next_word][ch] )
            {
                ch_cmp( words, cur_word, next_word, ch+1 );
            }
        }
    }

    return;
}


int main(char *args[], int count)
{
    int k;
    char _words[1000][256];
    int count_lines = 0;
    char *words[1000];
    int i = 0;
    FILE *fp = fopen( "d:/words2.txt", "r+");

    if (!fp)
        printf("ERROR: file not open!\n");
    system("chcp 1251");

    fseek( fp, 0, SEEK_END );
    ftell( fp );
    fseek( fp, 0, SEEK_SET );

    while (fgets( _words[count_lines], 256, fp ) ) count_lines++;

    printf("\n[ NOT SORTED WORDS: ]\n");

    for ( k=0; k<count_lines; k++)
    {
        if (_words[k][strlen(_words[k])-1] == '\n')
        {
            _words[k][strlen(_words[k])-1] = 0;
        }
        words[k] = _words[k];

        printf("%s\n", words[k]);
    }

    sort_words( words,  &count_lines );

    fseek( fp, 0, SEEK_SET);

    while ( i < count_lines )
    {
        fputs( words[i], fp );
        fputc('\n', fp);
        i++;
    }

    fclose( fp );

    printf("\n[ SORTED WORDS: ]\n");

    for ( k=0; k<count_lines; k++)
        printf("%s\n", words[k]);

    return 0;
}
