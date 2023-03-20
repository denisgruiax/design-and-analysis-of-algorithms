#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "../interface/generalized-trees.h"

GeneralizedTree *tree = NULL;

void set_up()
{
    create_root(&tree, 1);

    add_son(tree, 1, 2);
    add_son(tree, 1, 3);
    add_son(tree, 1, 4);
    add_son(tree, 1, 14);
    add_son(tree, 1, 15);

    add_son(tree, 2, 5);
    add_son(tree, 2, 6);
    add_son(tree, 2, 7);

    add_son(tree, 3, 8);
    add_son(tree, 3, 9);
    add_son(tree, 3, 10);
    add_son(tree, 3, 11);

    add_son(tree, 4, 12);
    add_son(tree, 4, 13);

    add_son(tree, 15, 16);

    add_son(tree, 16, 17);
    add_son(tree, 16, 18);

    add_son(tree, 17, 19);

    add_son(tree, 18, 20);

    add_son(tree, 20, 21);
}

void tear_down()
{
    tree = initialize_tree(tree);
}

START_TEST(node_pointer_test)
{
    set_up();

    NodePointer node = node_pointer(tree, 9);

    ck_assert_int_eq(node->father->value, 3);
    ck_assert_int_eq(node->value, 9);
    ck_assert_int_eq(node->right_brother->value, 10);

    tear_down();
}
END_TEST

START_TEST(create_root_test)
{
    set_up();

    NodePointer son1 = node_pointer(tree, 2);
    NodePointer son2 = node_pointer(tree, 3);
    NodePointer son3 = node_pointer(tree, 4);

    ck_assert_int_eq(tree->value, 1);

    ck_assert_int_eq(son1->value, 2);
    ck_assert_int_eq(son2->value, 3);
    ck_assert_int_eq(son3->value, 4);
}
END_TEST

START_TEST(add_son_test)
{
    set_up();

    add_son(tree, 1, 14);

    ck_assert_int_eq(node_pointer(tree, 4)->right_brother->value, 14);

    tear_down();
}
END_TEST

START_TEST(initialize_tree_test)
{
    set_up();

    tear_down();

    ck_assert_ptr_eq(tree, NULL);
}
END_TEST

START_TEST(father_test)
{
    set_up();

    NodePointer node = node_pointer(tree, 3);
    ck_assert_int_eq(node->father->value, 1);

    tear_down();
}
END_TEST

START_TEST(first_son_test)
{
    set_up();

    NodePointer node = node_pointer(tree, 3);
    ck_assert_int_eq(node->first_son->value, 8);

    tear_down();
}
END_TEST

START_TEST(right_brother_test)
{
    set_up();

    NodePointer node = node_pointer(tree, 3);
    ck_assert_int_eq(node->right_brother->value, 4);

    tear_down();
}
END_TEST

Suite *generalized_trees_suite(void)
{
    Suite *suite;
    TCase *generalized_trees_cases;

    suite = suite_create("generalized_trees_suite");
    generalized_trees_cases = tcase_create("generalized_trees");

    tcase_add_test(generalized_trees_cases, node_pointer_test);
    tcase_add_test(generalized_trees_cases, create_root_test);
    tcase_add_test(generalized_trees_cases, add_son_test);
    tcase_add_test(generalized_trees_cases, initialize_tree_test);
    tcase_add_test(generalized_trees_cases, father_test);
    tcase_add_test(generalized_trees_cases, first_son_test);
    tcase_add_test(generalized_trees_cases, right_brother_test);

    suite_add_tcase(suite, generalized_trees_cases);

    return suite;
}

/*Application 1 requirement*/
START_TEST(insert_root_test)
{
    set_up();

    insert_root(&tree, 125);

    ck_assert_ptr_eq(tree->father, NULL);
    ck_assert_ptr_eq(tree->first_son, NULL);
    ck_assert_ptr_eq(tree->right_brother, NULL);
    ck_assert_int_eq(tree->value, 125);

    tear_down();
}
END_TEST

