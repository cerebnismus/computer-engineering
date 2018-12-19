struct node{	
    int data;
    struct node* next, *prev;
};


int main(int argc, char**argv){

    
    struct node *liste = new struct node;
    liste->data = 10;
    liste->prev = nullptr;
    liste->next = nullptr;

    struct node *current = nullptr;
    struct node *last = liste;

    current = new struct node;
    current->data = 20;
    current->prev = last;
    current->next = nullptr;
    last->next = current;

    last = current;

    current = new struct node;
    current->data = 30;
    current->prev = last;
    current->next = nullptr;
    last->next = current;

    last = current;

    current = new struct node;
    current->data = 40;
    current->prev = last;
    current->next = nullptr;
    last->next = current;

    last = current;


    struct node *iter = last;

    while(iter != nullptr){

        // print iter->data

        iter = iter->prev;

    }



}