#ifndef _HashSep_H
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(int key, HashTable H);
void Insert(int key, HashTable H);
int Retrieve(Position P);

struct ListNode
{
	int data;
	Position next;
};
typedef Position List;
struct HashTbl 
{
	int TableSize;
	List *TheList;
};
#endif // !_HashSep_H
