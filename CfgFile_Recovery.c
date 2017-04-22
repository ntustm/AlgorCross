/// Title:
// Author: Willis Chu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE_SIZE	27
#define NOT_MATCH	-1
#define false		0
#define true		1

typedef struct TrieNode
{
	int id;
	int valid;
	struct TrieNode* next[SPACE_SIZE];//26 letters + blank
} CtwNode, *Trie;

CtwNode* createNode() {
	CtwNode* currNode = (CtwNode*)malloc(sizeof(CtwNode));
	currNode->valid = false;
	memset(currNode->next, 0, sizeof(currNode->next));
	return currNode;
}

int insertWord(Trie root, char* word, int id){
	CtwNode* node = root;
	int pos;
	int is_after_space = false;
	int is_first_visit = true;
	char *p = word;
	while(*p){
		if (*p == ' ') {
			is_after_space = true; //set and hold
			pos = SPACE_SIZE-1;
		}
		else {
			pos = *p-'a';
		}
		// self-add advacned to confirm if next char is '\0'
		p++; 
		// new node
		if(NULL==node->next[pos]) {
			node->next[pos] = createNode();	
			node = node->next[pos]; 
			node->id = id;
			if (*p == '\0') {
				node->valid = true;
			}
			else
				node->valid = false;	
		}
		else {
			node = node->next[pos];
			if ((*p == '\0') && (is_after_space)) {
			//if (*p == '\0' ) {
				node->valid = false;
			}
		}
	}
	return 0;
}

int searchTrie(Trie root, char* word) {
	CtwNode* node = root;
	char *p = word;  
	int pos;
    while(*p && (NULL!=node)) { 
		pos = (' '==*p) ? (SPACE_SIZE-1) : (*p-'a');
        node = node->next[pos];  
        p++; 
    }
    if (NULL == node)
    	return -2;
    else if (node->valid)
    	return node->id;
    else
    	return -3;
}

int insertAllPatern_1 (Trie root, int id, char* cmd, int len_cmd) {
	char tmp_str[16];
	int i;
	CtwNode* root_tmp = root;
	strcpy(tmp_str, cmd);
	for (i = 0; i < len_cmd; ++i) {
		tmp_str[len_cmd-i]='\0';
		insertWord(root_tmp, tmp_str, id);	
	}
	return 0;
}

int insertAllPatern_2 (Trie root, int id, char* cmd, int len_cmd, char* opt, int len_opt) {
	char tmp_str[32];
	char cmd_tmp[16];
	char opt_tmp[16];
	int i,j;
	CtwNode* root_tmp = root;
	strcpy(cmd_tmp, cmd);
	strcpy(opt_tmp, opt);
	for (i = 0; i < len_cmd; ++i) {
		cmd_tmp[len_cmd-i]='\0';
		strcpy(opt_tmp, opt);	
		for (j = 0; j < len_opt; ++j) {
			opt_tmp[len_opt-j]='\0';
			strcpy(tmp_str, cmd_tmp);
			strcat(tmp_str, " \0");
			strcat(tmp_str, opt_tmp);
			insertWord(root_tmp, tmp_str, id);			
		}
	}
	return 0;
}

void DBG(char*);

int main(void)
{
	int i,j;
	CtwNode* root_node = createNode();
	char instr[256];
	char *strCmdList[6] = {
		"reset",
		"reset board",
		"board add",
		"board delet",
		"reboot backplane",
		"backplane abort" 
	};
	char *strResList[7] = {
		"reset what",
		"board fault",
		"where to add",
		"no board at all",
		"impossible",
		"install first",
		"unkown command"
	};
	// initial trie tree
	insertAllPatern_1 (root_node, 0, "reset\0", 5);
	insertAllPatern_2 (root_node, 1, "reset\0", 5, "board\0", 5);
	insertAllPatern_2 (root_node, 2, "board\0", 5, "add\0", 3);
	insertAllPatern_2 (root_node, 3, "board\0", 5, "delet\0", 5);
	insertAllPatern_2 (root_node, 4, "reboot\0", 6, "backplane\0", 9);
	insertAllPatern_2 (root_node, 5, "backplane\0", 9, "abort\0", 5);
printf("InputCMD:\n");
	while(NULL != gets(instr)) {
		i = searchTrie(root_node, instr);
		if (i>NOT_MATCH) 
			printf("%s\n", strResList[i]);
		else
			printf("%s\n", strResList[6]);	
	}
	return 0;
}

void DBG(char* str) {
	printf("%s\npress any key to continue\n", str);
	getch();
}
