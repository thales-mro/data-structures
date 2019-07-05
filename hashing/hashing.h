#define MAX 1783

typedef struct {
    char key[10];
    int data;
    Node * next;
} Node;

typedef Node * node_ptr;

typedef struct {
    node_ptr vector[MAX];
} Hash;

typedef Hash * hash_ptr;

hash_ptr createHash();

void destroyHash(hash_ptr t);

void insert(hash_ptr t, char *key, int data);

void remove(hash_ptr t, char *key);

node_ptr search(hash_ptr t, char *key);