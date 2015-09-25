#pragma once


//-----------------------------------------------------------------------------
//--------------------------------VIDEO & WINDOW-------------------------------
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


//-----------------------------------------------------------------------------
//--------------------------------ERROR CODES----------------------------------
//-----------------------------------------------------------------------------

#define ERR_SUCCESS        0
#define ERR_WINDOW         1
#define ERR_SHADER         2
#define ERR_STATIC_OBJECT  3


//-----------------------------------------------------------------------------
//--------------------------------ATTRIBUTES-----------------------------------
//-----------------------------------------------------------------------------

#define SIZE_POS        4
#define SIZE_NORMAL     4
#define SIZE_TEXCOORD   2
#define NAME_POS        "a_position"
#define NAME_TEXCOORD   "a_texcoord"
#define NAME_NORMAL     "a_normal"