START_TEST(search_value_test)
{
    set_up();

    ck_assert_int_eq(search_value(tree, 1), 1);
    ck_assert_int_eq(search_value(tree, 8), 1);
    ck_assert_int_eq(search_value(tree, 3), 1);
    ck_assert_int_eq(search_value(tree, 12), 1);
    ck_assert_int_eq(search_value(tree, 5), 1);

    ck_assert_int_eq(search_value(tree, 0), 0);
    ck_assert_int_eq(search_value(tree, 65), 0);
    ck_assert_int_eq(search_value(tree, 123), 0);

    tear_down();
}
END_TEST

START_TEST(delete_value_test)
{
    set_up();

    ck_assert_int_eq(delete_value(&tree, 1), 1);
    ck_assert_ptr_eq(tree, NULL);

    tear_down();
}
END_TEST

START_TEST(delete_value_test2)
{
    set_up();

    ck_assert_int_eq(delete_value(&tree, 4), 1);
    ck_assert_int_eq(delete_value(&tree, 15), 1);

    tear_down();
}
END_TEST

START_TEST(height_tree_test)
{
    set_up();

    GeneralizedTree *root = NULL;
    create_root(&root, 0);

    ck_assert_int_eq(height_tree(root), 0);
    ck_assert_int_eq(height_tree(tree), 5);

    add_son(tree, 8, 22);
    add_son(tree, 22, 23);
    add_son(tree, 23, 24);
    add_son(tree, 24, 25);
    ck_assert_int_eq(height_tree(tree), 6);

    add_son(tree, 25, 26);
    add_son(tree, 26, 27);
    ck_assert_int_eq(height_tree(tree), 8);

    add_son(tree, 27, 28);
    add_son(tree, 28, 29);
    add_son(tree, 29, 30);
    ck_assert_int_eq(height_tree(tree), 11);

    root = initialize_tree(root);

    tear_down();
}
END_TEST

START_TEST(degree_tree_test)
{
    set_up();

    ck_assert_int_eq(degree_tree(tree), 5);
    ck_assert_int_eq(degree_tree(node_pointer(tree, 2)), 3);
    ck_assert_int_eq(degree_tree(node_pointer(tree, 3)), 4);
    ck_assert_int_eq(degree_tree(node_pointer(tree, 15)), 1);
    ck_assert_int_eq(degree_tree(node_pointer(tree, 16)), 2);
    ck_assert_int_eq(degree_tree(node_pointer(tree, 17)), 1);

    ck_assert_int_eq(degree_tree(node_pointer(tree, 21)), 0);

    ck_assert_int_eq(degree_tree(node_pointer(tree, 25)), -1);

    tear_down();
}
END_TEST

START_TEST(the_leftmost_brother_test)
{
    set_up();

    ck_assert_int_eq(the_leftmost_brother(tree, 11), 8);
    ck_assert_int_eq(the_leftmost_brother(tree, 13), 12);
    ck_assert_int_eq(the_leftmost_brother(tree, 7), 5);

    ck_assert_int_eq(the_leftmost_brother(tree, 1), -1);
    ck_assert_int_eq(the_leftmost_brother(tree, 16), -1);
    ck_assert_int_eq(the_leftmost_brother(tree, 26), -1);
    ck_assert_int_eq(the_leftmost_brother(tree, 1013), -1);

    tear_down();
}
END_TEST

START_TEST(the_rightmost_brother_test)
{
    set_up();

    ck_assert_int_eq(the_rightmost_brother(tree, 8), 11);
    ck_assert_int_eq(the_rightmost_brother(tree, 5), 7);
    ck_assert_int_eq(the_rightmost_brother(tree, 12), 13);

    ck_assert_int_eq(the_rightmost_brother(tree, 1), -1);
    ck_assert_int_eq(the_rightmost_brother(tree, 16), -1);
    ck_assert_int_eq(the_rightmost_brother(tree, 17), 18);
    ck_assert_int_eq(the_rightmost_brother(tree, 21), -1);
    ck_assert_int_eq(the_rightmost_brother(tree, 1013), -1);

    tear_down();
}
END_TEST

