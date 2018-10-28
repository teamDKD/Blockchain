//#include <fstream>
//#include <iostream>
//#include<vector>
//#include "sha256.h"
//#define Hash_Len 64
//#define Max_Info 1024
//using namespace std;
//
//
//class block {
//private:
//	char HeaderHash[Hash_Len];
//	char PreHash[Hash_Len];
//	char MerkleRoot[Hash_Len];
//	char P_add[Hash_Len];
//	char H_add[Hash_Len];
//public:
//	block(char _HeaderHash[Hash_Len], char _PreHash[Hash_Len], char _MerkleRoot[Hash_Len], char _P_add[Hash_Len], char _H_add[Hash_Len]);
//	void makeBlock();
//};
//
//class merkle {
//private:
//	char MerkleRoot[Hash_Len];
//	char *dataset[100];
//public:
//	char* MerkleTree();
//	char* makeMerkleTree();
//};
//
//
//char* getheadhash(char* MerkleTree[Hash_Len], char P_add[Hash_Len], char H_add[Hash_Len], char PreHash[Hash_Len]);
//char* getpadd();
//char* gethadd();
//char* getprehash();
//
//int main(){
//	merkle mk;
//
//	char* preHash[Hash_Len] ; //complete
//	char* p_add[Hash_Len] ; //complete
//	char* h_add[Hash_Len] ;//complete
//	char* merkletree[Hash_Len];
//	char* headHash[Hash_Len];
//	preHash[Hash_Len] = getprehash(); //complete
//	p_add[Hash_Len] = getpadd(); //complete
//	h_add[Hash_Len] = gethadd();//complete
//	merkletree[Hash_Len] = mk.MerkleTree();
//	headHash[Hash_Len] = getheadhash(merkletree, p_add, h_add, preHash);
//
//	block block(headHash, preHash, merkletree, p_add, h_add);
//	block.makeBlock();
//
//	return 0;
//}
//
//
//
//block::block(char _HeaderHash[Hash_Len], char _PreHash[Hash_Len], char _MerkleRoot[Hash_Len], char _P_add[Hash_Len], char _H_add[Hash_Len]) {
//	HeaderHash[Hash_Len] = _HeaderHash[Hash_Len];
//	PreHash[Hash_Len] = _PreHash[Hash_Len];
//	MerkleRoot[Hash_Len] = _MerkleRoot[Hash_Len];
//	P_add[Hash_Len] = _P_add[Hash_Len];
//	H_add[Hash_Len] = _H_add[Hash_Len];
//}
//
//
//
//char* merkle::MerkleTree() {
//	char info[Max_Info];
//	int i = 0;
//	FILE * txop = fopen("Info/info.txt", "rt");
//	
//	char *merkle;
//	while (!feof(txop)) {
//		merkle = fgets(info, sizeof(info), txop);
//		dataset[i] = merkle;
//		i++;
//	}
//
//	makeMerkleTree();
//}
//
//
//
//char* merkle::makeMerkleTree() {
//	for (int i = 0;; i++) {
//		string data = string(dataset[2 * i]) + string(dataset[2 * i + 1]);
//		string shainfo = sha256(data);
//		dataset[i] = new char[shainfo.length() + 1];
//	}
//}
//
//
//
//char* getheadhash(char* MerkleTree[Hash_Len], char P_add[Hash_Len], char H_add[Hash_Len], char PreHash[Hash_Len]) {
//	string headerhash  = sha256(MerkleTree + P_add + H_add + PreHash);
//
//	vector<char> writable(headerhash.begin(), headerhash.end());
//	writable.push_back('\0');
//	char* output = &writable[0];
//
//	return output;
//}
//
//
//
//char* gethadd() {
//	char H_address[Hash_Len];
//	FILE * H_add = fopen("Info/H_add.txt", "rt");
//	if (H_add == NULL) {
//		cout << "Can't open H_add File" << endl;
//		return 0;
//	}
//
//	fgets(H_address, Hash_Len, H_add);
//
//	return H_address;
//}
//
//
//char* getpadd() {
//	char P_address[Hash_Len];
//	FILE * P_add = fopen("Info/P_add.txt", "rt");
//
//	if (P_add == NULL) {
//		cout << "Can't open P_add File" << endl;
//		return 0;
//	}
//
//	fgets(P_address, Hash_Len, P_add);
//
//	return P_address;
//}
//
//
//char* getprehash() {
//	char _preHash[Hash_Len];
//
//	FILE * prehash = fopen("Info/previousHash.txt", "rt");
//
//	if (prehash == NULL) {
//		cout << "Can't read File";
//		return 0;
//	}
//
//	fgets(_preHash, Hash_Len, prehash);
//
//	return _preHash;
//}
//
//void block::makeBlock() {
//
//}