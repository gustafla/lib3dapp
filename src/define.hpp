#pragma once


//-----------------------------------------------------------------------------
//--------------------------------VIDEO & WINDOW-------------------------------
//-----------------------------------------------------------------------------

#define APPLICATION_NAME "test"
#ifdef DEBUG
    #define APPLICATION_VERSION "(debug build)"
#else
    #define APPLICATION_VERSION "alpha"
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

#define ERR_SUCCESS             0
#define ERR_WINDOW              1
#define ERR_PROGRAM             2
#define ERR_STATIC_OBJECT       3
#define ERR_OBJ_FILE            4
#define ERR_TGA_FILE            6
#define ERR_TEXTURE             5
#define ERR_SHADER              7
#define ERR_NO_RPI_DISPLAY_SIZE 8


//-----------------------------------------------------------------------------
//--------------------------------ATTRIBUTES-----------------------------------
//-----------------------------------------------------------------------------

#define SIZE_POS        4
#define SIZE_NORMAL     4
#define SIZE_TEXCOORD   2
#define NAME_POS        "a_position"
#define NAME_TEXCOORD   "a_texcoord"
#define NAME_NORMAL     "a_normal"
