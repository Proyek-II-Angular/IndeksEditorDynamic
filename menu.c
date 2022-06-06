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

void Box_menu_list(){
//  int c = 0, r = 1;
//
//  color(7);
//
//  //sisi kiri
//  for(r = 1; r <= 5; r++){
//    gotoxy(0, 1);
//    printf("%c", 186);
//  }
//
//  //sudut atas kiri
//  gotoxy(0, 0);
//  printf("%c", 201);
//
//  //sisi atas 1
//  for(r = 1; r <= 6; r++){
//    gotoxy(r, 0);
//    printf("%c", 205);
//  }
//
//  //sisi potong 1
//  gotoxy(7, 0);
//  printf("%c", 203);
//
//  //sisi lurus potong 1
//  gotoxy(7, 1);
//  printf("%c", 186);
//
//  //sisi atas 2
//  for(r = 8; r <= 13; r++){
//    gotoxy(r, 0);
//    printf("%c", 205);
//  }
//
//  //sisi potong 2
//  gotoxy(14, 0);
//  printf("%c", 203);
//
//  //sisi lurus potong 1
//  gotoxy(14, 1);
//  printf("%c", 186);
//
//  //sisi atas 3
//  for(r = 15; r <= 19; r++){
//    gotoxy(r, 0);
//    printf("%c", 205);
//  }
//
//  //sudut atas kanan
//  gotoxy(20, 0);
//  printf("%c", 187);
//
//  //sisi kanan
//  gotoxy(20, 1);
//  printf("%c", 186);
//
//  //sisi sudut bawah kanan
//  gotoxy(20, 2);
//  printf("%c", 188);
//
//  //sisi bawah 3
//  for(r = 1; r <= 5; r++){
//    gotoxy(r + 14, 2);
//    printf("%c", 205);
//  }
//
//  //sudut ptong bawah
//  gotoxy(14, 2);
//  printf("%c", 202);
//
//  //sisi bawah 4
//  for(r = 1; r <= 6; r++){
//    gotoxy(r + 7, 2);
//    printf("%c", 205);
//  }
//
//  //sudut ptong bawah 2
//  gotoxy(7, 2);
//  printf("%c", 202);
//
//  //sisi bawah 5
//  for(r = 1; r <= 6; r++){
//    gotoxy(r, 2);
//    printf("%c", 205);
//  }
//
//  //sisi sudut bawah kiri
//  gotoxy(0, 2);
//  printf("%c", 200);

	for(int i = 0; i <= 119; i++){
		gotoxy(i, 0);
		printf(" ");
		color(112);
	}
	gotoxy(120, 0);
	printf("\n");
	color(7);

//	char a = " ";
//	while(a != "\n"){
//		printf("%c\n", &a);
//		color(112);
//		a = "\n";
//	}
//	color(7);
}

int bar(List* content){

//  system("CLS");
//  int Set[] = {112, 7, 7};
  int Set[] = {113, 112, 112};
  int counter = 1;
  char key;

//  	for(int coorX = 0; coorX < 100; coorX++){
//		gotoxy(coorX, 0);
//	    color(112);
//	    printf(" ");
//	}

  for(int i = 0 ;;){
  	Box_menu_list();

    gotoxy(0, 0);
    color(Set[0]);
    printf(" File ");

    gotoxy(8, 0);
    color(Set[1]);
    printf(" Edit ");

    gotoxy(16, 0);
    color(Set[2]);
    printf(" (Back) ");

    color(112);
    gotoxy(50, 0);
    printf(" --Indeks Editor-- ");

    gotoxy(100, 0);
    printf("line %d", (getHeight(content) + 1));

    color(7);

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
//        gotoxy(0, 1);
//        color(7);
		color(113);
        // fileMenu();
        return 1;
      }
      if(counter == 2){
        system("COLOR 0F");
        system("CLS");
//        gotoxy(0, 1);
//        color(7);
		color(113);
        // editMenu();
        return 2;
      }
      if(counter == 3){
        system("COLOR 0F");
        system("CLS");
//        gotoxy(0, 1);
//        color(7);
		  color(113);
        return 3;
//        printf("() Menu is Opened");
		// return;
      }
    }
