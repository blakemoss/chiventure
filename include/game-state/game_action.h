
#include "game_state_common.h"
#include "action_management/action_structs.h"
#include "item.h"



// ------------------------- ACTION FUNCTIONS -------------------------
// the following functions are to do with searching for allowed actions
// and conducting actions

/* get_action() returns the game_action_t associated with an action
 * Parameters:
 *  a pointer to the item
 *  the action name
 * Returns:
 *  the action struct associated or NULL if not associated
 */
game_action_t *get_action(item_t *item, char* action_name);

/* add_action() adds a (presumed legal) action to an item
 * Parameters:
 *  a pointer to the item
 *  the action name
 *  the action struct
 *  the action type (as specified by action management)
 *  the string to print should the action be performed successfully
 *  the string to print shoulf the action fail to be performed
 * Returns:
 *  SUCCESS if added correctly, FAILURE if failed to add
 */
int add_action(item_t* item, char *action_name, char* success_str, char* fail_str);


/* possible_action() checks if an item permits a specific action
 * Parameters:
 *  a pointer to the item
 *  the action name
 * Returns:
 *  SUCCESS if item contains action, FAILURE if it does not
 */
int possible_action(item_t* item, char* action_name);

/*
 * Function to get a linked list (utlist) of all the actions in the item
 *
 * Parameters:
 *  item
 *
 * Returns:
 *  linked list of pointers to actions (the head element)
 */
game_action_hash_t *get_all_actions(item_t *item);


/* game_action_free() frees allocated space for an action struct in memory
 *  Parameters:
 *    a pointer to the action
 *  Returns:
 *    SUCCESS if successful, FAILURE if not
 */
int game_action_free(game_action_t *action_tofree);


// ------------------------- CONDITION FUNCTIONS -------------------------

/* add_action_condition() creates a new condition for an item's action and
 * adds to the action's condition list
 * Parameters:
 *  a pointer to the item the action is being performed on
 *  a pointer to the action to which the condition is being added
 *  a pointer to the item specified in the action condition
 *  a pointer to the attribute of the item specified in action condition that needs to be validated
 *  the value of the above attribute that needs to be validated
 * Returns:
 *  SUCCESS upon SUCCESS
 *  ITEM_SRC_NULL if first item ID does not exist
 *  ACTION_NULL if specified action does not exist in first item
 *  ITEM_MODIFY_NULL if second item ID does not exist
 */
int add_action_condition(item_t *item, game_action_t *action, item_t *cond_item, 
			 attribute_t *cond_attribute, attribute_value_t cond_value);

/* delete_action_condition_llist frees a linked list of action conditions
 * Parameters:
 *  linked list of conditions
 *
 * Returns:
 *  always returns SUCCESS
 */
int delete_action_condition_llist(action_condition_list_t *conditions);

/* condition_new() creates a new condition in an item with given inputs
 * Parameters:
 *  a pointer to the item to be modified
 *  a pointer to the attribute
 *  the desired value of the attribute
 * Returns:
 *  NULL if item or attribute are NULL, the new condition if succcessful
 */
game_action_condition_t *condition_new(item_t *item_to_modify, attribute_t *attribute,
				       attribute_value_t new_value);

/* check_condition() checks if the actual attribute of an item is equal
 * to the desired attribute
 * Parameters:
 *  a pointer to the item to check
 *  the desired attribute
 * Returns:
 *  true if desired attribute matches the actual, false if not
 */
bool check_condition(game_action_condition_t *condition);


/* all_conditions_met() checks if all of the conditions of an action are met
 * Parameters:
 *  a pointer to the item to check
 *  the action
 * Returns:
 *  SUCCESS if all conditions are met, FAILURE if not
 *  2 if action not possible
 */
int all_conditions_met(item_t* item, char* action_name);


// ------------------------- EFFECT FUNCTIONS ------------------------------


/* add_action_effect creates an effect_t struct and adds it to the action pointed to
 * Parameters:
 *  pointer to action
 *  pointer to item being modified
 *  pointer to attribute to modify
 *  new attribute_value_t (takes tag from attribute above)
 *
 * Returns:
 * SUCCESS upon success, FAILURE upon failure
 * ACTION_NULL if action NULL
 * ITEM_MODIFY_NULL if item to modify is null
 */
int add_action_effect(game_action_t *action, item_t *item_to_add, 
		      attribute_t *attribute, attribute_value_t new_value);

/* delete_action_effect_llist frees a linked list of action effects
 * Parameters:
 *  linked list of effects
 *
 * Returns:
 *  always returns SUCCESS
 */
int delete_action_effect_llist(action_effect_list_t *effects);

//alt version

/* do_effects() sets an effect
 * Parameters:
 *  pointer to effect
 * Returns:
 *  SUCCESS if effect is set, FAILURE if not
 */
int do_effect(game_action_effect_t *effect);

/* do_all_effects() sets all effects of an action
 * Parameters:
 *  pointer to the item to check
 *  the action_name
 * Returns:
 *  SUCCESS if all effects are set, FAILURE if not
 */
int do_all_effects(item_t* item, char* action_name);


