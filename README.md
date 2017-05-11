[![Build Status](https://travis-ci.org/luongnv89/AVL-tree.svg?branch=master)](https://travis-ci.org/luongnv89/AVL-tree)

### Introduction

A simple c/cpp API for implementing AVL Tree as a data structure

More about AVL Tree on (wikipedia)[https://en.wikipedia.org/wiki/AVL_tree]

### API 

```
avltree_t * avltree_new();
```

Create a new AVL Tree node. Return NULL if cannot allocate memory for new node or return a pointer points to the new AVL Tree node which has `key = 0` and `data = NULL`. 


```
alvtree_t * avltree_create(int key, void * user_args);
```

Create a new AVL Tree node from given key and user data. Return NULL if cannot allocate memory for new node or return a pointer points to the new AVL Tree node which has given key and data

```
void avltree_free_node(avltree_t * node);
```

Free the resources used by given AVL Tree node

```
void avltree_free_tree(avltree_t * node);
```

Free the resources used by a given Tree

```
int avltree_get_key(avltree_t * node);
```

Get the key value of given AVL Tree node.

```
void * avltree_get_data(avltree_t * node);
```

Get the pointer points to the data of given AVL Tree node

```
alvtree_t * avltree_insert(avltree_t * root, avltree_t * new_node);
```

Insert a new AVLT Tree node into an AVL Tree. Return the root of the new AVL Tree after inserting.

```
avltree_t * avltree_find(avltree_t * root, int key);
```

Find an AVL Tree node which has the key value equals with given `key` in given AVL Tree

```
void avltree_show_tree(avltree_t * node);
```

Print out an AVL Tree.

```
void avltree_show_tree(avltree_t * node);
```

Print out an AVL Tree node


### Install

No need to install it. Just include this file in your code and use the API.  

```
#include "avltree.h"
```

### Usage

Compile your program:

```
gcc -o mytest avltree/avltree.c example.c
```

You can look at the example to see how it works.

### example.c

Compile:

```
gcc -o example avltree.c example.c
```

Test:

```
./example
```

### Change logs

- 11/05/2017: First version
