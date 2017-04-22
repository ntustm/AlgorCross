# Title:
# Author: Willis Chu

#include <stdio.h>

const int SPACE_SIZE = 27;
const int NOT_MATCH = -1;

typedef struct TrieNode{ 
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
int insertWord(Trie root, char* word, int id){ 
	CtwNode* node = root; 
	int pos; 
	bool is_after_space = false; 
	char *p = word; 
	pos = (' '==*p) ? (SPACE_SIZE-1) : (*p-'a'); 
	while(*p){  
		if(NULL==node->next[pos]) {   
			node->next[pos] = createNode();   
			node->overlap = false;   
			node->id = id;  
		}  // magic  
		if (*p == ' ') {   
			is_after_space = true;  
		}  
		p++;  
		if (*p == '\0') {   
			node->overlap = is_after_space;  
		}  // end magic  
		node = node->next[pos];  
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

int insertAllPatern_1 (char* cmd, int len_cmd) { 
	for (int i = 0; i < len_cmd; ++i) { 
	}
}

int insertAllPatern_2 (char* cmd, char* opt, int len_cmd, int len_opt) { 
	for (int i = 0; i < count; ++i) {  
		for (int j = 0; j < count; ++j) {
		} 
	}
}

int main(void){ 
	int i,j; 
	CtwNode* root_node = createNode(); 
	char *strCmdList[6] = {  
		"reset",  
		"reset board",  
		"board add",  
		"board delet",  
		"reboot backplane",  
		"backplane abort"  
	} 
	char *strResList[7] = {  
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

