#include <limits.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include <time.h>
#include "../avltree.h"
#include "gtest/gtest.h"
using namespace std;

int number_exists(int nb, int array[],int length){
    int i = 0;
    for( i =0 ; i < length; i ++){
        if(array[i] == nb) return 1;
    }
    return 0;
}


int get_random_number(int max,int array[], int length){
    srand(time(NULL)); 
    int nb = rand()%max;
    while(nb == 0 || number_exists(nb,array,length) == 1){
        nb = rand()%max;
    }
    return nb;
}

class avltree_test : public testing::Test {

protected:

    void SetUp() {
        node = avltree_new();
        int i = 0;
        
        for(i = 0; i < 8; i ++){
            keys[i] = get_random_number(10,keys,i);
        }
    }

    void TearDown() {
    }
    avltree_t * node;
    int keys[8];
};

TEST_F(avltree_test, avltree_new) {
    EXPECT_TRUE(node != NULL);
    EXPECT_TRUE(node->parent == NULL);
    EXPECT_TRUE(node->left_child == NULL);
    EXPECT_TRUE(node->right_child == NULL);
    EXPECT_TRUE(node->data == NULL);
    EXPECT_EQ(node->key, 0);
}

TEST_F(avltree_test, avltree_get_height) {
    avltree_t * current_node = node;
    node->key = keys[0];
    int i = 1;
    for(i = 1; i < 8; i++){
        avltree_t * new_node = avltree_new();
        if(new_node!=NULL){
            new_node->key = keys[i];
            current_node = avltree_insert(current_node,new_node);
        }
    }
    avltree_show_tree(current_node);
}
