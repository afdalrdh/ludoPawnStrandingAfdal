#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<MMsystem.h>

struct Bidak {
	char ID[5];
	char ID_Pemilik[5];
	int Lokasi;
	char Status[10];
};

struct User {
	char ID[7];
	char Nama[50];
	char Warna[10];
	unsigned int Score;
	struct Bidak BidakUser[4];
};

struct Com {
	char ID[7];
	char Nama[50];
	char Warna[10];
	char Personality[10];
	struct Bidak BidakCom[4];
};

char sa[10], sb[10], sc[10], sd[10];
int a=10, b=0, c=0, d=0;
int ua=0, ub = 20, uc= 3, ud = 7;
int finish = 73;
void gotoxy(int x, int y);
void setcolor(unsigned short color);
void mainMenu();
void inputUserData();
void generateUserData(char a[50], char b, struct User *c);
void generateComData(struct Com a, struct Com b, struct Com c, struct User e, int d);
void resetComData(struct Com *Com1, struct Com *Com2, struct Com *Com3);
void generateCom1(struct Com *Com1, struct User pemain);
void generateCom2(struct Com *Com2, struct Com Com1, struct User pemain);
void generateCom3(struct Com *Com3, struct Com Com2, struct User pemain);
void printData(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3);
void data(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3, int urutan);
void showCom1Data(struct Com Com2);
void showCom3Data(struct Com Com2);
void userChoice(struct User *pemain, struct Com *Com1, struct Com *Com2, struct Com *Com3, int langkah, int urutan);
void userMovePawn(struct User *pemain, int langkah);
void userOutPawn(struct User *pemain, int langkah);
void maju(struct User *pemain, struct Com *Com1, struct Com *Com2, struct Com *Com3, int langkah, int urutan);
void cekPosisi(int a, char *b);
int max4Value(int value1, int value2, int value3, int value4);
void gameOver(struct User pemain, struct Com Com1, int winner);


//        _    _     _                                              _     _       
//       | |  | |   (_)                                            | |   | |      
//   __ _| | _| |__  _ _ __   _ __  _   _ _ __  _   _  __ _    __ _| | __| |_   _ 
//  / _` | |/ / '_ \| | '__| | '_ \| | | | '_ \| | | |/ _` |  / _` | |/ _` | | | |
// | (_| |   <| | | | | |    | |_) | |_| | | | | |_| | (_| | | (_| | | (_| | |_| |
//  \__,_|_|\_\_| |_|_|_|    | .__/ \__,_|_| |_|\__, |\__,_|  \__,_|_|\__,_|\__, |
//                           | |                 __/ |                       __/ |
//                           |_|                |___/                       |___/ 




void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(unsigned short color)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hCon,color);

}

void StartMenu();
void MainMenu();
void StartGame();
void ModeSelect(int select, int jmlCom, char pilihWarna, char Nama[]);
void ContinueGame();
void HighScore();
void Credit();
void Exit();
void InputUserData();
void Papan();
void random();
void save(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3, int urutan);


char pilih, id, nama[50], warna[10], score[100];

char teks1[100] ="   _  _      .____              .___       ____  ___ __                                          ";
char teks2[100] ="__| || |__   |    |    __ __  __| _/____   \\   \\/  //  |________   ____   _____   ____           ";
char teks3[100] ="\\   __   /   |    |   |  |  \\/ __ |/  _ \\   \\     /\\   __\\_  __ \\_/ __ \\ /     \\_/ __ \\          ";
char teks4[100] =" |  ||  |    |    |___|  |  / /_/ (  <_> )  /     \\ |  |  |  | \\/\\  ___/|  Y Y  \\  ___/          ";
char teks5[100] ="/_  ~~  _\\   |_______ \\____/\\____ |\\____/  /___/\\  \\|__|  |__|    \\___  >__|_|  /\\___  >         ";
char teks6[100] ="  |_||_|             \\/          \\/              \\_/                  \\/      \\/     \\/          ";
char teks7[100] ="__________                         _________ __                            .___.__                ";
char teks8[100] ="\\______   \\_____ __  _  ______    /   _____//  |_____________    ____    __| _/|__| ____    ____  ";
char teks9[100] =" |     ___/\\__  \\\\ \\/ \\/ /    \\   \\_____  \\\\   __\\_  __ \\__  \\  /    \\  / __ | |  |/    \\  / ___\\ ";
char teks10[100]=" |    |     / __ \\\\     /   |  \\  /        \\|  |  |  | \\// __ \\|   |  \\/ /_/ | |  |   |  \\/ /_/  >";
char teks11[100]=" |____|    (____  /\\/\\_/|___|  / /_______  /|__|  |__|  (____  /___|  /\\____ | |__|___|  /\\___  / ";
char teks12[100]="                \\/           \\/          \\/                  \\/     \\/      \\/         \\//_____/  ";

void Logo(){
	setcolor(15);
	gotoxy(5,3);printf("%s", teks1);
	gotoxy(5,4);printf("%s", teks2);
	gotoxy(5,5);printf("%s", teks3);
	gotoxy(5,6);printf("%s", teks4);
	gotoxy(5,7);printf("%s", teks5);
	gotoxy(5,8);printf("%s", teks6);
	setcolor(12);
	gotoxy(5,9);printf("%s", teks7);
	gotoxy(5,10);printf("%s", teks8);
	gotoxy(5,11);printf("%s", teks9);
	gotoxy(5,12);printf("%s", teks10);
	gotoxy(5,13);printf("%s", teks11);
	gotoxy(5,14);printf("%s", teks12);
	setcolor(199);
	gotoxy(99,3);printf("      ");
	setcolor(240);
	gotoxy(99,4);printf("      ");
	setcolor(15);
}

struct user{
	char ID[10];
	char Nama[50];
	char Warna[10];
	int Score[100];
}user;


