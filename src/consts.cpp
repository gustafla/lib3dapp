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

#include "3dapp_consts.hpp"

namespace Lib3dapp {
    //-----------------------------------------------------------------------------
    //--------------------------------VIDEO & WINDOW-------------------------------
    //-----------------------------------------------------------------------------
    
    const unsigned int SCREEN_W = 800;
    const unsigned int SCREEN_H = 600;
    
    
    //-----------------------------------------------------------------------------
    //--------------------------------DIRECTORIES----------------------------------
    //-----------------------------------------------------------------------------
    
    const char* DATA_DIR    = "data";
    const char* SHADER_DIR  = "shaders";
    const char* TEXTURE_DIR = "textures";
    const char* SOUND_DIR   = "sounds";
    const char* MUSIC_DIR   = "music";
    const char* MESH_DIR    = "meshes";
    
    
    //-----------------------------------------------------------------------------
    //--------------------------------ERROR CODES----------------------------------
    //-----------------------------------------------------------------------------
    
    const int ERR_SUCCESS            = 0;
    const int ERR_WINDOW             = 1;
    const int ERR_PROGRAM            = 2;
    const int ERR_STATIC_OBJECT      = 3;
    const int ERR_OBJ_FILE           = 4;
    const int ERR_TGA_FILE           = 6;
    const int ERR_TEXTURE            = 5;
    const int ERR_SHADER             = 7;
    const int ERR_NO_DISPLAY_SIZE    = 8;
    const int ERR_INVALID_ARGUMENT   = 9;
    const int ERR_WTF                = 10;
    
    
    //-----------------------------------------------------------------------------
    //----------------------------------LIMITS-------------------------------------
    //-----------------------------------------------------------------------------
    
    /*NOT REINFORCED YET*/
    const unsigned int MAX_N_DIRECTIONAL_LIGHTS = 16;
    const unsigned int MAX_N_POINT_LIGHTS       = 256;
    
    
    //-----------------------------------------------------------------------------
    //--------------------------------ATTRIBUTES-----------------------------------
    //-----------------------------------------------------------------------------
    
    const unsigned int SIZE_POS       = 3;
    const unsigned int SIZE_NORMAL    = 3;
    const unsigned int SIZE_TEXCOORD  = 2;
    const char* NAME_A_POSITION  = "a_position";
    const char* NAME_A_TEXCOORD  = "a_texcoord";
    const char* NAME_A_NORMAL    = "a_normal";
    const char* MACRO_LIGHTS_DIRECTIONAL = "N_LIGHTS_DIRECTIONAL";
    const char* MACRO_LIGHTS_POINT       = "N_LIGHTS_POINT";
    
    
    //-----------------------------------------------------------------------------
    //---------------------------------UNIFORMS------------------------------------
    //-----------------------------------------------------------------------------
    
    const char* NAME_U_MAT_PROJECTION      = "u_m_projection";
    const char* NAME_U_MAT_VIEW            = "u_m_view";
    const char* NAME_U_MAT_MODEL           = "u_m_model";
    const char* NAME_U_COLOR               = "u_color";
    const char* NAME_U_RESOLUTION          = "u_resolution";
    const char* NAME_U_TIME                = "u_time";
    const char* NAME_U_OPACITY             = "u_opacity";
    const char* NAME_U_TEXTURES            = "u_textures";
    const char* NAME_U_LIGTHS_POINT        = "u_lights_point";
    const char* NAME_U_LIGTHS_DIRECTIONAL  = "u_lights_directional";
    const char* NAME_U_LIGTH_AMBIENT       = "u_light_ambient";
};
