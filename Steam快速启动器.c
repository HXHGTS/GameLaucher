#include<stdio.h>
#include<stdlib.h>

char run[150];
int main() {
	int mode,gameid;
	system("title Steam快速启动器");
	AuthUser();
	SteamFinder();
	p2:printf("请选择运行模式：\n1.启动Steam\n2.Steam主页\n3.快速启动Steam游戏\n4.快速启动Uplay游戏\n5.腾讯手游助手\n6.MFA令牌\n请选择：");
	scanf("%d", &mode);
	if (mode == 1) {
		RunSteam();
		system("cls");
		goto p2;
	}
	else if (mode == 2) {
		sprintf(run, "explorer https://store.steampowered.com");
		system(run);
		system("cls");
		goto p2;
	}
	else if (mode == 3) {
		system("cls");
		printf("请选择要打开的游戏：\n1.侠盗猎车手 5\n2.怪物猎人 世界\n3.绝地求生大逃杀\n4.古墓丽影 崛起\n5.饥荒\n请选择：");
		scanf("%d", &gameid);
		SteamLaucher(gameid);
		system("cls");
		goto p2;
	}
	else if (mode == 4) {
		system("cls");
		printf("请选择要打开的游戏：\n1.彩虹六号 围攻\n2.荣耀战魂\n3.极限巅峰\n4.刺客信条 起源\n5.刺客信条 奥德赛\n请选择：");
		scanf("%d", &gameid);
		UplayLaucher(gameid);
		system("cls");
		goto p2;
	}
	else if (mode == 5) {
		system("cls");
		EmulatorLaucher();
		system("cls");
		goto p2;
	}
	else if (mode == 6) {
		system("cls");
		AuthyLaucher();
		system("cls");
		goto p2;
	}
	system("cls");
	return 0;
}

int RunSteam() {
	int userinfo;
	char steamid[15], steampw[31];
	FILE* loginfo;
	if ((loginfo = fopen("RunSteam.bat","r")) == NULL) {
		printf("第一次使用本功能，");
		p3:printf("请输入Steam登录信息，账号密码间用空格隔开\n");
		scanf("%s %s", steamid, steampw);
		loginfo = fopen("RunSteam.bat", "w");
		fprintf(loginfo, "@echo off\nsteam.lnk -login %s %s",steamid,steampw);
		fclose(loginfo);
		printf("登录信息已保存，下次可直接登录Steam\n");
		sprintf(run, "steam.lnk -login %s %s", steamid, steampw);
		printf("正在登录Steam. . .\n");
		system(run);
	}
	else {
		printf("检测到上次登录的用户id与密码，是否直接登录（是=1，否=0）：\n");
		scanf("%d", &userinfo);
		if (userinfo == 1) {
			sprintf(run, "%s", "RunSteam.bat");
			printf("正在登录Steam. . .\n");
			system(run);
		}
		else {
			goto p3;
		}
	}
}

int SteamFinder() {
	char SteamClient[100];
	FILE* steamlink;
p1:if ((steamlink = fopen("steam.lnk", "r")) == NULL) {
		printf("请将Steam的快捷方式拖拽到在本窗口中\n");
		scanf("%s", SteamClient);
		sprintf(run, "copy \"%s\" steam.lnk", SteamClient);
		printf("正在执行：%s", run);
		system(run);
		system("cls");
		goto p1;
	}
	return 0;
}

int SteamLaucher(int gameid) {
	if (gameid == 1) {
		printf("正在打开GTA V. . .\n");
		system("explorer \"steam://rungameid/271590\"");
	}
	else if (gameid == 2) {
		printf("正在打开MonsterHunter World. . .\n");
		system("explorer \"steam://rungameid/582010\"");
	}
	else if (gameid == 3) {
		printf("正在打开PLAYERUNKNOWN'S BATTLEGROUNDS. . .\n");
		system("explorer \"steam://rungameid/578080\"");
	}
	else if (gameid == 4) {
		printf("正在打开Rise of the Tomb Raider. . .\n");
		system("explorer \"steam://rungameid/391220\"");
	}
	else if (gameid == 5) {
		printf("正在打开Don't Starve. . .\n");
		system("explorer \"steam://rungameid/219740\"");
	}
	return 0;
}

int UplayLaucher(int gameid) {
	if (gameid == 1) {
		printf("正在打开彩虹六号 围攻. . .\n");
		system("explorer \"uplay://launch/635/0\"");
	}
	return 0;
}

int EmulatorLaucher() {
	char EmulatorClient[100];
	FILE* syzslink;
p4:if ((syzslink = fopen("syzs.lnk", "r")) == NULL) {
	printf("请将腾讯手游助手的快捷方式拖拽到在本窗口中\n");
	scanf("%s", EmulatorClient);
	sprintf(run, "copy \"%s\" syzs.lnk", EmulatorClient);
	system(run);
	system("cls");
	goto p4;
}
	system("syzs.lnk");
	return 0;
}

int AuthyLaucher() {
	char AuthyClient[100];
	FILE* authylink;
p5:if ((authylink = fopen("authy.lnk", "r")) == NULL) {
	printf("请将Authy的快捷方式拖拽到在本窗口中\n");
	scanf("%s", AuthyClient);
	sprintf(run, "copy \"%s\" Authy.lnk", AuthyClient);
	system(run);
	system("cls");
	goto p5;
}
	system("Authy.lnk");
	return 0;
}

int AuthUser() {
	int pw;
	printf("请输入启动密码：");
	scanf("%d", &pw);
	if (pw != 1330213302) {
		exit(0);
	}
	system("cls");
}