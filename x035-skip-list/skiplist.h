#ifndef MY_SOLUTION__
#define MY_SOLUTION__

#include <iostream>

/**
 * skiplist node definition
 */
struct node {
    int val;
    node **forward;
    node(int v, int level):val(v) {
        forward = new node*[level];
        for (int i = 0; i < level; ++i) {
            forward[i] = nullptr;
        }
    }
    ~node() {
        delete []forward;
    }
};

class SkipList{
private:
    // Maximum level for this skip list.
    int MAX_LEVEL;

    // prop is the probability for a head toss.
    float prob;

    // the number layers of the current skiplist.
    int num_layers;

    // pointer to the header node.
    node *header;

public:
    SkipList(int maxLevel, float p=0.5):MAX_LEVEL(maxLevel),prob(p){
        header = new node(-1, maxLevel);
        num_layers = 0;
    }

    ~SkipList() {
    }

    // Insert a val to the skiplist.
    void insert(int val) {
        // Step 1: find all insert pre for all layers.
        node** prev = new node*[MAX_LEVEL];
        memset(prev, 0, sizeof(node *) * MAX_LEVEL);

        node *current = header;
        for (int i = num_layers; i >= 0; --i) {
            while (current->forward[i] != nullptr && current->forward[i]->val < val) {
                current = current->forward[i];
            }
            prev[i] = current;
        }

        current = current->forward[0];

        if (current == nullptr || current->val != val) {
            // Step 2: get inserted layer
            // and if new layer is larger than current layer, we should update larger prev
            int layer = getRandomLayer();
            if (layer > num_layers) {
                for (int i = layer; i > num_layers; --i) {
                    prev[i] = header;
                }
                num_layers = layer;
            }

            // Step 3: create the new node.
            node* element = new node(val, layer + 1);

            for (int i = 0; i <= layer; ++i) {
                element->forward[i] = prev[i]->forward[i];
                prev[i]->forward[i] = element;
            }
        }
    }

    // A coin is tossed util a head appears.
    int getRandomLayer() {
        float r;
        int layer = -1;
        do {
            ++layer;
            r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        } while (r < prob && layer < MAX_LEVEL - 1);
        return layer;
    }

    void display() {
        for (int i = 0; i <= num_layers; ++i) {
            node *p = header->forward[i];
            std::cout << "Level " << i << ": " ;
            while (p) {
                std::cout << p->val << ",";
                p = p->forward[i];
            }
            std::cout << std::endl;
        }
    }
};



#endif /* ifndef MY_SOLUTION__ */
