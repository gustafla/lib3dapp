// Copyright 2016 Lauri Gustafsson
/*  This file is part of lib3dapp.

    lib3dapp is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    lib3dapp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with lib3dapp.  If not, see <http://www.gnu.org/licenses/>.*/

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
#define NAME_A_POSITION   "a_position"
#define NAME_A_TEXCOORD   "a_texcoord"
#define NAME_A_NORMAL     "a_normal"
#define MACRO_LIGHTS_DIRECTIONAL "N_LIGHTS_DIRECTIONAL"
#define MACRO_LIGHTS_POINT       "N_LIGHTS_POINT"


//-----------------------------------------------------------------------------
//---------------------------------UNIFORMS------------------------------------
//-----------------------------------------------------------------------------

#define NAME_U_MAT_PROJECTION       "u_m_projection"
#define NAME_U_MAT_VIEW             "u_m_view"
#define NAME_U_MAT_MODEL            "u_m_model"
#define NAME_U_COLOR                "u_color"
#define NAME_U_RESOLUTION           "u_resolution"
#define NAME_U_TIME                 "u_time"
#define NAME_U_OPACITY              "u_opacity"
#define NAME_U_TEXTURES             "u_textures"
#define NAME_U_LIGTHS_POINT         "u_lights_point"
#define NAME_U_LIGTHS_DIRECTIONAL   "u_lights_directional"
#define NAME_U_LIGTH_AMBIENT        "u_light_ambient"
