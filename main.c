#include <stdio.h>
#include "editor.h"
#include "menu.h"

int main(int argc, char *argv[]) {
    char namafile[100];
    char *filename;
    char newfilename[20];
    unsigned int function;
    FILE *fp;
    List *content;
    Point *CursorPos;

    restart:
    system("cls");
    if(argc == 1) /* No Command-line arguments */
    {
        printf("Insert File Name : ");
        scanf("%s",namafile);
        printf("%s",namafile);
        filename = namafile;
        content = listCtor();
        fp = fopen(filename, "r");

        CursorPos = pointCtor();
        system("cls");
        readFile(fp, content, CursorPos);
        fclose(fp);
        argc = 0;
    }
    else
    {
        filename = *++argv;
        content = listCtor();
        fp = fopen(filename, "r");

        CursorPos = pointCtor();
        system("cls");
        readFile(fp, content, CursorPos);
        fclose(fp);
    }

    edit:
    displayMenuBar();
    displayLine(CursorPos, content);
    displayContent(CursorPos, content);


    switch(function = editContent(filename, content, CursorPos)){
    case 0:
        if(argc == 1){
            fflush(stdin);
            fp = fopen(filename, "w");
            saveToFile(fp, content);
            fclose(fp);
            printf("Enter file name : ");
            scanf("%[^\n]s",newfilename);
            rename(filename,newfilename);
            putchar('\n');
        }
        else{
            fp = fopen(filename, "w");
            saveToFile(fp, content);
            fclose(fp);
            putchar('\n');
        }
        break;
    case 1:
        system("PAUSE");
        break;
    case 2:
        if(argc == 1){
            fflush(stdin);
            fp = fopen(filename, "w");
            saveToFile(fp, content);
            fclose(fp);
            printf("Enter file name : ");
            scanf("%[^\n]s",newfilename);
            rename(filename,newfilename);
            putchar('\n');
        }
        else{
            fp = fopen(filename, "w");
            saveToFile(fp, content);
            fclose(fp);
            putchar('\n');
        }
        argc = 0;
        system("PAUSE");
        system("cls");
        goto edit;
        break;
    case 3:
        fflush(stdin);
        argc = 1;
        system("PAUSE");
        system("cls");
        goto restart;
        break;
    case 4:
        if(argc == 1){
            fflush(stdin);
            fp = fopen(filename, "w");
            saveToFile(fp, content);
            fclose(fp);
            printf("Enter file name : ");
            scanf("%[^\n]s",newfilename);
            rename(filename,newfilename);
            putchar('\n');
        }
        else{
            fp = fopen(filename, "w");
            saveToFile(fp, content);
            fclose(fp);
            putchar('\n');
        }
        fflush(stdin);
        argc = 1;
        system("PAUSE");
        system("cls");
        goto restart;
        break;
    }


    deleteList(content);
    return 0;
}
