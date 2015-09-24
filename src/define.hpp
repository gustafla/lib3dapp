#pragma once


//-----------------------------------------------------------------------------
//------------------------------VIDEO & WINDOW---------------------------------
//-----------------------------------------------------------------------------

#define GAME_NAME "RPG test"
#ifdef DEBUG
    #define GAME_VERSION "(debug build)"
#else
    #define GAME_VERSION "alpha"
#endif
#define SCREEN_W 800
#define SCREEN_H 600


//-----------------------------------------------------------------------------
//--------------------------------DIRECTORIES----------------------------------
//-----------------------------------------------------------------------------

#define DATA_DIR    "data"
#define SHADER_DIR  "shaders"
#define TEXTURE_DIR "textures"
#define SOUND_DIR   "sounds"
#define MUSIC_DIR   "music"
#define MESH_DIR    "meshes"
