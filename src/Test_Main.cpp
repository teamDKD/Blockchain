#include <fstream>
#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include "sha256.h"
#define Hash_Len 64
#define Max_Info 1024
using namespace std;

FILE * stream = fopen("Blocks/Block.txt", "wt");
//FILE * LogFile = fopen("Log/log.txt", "r+");

char* PreviousHash();
char* Address_P();
char* Address_H();
char* HeaderHash(char* _merkletree, char* _previoushash,char* _address_p,char* _address_h);
void makeBody();
void recordlog();

//class block {
//private:
//	char* MerkleTree;
//	char* PreviousHash;
//	char* P_add;
//	char* H_add;
//	char* HeaderHash;
//public:
//	block(char* _MerkleTree, char* _PreviousHash, char* _P_add, char* _H_add, char* _HeaderHash);
//	/*void makeBlock();*/
//};

class HashTree {
private:
	char* Tree[Hash_Len];
	char* dataset[100];
public:
	char* MerkleTree();
};

int main() {
	HashTree HT;
	char* Final_Merkle_Tree = HT.MerkleTree();
	char* Final_Previous_Hash = PreviousHash();
	char* Final_Address_P = Address_P();
	char* Final_Address_H = Address_H();
	char* Final_HeaderHash = HeaderHash(Final_Merkle_Tree, Final_Previous_Hash,Final_Address_P,Final_Address_H);
	makeBody();
	recordlog();

	//block block(Final_Merkle_Tree, Final_Previous_Hash, Final_Address_P, Final_Address_H, Final_HeaderHash);

	/*block.makeBlock();*/

	return 0;
}

//block::block(char* _MerkleTree, char* _PreviousHash, char* _P_add, char* _H_add, char* _HeaderHash) {
//	char* MerkleTree = _MerkleTree;
//	char* PreviousHash = _PreviousHash;
//	char* P_add = _P_add;
//	char* H_add = _H_add;
//	char* HeaderHash = _HeaderHash;
//}

char* HashTree::MerkleTree() {
	char info[Max_Info];
	int i = 0;
	FILE * txop = fopen("Info/info.txt", "rt");
	string data;
	char *merkle;
	while (!feof(txop)) {
		merkle = fgets(info, sizeof(info), txop);
		dataset[i] = merkle;
		data += string(dataset[i]);
		i++;
	}
	string output = sha256(data);

	vector<char> outtochar(output.begin(), output.end());
	outtochar.push_back('\0');
	char* finalout = &outtochar[0];

	fclose(txop);

	fprintf(stream, "MerkleTree: %s\n\n\n", finalout);
	return finalout;
}

char* PreviousHash() {
	char _previousHash[Hash_Len];

	FILE * blop = fopen("Info/previousHash.txt", "rt");
	fgets(_previousHash, Hash_Len, blop);

	fprintf(stream, "PreviousHash: %s\n\n\n", _previousHash);
	return _previousHash;
}

char* Address_P() {
	char address_p[Hash_Len];

	FILE * adop_p = fopen("Info/P_add.txt", "rt");
	fgets(address_p, Hash_Len, adop_p);
	
	fprintf(stream, "Patient Address: %s\n\n\n", address_p);
	return address_p;
}

char* Address_H() {
	char address_h[Hash_Len];

	FILE * adop_h = fopen("Info/H_add.txt", "rt");
	fgets(address_h, Hash_Len, adop_h);
	
	fprintf(stream, "Hospital Address: %s\n\n\n",address_h);
	return address_h;
}

char* HeaderHash(char* _merkletree, char* _previoushash, char* _address_p, char* _address_h) {
	string shaoutput = sha256(string(_merkletree) + string(_previoushash) + string(_address_p) + string(_address_h));

	vector<char> outtochar(shaoutput.begin(), shaoutput.end());
	outtochar.push_back('\0');
	char* finalout = &outtochar[0];
	
	fprintf(stream, "HeaderHash: %s\n\n\n", finalout);
	return finalout;
}

void makeBody() {
	char info[Max_Info];
	int i = 0;
	FILE * body = fopen("Info/info.txt", "rt");
	string data;
	char* dataset[100];
	char *merkle;
	while (!feof(body)) {
		merkle = fgets(info, sizeof(info), body);
		dataset[i] = merkle;
		fprintf(stream, "Body_%d: %s\n\n",i, dataset[i]);
		i++;
	}

}

//void recordlog() {
//	char info[2];
//	char* number = fgets(info,sizeof(info),LogFile);
//	cout << number;
//	int nonce = atoi(number);
//	fprintf(LogFile, "%d",nonce+1);
//	fclose(LogFile);
//}
//void block::makeBlock() {
//	FILE * stream = fopen("Block.txt", "wt");
//	
//	cout << HeaderHash << endl;
//	cout << PreviousHash << endl;
//	cout << MerkleTree << endl;
//	cout << P_add << endl;
//	cout << H_add << endl;
//
//	fprintf(stream, "HeaderHash: %s\n", HeaderHash);
//	fprintf(stream, "PreviousHash: %s\n", PreviousHash);
//	fprintf(stream, "MerkleTree: %s\n", MerkleTree);
//	fprintf(stream, "Patient Address: %s\n", P_add);
//	fprintf(stream, "Hospital Address: %s\n", H_add);
//
//	fclose(stream);
//}
