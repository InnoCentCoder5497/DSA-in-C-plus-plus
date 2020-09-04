#include<iostream>
using namespace std;

struct character {
    char c;
    int freq;
    character* left;
    character* right;
};

// Min Priority Queue with heap methods
// get parent index
int Parent(int i){
    return i / 2;
}

// get left child index
int Left(int i){
    return 2 * i;
}

// get right child index
int Right(int i){
    return 2 * i + 1;
}

// min heapify from given index
void min_heapify(character* arr[], int i, int heap_size){
    int l = Left(i);
    int r = Right(i);
    character *temp;
    int smallest;

    if(l <= heap_size && arr[l]->freq < arr[i]->freq){
        smallest = l;
    }
    else{
        smallest = i;
    }

    if(r <= heap_size && arr[r]->freq < arr[smallest]->freq){
        smallest = r;
    }

    if(smallest != i){
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        min_heapify(arr, smallest, heap_size);
    }
}

// build complete min heap -> min priority queue
void build_min_heap(character *arr[], int size){
    int i = size/ 2;
    while(i > 0){
        min_heapify(arr, i, size);
        i--;
    }
}

// extract minimum element from quueue
character* heap_extract_min(character* arr[], int *cur_size){
    if(*cur_size < 1){
        cout << "Heap Underflow" << endl;
    }
    else{
        character* mini = arr[1];
        arr[1] = arr[*cur_size];
        *cur_size = *cur_size - 1;
        min_heapify(arr, 1, *cur_size);
        return mini;
    }
    return NULL;
}

// increase key for new element
void heap_increase_key(character *arr[], int i, character *key){
    character *temp;
    arr[i] = key;
    while(i > 1 && arr[Parent(i)]->freq > arr[i]->freq){
        temp = arr[i];
        arr[i] = arr[Parent(i)];
        arr[Parent(i)] = temp;

        i = Parent(i);
    }
}

// insert new element in queue
void min_heap_insert(character *arr[], character *var, int* cur_size, int size){
    if(*cur_size + 1 > size){
        cout << "Heap Overflow" << endl;
        return;
    }
    *cur_size = *cur_size + 1;
    arr[*cur_size] = NULL;
    heap_increase_key(arr, *cur_size, var);
}

// generate huffman code tree and return head
character* huffman(character *arr[], int n, int *cursize, int size){
    int i;
    character *z;
    character *ext;
    for(i = 1; i < n; i++){
        z = new character;
        ext = heap_extract_min(arr, cursize);
        z->left = ext;
        z->freq = ext->freq;
        ext = heap_extract_min(arr, cursize);
        z->right = ext;
        z->freq += ext->freq;
        z->c = '*';
        min_heap_insert(arr, z, cursize, size);
    }

    return heap_extract_min(arr, cursize);
}

// iterate huffman code tree and print codes
void print_huffman(character *head, char direction, string code){
    if(head != NULL){
        if(direction == 'l')
            code = code + '0';
        else if(direction == 'r')
            code = code + '1';

        print_huffman(head->left, 'l', code);
        print_huffman(head->right, 'r', code);

        if(head->c != '*'){
            cout << head->c << " --> " << code << endl;
        }
    }
}

int main() {
    int n = 6;
    char c;
    int freq;
    int current_size = n;
    character *myq[n + 1];
    character *var;
    for(int i = 1; i <= n; i++){
        cout << "Enter character and its frequency : ";
        cin >> c >> freq;
        var = new character;
        var->c = c;
        var->freq = freq;
        var->left = NULL;
        var->right = NULL;
        myq[i] = var;
    }


    for(int i = 1; i <= n; i++){
        cout << "Character : " << myq[i]->c << " its frequency : " << myq[i]->freq << endl;
    }

    build_min_heap(myq, n);
    for(int i = 1; i <= current_size; i++){
        cout << "Character : " << myq[i]->c << " its frequency : " << myq[i]->freq << endl;
    }

    character *temp;

    temp = huffman(myq, n, &current_size, n);

    print_huffman(temp, 0, "");

    return 0;
}