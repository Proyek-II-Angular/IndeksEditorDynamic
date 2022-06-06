#include <stdio.h>
#include <conio.h>
#include <editor.c>

void help()
{
    FILE *filePointer;
    
    char dataToBeRead[50];

    filePointer = fopen("helpfitur.txt", "r");
    
    if (filePointer == NULL) {
        printf( " file failed to open." );
    } else {
        printf("PERHATIAN!.\n");
        
        while(fgets(dataToBeRead, 50, filePointer) != NULL)
        {
            printf( "%s" , dataToBeRead);
        }
         
        fclose(filePointer) ;
    }      
    getch();
    Welcome();
}

void about ()
{
	FILE *filePointer;
    
    char dataToBeRead[50];

    filePointer = fopen("about.txt", "r");
    
    if (filePointer == NULL) {
        printf( "Can't open This file'." );
    } else {
        printf("The file now opened.\n");
        
        while(fgets(dataToBeRead, 50, filePointer) != NULL)
        {
            printf( "%s" , dataToBeRead);
        }
         
        fclose(filePointer) ;
    }      
    getch();
    Welcome();
}