START_TEST(number_of_siblings_test)
{
    set_up();

    ck_assert_int_eq(number_of_siblings(tree, 1), -1);

    ck_assert_int_eq(number_of_siblings(tree, 19), 1);
    ck_assert_int_eq(number_of_siblings(tree, 20), 1);

    ck_assert_int_eq(number_of_siblings(tree, 2), 5);
    ck_assert_int_eq(number_of_siblings(tree, 3), 5);
    ck_assert_int_eq(number_of_siblings(tree, 4), 5);
    ck_assert_int_eq(number_of_siblings(tree, 15), 5);

    ck_assert_int_eq(number_of_siblings(tree, 8), 4);
    ck_assert_int_eq(number_of_siblings(tree, 10), 4);
    ck_assert_int_eq(number_of_siblings(tree, 13), 2);
    ck_assert_int_eq(number_of_siblings(tree, 7), 3);

    tear_down();
}
END_TEST

START_TEST(depth_of_node_test)
{
    set_up();

    ck_assert_int_eq(depth_of_node(tree), 0);

    add_son(tree, 8, 20);
    add_son(tree, 20, 21);
    add_son(tree, 20, 22);
    ck_assert_int_eq(depth_of_node(node_pointer(tree, 4)), 1);

    add_son(tree, 15, 30);
    add_son(tree, 30, 31);
    add_son(tree, 31, 32);
    add_son(tree, 32, 33);
    add_son(tree, 33, 34);
    ck_assert_int_eq(depth_of_node(node_pointer(tree, 34)), 6);

    add_son(tree, 34, 35);
    add_son(tree, 35, 36);
    add_son(tree, 36, 37);
    add_son(tree, 37, 38);
    add_son(tree, 38, 39);
    ck_assert_int_eq(depth_of_node(node_pointer(tree, 39)), 11);

    tear_down();
}
END_TEST

START_TEST(number_of_siblings_at_same_depth_test)
{
    set_up();

    ck_assert_int_eq(number_of_siblings_at_same_depth(tree, 0), 1);
    ck_assert_int_eq(number_of_siblings_at_same_depth(tree, 1), 5);
    ck_assert_int_eq(number_of_siblings_at_same_depth(tree, 2), 10);
    ck_assert_int_eq(number_of_siblings_at_same_depth(tree, 3), 2);
    ck_assert_int_eq(number_of_siblings_at_same_depth(tree, 4), 2);
    ck_assert_int_eq(number_of_siblings_at_same_depth(tree, 5), 1);

    ck_assert_int_eq(number_of_siblings_at_same_depth(tree, 17), 0);
    ck_assert_int_eq(number_of_siblings_at_same_depth(tree, 103), 0);

    tear_down();
}
END_TEST

Suite *application1_suite(void)
{
    Suite *suite;
    TCase *application1_cases;

    suite = suite_create("application1_suite");
    application1_cases = tcase_create("application1");

    tcase_add_test(application1_cases, insert_root_test);
    tcase_add_test(application1_cases, search_value_test);
    tcase_add_test(application1_cases, delete_value_test);
    tcase_add_test(application1_cases, delete_value_test2);
    tcase_add_test(application1_cases, height_tree_test);
    tcase_add_test(application1_cases, depth_of_node_test);
    tcase_add_test(application1_cases, the_leftmost_brother_test);
    tcase_add_test(application1_cases, the_rightmost_brother_test);
    tcase_add_test(application1_cases, number_of_siblings_test);
    tcase_add_test(application1_cases, degree_tree_test);
    tcase_add_test(application1_cases, number_of_siblings_at_same_depth_test);

    suite_add_tcase(suite, application1_cases);

    return suite;
}

int main()
{
    int number_failed;
    SRunner *suite_runner;

    Suite *generalized_trees, *application1;

    generalized_trees = generalized_trees_suite();
    application1 = application1_suite();

    suite_runner = srunner_create(generalized_trees);
    srunner_add_suite(suite_runner, application1);

    srunner_run_all(suite_runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}