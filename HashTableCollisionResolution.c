#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define TABLE_SIZE 5
#define HASH_CONSTANT 179  //Random Number

typedef struct HashNode{
    char* key;
    int value;
} HashNode;

HashNode* HashTable[TABLE_SIZE];

unsigned int hash(char* key){
    int keySize=strlen(key);
    unsigned int hashValue=0;
    for(int i=0;i<keySize;i++){
        hashValue+=key[i];
        hashValue=(hashValue*HASH_CONSTANT)%TABLE_SIZE;
    }
    return hashValue;
}

HashNode* createNode(char* key,int value){
    HashNode* newNode=(HashNode*)malloc(sizeof(HashNode));
    newNode->key=strdup(key);  //If we dont use strdup(Duplicate String), The pointer to the string never changes so every new value is stored in same address
    newNode->value=value;
    return newNode;
}

//Open Addressing, Used Linear Probing
bool insert(char* key,int value){
    HashNode* newNode=createNode(key,value);
    if(newNode == NULL) return false;

    int index=hash(newNode->key);
    if(HashTable[index]!=NULL && strcmp(HashTable[index]->key,key)==0) return false;
    for(int i=0;i<TABLE_SIZE;i++){
        int try=(index+i)%TABLE_SIZE;
        if(HashTable[try]==NULL){
            HashTable[try]=newNode;
            return true;
        }
    }

    return false;
}

HashNode* search(char* key){
    int index=hash(key);

    for(int i=0;i<TABLE_SIZE;i++){
        int try=(index+i)%TABLE_SIZE;
        if(HashTable[try]!=NULL && strcmp(HashTable[try]->key,key)==0){
            return HashTable[try];
        }
    }
    return NULL;
}

bool delete(char* key){
    int index=hash(key);
    for(int i=0;i<TABLE_SIZE;i++){
        int try=(index+i)%TABLE_SIZE;
        if(HashTable[try]!=NULL && strcmp(HashTable[try]->key,key)==0){
            free(HashTable[try]->key);
            HashTable[try]=NULL;
            return true;
        }
    }
    return false;
}

void initHashTable(){
    for(int i=0;i<TABLE_SIZE;i++){
        HashTable[i]=NULL;
    }
}

void printTable(){
    for(int i=0;i<TABLE_SIZE;i++){
        if(HashTable[i]==NULL) printf("\t%d\t-----\n",i);
        else printf("\t%d\t%s\t%d\n",i,HashTable[i]->key,HashTable[i]->value);
    }
}

int main(){

    initHashTable();

    for(int i=0;i<TABLE_SIZE;i++){
        char tempKey[100];
        int tempValue;
        printf("Enter the Key: "); scanf("%99s",tempKey);
        printf("Enter the Value: "); scanf("%d",&tempValue);
        if(!insert(tempKey,tempValue)){ 
            printf("Duplicate Value: Not Inserted\n");
            i--;
        }else printf("Data Inserted\n");
    }
    printf("Table:\n");
    printTable();
    
    HashNode* found=search("Sinchan");
    if(found==NULL) printf("Not Found\n");
    else printf("Found: %s\t%d\n",found->key,found->value);

    bool deleted=delete("Ayush");
    if(!deleted) printf("Not Found\n");
    else printf("Data Deleted\n");
    printf("Table After Deletion:\n");
    printTable();
    return 0;
}