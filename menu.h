#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//properties
int bar(List* content);
//void fileMenu();
int fileMenu(List* content);
int getHeight(List* content);
void createBoxMenuFile();
//void editMenu();
int editMenu(List* content);
void createBoxMenuEdit();
void gotoxy(int x, int y);
void color(int color);

int ToggleMenuAccess(char filename, List *content, Point *CursorPos);
void displayMenuBar();
void displayLine(List* content);
//

#endif // MENU_H_INCLUDED
