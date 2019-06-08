#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include "actionmanagement.h"
#include "action_structs.h"
#include "item.h"
#include "game.h"
#include "player.h"

#define BUFFER_SIZE (100)
#define WRONG_KIND (1)
#define NOT_ALLOWED_DIRECT (2)
#define NOT_ALLOWED_INDIRECT (3)
#define CONDITIONS_NOT_MET (4)
#define ATTRIBUTE_TYPE_DNE (5)
#define ATTRIBUTE_NOT_SET (6)

int execute_do_item_item_action(char *act_name, enum action_kind kind, char *allowed_act_name1, enum action_kind allowed_kind1, char *allowed_act_name2, enum action_kind allowed_kind2)
{
    action_type_t *a = action_type_new(act_name, kind);
    action_type_t *allowed_a1 = action_type_new(allowed_act_name1, allowed_kind1);
    action_type_t *allowed_a2 = action_type_new(allowed_act_name2, allowed_kind2);
    item_t *direct = item_new("direct", "The direct item", "The directmost object of interest");
    item_t *indirect = item_new("indirect", "The indirect item", "The indirectmost object of interest");
    add_allowed_action(direct, allowed_act_name1, allowed_a1);
    add_allowed_action(indirect, allowed_act_name2, allowed_a2);
    char *string = malloc(BUFFER_SIZE);

    int rc = do_item_item_action(a, direct, indirect, &string);

    item_free(direct);
    item_free(indirect);
    action_type_free(a);

    return rc;
}


Test(item_item_actions, wrong_kind_ITEM)
{
    int rc = execute_do_item_item_action(ITEM, "dummy", ITEM, "dummy", ITEM);

    cr_assert_eq(rc, WRONG_KIND,
                 "execute_do_item_item_action returned %d for wrong kind 1, expected WRONG_KIND (1)", rc);
}


Test(item_item_actions, wrong_kind_PATH)
{

    int rc = execute_do_item_item_action(PATH, "dummy", PATH, "dummy", PATH);

    cr_assert_eq(rc, WRONG_KIND,
                 "execute_do_item_item_action returned %d for wrong kind 2, expected WRONG_KIND (1)", rc);
}


Test(item_item_actions, correct_kind_ITEM_ITEM)
{
    int rc = execute_do_item_item_action(ITEM_ITEM, "dummy", ITEM_ITEM, "dummy", ITEM_ITEM);

    cr_assert_eq(rc, SUCCESS,
                 "execute_do_item_item_action returned %d for correct kind 3, expected SUCCESS (0)", rc);
}


Test(item_item_actions, correct_allowed_actions)
{
    int rc = execute_do_item_item_action(ITEM_ITEM, "dummy", ITEM_ITEM, "dummy", ITEM_ITEM);

    cr_assert_eq(rc, SUCCESS,
                 "execute_do_item_item_action returned %d for correct allowed actions in indirect and direct, expected SUCCESS (0)", rc);
}


Test(item_item_actions, wrong_allowed_actions_direct)
{
    int rc = execute_do_item_item_action(ITEM_ITEM, "dummy_allowed", ITEM_ITEM, "dummy", ITEM_ITEM);

    cr_assert_eq(rc, NOT_ALLOWED_DIRECT,
                 "execute_do_item_item_action returned %d for incorrect allowed actions name in direct, expected NOT_ALLOWED_DIRECT (2)", rc);
}


Test(item_item_actions, wrong_allowed_actions_indirect)
{
    int rc = execute_do_item_item_action(ITEM_ITEM, "dummy", ITEM_ITEM, "dummy_allowed", ITEM_ITEM);

    cr_assert_eq(rc, NOT_ALLOWED_INDIRECT,
                 "execute_do_item_item_action returned %d for incorrect allowed actions name in indirect, expected NOT_ALLOWED_INDIRECT (3)", rc);
}


Test(item_item_actions, wrong_allowed_actions)
{
    int rc = execute_do_item_item_action(ITEM_ITEM, "dummy_allowed", ITEM_ITEM, "dummy_allowed", ITEM_ITEM);

    cr_assert_eq(rc, NOT_ALLOWED_DIRECT,
                 "execute_do_item_item_action returned %d for incorrect allowed actions name in indirect and direct, expected NOT_ALLOWED_DIRECT (2)", rc);
}

Test(item_item_actions, conditons_not_met)
{
}

Test(item_item_actions, conditons_met)
{
}

Test(item_item_actions, effect_set_double)
{
}

Test(item_item_actions, effect_set_boole)
{
}

Test(item_item_actions, effect_set_character)
{
}

Test(item_item_actions, effect_set_string)
{
}

Test(item_item_actions, effect_set_integer)
{
}

Test(item_item_actions, effect_set_actions)
{
}

Test(item_item_actions, effect_set_DNE)
{
}

Test(item_item_actions, failed_to_set?)
{
}