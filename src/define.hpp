#pragma once


//-----------------------------------------------------------------------------
//--------------------------------VIDEO & WINDOW-------------------------------
//-----------------------------------------------------------------------------

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
#define ERR_NO_DISPLAY_SIZE     8
#define ERR_INVALID_ARGUMENT    9
#define ERR_WTF                 10


//-----------------------------------------------------------------------------
//----------------------------------LIMITS-------------------------------------
//-----------------------------------------------------------------------------

/*NOT REINFORCED YET*/
#define MAX_N_DIRECTIONAL_LIGHTS 16
#define MAX_N_POINT_LIGHTS       256


//-----------------------------------------------------------------------------
//--------------------------------ATTRIBUTES-----------------------------------
//-----------------------------------------------------------------------------

#define SIZE_POS        3
#define SIZE_NORMAL     3
#define SIZE_TEXCOORD   2
#define NAME_POS        "a_position"
#define NAME_TEXCOORD   "a_texcoord"
#define NAME_NORMAL     "a_normal"
#define MACRO_LIGHTS_DIRECTIONAL "N_LIGHTS_DIRECTIONAL"
#define MACRO_LIGHTS_POINT       "N_LIGHTS_POINT"
