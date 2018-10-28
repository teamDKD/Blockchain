//#include<iostream>
//#include<stdio.h>
//#define HASH_LEN 64
//using namespace std;
//
//int main() {/*
//	char information[HASH_LEN];
//
//	FILE *fp;
//	fopen_s(&fp,"Info/info.txt", "rt");
//
//	if (fp == NULL) {
//		cout << "¿¡·¯";
//		return 1;
//	}
//
//	fgets(information,HASH_LEN, fp);
//
//	printf("%s\n", information);
//	return 0;
//
//		int val[1000];
//		int i, j;
//		char filename[100];
//		FILE *fp;
//
//		for (i = 0; i < 1000; i++)
//			val[i] = i;
//
//		for (i = 0; i < 20; i++) {
//			sprintf(filename, "kosicheol-%d.txt", i);
//			fp = fopen(filename, "w");
//			if (!fp)
//				continue;
//			for (j = 0; j < 50; j++)
//				fprintf(fp, "%d\n", val[50 * i + j]);
//			fclose(fp);
//		}
//
//*/
//	char info[255];
//
//	FILE * txop = fopen("Info/info.txt", "rt");
//
//	char *merkle;
//
//	while (!feof(txop)) {
//		merkle = fgets(info, sizeof(info), txop);
//
//	}
//
//	
//	
//
//		return 0;
//}