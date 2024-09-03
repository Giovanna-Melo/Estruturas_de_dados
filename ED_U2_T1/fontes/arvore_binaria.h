struct node {
    int v;
    struct node *l;
    struct node *r;
};

struct node* new_node(int value);
void btinsert(struct node** r, struct node* n);
struct node* btsearch(struct node* r, int k);
void free_tree(struct node* n);

void measure_bta(void);
void measure_btw(void);