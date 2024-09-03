struct item {
    int v;
    struct item* n;
};

struct hash_table {
    struct item** table;
    unsigned int size;
    unsigned int last;
};

int hash_function(int key, int table_size);
struct hash_table* create_table();
void hash_insert(struct hash_table* t, int value);
void rehash(struct hash_table* t);
int hash_search(struct hash_table* t, int key);
void free_hash_table(struct hash_table* t);
void print_hash_table(struct hash_table* t);


void measure_tda(void);
void measure_tdw(void);