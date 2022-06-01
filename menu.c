#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "editor.h"
#include "menu.h"

void color(int color){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y){
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void menu_list(List* content){
	color(7);
	gotoxy(0, 0);
    printf("File");

    gotoxy(5, 0);
    printf("Edit");

    gotoxy(10, 0);
    printf("()");

    color(112);
    gotoxy(70, 0);
    printf("line %d",getHeight(content));
}



int bar(List* content){
//  system("CLS");
  int Set[] = {112, 7, 7, 112};
  int counter = 1;
  char key;

  for(int i = 0 ;;){
    gotoxy(0, 0);
    color(Set[0]);
    printf("File");

    gotoxy(5, 0);
    color(Set[1]);
    printf("Edit");

    gotoxy(10, 0);
    color(Set[2]);
    printf("()");

    gotoxy(70, 0);
    color(Set[3]);
    printf("line %d",getHeight(content));

    key = _getch();

    if(key == 75 && (counter >= 2 && counter <= 3)){//75 = left arrow key
      counter--;
    }
    if(key == 77 && (counter >= 1 && counter <= 2)){//77 = right arrow key
      counter++;
    }
    if(key == '\r'){
      if(counter == 1){
        system("COLOR 0F");
        system("CLS");
        gotoxy(0, 1);
        // fileMenu();
        return 1;
      }
      if(counter == 2){
        system("COLOR 0F");
        system("CLS");
        gotoxy(0, 1);
        // editMenu();
        return 2;
      }
      if(counter == 3){
        system("COLOR 0F");
        system("CLS");
        gotoxy(0, 1);
        color(7);
        return 3;
//        printf("() Menu is Opened");
		// return;
      }
    }
    Set[0] = 7;
    Set[1] = 7;
    Set[2] = 7;

    if(counter == 1){
      Set[0] = 112;
    }
    if(counter == 2){
      Set[1] = 112;
    }
    if(counter == 3){
      Set[2] = 112;
    }
  }
  if(key == 27){
        system("CLS");
        // break;
    }
}

void createBoxMenuFile(){
  int c = 0, r = 1;

  //sisi kiri
  for(r = 1; r <= 7; r++){
    gotoxy(c, r);
    printf("%c", 186);
  }

  //sudut atas kiri
  gotoxy(0, 1);
  printf("%c", 201);

  //sisi atas
  for(r = 1; r <= 14; r++){
    gotoxy(r, 1);
    printf("%c", 205);
  }

  //sudut atas kanan
  gotoxy(15, 1);
  printf("%c", 187);

  //sisi kanan
  for(r = 1; r <= 6; r++){
    gotoxy(15, r + 1);
    printf("%c", 186);
  }

  //sisi sudut bawah kanan
  gotoxy(15, 7);
  printf("%c", 188);

  //sisi bawah
  for(r = 1; r <= 14; r++){
    gotoxy(r, 7);
    printf("%c", 205);
  }

  //sisi sudut bawah kiri
  gotoxy(0, 7);
  printf("%c", 200);
}


int fileMenu(List* content){
  createBoxMenuFile();

int Set[] = {112, 7, 7, 7, 7};
int counter = 1;
char key;

for(int i = 0 ;;){
    gotoxy(3, 2);
    color(Set[0]);
    printf("New File");

    gotoxy(3, 3);
    color(Set[1]);
    printf("Open File");

    gotoxy(3, 4);
    color(Set[2]);
    printf("Save File");

    gotoxy(3, 5);
    color(Set[3]);
    printf("Cancel");

    gotoxy(3, 6);
    color(Set[4]);
    printf("Exit");

    key = _getch();

    if(key == 72 && (counter >= 2 && counter <= 5)){//75 = left arrow key
      counter--;
    }
    if(key == 80 && (counter >= 1 && counter <= 4)){//77 = right arrow key
      counter++;
    }
    if(key == 27){
      system("CLS");
      bar(content);
    }
    if(key == '\r'){
      switch (counter) {
        case 1:
          system("COLOR 0F");
          system("CLS");
//          createBoxMenuFile();
//          gotoxy(0, 10);
          return 1;
          break;
        case 2:
          system("COLOR 0F");
          system("CLS");
//          createBoxMenuFile();
//          gotoxy(0, 10);
//          printf("Open File Menu");
		  return 2;
          break;
        case 3:
          system("COLOR 0F");
          system("CLS");
//          createBoxMenuFile();
//          gotoxy(0, 10);
          return 3;
//          printf("Save File Menu");
          break;
        case 4:
          system("COLOR 0F");
          system("CLS");
          color(7);
          return 4;
//          bar();
          break;
        case 5:
          system("COLOR 0F");
          system("CLS");
//          createBoxMenuFile();
//          gotoxy(0, 10);
          return 5;
//          printf("Exit");
          break;
      }
    }
    Set[0] = 7;
    Set[1] = 7;
    Set[2] = 7;
    Set[3] = 7;
    Set[4] = 7;

    if(counter == 1){
      Set[0] = 112;
    }
    if(counter == 2){
      Set[1] = 112;
    }
    if(counter == 3){
      Set[2] = 112;
    }
    if(counter == 4){
      Set[3] = 112;
    }
    if(counter == 5){
      Set[4] = 112;
    }
  }
}

void createBoxMenuEdit(){
  int c = 0, r = 1;

  //sisi kiri
  for(r = 1; r <= 5; r++){
    gotoxy(c + 5, r);
    printf("%c", 186);
  }

  //sudut atas kiri
  gotoxy(0 + 5, 1);
  printf("%c", 201);

  //sisi atas
  for(r = 1; r <= 14; r++){
    gotoxy(r + 5, 1);
    printf("%c", 205);
  }

  //sudut atas kanan
  gotoxy(15 + 5, 1);
  printf("%c", 187);

  //sisi kanan
  for(r = 1; r <= 5; r++){
    gotoxy(15 + 5, r + 1);
    printf("%c", 186);
  }

  //sisi sudut bawah kanan
  gotoxy(15 + 5, 6);
  printf("%c", 188);

  //sisi bawah
  for(r = 1; r <= 14; r++){
    gotoxy(r + 5, 6);
    printf("%c", 205);
  }

  //sisi sudut bawah kiri
  gotoxy(0 + 5, 6);
  printf("%c", 200);
}

int editMenu(List* content){
  createBoxMenuEdit();

  int Set[] = {112, 7, 7};
  int counter = 1;
  char key;

  for(int i = 0 ;;){
    gotoxy(8, 2);
    color(Set[0]);
    printf("Undo");

    gotoxy(8, 3);
    color(Set[1]);
    printf("Redo");

    gotoxy(8, 4);
    color(Set[2]);
    printf("Cancel");

    key = _getch();

    if(key == 72 && (counter >= 2 && counter <= 3)){//75 = left arrow key
      counter--;
    }
    if(key == 80 && (counter >= 1 && counter <= 2)){//77 = right arrow key
      counter++;
    }
    if(key == 27){
      system("CLS");
      bar(content);
    }
    if(key == '\r'){
      if(counter == 1){
        system("COLOR 0F");
        system("CLS");
//        createBoxMenuEdit();
//        gotoxy(0, 10);
        return 1;
//        printf("Edit Menu 1");
      }
      if(counter == 2){
        system("COLOR 0F");
        system("CLS");
//        createBoxMenuEdit();
//        gotoxy(0, 10);
        return 2;
//       printf("Edit Menu 2");
      }
      if(counter == 3){
        system("COLOR 0F");
        system("CLS");
        color(7);
        return 3;
//        bar();
      }
    }
    Set[0] = 7;
    Set[1] = 7;
    Set[2] = 7;

    if(counter == 1){
      Set[0] = 112;
    }
    if(counter == 2){
      Set[1] = 112;
    }
    if(counter == 3){
      Set[2] = 112;
    }
  }
}

void displayMenuBar(){
    gotoxy(0, 0);
    printf("File");
    gotoxy(5, 0);
    printf("Edit");
    gotoxy(10, 0);
    printf("()");
}

void displayLine(List* content){
    gotoxy(70, 0);
    printf("line %d",getHeight(content));
}

int ToggleMenuAccess(char filename, List *content, Point *CursorPos){
//	system("CLS");
	menu_list(content);
	displayLine(content);
    displayMenuBar();

    gotoxy(0, 1);
//  char key = _getch();

//  if(key == 27){
    int keyAccess = bar(content);

    if(keyAccess == 1){
      createBoxMenuFile();
      int keyFile = fileMenu(content);
      switch(keyFile){
      	case 1:
      		gotoxy(0, 10);
      		printf("New File");
      		return 1;
      		break;
      	case 2:
      		gotoxy(0, 10);
      		printf("Open File");
      		return 2;
      		break;
      	case 3:
      		gotoxy(0, 10);
      		printf("Save File");
//      		FILE *saveFile = fopen(filename, "w");
//      		saveToFile(saveFile, content);
			return 3;
      		break;
      	case 4:
      		gotoxy(0, 10);
      		printf("Cancel");
      		return 4;
      		break;
      	case 5:
      		gotoxy(0, 10);
      		printf("Exit");
      		return 5;
      		break;
      	default : break;
	  }
    }else if(keyAccess == 2){
      createBoxMenuEdit();
      int keyEdit = editMenu(content);
      switch(keyEdit){
      	case 1:
      		gotoxy(0, 10);
      		printf("Undo");
      		return 6;
      		break;
      	case 2:
      		gotoxy(0, 10);
      		printf("Redo");
      		return 7;
      		break;
		case 3:
			gotoxy(0, 10);
			printf("Cancel");
			return 8;
			break;
		default : break;

	  }
    }else if(keyAccess == 3){
//      editContent(content, CursorPos);
		return 9;
    }
//  }
}
