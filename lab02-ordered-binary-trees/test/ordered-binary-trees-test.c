#include <check.h>

#include "../interface/ordered-binary-trees.h"

OrderedBinaryTree tree = NULL;

void set_up()
{
    add(&tree, 10);

    add(&tree, 5);
    add(&tree, 4);
    add(&tree, 7);
    add(&tree, 6);
    add(&tree, 8);

    add(&tree, 20);
    add(&tree, 19);
    add(&tree, 18);
    add(&tree, 21);
    add(&tree, 22);
}

void tear_down()
{
    tree = initialize(&tree);
}

START_TEST(add_test)
{
    set_up();

    ck_assert_int_eq(tree->value, 10);

    ck_assert_int_eq(tree->left->value, 5);
    ck_assert_int_eq(tree->left->right->left->value, 6);

    ck_assert_int_eq(tree->right->value, 20);
    ck_assert_int_eq(tree->right->right->right->value, 22);

    tear_down();
}
END_TEST

START_TEST(initialize_test)
{
    set_up();

    tear_down();

    ck_assert_ptr_eq(tree, NULL);
}
END_TEST

START_TEST(search_test)
{
    set_up();

    ck_assert_int_eq(search(tree, 10), TRUE);
    ck_assert_int_eq(search(tree, 4), TRUE);
    ck_assert_int_eq(search(tree, 8), TRUE);
    ck_assert_int_eq(search(tree, 18), TRUE);
    ck_assert_int_eq(search(tree, 19), TRUE);

    ck_assert_int_eq(search(tree, 100), FALSE);
    ck_assert_int_eq(search(tree, 13), FALSE);

    tear_down();
}
END_TEST

START_TEST(suppress_test)
{
    set_up();

    suppress(&tree, 7);

    ck_assert_int_eq(search(tree, 7), FALSE);
    ck_assert_int_eq(search(tree, 6), FALSE);
    ck_assert_int_eq(search(tree, 8), FALSE);

    suppress(&tree, 20);

    ck_assert_int_eq(search(tree, 20), FALSE);
    ck_assert_int_eq(search(tree, 19), FALSE);
    ck_assert_int_eq(search(tree, 18), FALSE);
    ck_assert_int_eq(search(tree, 21), FALSE);
    ck_assert_int_eq(search(tree, 22), FALSE);
    ck_assert_ptr_eq(tree->right, NULL);

    suppress(&tree, 10);

    ck_assert_ptr_eq(tree, NULL);

    tear_down();
}
END_TEST

START_TEST(smallest_node_test)
{
    set_up();
    ck_assert_int_eq(smallest_node(tree), 4);
    tear_down();
}
END_TEST

START_TEST(greatest_node_test)
{
    set_up();
    ck_assert_int_eq(greatest_node(tree), 22);
    tear_down();
}
END_TEST

START_TEST(same_geometric_shape_test)
{
    OrderedBinaryTree tree = NULL, tree2 = NULL;

    ck_assert_int_eq(same_geometric_shape(tree, tree2), 1);

    add(&tree, 10);
    ck_assert_int_eq(same_geometric_shape(tree, tree2), 0);

    add(&tree2, 10);
    ck_assert_int_eq(same_geometric_shape(tree, tree2), 1);

    add(&tree, 7);
    ck_assert_int_eq(same_geometric_shape(tree, tree2), 0);

    add(&tree2, 7);
    ck_assert_int_eq(same_geometric_shape(tree, tree2), 1);

    add(&tree, 12);
    ck_assert_int_eq(same_geometric_shape(tree, tree2), 0);
    
    add(&tree2, 12);
    ck_assert_int_eq(same_geometric_shape(tree, tree2), 1);

    add(&tree, 8);
    add(&tree2, 8);
    add(&tree, 6);
    ck_assert_int_eq(same_geometric_shape(tree, tree2), 0);

    add(&tree2, 6);
    ck_assert_int_eq(same_geometric_shape(tree, tree2), 1);

    add(&tree, 11);
    add(&tree2, 11);
    ck_assert_int_eq(same_geometric_shape(tree, tree2), 1);

    tree = initialize(&tree);
    tree2 = initialize(&tree2);
}
END_TEST

START_TEST(height_test)
{
    OrderedBinaryTree tree = NULL;

    ck_assert_int_eq(height(tree), -1);

    add(&tree, 10);
    ck_assert_int_eq(height(tree), 0);

    add(&tree, 7);
    ck_assert_int_eq(height(tree), 1);

    add(&tree, 12);
    ck_assert_int_eq(height(tree), 1);

    add(&tree, 8);
    ck_assert_int_eq(height(tree), 2);

    add(&tree, 11);
    ck_assert_int_eq(height(tree), 2);

    add(&tree, 14);
    add(&tree, 16);

    ck_assert_int_eq(height(tree), 3);

    add(&tree, 17);
    add(&tree, 18);
    add(&tree, 19);
    add(&tree, 20);
    ck_assert_int_eq(height(tree), 7);

    tree = initialize(&tree);
}
END_TEST

Suite *ordered_binary_trees_suite(void)
{
    Suite *suite;
    TCase *ordered_binary_trees_cases;

    suite = suite_create("ordered_binary_trees_suite");
    ordered_binary_trees_cases = tcase_create("ordered_binary_trees");

    tcase_add_test(ordered_binary_trees_cases, add_test);
    tcase_add_test(ordered_binary_trees_cases, initialize_test);
    tcase_add_test(ordered_binary_trees_cases, search_test);
    tcase_add_test(ordered_binary_trees_cases, suppress_test);
    tcase_add_test(ordered_binary_trees_cases, smallest_node_test);
    tcase_add_test(ordered_binary_trees_cases, greatest_node_test);
    tcase_add_test(ordered_binary_trees_cases, same_geometric_shape_test);
    tcase_add_test(ordered_binary_trees_cases, height_test);

    suite_add_tcase(suite, ordered_binary_trees_cases);

    return suite;
}

int main()
{
    int number_failed;
    SRunner *suite_runner;

    Suite *ordered_binary_trees;

    ordered_binary_trees = ordered_binary_trees_suite();

    suite_runner = srunner_create(ordered_binary_trees);

    srunner_run_all(suite_runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}