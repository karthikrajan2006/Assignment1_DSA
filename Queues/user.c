#include "user.h"

/* Maps a Faction enum value to a readable string */
const char* faction_to_string(Faction f) {
    switch (f) {
    case FACTION_RED:   return "Red";
    case FACTION_BLUE:  return "Blue";
    case FACTION_GREEN: return "Green";
    default:            return "Unknown";
    }
}