//    Set[0] = 7;
//    Set[1] = 7;
//    Set[2] = 7;

    Set[0] = 112;
    Set[1] = 112;
    Set[2] = 112;

    if(counter == 1){
//      Set[0] = 112;
		Set[0] = 113;
    }
    if(counter == 2){
//      Set[1] = 112;
		Set[1] = 113;
    }
    if(counter == 3){
//      Set[2] = 112;
		Set[2] = 113;
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

//int Set[] = {112, 7, 7, 7, 7};
int Set[] = {112, 7, 7, 7};
int counter = 1;
char key;

for(int i = 0 ;;){
//    gotoxy(3, 2);
//    color(Set[0]);
//    printf("New File");

    gotoxy(3, 2);
    color(Set[0]);
    printf("Open File");

    gotoxy(3, 3);
    color(Set[1]);
    printf("Save File");

    gotoxy(3, 4);
    color(Set[2]);
    printf("Cancel");

    gotoxy(3, 5);
    color(Set[3]);
    printf("Exit");

    key = _getch();

    if(key == 72 && (counter >= 2 && counter <= 4)){//75 = left arrow key
      counter--;
    }
    if(key == 80 && (counter >= 1 && counter <= 3)){//77 = right arrow key
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
//    Set[4] = 7;

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
//    if(counter == 5){
//      Set[4] = 112;
//    }
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
	Box_menu_list();
	color(112);
    gotoxy(0, 0);
    printf(" File ");
    gotoxy(8, 0);
    printf(" Edit ");
    gotoxy(16, 0);
    printf(" (Back) ");

    gotoxy(50, 0);
    printf(" --Indeks Editor-- ");

    printf("\n");
//    printf("\n");
    color(7);
}

void displayLine(Point *CursorPos, List* content){
    color(112);
    gotoxy(100, 0);
    printf("line %d/%d", (CursorPos->y + 1), (getHeight(content) + 1));
    printf("\n");
//    printf("\n");
    color(7);
}

int ToggleMenuAccess(char filename, List *content, Point *CursorPos){
//	system("CLS");
//	menu_list();
    displayMenuBar(CursorPos, content);
    displayContent(CursorPos, content);
//    gotoxy(0, 1);
//  char key = _getch();
//  if(key == 27){
    int keyAccess = bar(content);

    if(keyAccess == 1){
      color(7);
      createBoxMenuFile();
      int keyFile = fileMenu(content);
      switch(keyFile){
//      	case 1:
//      		gotoxy(0, 10);
//      		printf("New File");
//      		return 1;
//      		break;
      	case 1:
      		gotoxy(0, 10);
      		printf("\nOpening File...\n");
      		return 1;
      		break;
      	case 2:
      		gotoxy(0, 10);
      		printf("\nSaving File...\n");
//      		FILE *saveFile = fopen(filename, "w");
//      		saveToFile(saveFile, content);
			return 2;
      		break;
      	case 3:
//      		gotoxy(0, 10);
//      		printf("Cancel");
      		return 3;
      		break;
      	case 4:
      		gotoxy(0, 10);
      		//printf("Exit");
      		return 4;
      		break;
      	default : break;
	  }
    }else if(keyAccess == 2){
      color(7);
      createBoxMenuEdit();
      int keyEdit = editMenu(content);
      switch(keyEdit){
      	case 1:
      		gotoxy(0, 10);
      		printf("Undo");
      		return 5;
      		break;
      	case 2:
      		gotoxy(0, 10);
      		printf("Redo");
      		return 6;
      		break;
		case 3:
//			gotoxy(0, 10);
//			printf("Cancel");
			return 7;
			break;
		default : break;

	  }
    }else if(keyAccess == 3){
    	color(7);
//      editContent(content, CursorPos);
		return 8;
    }
//    else if(keyAccess == 27){
//    	return 9;
//	}
//  }
}
