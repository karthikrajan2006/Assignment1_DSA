#ifndef USER_H
#define USER_H

#define USERNAME_LEN 10  /* fixed username length (not counting null terminator) */

/* Faction a user belongs to */
typedef enum {
    FACTION_RED,
    FACTION_BLUE,
    FACTION_GREEN
} Faction;

/* Represents a single game user */
typedef struct {
    char username[USERNAME_LEN + 1]; /* +1 for null terminator */
    int level;                       /* 1 - 60 */
    Faction faction;                 /* red, blue, or green */
} User;

/* Returns the printable name of a faction (e.g. "Red") */
const char* faction_to_string(Faction f);

#endif