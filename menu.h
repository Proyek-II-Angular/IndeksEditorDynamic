#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//properties
//int bar();
int bar(List* content);
//void fileMenu();
//int fileMenu();
int fileMenu(List* content);
void createBoxMenuFile();
//void editMenu();
int editMenu(List* content);
void createBoxMenuEdit();
void gotoxy(int x, int y);
void color(int color);

int ToggleMenuAccess(char filename, List *content, Point *CursorPos);
void displayMenuBar();

void Box_menu_list();

void displayLine(Point *CursorPos, List* content);
//

#endif // MENU_H_INCLUDED
