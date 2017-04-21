# Title:
# Author: Willis Chu

#include <stdio.h>

const int SPACE_SIZE = 27;
const int NOT_MATCH = -1;

typedef struct TrieNode
{
	int id;
	bool overlap;
	struct TrieNode *next[SPACE_SIZE];//26 letters + blank
} CtwNode, *Trie;

CtwNode* createNode() {
	CtwNode* currNode = (CtwNode*)malloc(sizeof(CtwNode));
	currNode->overlap = 0;
	memset(currNode->next, 0, sizeof(currNode->next));
	return currNode;
}

int insertNode(Trie root, char* word, int id){
	CtwNode* node = root;
	int pos;
	char *p = word;
	pos = (' '==*p) ? (SPACE_SIZE-1) : (*p-'a');
	while(*p){
		if(NULL==node->next[pos]) {
			node->next[pos] = createNode();
			node->overlap = false;
			node->id = id;
		}
		node = node->next[pos]; 
		p++;
	}
	return 0;
}

int searchTrie(Trie root, char* word) {
	CtwNode* node = root;
	char *p = word;  
    while(*p && (NULL!=node)) { 
		pos = (' '==*p) ? (SPACE_SIZE-1) : (*p-'a');
        node = node->next[pos];  
        p++; 
    }
    if (NULL == node)
    	return NOT_MATCH
    else if (node->overlap)
    	return NOT_MATCH;
    else
    	return node->id;
}

int main(void)
{
	int cnt;
	char *strCmdList[6] = {
		"reset",
		"reset board",
		"board add",
		"board delet",
		"reboot backplane",
		"backplane abort" 
	}
	char strResList[7] = {
		"reset what",
		"board fault",
		"where to add",
		"no board at all",
		"impossible",
		"install first",
		"unkown command"
	}

	for (cnt=0;cnt<6;cnt++) {
		strCmdList[cnt]
	}
	return 0;
}
