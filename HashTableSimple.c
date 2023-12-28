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

bool insert(char* key,int value){
    HashNode* newNode=createNode(key,value);
    if(newNode == NULL) return false;

    int index=hash(newNode->key);
    if(HashTable[index]!=NULL) return false;

    HashTable[index]=newNode;
    return true;
}

HashNode* search(char* key){
    int index=hash(key);
    HashNode* found=HashTable[index];
    if(found==NULL || strcmp(found->key,key)!=0) return NULL;
    return found;
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
    // printf("%u\n",hash("Sinchan"));
    // printf("%u\n",hash("Alapan"));
    // printf("%u\n",hash("Ayush"));
    // printf("%u\n",hash("Sinchan"));

    initHashTable();

    // insert("Sinchan",10);
    // insert("Alapan",14);
    // insert("Ayush",13);
    // insert("Sinchan",15);

    for(int i=0;i<TABLE_SIZE;i++){
        char tempKey[100];
        int tempValue;
        printf("Enter the Key: "); scanf("%99s",tempKey);
        printf("Enter the Value: "); scanf("%d",&tempValue);
        if(!insert(tempKey,tempValue)) printf("Conflict Occured: Not Inserted\n");
        else printf("Data Inserted\n");
    }

    printTable();
    
    HashNode* found=search("3");
    if(found==NULL) printf("Not Found\n");
    else printf("Found: %s\t%d\n",found->key,found->value);
    return 0;
}