#include <limits.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include <time.h>
#include "../avltree.h"
#include "gtest/gtest.h"
using namespace std;

int number_exists(int nb, int array[], int length) {
    int i = 0;
    for ( i = 0 ; i < length; i ++) {
        if (array[i] == nb) return 1;
    }
    return 0;
}


int get_random_number(int max, int array[], int length) {
    srand(time(NULL));
    int nb = rand() % max;
    while (nb == 0 || number_exists(nb, array, length) == 1) {
        nb = rand() % max;
    }
    return nb;
}

class avltree_test : public testing::Test {

protected:

    void SetUp() {
        root = 0x0;

        node = avltree_new();

        data = (char *) malloc(sizeof(char) * 7);
        sprintf(data, "Data-x");
        data[6] = '\0';
        node2 = avltree_create(100, (void*)data);

        int i = 0;
        for (i = 0; i < 8; i ++) {
            keys[i] = get_random_number(10, keys, i);
        }

        // Create an AVL Tree
        for (i = 0; i < 8; i++) {
            char * data = NULL;
            data = (char *) malloc(sizeof(char) * 7);
            sprintf(data, "Data-%d", keys[i]);
            data[6] = '\0';
            avltree_t * new_node = avltree_create(keys[i], data);
            if (new_node != NULL) {
                root = avltree_insert(root, new_node);
            }
        }        
    }

    void TearDown() {
        avltree_free_node(node);
        // avltree_free_node(node2);
        avltree_free_tree(root);
    }

    avltree_t * node, *node2, *root;
    char * data;
    int keys[8];
};

TEST_F(avltree_test, avltree_new) {
    EXPECT_TRUE(node != NULL);
    EXPECT_TRUE(node->parent == NULL);
    EXPECT_TRUE(node->left_child == NULL);
    EXPECT_TRUE(node->right_child == NULL);
    EXPECT_TRUE(node->data == NULL);
    EXPECT_EQ(node->key, 0);
    avltree_free_node(node2);
}

TEST_F(avltree_test, avltree_create) {
    EXPECT_TRUE(node2 != NULL);
    EXPECT_TRUE(node2->parent == NULL);
    EXPECT_TRUE(node2->left_child == NULL);
    EXPECT_TRUE(node2->right_child == NULL);
    EXPECT_TRUE(node2->data != NULL);
    EXPECT_EQ(node2->key, 100);
    EXPECT_STREQ((char*)node2->data, data);
    avltree_free_node(node2);
}


TEST_F(avltree_test, avltree_insert) {
    root = avltree_insert(root, node2);
}

TEST_F(avltree_test, avltree_find_not_found) {
    
    avltree_t * not_found_node = avltree_find(root,11);
    EXPECT_TRUE(not_found_node == NULL);
    avltree_show_tree(root);
    avltree_free_node(node2);
}

TEST_F(avltree_test, avltree_find_found) {
    
    root = avltree_insert(root, node2);

    avltree_t * found_node = avltree_find(root,100);

    EXPECT_TRUE(found_node != NULL);
    EXPECT_EQ(found_node->key, 100);
    EXPECT_STREQ((char*)found_node->data, data);
    avltree_show_node(found_node);
}

TEST_F(avltree_test, avltree_get_key) {
    root = avltree_insert(root, node2);

    avltree_t * found_node = avltree_find(root,100);

    EXPECT_TRUE(found_node != NULL);
    EXPECT_EQ(avltree_get_key(found_node), 100);
    avltree_show_node(found_node);
}

TEST_F(avltree_test, avltree_get_data) {
    root = avltree_insert(root, node2);

    avltree_t * found_node = avltree_find(root,100);

    EXPECT_TRUE(found_node != NULL);
    EXPECT_STREQ((char*)avltree_get_data(found_node), data);
    avltree_show_node(found_node);
}


