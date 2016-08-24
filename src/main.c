#include <stdio.h>
#include <stdlib.h>
#include "prefix tree.h"


int main()
{
    PrefixTree *tree=create_prefix_tree();

    add_data_in_prefix_tree(tree, "Alexey", 1);
    add_data_in_prefix_tree(tree, "Borisenko", 2);

/*
    int i;
    for(i=0; i<1000000000; i++)
        find_data_in_prefix_tree(tree, "Alexey");
*/
/*
    int i;
    for(i=0; i<1000000000; i++)
        add_data_in_prefix_tree(tree, "Alexey", 1);
*/
    printf("%d\n", find_data_in_prefix_tree(tree, "Alexey"));
    printf("%d\n", find_data_in_prefix_tree(tree, "Borisenko"));

    printf("%d", sizeof(PrefixTree));

    return 0;
}
