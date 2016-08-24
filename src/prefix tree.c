#include "prefix tree.h"


PrefixTree* create_prefix_tree()
{
    PrefixTree *new_node=malloc(sizeof(PrefixTree));
    int         i;

    for(i=0; i<256; i++)
        new_node->prefixes[i]=0;

    new_node->data=0;

    return new_node;
}


void add_data_in_prefix_tree(PrefixTree *tree, char *word, char *data)
{
    PrefixTree *next_node;

    for(; *word; word++)
    {
        next_node=tree->prefixes[(int)*word];

        if(!next_node)
        {
            next_node=create_prefix_tree();
            tree->prefixes[(int)*word]=next_node;
        }

        tree=next_node;
    }

    tree->data=data;
}


char* find_data_in_prefix_tree(PrefixTree *tree, char *word)
{
    for(; *word; word++)
    {
        tree=tree->prefixes[(int)*word];

        if(!tree)
            return 0;
    }

    return tree->data;
}


void destroy_prefix_tree(PrefixTree *tree, void (*destroy_data)(char *data))
{
    int i;

    for(i=0; i<256; i++)
        if(tree->prefixes[i])
            destroy_prefix_tree(tree->prefixes[i], destroy_data);

    if(tree->data)
        destroy_data(tree->data);

    free(tree->prefixes);
    free(tree);
}
