typedef struct {
    char name[20];
    int key;
} Item ;

typedef struct {
    Item *v;
    int n, size;
} PQ ;

typedef PQ * pq_ptr;

pq_ptr createPQ(int size);

void insertPQ(pq_ptr pq, Item item);

Item extractMaximumPQ(pq_ptr pq);

int emptyPQ(pq_ptr pq);

int fullPQ(pq_ptr pq);

void destroyPQ(pq_ptr pq);

void insertPQHeap(pq_ptr pq, Item item);

Item extractMaximumPQHeap(pq_ptr pq);

void changePriority(pq_ptr pq, int k, int val);

#define FATHER(i) ((i - 1)/2)

#define LEFT_CHILD(i) (2*i + 1)

#define RIGHT_CHILD(i) (2*i + 2)