int main(){
	PlaySound(TEXT("C:\\Users\\afdalrdh\\Desktop\\BAHAN LUDO SEMUA DISINI\\ludoPawnStranding\\portals.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
	system ("MODE 110,30");
	StartMenu();
	MainMenu(1);
	inputUserData();
	
	return 0;
	
}

void StartMenu(){	//Menampilkan animasi Menu Awal
	int i,j,jml;
	
	for(i=0;i<90;i++){
		gotoxy(5+i,3);printf("%c",teks1[i]);
		gotoxy(5+i,4);printf("%c",teks2[i]);
		gotoxy(5+i,5);printf("%c",teks3[i]);
		gotoxy(5+i,6);printf("%c",teks4[i]);
		gotoxy(5+i,7);printf("%c",teks5[i]);
		gotoxy(5+i,8);printf("%c",teks6[i]);
		
		for(j=0;j<9000000;j++){
		}
	}
	for(i=0;i<6;i++){
		setcolor(199);
		gotoxy(99+i,3);printf(" ");
		setcolor(240);
		gotoxy(99+i,4);printf(" ");
		setcolor(15);
		
		for(j=0;j<20000000;j++){
		}
	}
	sleep(1);
	for(i=0;i<110;i++){
		setcolor(12);
		gotoxy(104-i,9);printf("%c",teks7[99-i]);
		gotoxy(104-i,10);printf("%c",teks8[99-i]);
		gotoxy(104-i,11);printf("%c",teks9[99-i]);
		gotoxy(104-i,12);printf("%c",teks10[99-i]);
		gotoxy(104-i,13);printf("%c",teks11[99-i]);
		gotoxy(104-i,14);printf("%c",teks12[99-i]);
		for(j=0;j<90000;j++){
		}
	}
}

void MainMenu(int select){	//Menampilkan pilihan Menu Awal
	
	int a;
	system("cls");
	switch(select)
	{
		case 1:
			Logo();
			setcolor(112);
			gotoxy(32,19);printf("              1. M U L A I                 ");
			setcolor(15);
			gotoxy(32,20);printf("              2. L A N J U T               ");
			gotoxy(32,21);printf("              3. H I G H S C O R E         ");
			gotoxy(32,22);printf("              4. K R E D I T               ");
			gotoxy(32,23);printf("              5. K E L U A R               ");
			break;
		case 2:
			Logo();
			gotoxy(32,19);printf("              1. M U L A I                 ");
			setcolor(112);
			gotoxy(32,20);printf("              2. L A N J U T               ");
			setcolor(15);
			gotoxy(32,21);printf("              3. H I G H S C O R E         ");
			gotoxy(32,22);printf("              4. K R E D I T               ");
			gotoxy(32,23);printf("              5. K E L U A R               ");
			break;
		case 3:
			Logo();
			gotoxy(32,19);printf("              1. M U L A I                 ");
			gotoxy(32,20);printf("              2. L A N J U T               ");
			setcolor(112);
			gotoxy(32,21);printf("              3. H I G H S C O R E         ");
			setcolor(15);
			gotoxy(32,22);printf("              4. K R E D I T               ");
			gotoxy(32,23);printf("              5. K E L U A R               ");
			break;
		case 4:
			Logo();
			gotoxy(32,19);printf("              1. M U L A I                 ");
			gotoxy(32,20);printf("              2. L A N J U T               ");
			gotoxy(32,21);printf("              3. H I G H S C O R E         ");
			setcolor(112);
			gotoxy(32,22);printf("              4. K R E D I T               ");
			setcolor(15);
			gotoxy(32,23);printf("              5. K E L U A R               ");
			break;
		case 5:
			Logo();
			gotoxy(32,19);printf("              1. M U L A I                 ");
			gotoxy(32,20);printf("              2. L A N J U T               ");
			gotoxy(32,21);printf("              3. H I G H S C O R E         ");
			gotoxy(32,22);printf("              4. K R E D I T               ");
			setcolor(112);
			gotoxy(32,23);printf("              5. K E L U A R               ");
			setcolor(15);
			break;
	}
	a=getche();
	if(a==224){
		do{
			a=getche();
		}while(a==224);
		switch(a){
			case 72:	//atas
				if(select==1){
					MainMenu(1);
				}
				else{
					MainMenu(select-1);
				}
			break;
			case 80:	//bawah
				if(select==5){
					MainMenu(5);
				}
				else{
					MainMenu(select+1);
				}
			break;
			default:
				MainMenu(select);
			break;
		}
	}
	else if(a==13){
		switch(select){
			case 1:
				inputUserData();
				break;
			case 2:
				ContinueGame();
				break;
			case 3:
				HighScore();
				break;
			case 4:
				Credit();
				break;
			case 5:
				Exit();
				break;
		}
	}
	else{
		MainMenu(select);
	}
}

void StartGame(){
	
}


char a1[120] ="ษออออออออออออออออออออออออออออป";
char a2[120] ="บ                            บ";
char a3[120] ="บ                            บ";
char a4[120] ="บ                            บ";
char a5[120] ="บ                            บ";
char a6[120] ="บ                            บ";
char a7[120] ="บ                            บ";
char a8[120] ="บ           1 VS 1           บ";
char a9[120] ="บ                            บ";
char a10[120]="บ                            บ";
char a11[120]="บ                            บ";
char a12[120]="บ                            บ";
char a13[120]="บ                            บ";
char a14[120]="บ                            บ";
char a15[120]="ศออออออออออออออออออออออออออออผ";

char b1[120] ="ษออออออออออออออออออออออออออออป";
char b2[120] ="บ                            บ";
char b3[120] ="บ                            บ";
char b4[120] ="บ                            บ";
char b5[120] ="บ                            บ";
char b6[120] ="บ                            บ";
char b7[120] ="บ                            บ";
char b8[120] ="บ           1 VS 2           บ";
char b9[120] ="บ                            บ";
char b10[120]="บ                            บ";
char b11[120]="บ                            บ";
char b12[120]="บ                            บ";
char b13[120]="บ                            บ";
char b14[120]="บ                            บ";
char b15[120]="ศออออออออออออออออออออออออออออผ";

char c1[120] ="ษออออออออออออออออออออออออออออป";
char c2[120] ="บ                            บ";
char c3[120] ="บ                            บ";
char c4[120] ="บ                            บ";
char c5[120] ="บ                            บ";
char c6[120] ="บ                            บ";
char c7[120] ="บ                            บ";
char c8[120] ="บ           1 VS 3           บ";
char c9[120] ="บ                            บ";
char c10[120]="บ                            บ";
char c11[120]="บ                            บ";
char c12[120]="บ                            บ";
char c13[120]="บ                            บ";
char c14[120]="บ                            บ";
char c15[120]="ศออออออออออออออออออออออออออออผ";

char d1[120] =" __                          __   __   ___";
char d2[120] ="|__) | |    | |__|     |\\/| /  \\ |  \\ |__  ";
char d3[120] ="|    | |___ | |  |     |  | \\__/ |__/ |___ ";


void Mode(int select){
	switch(select){
		case 1:
			gotoxy(10,10);printf("%s", a1);
			gotoxy(10,11);printf("%s", a2);
			gotoxy(10,12);printf("%s", a3);
			gotoxy(10,13);printf("%s", a4);
			gotoxy(10,14);printf("%s", a5);
			gotoxy(10,15);printf("%s", a6);
			gotoxy(10,16);printf("%s", a7);
			gotoxy(10,17);printf("%s", a8);
			gotoxy(10,18);printf("%s", a9);
			gotoxy(10,19);printf("%s", a10);
			gotoxy(10,20);printf("%s", a11);
			gotoxy(10,21);printf("%s", a12);
			gotoxy(10,22);printf("%s", a13);
			gotoxy(10,23);printf("%s", a14);
			gotoxy(10,24);printf("%s", a15);
			break;
		case 2:
			gotoxy(40,10);printf("%s", b1);
			gotoxy(40,11);printf("%s", b2);
			gotoxy(40,12);printf("%s", b3);
			gotoxy(40,13);printf("%s", b4);
			gotoxy(40,14);printf("%s", b5);
			gotoxy(40,15);printf("%s", b6);
			gotoxy(40,16);printf("%s", b7);
			gotoxy(40,17);printf("%s", b8);
			gotoxy(40,18);printf("%s", b9);
			gotoxy(40,19);printf("%s", b10);
			gotoxy(40,20);printf("%s", b11);
			gotoxy(40,21);printf("%s", b12);
			gotoxy(40,22);printf("%s", b13);
			gotoxy(40,23);printf("%s", b14);
			gotoxy(40,24);printf("%s", b15);
			break;
		case 3:
			gotoxy(70,10);printf("%s", c1);
			gotoxy(70,11);printf("%s", c2);
			gotoxy(70,12);printf("%s", c3);
			gotoxy(70,13);printf("%s", c4);
			gotoxy(70,14);printf("%s", c5);
			gotoxy(70,15);printf("%s", c6);
			gotoxy(70,16);printf("%s", c7);
			gotoxy(70,17);printf("%s", c8);
			gotoxy(70,18);printf("%s", c9);
			gotoxy(70,19);printf("%s", c10);
			gotoxy(70,20);printf("%s", c11);
			gotoxy(70,21);printf("%s", c12);
			gotoxy(70,22);printf("%s", c13);
			gotoxy(70,23);printf("%s", c14);
			gotoxy(70,24);printf("%s", c15);
			break;
		case 4:
			gotoxy(34,3);printf("%s", d1);
			gotoxy(34,4);printf("%s", d2);
			gotoxy(34,5);printf("%s", d3);
			break;
	}
	
}

void ModeSelect(int select, int jmlCom, char pilihWarna, char Nama[]){
	
	struct User pemain;
	struct Com Com1, Com2, Com3;
	int urutan=1, a;
	
	strcpy(pemain.BidakUser[0].ID, "BU01");
	strcpy(pemain.BidakUser[0].ID_Pemilik, "USR18");
	strcpy(pemain.BidakUser[0].Status, "HOME");
	pemain.BidakUser[0].Lokasi = 0;
	strcpy(pemain.BidakUser[1].ID, "BU02");
	strcpy(pemain.BidakUser[1].ID_Pemilik, "USR18");
	strcpy(pemain.BidakUser[1].Status, "HOME");
	pemain.BidakUser[1].Lokasi = 0;
	strcpy(pemain.BidakUser[2].ID, "BU03");
	strcpy(pemain.BidakUser[2].ID_Pemilik, "USR18");
	strcpy(pemain.BidakUser[2].Status, "HOME");
	pemain.BidakUser[2].Lokasi = 0;
	strcpy(pemain.BidakUser[3].ID, "BU04");
	strcpy(pemain.BidakUser[3].ID_Pemilik, "USR18");
	strcpy(pemain.BidakUser[3].Status, "HOME");
	pemain.BidakUser[3].Lokasi = 0;
	
	system("cls");
	switch(select){
		case 1:
			setcolor(112);
			Mode(1);
			setcolor(15);
			Mode(2);
			Mode(3);
			Mode(4);
		break;
		case 2:
			Mode(1);
			setcolor(112);
			Mode(2);
			setcolor(15);
			Mode(3);
			Mode(4);
		break;
		case 3:
			Mode(1);
			Mode(2);
			setcolor(112);
			Mode(3);
			setcolor(15);
			Mode(4);
		break;
		case 4:
			Mode(1);
			Mode(2);
			Mode(3);
			setcolor(112);
			Mode(4);
			setcolor(15);
		break;
	}
	a=getche();
	if(a==224){
		do{
			a=getche();
		}while(a==224);
		switch(a){
			case 75:	//kiri
				if(select==1){
					ModeSelect(1, jmlCom, pilihWarna, Nama);
				}
				else{
					PlaySound(TEXT("C:\\Users\\afdalrdh\\Desktop\\BAHAN LUDO SEMUA DISINI\\ludoPawnStranding\\blip.wav"), NULL, SND_SYNC);
					ModeSelect(select-1, jmlCom, pilihWarna, Nama);
				}
			break;
			case 77:	//kanan
				if(select==3){
					ModeSelect(3, jmlCom, pilihWarna, Nama);
				}
				else{
					PlaySound(TEXT("C:\\Users\\afdalrdh\\Desktop\\BAHAN LUDO SEMUA DISINI\\ludoPawnStranding\\blip.wav"), NULL, SND_SYNC);
					ModeSelect(select+1, jmlCom, pilihWarna, Nama);
				}
			break;
			default:
				ModeSelect(select, jmlCom, pilihWarna, Nama);
			break;
		}
	}
	else if(a==13){
				
				strcpy(Com1.ID, "COM1");
				strcpy(Com1.Nama, "Bidjie");
				strcpy(Com1.Personality, "GGPRO");
				strcpy(Com1.Warna, "Kuning");
				
				strcpy(Com2.ID, "COM2");
				strcpy(Com2.Nama, "Jek");
				strcpy(Com2.Personality, "Lumayan");
				strcpy(Com2.Warna, "Hijau");
				
				strcpy(Com3.ID, "COM3");
				strcpy(Com3.Nama, "Kvda");
				strcpy(Com3.Personality, "NOOBZ");
				strcpy(Com3.Warna, "Biru");
				
				strcpy(Com1.BidakCom[0].ID, "C101");
				strcpy(Com1.BidakCom[0].ID_Pemilik, "COM01");
				strcpy(Com1.BidakCom[0].Status, "HOME");
				Com1.BidakCom[0].Lokasi = 0;
				strcpy(Com1.BidakCom[1].ID, "C102");
				strcpy(Com1.BidakCom[1].ID_Pemilik, "COM01");
				strcpy(Com1.BidakCom[1].Status, "HOME");
				Com1.BidakCom[1].Lokasi = 0;
				strcpy(Com1.BidakCom[2].ID, "C103");
				strcpy(Com1.BidakCom[2].ID_Pemilik, "COM01");
				strcpy(Com1.BidakCom[2].Status, "HOME");
				Com1.BidakCom[2].Lokasi = 0;
				strcpy(Com1.BidakCom[3].ID, "C104");
				strcpy(Com1.BidakCom[3].ID_Pemilik, "COM01");
				strcpy(Com1.BidakCom[3].Status, "HOME");
				Com1.BidakCom[3].Lokasi = 0;
				
				strcpy(Com2.BidakCom[0].ID, "C201");
				strcpy(Com2.BidakCom[0].ID_Pemilik, "COM02");
				strcpy(Com2.BidakCom[0].Status, "HOME");
				Com2.BidakCom[0].Lokasi = 0;
				strcpy(Com2.BidakCom[1].ID, "C202");
				strcpy(Com2.BidakCom[1].ID_Pemilik, "COM02");
				strcpy(Com2.BidakCom[1].Status, "HOME");
				Com2.BidakCom[1].Lokasi = 0;
				strcpy(Com2.BidakCom[2].ID, "C203");
				strcpy(Com2.BidakCom[2].ID_Pemilik, "COM02");
				strcpy(Com2.BidakCom[2].Status, "HOME");
				Com2.BidakCom[2].Lokasi = 0;
				strcpy(Com2.BidakCom[3].ID, "C204");
				strcpy(Com2.BidakCom[3].ID_Pemilik, "COM02");
				strcpy(Com2.BidakCom[3].Status, "HOME");
				Com2.BidakCom[3].Lokasi = 0;
				
				strcpy(Com3.BidakCom[0].ID, "C301");
				strcpy(Com3.BidakCom[0].ID_Pemilik, "COM02");
				strcpy(Com3.BidakCom[0].Status, "HOME");
				Com3.BidakCom[0].Lokasi = 0;
				strcpy(Com3.BidakCom[1].ID, "C302");
				strcpy(Com3.BidakCom[1].ID_Pemilik, "COM02");
				strcpy(Com3.BidakCom[1].Status, "HOME");
				Com3.BidakCom[1].Lokasi = 0;
				strcpy(Com3.BidakCom[2].ID, "C303");
				strcpy(Com3.BidakCom[2].ID_Pemilik, "COM02");
				strcpy(Com3.BidakCom[2].Status, "HOME");
				Com3.BidakCom[2].Lokasi = 0;
				strcpy(Com3.BidakCom[3].ID, "C304");
				strcpy(Com3.BidakCom[3].ID_Pemilik, "COM01");
				strcpy(Com3.BidakCom[3].Status, "HOME");
				Com3.BidakCom[3].Lokasi = 0;
				
				PlaySound(TEXT("C:\\Users\\afdalrdh\\Desktop\\BAHAN LUDO SEMUA DISINI\\ludoPawnStranding\\enter.wav"), NULL, SND_SYNC);
				jmlCom = 3;
				
				generateUserData(Nama, pilihWarna, &pemain);
				generateComData(Com1, Com2, Com3, pemain, jmlCom);
				data(pemain, Com1, Com2, Com3, urutan);
				
				
	}
	else{
		ModeSelect(select, jmlCom, pilihWarna, Nama);
	}
	
}


//                                        _     _       
//                                       | |   | |      
//  _ __  _   _ _ __  _   _  __ _    __ _| | __| |_   _ 
// | '_ \| | | | '_ \| | | |/ _` |  / _` | |/ _` | | | |
// | |_) | |_| | | | | |_| | (_| | | (_| | | (_| | |_| |
// | .__/ \__,_|_| |_|\__, |\__,_|  \__,_|_|\__,_|\__, |
// | |                 __/ |                       __/ |
// |_|                |___/                       |___/ 



void inputUserData()
{
	struct User pemain;
	struct Com Com1, Com2, Com3;
	char Nama[50], pilihWarna;
	int jmlCom;
	
	system("cls");
	
	gotoxy(2,9); printf("ษอออ  D E S K R I P S I   G A M E :  ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	gotoxy(2,10);printf("บ                                                                                                        บ");
	gotoxy(2,11);printf("บ      Permainan ini dimainkan oleh 1 orang pemain manusia, yang kemudian dalam game ini disebut users,  บ");
	gotoxy(2,12);printf("บ melawan 1-3 pemain komputer,yang kemudian dalam dokumen ini akan disebut com. Setiap com akan memiliki บ");
	gotoxy(2,13);printf("บ personality yang berbeda-beda. Com 1 akan memiliki personality yang mengedepankan untuk mengantarkan   บ");
	gotoxy(2,14);printf("บ bidaknya sampai di garis finish. Apabila ia mendapatkan angka 6 ketika mengocok dadu, ia akan segera   บ");
	gotoxy(2,15);printf("บ yang berada di lintasan, bukan mengeluarkan bidaknya yang masih berada di homebase. Com 2 akan memilki บ");
	gotoxy(2,16);printf("บ personality yang berbalik dengan com 1,dimana com 2 akan mengeluarkan seluruh bidaknya terlebih dahulu บ");
	gotoxy(2,17);printf("บ apabila memungkinkan dan terdapat lebih dari 1 bidaknya berada di atas lintasan,ia akan memajukan      บ");
	gotoxy(2,18);printf("บ bidaknya yang berada di paling belakang.Com 3 memiliki personality yang hampir sama dengan com 2,hanya บ");
	gotoxy(2,19);printf("บ saja com 3 memiliki sifat yang lebih 'ganas'. Com 3 akan berusaha keras menendang bidak yang dimiliki  บ");
	gotoxy(2,20);printf("บ oleh users dengan memajukan bidak yang memiliki jarak paling dekat dengan bidak users.                 บ");
	gotoxy(2,21);printf("บ                                                                                                        บ");
	gotoxy(2,22);printf("บ      Tujuan dari permainan ini yaitu mencari siapa yang tercepat dapat mengantarkan seluruh bidak yang บ");
	gotoxy(2,23);printf("บ dimilikinya sampai di finish. Baik users ataupun com akan diberikan masing-masing 4 buah bidak.Panjang บ");
	gotoxy(2,24);printf("บ lintasan dari permainan ini adalah 72 kotak ditambah dengan finish. Permainan akan berlangsung selama  บ");
	gotoxy(2,25);printf("บ 45 menit, apabila setelah 45 menit tidak ada pemain yang berhasil mengantarkan seluruh bidaknya sampai บ");
	gotoxy(2,26);printf("บ di garis finish, maka permainan akan berakhir dan dinyatakan tidak ada pemenang.  Selama permainan,    บ");
	gotoxy(2,27);printf("บ users bisa mendapatkan score,bisa juga kehilangan score tergantung aksi atau tindakan yang ia lakukan. บ");
	gotoxy(2,28);printf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
	
	resetComData(&Com1, &Com2, &Com3);
	
	
	gotoxy(2,1);printf("ออออ  I N P U T  D A T A  U S E R  ออออ");
	gotoxy(2,3);printf("Masukkan nama anda (tanpa spasi) : ");
	gets(Nama);
	
	system("cls");
	
	gotoxy(2,9); printf("ษอออ  D E S K R I P S I   G A M E :  ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	gotoxy(2,10);printf("บ                                                                                                        บ");
	gotoxy(2,11);printf("บ      Permainan ini dimainkan oleh 1 orang pemain manusia, yang kemudian dalam game ini disebut users,  บ");
	gotoxy(2,12);printf("บ melawan 1-3 pemain komputer,yang kemudian dalam dokumen ini akan disebut com. Setiap com akan memiliki บ");
	gotoxy(2,13);printf("บ personality yang berbeda-beda. Com 1 akan memiliki personality yang mengedepankan untuk mengantarkan   บ");
	gotoxy(2,14);printf("บ bidaknya sampai di garis finish. Apabila ia mendapatkan angka 6 ketika mengocok dadu, ia akan segera   บ");
	gotoxy(2,15);printf("บ yang berada di lintasan, bukan mengeluarkan bidaknya yang masih berada di homebase. Com 2 akan memilki บ");
	gotoxy(2,16);printf("บ personality yang berbalik dengan com 1,dimana com 2 akan mengeluarkan seluruh bidaknya terlebih dahulu บ");
	gotoxy(2,17);printf("บ apabila memungkinkan dan terdapat lebih dari 1 bidaknya berada di atas lintasan,ia akan memajukan      บ");
	gotoxy(2,18);printf("บ bidaknya yang berada di paling belakang.Com 3 memiliki personality yang hampir sama dengan com 2,hanya บ");
	gotoxy(2,19);printf("บ saja com 3 memiliki sifat yang lebih 'ganas'. Com 3 akan berusaha keras menendang bidak yang dimiliki  บ");
	gotoxy(2,20);printf("บ oleh users dengan memajukan bidak yang memiliki jarak paling dekat dengan bidak users.                 บ");
	gotoxy(2,21);printf("บ                                                                                                        บ");
	gotoxy(2,22);printf("บ      Tujuan dari permainan ini yaitu mencari siapa yang tercepat dapat mengantarkan seluruh bidak yang บ");
	gotoxy(2,23);printf("บ dimilikinya sampai di finish. Baik users ataupun com akan diberikan masing-masing 4 buah bidak.Panjang บ");
	gotoxy(2,24);printf("บ lintasan dari permainan ini adalah 72 kotak ditambah dengan finish. Permainan akan berlangsung selama  บ");
	gotoxy(2,25);printf("บ 45 menit, apabila setelah 45 menit tidak ada pemain yang berhasil mengantarkan seluruh bidaknya sampai บ");
	gotoxy(2,26);printf("บ di garis finish, maka permainan akan berakhir dan dinyatakan tidak ada pemenang.  Selama permainan,    บ");
	gotoxy(2,27);printf("บ users bisa mendapatkan score,bisa juga kehilangan score tergantung aksi atau tindakan yang ia lakukan. บ");
	gotoxy(2,28);printf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
	
	gotoxy(2,1);printf("ออออ  I N P U T  D A T A  U S E R  ออออ");
	gotoxy(2,3);printf("1. Merah");
	gotoxy(2,4);printf("2. Kuning");
	gotoxy(2,5);printf("3. Hijau");
	gotoxy(2,6);printf("4. Biru");
	gotoxy(2,7);printf("Inputkan nomor warna yang anda inginkan : ");scanf("%c", &pilihWarna);
	
	system("cls");
	
	ModeSelect(1, jmlCom, pilihWarna, Nama);
}

void resetComData(struct Com *Com1, struct Com *Com2, struct Com *Com3)
{
	strcpy((*Com1).Nama, "NONE");
	strcpy((*Com2).Nama, "NONE");
	strcpy((*Com3).Nama, "NONE");
}

void generateUserData(char Nama[50], char pilihWarna, struct User *pemain)
{
	strcpy((*pemain).ID, "USR18");
	strcpy((*pemain).Nama, Nama);
	switch(pilihWarna)
	{
		case '1':
			strcpy((*pemain).Warna, "Merah");
			break;
		case '2':
			strcpy((*pemain).Warna, "Kuning");
			break;
		case '3':;
			strcpy((*pemain).Warna, "Hijau");
			break;
		case '4':
			strcpy((*pemain).Warna, "Biru");
			break;
	}
	(*pemain).Score = 0;
	
}

void generateComData(struct Com Com1, struct Com Com2, struct Com Com3, struct User pemain, int jmlCom)
{
	switch(jmlCom)
	{
		case 1:
			generateCom1(&Com1, pemain);
			break;
		case 2:
			generateCom1(&Com1, pemain);
			generateCom2(&Com2, Com1, pemain);
			break;
		case 3:
			generateCom1(&Com1, pemain);
			generateCom2(&Com2, Com1, pemain);
			generateCom3(&Com3, Com2, pemain);
			break;
	}
}

void generateCom1(struct Com *Com1, struct User pemain)
{
	strcpy((*Com1).ID, "COM01");
	strcpy((*Com1).Nama, "Habib");
	strcpy((*Com1).Personality, "NOOBZ");
	if(strcmp(pemain.Warna, "Merah") == 0)
	{
		strcpy((*Com1).Warna, "Kuning");
	} else
	{
		strcpy((*Com1).Warna, "Merah");
	}
}

void generateCom2(struct Com *Com2, struct Com Com1, struct User pemain)
{
	strcpy((*Com2).ID, "COM02");
	strcpy((*Com2).Nama, "Kuda");
	strcpy((*Com2).Personality, "Lumayan");
	if((strcmp(pemain.Warna, "Kuning") == 0) || (strcmp(Com1.Warna, "Kuning") == 0))
	{
		strcpy((*Com2).Warna, "Hijau");
	} else
	{
		strcpy((*Com2).Warna, "Kuning");
	}
}

void generateCom3(struct Com *Com3, struct Com Com2, struct User pemain)
{
	strcpy((*Com3).ID, "COM03");
	strcpy((*Com3).Nama, "Zeki");
	strcpy((*Com3).Personality, "GGPRO");
	if((strcmp(pemain.Warna, "Hijau") == 0) || (strcmp(Com2.Warna, "Hijau") == 0))
	{
		strcpy((*Com3).Warna, "Biru");
	} else
	{
		strcpy((*Com3).Warna, "Hijau");
	}
}

void printData(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3)
{
	printf("\n%s si %s vs %s si %s vs %s si %s vs %s si %s ", pemain.Nama, pemain.Warna, Com1.Nama, Com1.Warna, Com2.Nama, Com2.Warna, Com3.Nama, Com3.Warna);
}

void data(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3, int urutan)
{
	int langkah, i;
	
	system("cls");
	
	if( pemain.BidakUser[0].Lokasi==73 && pemain.BidakUser[1].Lokasi==73 && pemain.BidakUser[2].Lokasi==73 && pemain.BidakUser[3].Lokasi==73 )
	{
		pemain.Score+=5000;
		gameOver(pemain, Com1, 1);
		
 	} else if( Com1.BidakCom[0].Lokasi==73 && Com1.BidakCom[1].Lokasi==73 && Com1.BidakCom[2].Lokasi==73 && Com1.BidakCom[3].Lokasi==73 )
 	{
 		gameOver(pemain, Com1, 2);
		getch();
	}
	
	save(pemain, Com1, Com2, Com3, urutan);
	Papan(pemain);
	
	if( urutan==1 )
	{
		gotoxy(38,3);
	} else if( urutan==2 )
	{
		gotoxy(81,3);
	} else if( urutan==3 )
	{
		gotoxy(38,11);
	} else
	{
		gotoxy(81,11);
	}
	printf("%s", "PLAYING");
	gotoxy(6,2);
	printf("%c", 218);
	for( i=0; i<82; i++)
	{
		if(i==39)
		{
			printf("%c", 194);
		} else
		{
			printf("%c", 196);
		}
	}
	printf("%c", 191);
	printf("\n");
	printf("      %c USER\n", 179);
	printf("      %c Nama    : %s\n", 179, pemain.Nama);
	printf("      %c Posisi Bidak\n", 179);
	printf("      %c Bidak 1 : %d\n", 179, pemain.BidakUser[0].Lokasi);
	printf("      %c Bidak 2 : %d\n", 179, pemain.BidakUser[1].Lokasi);
	printf("      %c Bidak 3 : %d\n", 179, pemain.BidakUser[2].Lokasi);
	printf("      %c Bidak 4 : %d\n", 179, pemain.BidakUser[3].Lokasi);
	printf("      %c", 195);
	for( i=0; i<82; i++)
	{
		printf("%c", 196);
	}
	printf("%c\n", 180);
	printf("      %c COM 2\n", 179);
	printf("      %c Nama    : %s\n", 179, Com2.Nama);
	printf("      %c Posisi Bidak\n", 179);
	printf("      %c Bidak 1 : %d\n", 179, Com2.BidakCom[0].Lokasi);
	printf("      %c Bidak 2 : %d\n", 179, Com2.BidakCom[1].Lokasi);
	printf("      %c Bidak 3 : %d\n", 179, Com2.BidakCom[2].Lokasi);
	printf("      %c Bidak 4 : %d\n", 179, Com2.BidakCom[3].Lokasi);
	printf("      %c", 192);
	for( i=0; i<82; i++)
	{
		if(i==39)
		{
			printf("%c", 193);
		} else
		{
			printf("%c", 196);
		}
	}
	printf("%c\n", 217);
	for( i=2; i<17; i++)
	{
		gotoxy(46,i+1);
		if(i==9)
		{
			printf("%c\n", 197);
		} else
		{
			printf("%c\n", 179);
		}
	}
	for( i=2; i<17; i++)
	{
		gotoxy(89,i+1);
		if(i==9)
		{
			printf("%c\n", 180);
		} else
		{
			printf("%c\n", 179);
		}
		
	}
	showCom1Data(Com1);
	showCom3Data(Com3);
	gotoxy(6,19);
	printf("Kocok dadu, tekan enter untuk melanjutkan...\n");
	getch();
	langkah = rand()%6+1;
	printf("      Angka yang didapatkan = %d\n", langkah);
	getch();
	if( urutan==1 )
	{
		userChoice(&pemain, &Com1, &Com2, &Com3, langkah, urutan);
	} else
	{
		maju(&pemain, &Com1, &Com2, &Com3, langkah, urutan);
	}
}

void showCom1Data(struct Com Com1)
{
	gotoxy(48,3);
	printf("COM 1");
	gotoxy(48,4);
	printf("Nama    : %s", Com1.Nama);
	gotoxy(48,5);
	printf("Posisi Bidak");
	gotoxy(48,6);
	printf("Bidak 1 : %d", Com1.BidakCom[0].Lokasi);
	gotoxy(48,7);
	printf("Bidak 2 : %d", Com1.BidakCom[1].Lokasi);
	gotoxy(48,8);
	printf("Bidak 3 : %d", Com1.BidakCom[2].Lokasi);
	gotoxy(48,9);
	printf("Bidak 4 : %d", Com1.BidakCom[3].Lokasi);
}

void showCom3Data(struct Com Com3)
{
	gotoxy(48,11);
	printf("COM 3");
	gotoxy(48,12);
	printf("Nama    : %s", Com3.Nama);
	gotoxy(48,13);
	printf("Posisi Bidak");
	gotoxy(48,14);
	printf("Bidak 1 : %d", Com3.BidakCom[0].Lokasi);
	gotoxy(48,15);
	printf("Bidak 2 : %d", Com3.BidakCom[1].Lokasi);
	gotoxy(48,16);
	printf("Bidak 3 : %d", Com3.BidakCom[2].Lokasi);
	gotoxy(48,17);
	printf("Bidak 4 : %d", Com3.BidakCom[3].Lokasi);
}

void userChoice(struct User *pemain, struct Com *Com1, struct Com *Com2, struct Com *Com3,int langkah, int urutan)
{
	int pilihBidak;
	if(langkah == 6)
	{
		if( (*pemain).BidakUser[0].Lokasi==0 && (*pemain).BidakUser[1].Lokasi==0 && (*pemain).BidakUser[2].Lokasi==0 && (*pemain).BidakUser[3].Lokasi==0 )
		{
			userOutPawn(pemain, langkah);
		} else if( (*pemain).BidakUser[0].Lokasi!=0 && (*pemain).BidakUser[1].Lokasi!=0 && (*pemain).BidakUser[2].Lokasi!=0 && (*pemain).BidakUser[3].Lokasi!=0 )
		{
			userMovePawn(pemain, langkah);
		} else
		{
			printf("      1. Keluarkan bidak dari dalam homebase\n");
			printf("      2. Gerakkan bidak yang berada di lintasan\n");
			printf("      Tindakan apa yang ingin anda lakukan? : ");scanf("%d", &pilihBidak);
			if(pilihBidak == 1)
			{
				userOutPawn(pemain, langkah);
			} else
			{
				userMovePawn(pemain, langkah);
			}
		}
	} else
	{
		if( strcmp((*pemain).BidakUser[0].Status, "JALAN")==0 || strcmp((*pemain).BidakUser[1].Status, "JALAN")==0 || strcmp((*pemain).BidakUser[2].Status, "JALAN")==0 || strcmp((*pemain).BidakUser[3].Status, "JALAN")==0 )
		{
			userMovePawn(pemain, langkah);
		} else
		{
			printf("Seluruh bidak masih berada di dalam Homebase");
			getch();
		}
	}
	
	urutan+=1;
	
	data(*pemain, *Com1, *Com2, *Com3, urutan);
	
}

void userOutPawn(struct User *pemain, int langkah)
{
	int pilihBidak;
	char status[20];
	printf("      Inputkan no bidak yang ingin anda keluarkan : ");scanf("%d", &pilihBidak);
	if( pilihBidak==1 )
	{
		if( (*pemain).BidakUser[0].Lokasi!=0 )
		{
			printf("      Bidak sudah berada di luar homebase\n");
			system("pause");
			userOutPawn(pemain, langkah);
		} else
		{
			(*pemain).BidakUser[0].Lokasi = 1;
			cekPosisi((*pemain).BidakUser[0].Lokasi, status);
			strcpy((*pemain).BidakUser[0].Status, status);
		}
	} else if( pilihBidak==2 )
	{
		if( (*pemain).BidakUser[1].Lokasi!=0 )
		{
			printf("      Bidak sudah berada di luar homebase\n");
			system("pause");
			userOutPawn(pemain, langkah);
		} else
		{
			(*pemain).BidakUser[1].Lokasi = 1;
			cekPosisi((*pemain).BidakUser[1].Lokasi, status);
			strcpy((*pemain).BidakUser[1].Status, status);
		}
	} else if( pilihBidak==3 )
	{
		if( (*pemain).BidakUser[2].Lokasi!=0 )
		{
			printf("      Bidak sudah berada di luar homebase\n");
			system("pause");
			userOutPawn(pemain, langkah);
		} else
		{
			(*pemain).BidakUser[2].Lokasi = 1;
			cekPosisi((*pemain).BidakUser[2].Lokasi, status);
			strcpy((*pemain).BidakUser[2].Status, status);
		}
	} else if( pilihBidak==4 )
	{
		if( (*pemain).BidakUser[3].Lokasi!=0 )
		{
			printf("      Bidak sudah berada di luar homebase\n");
			system("pause");
			userOutPawn(pemain, langkah);
		} else
		{
			(*pemain).BidakUser[3].Lokasi = 1;
			cekPosisi((*pemain).BidakUser[3].Lokasi, status);
			strcpy((*pemain).BidakUser[3].Status, status);
		}
	}
}

void userMovePawn(struct User *pemain, int langkah)
{
	int pilihBidak;
	char status[20];
	printf("Inputkan no bidak yang ingin anda majukan (1-4) : ");scanf("%d", &pilihBidak);
	if( pilihBidak==1 )
	{
		if( (*pemain).BidakUser[0].Lokasi==0 )
		{
			printf("Bidak tidak dapat dikeluarkan karena masih berada di dalam homebase\n");
			getch();
			userMovePawn(pemain, langkah);
		} else
		{
			if( (*pemain).BidakUser[0].Lokasi+langkah>73 )
			{
				(*pemain).BidakUser[0].Lokasi = 73;
				strcpy((*pemain).BidakUser[0].Status, "FINISH");
			} else
			{
				(*pemain).BidakUser[0].Lokasi += langkah;
				cekPosisi((*pemain).BidakUser[0].Lokasi, status);
				strcpy((*pemain).BidakUser[0].Status, status);
			}
		}
	} else if( pilihBidak==2 )
	{
		if( (*pemain).BidakUser[1].Lokasi==0 )
		{
			printf("Bidak tidak dapat dikeluarkan karena masih berada di dalam homebase\n");
			getch();
			userMovePawn(pemain, langkah);
		} else
		{
			if( (*pemain).BidakUser[1].Lokasi+langkah>73 )
			{
				(*pemain).BidakUser[1].Lokasi = 73;
				strcpy((*pemain).BidakUser[1].Status, "FINISH");
			} else
			{
				(*pemain).BidakUser[1].Lokasi += langkah;
				cekPosisi((*pemain).BidakUser[1].Lokasi, status);
				strcpy((*pemain).BidakUser[1].Status, status);
			}
		}
	} else if( pilihBidak==3 )
	{
		if( (*pemain).BidakUser[2].Lokasi==0 )
		{
			printf("Bidak tidak dapat dikeluarkan karena masih berada di dalam homebase\n");
			getch();
			userMovePawn(pemain, langkah);
		} else
		{
			if( (*pemain).BidakUser[2].Lokasi+langkah>73 )
			{
				(*pemain).BidakUser[2].Lokasi = 73;
				strcpy((*pemain).BidakUser[2].Status, "FINISH");
			} else
			{
				(*pemain).BidakUser[2].Lokasi += langkah;
				cekPosisi((*pemain).BidakUser[2].Lokasi, status);
				strcpy((*pemain).BidakUser[1].Status, status);
			}
		}
	} else if( pilihBidak==4 )
	{
		if( (*pemain).BidakUser[3].Lokasi==0 )
		{
			printf("Bidak tidak dapat dikeluarkan karena masih berada di dalam homebase\n");
			getch();
			userMovePawn(pemain, langkah);
		} else
		{
			if( (*pemain).BidakUser[3].Lokasi+langkah>73 )
			{
				(*pemain).BidakUser[3].Lokasi = 73;
				strcpy((*pemain).BidakUser[3].Status, "FINISH");
			} else
			{
				(*pemain).BidakUser[3].Lokasi += langkah;
				cekPosisi((*pemain).BidakUser[3].Lokasi, status);
				strcpy((*pemain).BidakUser[1].Status, status);
			}
		}
	}
}

void maju(struct User *pemain, struct Com *Com1, struct Com *Com2, struct Com *Com3, int langkah, int urutan)
{
	if( urutan==2 )
	{
		if( langkah==6 )
		{
			if( (*Com1).BidakCom[0].Lokasi==0 )
			{
				(*Com1).BidakCom[0].Lokasi = 1;
				cekPosisi((*Com1).BidakCom[0].Lokasi, sa);
				strcpy((*Com1).BidakCom[0].Status, sa);
				
			} else if( ((*Com1).BidakCom[1].Lokasi==0) && ((*Com1).BidakCom[0].Lokasi==finish) )
			{
				(*Com1).BidakCom[1].Lokasi = 1;
				cekPosisi((*Com1).BidakCom[1].Lokasi, sb);
				strcpy((*Com1).BidakCom[1].Status, sb);
			}
			else if( ((*Com1).BidakCom[2].Lokasi==0) && ((*Com1).BidakCom[1].Lokasi==finish) && ((*Com1).BidakCom[0].Lokasi==finish) )
			{
				(*Com1).BidakCom[2].Lokasi = 1;
				cekPosisi((*Com1).BidakCom[2].Lokasi, sc);
				strcpy((*Com1).BidakCom[2].Status, sc);
			}
			else if( ((*Com1).BidakCom[3].Lokasi==0) && ((*Com1).BidakCom[2].Lokasi==finish) && ((*Com1).BidakCom[1].Lokasi==finish) && ((*Com1).BidakCom[0].Lokasi==finish) )
			{
				(*Com1).BidakCom[3].Lokasi = 1;
				cekPosisi((*Com1).BidakCom[3].Lokasi, sd);
				strcpy((*Com1).BidakCom[3].Status, sd);
			} else if ( (((*Com1).BidakCom[0].Lokasi!=0) || ((*Com1).BidakCom[0].Lokasi!= finish)) && strcmp((*Com1).BidakCom[0].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[0].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[0].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[0].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[0].Lokasi, sa);
				strcpy((*Com1).BidakCom[0].Status, sa);
			} else if ( (((*Com1).BidakCom[1].Lokasi!=0) || ((*Com1).BidakCom[1].Lokasi!= finish)) && strcmp((*Com1).BidakCom[1].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[1].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[1].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[1].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[1].Lokasi, sb);
				strcpy((*Com1).BidakCom[1].Status, sb);
			} else if ( (((*Com1).BidakCom[2].Lokasi!=0) || ((*Com1).BidakCom[2].Lokasi!= finish)) && strcmp((*Com1).BidakCom[2].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[2].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[2].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[2].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[2].Lokasi, sc);
				strcpy((*Com1).BidakCom[2].Status, sc);
			} else if ( (((*Com1).BidakCom[3].Lokasi!=0) || ((*Com1).BidakCom[3].Lokasi!= finish)) && strcmp((*Com1).BidakCom[3].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[3].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[3].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[3].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[3].Lokasi, sd);
				strcpy((*Com1).BidakCom[3].Status, sd);
			}
		} else if( (((*Com1).BidakCom[0].Lokasi!=0) && strcmp((*Com1).BidakCom[0].Status, "FINISH") != 0) || (((*Com1).BidakCom[1].Lokasi!=0) && strcmp((*Com1).BidakCom[1].Status, "FINISH") != 0) || (((*Com1).BidakCom[2].Lokasi!=0) && strcmp((*Com1).BidakCom[2].Status, "FINISH") != 0) || (((*Com1).BidakCom[3].Lokasi!=0) && strcmp((*Com1).BidakCom[3].Status, "FINISH") != 0) )
		{
			if ( (((*Com1).BidakCom[0].Lokasi!=0) || ((*Com1).BidakCom[0].Lokasi!= finish)) && strcmp((*Com1).BidakCom[0].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[0].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[0].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[0].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[0].Lokasi, sa);
				strcpy((*Com1).BidakCom[0].Status, sa);
			} else if ( (((*Com1).BidakCom[1].Lokasi!=0) || ((*Com1).BidakCom[1].Lokasi!= finish)) && strcmp((*Com1).BidakCom[1].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[1].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[1].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[1].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[1].Lokasi, sb);
				strcpy((*Com1).BidakCom[1].Status, sb);
			} else if ( (((*Com1).BidakCom[2].Lokasi!=0) || ((*Com1).BidakCom[2].Lokasi!= finish)) && strcmp((*Com1).BidakCom[2].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[2].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[2].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[2].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[2].Lokasi, sc);
				strcpy((*Com1).BidakCom[2].Status, sc);
			} else if ( (((*Com1).BidakCom[3].Lokasi!=0) || ((*Com1).BidakCom[3].Lokasi!= finish)) && strcmp((*Com1).BidakCom[3].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[3].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[3].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[3].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[3].Lokasi, sd);
				strcpy((*Com1).BidakCom[3].Status, sd);
			}
		}
	} else if(urutan == 3)
	{
		int max, jarak1, jarak2, jarak3, jarak4;
		char sa[50], sb[50], sc[50], sd[50];
		if( langkah==6 )
		{
			if( (*Com2).BidakCom[0].Lokasi==0 )
			{
				(*Com2).BidakCom[0].Lokasi = 1;
				cekPosisi((*Com2).BidakCom[0].Lokasi, sa);
				strcpy((*Com2).BidakCom[0].Status, sa);
			} else if( (*Com2).BidakCom[0].Lokasi!=0 && (*Com2).BidakCom[1].Lokasi==0 )
			{
				(*Com2).BidakCom[1].Lokasi = 1;
				cekPosisi((*Com2).BidakCom[1].Lokasi, sb);
				strcpy((*Com2).BidakCom[0].Status, sb);
			} else if( (*Com2).BidakCom[0].Lokasi!=0 && (*Com2).BidakCom[1].Lokasi!=0 && (*Com2).BidakCom[2].Lokasi==0 )
			{
				(*Com2).BidakCom[2].Lokasi = 1;
				cekPosisi((*Com2).BidakCom[2].Lokasi, sc);
				strcpy((*Com2).BidakCom[0].Status, sc);
			} else if( a!=(*Com2).BidakCom[0].Lokasi && (*Com2).BidakCom[1].Lokasi!=0 && (*Com2).BidakCom[2].Lokasi!=0 && (*Com2).BidakCom[3].Lokasi==0 )
			{
				(*Com2).BidakCom[3].Lokasi = 1;
				cekPosisi((*Com2).BidakCom[3].Lokasi, sd);
				strcpy((*Com2).BidakCom[0].Status, sc);
			} else 
			{
				if(strcmp((*Com2).BidakCom[0].Status, "HOME") == 0)
				{
					jarak1 = -1;
				} else
				{
					jarak1 = finish-(*Com2).BidakCom[0].Lokasi;
				}
				if(strcmp((*Com2).BidakCom[1].Status, "HOME") == 0)
				{
					jarak2 = -1;
				} else
				{
					jarak2 = finish-(*Com2).BidakCom[1].Lokasi;
				}
				if(strcmp((*Com2).BidakCom[2].Status, "HOME") == 0)
				{
					jarak3 = -1;
				} else
				{
					jarak3 = finish-(*Com2).BidakCom[2].Lokasi;
				}
				if(strcmp((*Com2).BidakCom[3].Status, "HOME") == 0)
				{
					jarak4 = -1;
				} else
				{
					jarak4 = finish-(*Com2).BidakCom[3].Lokasi;
				}
				max = max4Value(jarak1, jarak2, jarak3, jarak4);
				if ( (max==jarak1) && strcmp((*Com2).BidakCom[0].Status, "JALAN") == 0 )
				{
					if((*Com2).BidakCom[0].Lokasi+langkah >=73)
					{
						(*Com2).BidakCom[0].Lokasi = 73;
					} else
					{
						(*Com2).BidakCom[0].Lokasi += langkah;
					}
					cekPosisi((*Com2).BidakCom[0].Lokasi, sa);
					strcpy((*Com2).BidakCom[0].Status, sa);
				} else if ( (max==jarak2) && strcmp((*Com2).BidakCom[1].Status, "JALAN") == 0 )
				{
					if((*Com2).BidakCom[1].Lokasi+langkah >=73)
					{
						(*Com2).BidakCom[1].Lokasi = 73;
					} else
					{
						(*Com2).BidakCom[1].Lokasi += langkah;
					}
					cekPosisi((*Com2).BidakCom[1].Lokasi, sb);
					strcpy((*Com2).BidakCom[0].Status, sb);
				} else if ( (max==jarak3) && strcmp((*Com2).BidakCom[2].Status, "JALAN") == 0 )
				{
					if((*Com2).BidakCom[2].Lokasi+langkah >=73)
					{
						(*Com2).BidakCom[2].Lokasi = 73;
					} else
					{
						(*Com2).BidakCom[2].Lokasi += langkah;
					}
					cekPosisi((*Com1).BidakCom[2].Lokasi, sc);
					strcpy((*Com2).BidakCom[0].Status, sc);
				} else if ( (max==jarak4) && strcmp((*Com2).BidakCom[3].Status, "JALAN") == 0 )
				{
					if((*Com2).BidakCom[3].Lokasi+langkah >=73)
					{
						(*Com2).BidakCom[3].Lokasi = 73;
					} else
					{
						(*Com2).BidakCom[3].Lokasi += langkah;
					}
					cekPosisi((*Com2).BidakCom[3].Lokasi, sd);
					strcpy((*Com2).BidakCom[0].Status, sd);
				}
			}
		} else
		{
			if(strcmp(sa, "HOME") == 0)
			{
				jarak1 = -1;
			} else
			{
				jarak1 = finish-a;
			}
			if(strcmp(sb, "HOME") == 0)
			{
				jarak2 = -1;
			} else
			{
				jarak2 = finish-b;
			}
			if(strcmp(sc, "HOME") == 0)
			{
				jarak3 = -1;
			} else
			{
				jarak3 = finish-c;
			}
			if(strcmp(sd, "HOME") == 0)
			{
				jarak4 = -1;
			} else
			{
				jarak4 = finish-d;
			}
			max = max4Value(jarak1, jarak2, jarak3, jarak4);
			if ( (max==jarak1) && strcmp(sa, "JALAN") == 0 )
			{
				if(a+langkah >=73)
				{
					a = 73;
				} else
				{
					a += langkah;
				}
				cekPosisi(a, sa);
			} else if ( (max==jarak2) && strcmp(sb, "JALAN") == 0 )
			{
				if(b+langkah >=73)
				{
					b = 73;
				} else
				{
					b += langkah;
				}
				cekPosisi(b, sb);
			} else if ( (max==jarak3) && strcmp(sc, "JALAN") == 0 )
			{
				if(c+langkah >=73)
				{
					c = 73;
				} else
				{
					c += langkah;
				}
				cekPosisi(c, sc);
			} else if ( (max==jarak4) && strcmp(sd, "JALAN") == 0 )
			{
				if(d+langkah >=73)
				{
					d = 73;
				} else
				{
					d += langkah;
				}
				cekPosisi(d, sd);
			}
		}
	} else if(urutan==4 )
	{
		if( langkah==6 )
		{
			if( a==0 )
			{
				a = 1;
				cekPosisi(a, sa);
			} else if( a!=0 && b==0 )
			{
				b = 1;
				cekPosisi(b, sb);
			} else if( a!=0 && b!=0 && c==0 )
			{
				c = 1;
				cekPosisi(c, sc);
			} else if( a!=0 && b!=0 && c!=0 && d==0 )
			{
				d = 1;
				cekPosisi(d, sd);
			} else 
			{
				int min;
				int jarakua_a, jarakub_a, jarakuc_a, jarakud_a;
				int jarakua_b, jarakub_b, jarakuc_b, jarakud_b;
				int jarakua_c, jarakub_c, jarakuc_c, jarakud_c;
				int jarakua_d, jarakub_d, jarakuc_d, jarakud_d;
				
				if( (ua-a<0 || ua-a<langkah) || strcmp(sa, "HOME") == 0  )
				{
					jarakua_a = 100;
				} else
				{
					jarakua_a = ua-a;
				}
				if( (ub-a<0 || ub-a<langkah) || strcmp(sa, "HOME") == 0  )
				{
					jarakub_a = 100;
				} else
				{
					jarakub_a = ub-a;
				}
				if( (uc-a<0 || uc-a<langkah) || strcmp(sa, "HOME") == 0  )
				{
					jarakuc_a = 100;
				} else
				{
					jarakuc_a = uc-a;
				}
				if( (ud-a<0 || ud-a<langkah) || strcmp(sa, "HOME") == 0  )
				{
					jarakud_a = 100;
				} else
				{
					jarakud_a = ud-a;
				}
				if( (ua-b<0 || ua-b<langkah) || strcmp(sb, "HOME") == 0  )
				{
					jarakua_b = 100;
				} else
				{
					jarakua_b = ua-b;
				}
				if( (ub-b<0 || ub-b<langkah) || strcmp(sb, "HOME") == 0  )
				{
					jarakub_b = 100;
				} else
				{
					jarakub_b = ub-b;
				}
				if( (uc-b<0 || uc-b<langkah) || strcmp(sb, "HOME") == 0  )
				{
					jarakuc_b = 100;
				} else
				{
					jarakuc_b = uc-b;
				}
				if( (ud-b<0 || ud-b<langkah) || strcmp(sb, "HOME") == 0  )
				{
					jarakud_b = 100;
				} else
				{
					jarakud_b = ud-b;
				}
				if( (ua-c<0 || ua-c<langkah) || strcmp(sc, "HOME") == 0  )
				{
					jarakua_c = 100;
				} else
				{
					jarakua_c = ua-c;
				}
				if( (ub-c<0 || ub-c<langkah) || strcmp(sc, "HOME") == 0  )
				{
					jarakub_c = 100;
				} else
				{
					jarakub_c = ub-c;
				}
				if( (uc-c<0 || uc-c<langkah) || strcmp(sc, "HOME") == 0  )
				{
					jarakuc_c = 100;
				} else
				{
					jarakuc_c = uc-c;
				}
				if( (ud-c<0 || ud-c<langkah) || strcmp(sc, "HOME") == 0  )
				{
					jarakud_c = 100;
				} else
				{
					jarakud_c = ud-c;
				}
				if( (ua-d<0 || ua-d<langkah) || strcmp(sd, "HOME") == 0  )
				{
					jarakua_d = 100;
				} else
				{
					jarakua_d = ua-d;
				}
				if( (ub-d<0 || ub-d<langkah) || strcmp(sd, "HOME") == 0  )
				{
					jarakub_d = 100;
				} else
				{
					jarakub_d = ub-d;
				}
				if( (uc-d<0 || uc-d<langkah) || strcmp(sd, "HOME") == 0  )
				{
					jarakuc_d = 100;
				} else
				{
					jarakuc_d = uc-d;
				}
				if( (ud-d<0 || ud-d<langkah) || strcmp(sd, "HOME") == 0  )
				{
					jarakud_d = 100;
				} else
				{
					jarakud_d = ud-d;
				}
				
				min = min4Value(min4Value(jarakua_a, jarakub_a, jarakuc_a, jarakud_a), min4Value(jarakua_b, jarakub_b, jarakuc_b, jarakud_b), min4Value(jarakua_c, jarakub_c, jarakuc_c, jarakud_c), min4Value(jarakua_d, jarakub_d, jarakuc_d, jarakud_d));
				
				if ( (min==jarakua_a || min==jarakub_a || min==jarakuc_a || min==jarakud_a) && strcmp(sa, "JALAN") == 0 )
				{
					if(a+langkah >=73)
					{
						a = 73;
					} else
					{
						a += langkah;
					}
					cekPosisi(a, sa);
				} else if ( (min==jarakua_b || min==jarakub_b || min==jarakuc_b || min==jarakud_b) && strcmp(sa, "JALAN") == 0 )
				{
					if(b+langkah >=73)
					{
						b = 73;
					} else
					{
						b += langkah;
					}
					cekPosisi(b, sb);
				} else if ( (min==jarakua_c || min==jarakub_c || min==jarakuc_c || min==jarakud_c) && strcmp(sc, "JALAN") == 0 )
				{
					if(c+langkah >=73)
					{
						c = 73;
					} else
					{
						c += langkah;
					}
					cekPosisi(c, sc);
				} else if ( (min==jarakua_d || min==jarakub_d || min==jarakuc_d || min==jarakud_d) && strcmp(sd, "JALAN") == 0 )
				{
					if(d+langkah >=73)
					{
						d = 73;
					} else
					{
						d += langkah;
					}
					cekPosisi(d, sd);
				}
			}
		} else
		{
			int min;
			int jarakua_a, jarakub_a, jarakuc_a, jarakud_a;
			int jarakua_b, jarakub_b, jarakuc_b, jarakud_b;
			int jarakua_c, jarakub_c, jarakuc_c, jarakud_c;
			int jarakua_d, jarakub_d, jarakuc_d, jarakud_d;
			
			if( (ua-a<0 || ua-a<langkah) || strcmp(sa, "HOME") == 0  )
			{
				jarakua_a = 100;
			} else
			{
				jarakua_a = ua-a;
			}
			if( (ub-a<0 || ub-a<langkah) || strcmp(sa, "HOME") == 0  )
			{
				jarakub_a = 100;
			} else
			{
				jarakub_a = ub-a;
			}
			if( (uc-a<0 || uc-a<langkah) || strcmp(sa, "HOME") == 0  )
			{
				jarakuc_a = 100;
			} else
			{
				jarakuc_a = uc-a;
			}
			if( (ud-a<0 || ud-a<langkah) || strcmp(sa, "HOME") == 0  )
			{
				jarakud_a = 100;
			} else
			{
				jarakud_a = ud-a;
			}
			if( (ua-b<0 || ua-b<langkah) || strcmp(sb, "HOME") == 0  )
			{
				jarakua_b = 100;
			} else
			{
				jarakua_b = ua-b;
			}
			if( (ub-b<0 || ub-b<langkah) || strcmp(sb, "HOME") == 0  )
			{
				jarakub_b = 100;
			} else
			{
				jarakub_b = ub-b;
			}
			if( (uc-b<0 || uc-b<langkah) || strcmp(sb, "HOME") == 0  )
			{
				jarakuc_b = 100;
			} else
			{
				jarakuc_b = uc-b;
			}
			if( (ud-b<0 || ud-b<langkah) || strcmp(sb, "HOME") == 0  )
			{
				jarakud_b = 100;
			} else
			{
				jarakud_b = ud-b;
			}
			if( (ua-c<0 || ua-c<langkah) || strcmp(sc, "HOME") == 0  )
			{
				jarakua_c = 100;
			} else
			{
				jarakua_c = ua-c;
			}
			if( (ub-c<0 || ub-c<langkah) || strcmp(sc, "HOME") == 0  )
			{
				jarakub_c = 100;
			} else
			{
				jarakub_c = ub-c;
			}
			if( (uc-c<0 || uc-c<langkah) || strcmp(sc, "HOME") == 0  )
			{
				jarakuc_c = 100;
			} else
			{
				jarakuc_c = uc-c;
			}
			if( (ud-c<0 || ud-c<langkah) || strcmp(sc, "HOME") == 0  )
			{
				jarakud_c = 100;
			} else
			{
				jarakud_c = ud-c;
			}
			if( (ua-d<0 || ua-d<langkah) || strcmp(sd, "HOME") == 0  )
			{
				jarakua_d = 100;
			} else
			{
				jarakua_d = ua-d;
			}
			if( (ub-d<0 || ub-d<langkah) || strcmp(sd, "HOME") == 0  )
			{
				jarakub_d = 100;
			} else
			{
				jarakub_d = ub-d;
			}
			if( (uc-d<0 || uc-d<langkah) || strcmp(sd, "HOME") == 0  )
			{
				jarakuc_d = 100;
			} else
			{
				jarakuc_d = uc-d;
			}
			if( (ud-d<0 || ud-d<langkah) || strcmp(sd, "HOME") == 0  )
			{
				jarakud_d = 100;
			} else
			{
				jarakud_d = ud-d;
			}
			
			min = min4Value(min4Value(jarakua_a, jarakub_a, jarakuc_a, jarakud_a), min4Value(jarakua_b, jarakub_b, jarakuc_b, jarakud_b), min4Value(jarakua_c, jarakub_c, jarakuc_c, jarakud_c), min4Value(jarakua_d, jarakub_d, jarakuc_d, jarakud_d));
			
			if ( (min==jarakua_a || min==jarakub_a || min==jarakuc_a || min==jarakud_a) && strcmp(sa, "JALAN") == 0 )
			{
				if(a+langkah >=73)
				{
					a = 73;
				} else
				{
					a += langkah;
				}
				cekPosisi(a, sa);
			} else if ( (min==jarakua_b || min==jarakub_b || min==jarakuc_b || min==jarakud_b) && strcmp(sa, "JALAN") == 0 )
			{
				if(b+langkah >=73)
				{
					b = 73;
				} else
				{
					b += langkah;
				}
				cekPosisi(b, sb);
			} else if ( (min==jarakua_c || min==jarakub_c || min==jarakuc_c || min==jarakud_c) && strcmp(sc, "JALAN") == 0 )
			{
				if(c+langkah >=73)
				{
					c = 73;
				} else
				{
					c += langkah;
				}
				cekPosisi(c, sc);
			} else if ( (min==jarakua_d || min==jarakub_d || min==jarakuc_d || min==jarakud_d) && strcmp(sd, "JALAN") == 0 )
			{
				if(d+langkah >=73)
				{
					d = 73;
				} else
				{
					d += langkah;
				}
				cekPosisi(d, sd);
			}
		}
	}
	
	if( urutan==2 )
	{
		urutan = 1;
	} else
	{
		urutan+=1;
	}
	
	data(*pemain, *Com1, *Com2, *Com3, urutan);
}

int max4Value(int value1, int value2, int value3, int value4)
{
	int maximum, temp_max1, temp_max2;
	
	if( value1>value2 )
	{
		temp_max1 = value1;
	} else
	{
		temp_max1 = value2;
	}
	if( value3>value4 )
	{
		temp_max2 = value3;
	} else
	{
		temp_max2 = value4;
	}
	if( temp_max1>temp_max2 )
	{
		maximum = temp_max1;
	} else
	{
		maximum = temp_max2;
	}
	
	return maximum;
}

int min4Value(int value1, int value2, int value3, int value4)
{
	int minimum, temp_min1, temp_min2;
	
	if( value1<value2 )
	{
		temp_min1 = value1;
	} else
	{
		temp_min1 = value2;
	}
	if( value3<value4 )
	{
		temp_min2 = value3;
	} else
	{
		temp_min2 = value4;
	}
	if( temp_min1<temp_min2 )
	{
		minimum = temp_min1;
	} else
	{
		minimum = temp_min2;
	}
	
	return minimum;
}

void cekPosisi(int posisi, char *status)
{
	if(posisi == 73)
	{
		strcpy(status, "FINISH");
	} else if ( posisi>0 && posisi<73 )
	{
		strcpy(status, "JALAN");
	}
}


//        _    _     _                                              _     _       
//       | |  | |   (_)                                            | |   | |      
//   __ _| | _| |__  _ _ __   _ __  _   _ _ __  _   _  __ _    __ _| | __| |_   _ 
//  / _` | |/ / '_ \| | '__| | '_ \| | | | '_ \| | | |/ _` |  / _` | |/ _` | | | |
// | (_| |   <| | | | | |    | |_) | |_| | | | | |_| | (_| | | (_| | | (_| | |_| |
//  \__,_|_|\_\_| |_|_|_|    | .__/ \__,_|_| |_|\__, |\__,_|  \__,_|_|\__,_|\__, |
//                           | |                 __/ |                       __/ |
//                           |_|                |___/                       |___/ 




void ContinueGame(){
	FILE *frec;
	struct User pemain;
	struct Com Com1, Com2, Com3;
	int urutan;
	
	if ((frec=fopen("Save.txt","rb"))==NULL)
		printf("File tidak dapat dibuka !");
	else
	{
		while(!feof(frec)) //cek apakah end of file ?
		{
			printf("\n\n\n\n\tMasuk");
			fscanf(frec, "%s %s %d %d %d %d %d %s %d %d %d %d %s %d %d %d %d %s %d %d %d %d %d\n", pemain.Nama, pemain.Warna, &pemain.Score, &pemain.BidakUser[0].Lokasi, &pemain.BidakUser[1].Lokasi, &pemain.BidakUser[2].Lokasi, &pemain.BidakUser[3].Lokasi, Com1.Nama, &Com1.BidakCom[0].Lokasi, &Com1.BidakCom[1].Lokasi, &Com1.BidakCom[2].Lokasi, &Com1.BidakCom[3].Lokasi, Com2.Nama, &Com2.BidakCom[0].Lokasi, &Com2.BidakCom[1].Lokasi, &Com2.BidakCom[2].Lokasi, &Com2.BidakCom[3].Lokasi, Com3.Nama, &Com3.BidakCom[0].Lokasi, &Com3.BidakCom[1].Lokasi, &Com3.BidakCom[2].Lokasi, &Com3.BidakCom[3].Lokasi, &urutan);
			//printf("%s %d %d %d %d %d %s %d %d %d %d %s %d %d %d %d %s %d %d %d %d %d\n", pemain.Nama, pemain.Score, pemain.BidakUser[0].Lokasi, pemain.BidakUser[1].Lokasi, pemain.BidakUser[2].Lokasi, pemain.BidakUser[3].Lokasi, Com1.Nama, Com1.BidakCom[0].Lokasi, Com1.BidakCom[1].Lokasi, Com1.BidakCom[2].Lokasi, Com1.BidakCom[3].Lokasi, Com2.Nama, Com2.BidakCom[0].Lokasi, Com2.BidakCom[1].Lokasi, Com2.BidakCom[2].Lokasi, Com2.BidakCom[3].Lokasi, Com3.Nama, Com3.BidakCom[0].Lokasi, Com3.BidakCom[1].Lokasi, Com3.BidakCom[2].Lokasi, Com3.BidakCom[3].Lokasi, urutan);		
			getch();
		}
		fclose(frec); //tutup file
	}
	data(pemain, Com1, Com2, Com3, urutan);
}

void HighScore(){
	FILE *frec;
	char Nama[50];
	int HighScore;
	system("cls");
	
	gotoxy(5,3); printf("            _    _ _       _                                      ");
	gotoxy(5,4); printf("           | |  | (_)     | |                                     ");
	gotoxy(5,5); printf("  ______   | |__| |_  __ _| |__  ___  ___ ___  _ __ ___    ______ ");
	gotoxy(5,6); printf(" |______|  |  __  | |/ _` | '_ \\/ __|/ __/ _ \\| '__/ _ \\  |______|");
	gotoxy(5,7); printf("           | |  | | | (_| | | | \\__ \\ (_| (_) | | |  __/          ");
	gotoxy(5,8); printf("           |_|  |_|_|\\__, |_| |_|___/\\___\\___/|_|  \\___|          ");
	gotoxy(5,9); printf("                      __/ |                                       ");
	gotoxy(5,10);printf("                     |___/                                        \n\n\n\n");
	
	
	if ((frec=fopen("HighScore.txt","rb"))==NULL)
		printf("File tidak dapat dibuka !");
	else
	{
		while(!feof(frec)) //cek apakah end of file ?
		{
			fscanf(frec, "%s %d\n", Nama, &HighScore);
			printf("\t\t\t%s\t\t%d\n", Nama, HighScore);
		}
		fclose(frec); //tutup file
	}
	
	getch();
	MainMenu(3);
}

void Credit(){
	system("cls");
	printf("\nGame ini dibuat untuk memenuhi tugas DDP Praktek semester 1\n");
	printf("Author : \n");
	printf("191524001 - Afdal Ramdan Daman Huri\n");
	printf("191524003 - Aldy Akbarrizky\n\n");
	printf("Tekan sembarang untuk kembali ... ");
	pilih = getche();
	MainMenu(4);
}

void Exit(){
	system("exit");
}

void Papan(struct User pemain){
	int com;
	system ("MODE 160,35");
	gotoxy(93,2); printf("ษอออออออออออออออออออออออปอออออออออออษอออออออออออออออออออออออป");	//atas
    gotoxy(93,3); printf("บ                       บ 12บ 13บ 1 บ                       บ");
    gotoxy(93,4); printf("บ  A. BASE : USER       บอออษอออออออป  B. BASE :            บ");
    gotoxy(93,5); printf("บ                       บ 11บ 14บ 2 บ                       บ");
    gotoxy(93,6); printf("บ     ษอออป   ษอออป     บอออบอออษอออผ     ษอออป   ษอออป     บ");
    gotoxy(93,7); printf("บ     บ A บ   บ B บ     บ 10บ 15บ 3 บ     บ A บ   บ B บ     บ");
    gotoxy(93,8); printf("บ     ศอออผ   ศอออผ     บอออบอออบอออบ     ศอออผ   ศอออผ     บ");
    gotoxy(93,9); printf("บ                       บ 9 บ 16บ 4 บ                       บ");
    gotoxy(93,10);printf("บ     ษอออป   ษอออป     บอออบอออบอออบ     ษอออป   ษอออป     บ");
    gotoxy(93,11);printf("บ     บ C บ   บ D บ     บ 8 บ 17บ 5 บ     บ C บ   บ D บ     บ");
    gotoxy(93,12);printf("บ     ศอออผ   ศอออผ     บอออบอออบอออบ     ศอออผ   ศอออผ     บ");
    gotoxy(93,13);printf("บ                       บ 7 บ 18บ 6 บ                       บ");
    gotoxy(93,14);printf("ศอออษอออปอออออออออออออออผอออศอออผอออศอออออออออออออออออออออออผ");
    
    gotoxy(93,15);printf("บ 1 บ 2 บ 3 บ 4 บ 5 บ 6 บ           บ 7 บ 8 บ 9 บ 10บ 11บ 12บ");	//tengah
    gotoxy(93,16);printf("บอออบอออศอออออออออออออออป           ษอออออออออออออออออออปอออบ");
    gotoxy(93,17);printf("บ 13บ 14บ 15บ 16บ 17บ 18บ     ?     บ 18บ 17บ 16บ 15บ 14บ 13บ");
    gotoxy(93,18);printf("บอออศอออออออออออออออออออผ           ศอออออออออออออออปอออบอออบ");
    gotoxy(93,19);printf("บ 12บ 11บ 10บ 9 บ 8 บ 7 บ           บ 6 บ 5 บ 4 บ 3 บ 2 บ 1 บ");
    
	gotoxy(93,20);printf("ศอออออออออออออออออออออออปอออษอออปอออษอออออออออออออออศอออผอออป");	//bawah
    gotoxy(93,21);printf("บ                       บ 6 บ 18บ 7 บ                       บ");
    gotoxy(93,22);printf("บ  D. BASE              บอออบอออบอออบ  C. BASE :            บ");
    gotoxy(93,23);printf("บ                       บ 5 บ 17บ 8 บ                       บ");
    gotoxy(93,24);printf("บ     ษอออป   ษอออป     บอออบอออบอออบ     ษอออป   ษอออป     บ");
    gotoxy(93,25);printf("บ     บ A บ   บ B บ     บ 4 บ 16บ 9 บ     บ A บ   บ B บ     บ");
    gotoxy(93,26);printf("บ     ศอออผ   ศอออผ     บอออบอออบอออบ     ศอออผ   ศอออผ     บ");
    gotoxy(93,27);printf("บ                       บ 3 บ 15บ 10บ                       บ");
    gotoxy(93,28);printf("บ     ษอออป   ษอออป     ษอออผอออบอออบ     ษอออป   ษอออป     บ");
    gotoxy(93,29);printf("บ     บ C บ   บ D บ     บ 2 บ 14บ 11บ     บ C บ   บ D บ     บ");
    gotoxy(93,30);printf("บ     ศอออผ   ศอออผ     ศอออออออผอออบ     ศอออผ   ศอออผ     บ");
    gotoxy(93,31);printf("บ                       บ 1 บ 13บ 12บ                       บ");
    gotoxy(93,32);printf("ศอออออออออออออออออออออออผอออออออออออศอออออออออออออออออออออออผ");
    
    //USER
    
    setcolor(12);
    
    if( strcmp(pemain.Warna, "Merah")==0 ){
    	printf("%s", pemain.Warna);
    	setcolor(12);
	}
	else if(strcmp(pemain.Warna, "Kuning")==0){
		setcolor(6);
	}
	else if(strcmp(pemain.Warna, "Hijau")==0){
		setcolor(10);
	}
	else if(strcmp(pemain.Warna, "Biru")==0){
		setcolor(9);
	}
	
    gotoxy(93,2); printf("ษอออออออออออออออออออออออป");
    gotoxy(93,3); printf("บ                       บ");
    gotoxy(93,4); printf("บ  A. BASE : USER       บ");
    gotoxy(93,5); printf("บ                       บ");
    gotoxy(93,6); printf("บ     ษอออป   ษอออป     บ");
    gotoxy(93,7); printf("บ     บ A บ   บ B บ     บ");
    gotoxy(93,8); printf("บ     ศอออผ   ศอออผ     บ");
    gotoxy(93,9); printf("บ                       บ");
    gotoxy(93,10);printf("บ     ษอออป   ษอออป     บ");
    gotoxy(93,11);printf("บ     บ C บ   บ D บ     บ");
    gotoxy(93,12);printf("บ     ศอออผ   ศอออผ     บ");
    gotoxy(93,13);printf("บ                       บ");
    gotoxy(93,14);printf("ศอออษอออปอออออออออออออออผ");
    
    gotoxy(97,14);printf("ษอออป");
    gotoxy(97,15);printf("บ 2 บ");
    gotoxy(97,16);printf("บอออศอออออออออออออออป");
    gotoxy(97,17);printf("บ 14บ 15บ 16บ 17บ 18บ");
    gotoxy(97,18);printf("ศอออออออออออออออออออผ");
    
    //COM 1
    setcolor(11);
    gotoxy(129,2); printf("ษอออออออออออออออออออออออป");
    gotoxy(129,3); printf("บ                       บ");
    gotoxy(129,4); printf("ป  B.                   บ");
    gotoxy(129,5); printf("บ                       บ");
    gotoxy(129,6); printf("ผ    ษอออป   ษอออป      บ");
    gotoxy(129,7); printf("บ    บ A บ   บ B บ      บ");
    gotoxy(129,8); printf("บ    ศอออผ   ศอออผ      บ");
    gotoxy(129,9); printf("บ                       บ");
    gotoxy(129,10);printf("บ    ษอออป   ษอออป      บ");
    gotoxy(129,11);printf("บ    บ C บ   บ D บ      บ");
    gotoxy(129,12);printf("บ    ศอออผ   ศอออผ      บ");
    gotoxy(129,13);printf("บ                       บ");
    gotoxy(129,14);printf("ศอออออออออออออออออออออออผ");
    
    gotoxy(121,4); printf("ษอออออออป");
    gotoxy(121,5); printf("บ 14บ 2 บ");
    gotoxy(121,6); printf("บอออษอออผ");
    gotoxy(121,7); printf("บ 15บ");
    gotoxy(121,8); printf("บอออบ");
    gotoxy(121,9); printf("บ 16บ");
    gotoxy(121,10);printf("บอออบ");
    gotoxy(121,11);printf("บ 17บ");
    gotoxy(121,12);printf("บอออบ");
    gotoxy(121,13);printf("บ 18บ");
    gotoxy(121,14);printf("ศอออผ");
    
    //COM 2
	setcolor(13);
	gotoxy(129,20);printf("ษอออออออออออออออศอออผอออป");
    gotoxy(129,21);printf("บ                       บ");
    gotoxy(129,22);printf("บ  C.                   บ");
    gotoxy(129,23);printf("บ                       บ");
    gotoxy(129,24);printf("บ                       บ");
    gotoxy(129,25);printf("บ                       บ");
    gotoxy(129,26);printf("บ                       บ");
    gotoxy(129,27);printf("บ                       บ");
    gotoxy(129,28);printf("บ                       บ");
    gotoxy(129,29);printf("บ                       บ");
    gotoxy(129,30);printf("บ                       บ");
    gotoxy(129,31);printf("บ                       บ");
    gotoxy(129,32);printf("ศอออออออออออออออออออออออผ");
	
    gotoxy(129,16);printf("ษอออออออออออออออออออป");
    gotoxy(129,17);printf("บ 18บ 17บ 16บ 15บ 14บ");
    gotoxy(129,18);printf("ศอออออออออออออออปอออบ");
    gotoxy(145,19);printf("บ 2 บ");
	gotoxy(145,20);printf("ศอออผ");
	
	//COM 3
	setcolor(14);
	gotoxy(93,20);printf("ษอออออออออออออออออออออออป");
    gotoxy(93,21);printf("บ                       บ");
    gotoxy(93,22);printf("บ  D.                   บ");
    gotoxy(93,23);printf("บ                       บ");
    gotoxy(93,24);printf("บ                       บ");
    gotoxy(93,25);printf("บ                       บ");
    gotoxy(93,26);printf("บ                       บ");
    gotoxy(93,27);printf("บ                       บ");
    gotoxy(93,28);printf("บ                       ษ");
    gotoxy(93,29);printf("บ                       บ");
    gotoxy(93,30);printf("บ                       ศ");
    gotoxy(93,31);printf("บ                       บ");
    gotoxy(93,32);printf("ศอออออออออออออออออออออออผ");
	
    gotoxy(121,20);printf("ษอออป");
    gotoxy(121,21);printf("บ 18บ");
    gotoxy(121,22);printf("บอออบ");
    gotoxy(121,23);printf("บ 17บ");
    gotoxy(121,24);printf("บอออบ");
	gotoxy(121,25);printf("บ 16บ");
	gotoxy(121,26);printf("บอออบ");
	gotoxy(121,27);printf("บ 15บ");
	gotoxy(117,28);printf("ษอออผอออบ");
	gotoxy(117,29);printf("บ 2 บ 14บ");
	gotoxy(117,30);printf("ศอออออออผ");
	
	setcolor(15);
    
    gotoxy(30,35);printf(" ");
    
    if(com==1){
    	
	}
}

void gameOver(struct User pemain, struct Com Com1, int winner){
	FILE *frec;
	
	system("cls");
	gotoxy(5,3); printf("__________                            .__                      ");
	gotoxy(5,4); printf("\\______   \\ ___________  _____ _____  |__| ____ _____    ____  ");
	gotoxy(5,5); printf(" |     ___// __ \\_  __ \\/     \\\\__  \\ |  |/    \\\\__  \\  /    \\ ");
	gotoxy(5,6); printf(" |    |   \\  ___/|  | \\/  Y Y  \\/ __ \\|  |   |  \\/ __ \\|   |  \\");
	gotoxy(5,7); printf(" |____|    \\___  >__|  |__|_|  (____  /__|___|  (____  /___|  /");
	gotoxy(5,8); printf("               \\/            \\/     \\/        \\/     \\/     \\/ ");
	setcolor(12);
	gotoxy(5,9); printf("        _________      .__                        .__          ");
	gotoxy(5,10);printf("       /   _____/ ____ |  |   ____   ___________  |__|         ");
	gotoxy(5,11);printf("       \\_____  \\_/ __ \\|  | _/ __ \\ /  ___/\\__  \\ |  |         ");
	gotoxy(5,12);printf("       /        \\  ___/|  |_\\  ___/ \\___ \\  / __ \\|  |         ");
	gotoxy(5,13);printf("      /_______  /\\___  >____/\\___  >____  >(____  /__|         ");
	gotoxy(5,14);printf("              \\/     \\/          \\/     \\/      \\/             ");
	
	if( winner==1 )
	{
		printf("\nSelamat! Anda memenangkan games ini dengan Score %d\n", pemain.Score);
	} else
	{
		printf("Sayang Sekali, anda kalah! Score anda adalah %d\n", pemain.Score);
	}
	if((frec=fopen("HighScore.txt", "ab")) != NULL)
	{
		fprintf(frec, "%s\t\t%d\n", pemain.Nama, pemain.Score);
	} else
	{
		printf("Pembuatan File Gagal !\n");
		system("exit");	
	}
	fclose(frec);
	printf("Tekan sembarang untuk kembali ... ");
	pilih = getche();
	MainMenu(3);
	
}

void random(){
	int i,x;
	
	for(i=0;i<1;i--){
		system("cls");
		x = rand()%6+1;
		printf("%d\n", x);
		sleep(1);
	}
	
	do{
		system("cls");
		x = rand()%6+1;
		printf("%d\n", x);
		printf("Press any key ...");
		pilih = getche();
	}while(!(pilih=='1'));
	
	if(pilih=='1'){
		system("exit");
	}
}

void save(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3, int urutan){
	FILE *frec;
	
	if((frec=fopen("Save.txt", "wb")) != NULL)
	{
		fprintf(frec, "%s %s %d %d %d %d %d %s %d %d %d %d %s %d %d %d %d %s %d %d %d %d %d\n", pemain.Nama, pemain.Warna, pemain.Score, pemain.BidakUser[0].Lokasi, pemain.BidakUser[1].Lokasi, pemain.BidakUser[2].Lokasi, pemain.BidakUser[3].Lokasi, Com1.Nama, Com1.BidakCom[0].Lokasi, Com1.BidakCom[1].Lokasi, Com1.BidakCom[2].Lokasi, Com1.BidakCom[3].Lokasi, Com2.Nama, Com2.BidakCom[0].Lokasi, Com2.BidakCom[1].Lokasi, Com2.BidakCom[2].Lokasi, Com2.BidakCom[3].Lokasi, Com3.Nama, Com3.BidakCom[0].Lokasi, Com3.BidakCom[1].Lokasi, Com3.BidakCom[2].Lokasi, Com3.BidakCom[3].Lokasi, urutan);
	} else
	{
		printf("Pembuatan File Gagal !\n");
		system("exit");	
	}
	
	fclose(frec);
}
