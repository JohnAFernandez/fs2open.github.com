/*
* Copyright (C) Volition, Inc. 1999.  All rights reserved.
*
* All source code herein is the property of Volition, Inc. You may not sell 
* or otherwise commercially exploit the source or things you created based on the 
* source.
*
*/

#include "network/multilua.h"
#include "network/multimsgs.h"
#include "network/multi.h"
#include "globalincs/globals.h"
#include "cfile/cfile.h"

SCP_vector<lua_packet_data>Lua_Packets_In;
SCP_vector<lua_packet_data>Lua_Packets_Out;


void multi_lua_init() {
	Lua_Packets_In.clear;
	Lua_Packets_Out.clear;
}

int multi_lua_initialize_out_packet(){
	lua_packet_data new_packet;
	new_packet.lua_id_number = multi_lua_get_next_packet_number();
	new_packet.sent = false;
	Lua_Packets_Out.push_back(new_packet);
	return new_packet.lua_id_number_number;
}

void multi_lua_process_in_packet(ubyte* data, header h_info) {
	int offset = 0;

	lua_packet_data new_packet;
	GET_INT(new_packet.lua_id_number);

}