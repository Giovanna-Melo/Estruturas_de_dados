struct node_avl {
    int v;
    struct node_avl* l;
    struct node_avl* r;
    struct node_avl* p;
    unsigned int h;
};

unsigned int height(struct node_avl *n);
struct node_avl* new_node_avl(int value);
int balance_factor(struct node_avl *n);
void update_height(struct node_avl **n);
void rotate_left(struct node_avl **r);
void rotate_right(struct node_avl **r);
void balanceamento(struct node_avl **r);
void btinsert_avl(struct node_avl** r, struct node_avl* n);
struct node_avl* btsearch_avl(struct node_avl* r, int k) ;
void free_tree_avl(struct node_avl* n);

void print_tree(struct node_avl* r, int space, int height);
void print_avl(struct node_avl *r);


void measure_avl_average(void);
void measure_avl_worst(void);
void teste(void);