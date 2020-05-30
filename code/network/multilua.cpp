/*
* Copyright (C) Volition, Inc. 1999.  All rights reserved.
*
* All source code herein is the property of Volition, Inc. You may not sell 
* or otherwise commercially exploit the source or things you created based on the 
* source.
*
*/

#include <climits>

#include "globalincs/pstypes.h"
#include "network/multilua.h"
#include "network/multimsgs.h"
#include "network/multimsgs.h"
#include "network/multi.h"
#include "libs/jansson.h"


#include "cfile/cfile.h"

struct LUA_organizer{
	int next_packet_id;	// this will probably get switched out later.
	SCP_vector<lua_packet_data>packets_out;
	SCP_vector<lua_packet_data>packets_in;
};

LUA_organizer Lua_packets;

void multi_lua_clear_all() {
	Lua_packets.next_packet_id = -1;
	Lua_packets.packets_in.clear();
	Lua_packets.packets_out.clear();
}

int multi_lua_initialize_out_packet(){
	lua_packet_data new_packet;
	new_packet.lua_id_number = Lua_packets.next_packet_id;
	new_packet.lua_id_number++;
	new_packet.sent = false;
	Lua_packets.push_back(new_packet);
	return new_packet.lua_id_number_number;
}

void multi_lua_process_in_packet(ubyte* data, header h_info) {
	int offset = 0;

	lua_packet_data new_packet;
	GET_INT(new_packet.lua_id_number);
	
}

void multi_lua_send_packet(int packet_number) {
	ubyte data[MAX_PACKET_SIZE];
	int packet_size;

	BUILD_HEADER(LUA_BASIC)
	
}