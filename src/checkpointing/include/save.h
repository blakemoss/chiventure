#ifndef SAVE_H
#define SAVE_H

#include "../game.pb-c.h"

/*
 * Dummy Structs Generally Based off of Game-State's Structs
 *
 * Implementation of a save function
 */

typedef struct object {
  char *object_id;
  char *short_desc;
  char *long_desc;
  //placeholder tagged union thing;
} object_t;

typedef struct player {
  int player_id;
  char *username; // initialized to null if not in use
  int level; // initialized to -1 if not in use
  int health; // initialized to -1 if not in use
  int xp; // initialized to -1 if not in use
  object_t **inventory; // array of pointers inventory objects
  int inventory_len;
  object_t **clothes; // array of pointers clothes objects
  int clothes_len;
} player_t;

typedef struct room {
  char *room_id;
  char *short_desc;
  char *long_desc;
  int objs_len;
  object_t **objs; // array of pointers objects
  // path_t paths; // hashtable placeholder for potential paths
} room_t;

typedef struct game {
  player_t **players; // array of pointers of players
  int players_len;
  room_t **rooms; // array of pointers of rooms
  int rooms_len;
  char *curr_room; // room id
  int start_time;
} game_t;


/* 
 * Packs the object_t struct into the Object field in the protofile.
 * 
 * Parameters:
 *   - o: the proto file object struct
 *   - o_t: the game struct object_t struct
 *
 * Return:
 *   - 0 if successful, -1 if unsuccessful 
 */
int transfer_object(Object *o, object_t *o_t);


/* 
 * Packs the room_t struct into the Room field in the protofile.
 * 
 * Parameters:
 *   - r: the proto file object struct
 *   - r_t: the game struct object_t struct
 *
 * Return:
 *   - 0 if successful, -1 if unsuccessful 
 */
int transfer_room(Room *r, room_t *r_t);


/* 
 * Packs the player_t struct into the Player field in the protofile.
 * 
 * Parameters:
 *   - p: the proto file object struct
 *   - p_t: the game struct object_t struct
 *   - level: flag signifying whether level field is in use or not
 *      - 1 for in use, -1 for not in use
 *   - health:  flag signifying whether health field is in use or not
 *      - 1 for in use, -1 for not in use
 *   - xp: flag signifying whether xp field is in use or not
 *      - 1 for in use, -1 for not in use
 *
 * Return:
 *   - 0 if successful, -1 if unsuccessful 
 */
int transfer_player(Player *p, player_t *p_t, int level, int health, int xp);


/* 
 * Packs the game_t struct into the Game field in the protofile.
 * 
 * Parameters:
 *   - g: the proto file object struct
 *   - g_t: the game struct object_t struct
 *
 * Return:
 *   - 0 if successful, -1 if unsuccessful 
 */
int transfer_game(Game *g, game_t *g_t);


/* 
 * Writes the serialized game into a file
 * 
 * Parameters:
 *   - filename: name of the file given from command line
 *   - buffer: buffer containing seraizlied game
 *   - len: the length of the serialized game in buffer
 *
 * Return:
 *   - 0 if successful, -1 if unsuccessful 
 */
int write_to_file(char *filename, uint8_t *buffer, unsigned len);


/* 
 * Calls all above functions to save game into file
 * 
 * Parameters:
 *   - g: game_t struct containing the game we want to save
 *   - filename: the name of the save file
 *
 * Return:
 *   - 0 if successful, -1 if unsuccessful 
 */
int save(game_t *game, char *filename);

#endif
