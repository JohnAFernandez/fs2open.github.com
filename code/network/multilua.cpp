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

const int MAX_LUA_PACKET_ID = INT_MAX;
const ushort MINIMUM_LUA_PACKET_LEN = 8;	//header ubyte, lua header ushort, packet size ushort, 4 length numbers (ubytes)
const int BOOLS_PER_UBYTE = 8;				// used for calculating bool size.

struct lua_packet_organizer{
	int next_packet_id = -1;	// this will probably get switched out later.
	SCP_vector<lua_sending_packet>packets_out;
	SCP_vector<lua_received_packet>packets_in[MAX_PLAYERS];
	
	int reading_from = 0;
	int reading_to = 0;
};

lua_packet_organizer Lua_packets;

void multi_lua_clear_all() {
	Lua_packets.next_packet_id = -1; // this needs to be reset to the the a player net_signature
	Lua_packets.packets_out.clear();
	for (int i = 0; i < MAX_PLAYERS; i++) {
		Lua_packets.packets_in[i].clear();
	}
}


int multi_lua_initialize_out_packet(){
	lua_sending_packet new_packet;
	new_packet.lua_id_number = Lua_packets.next_packet_id;
	Lua_packets.next_packet_id++;
	if (Lua_packets.next_packet_id == MAX_LUA_PACKET_ID)

	new_packet.sent = false;
	Lua_packets.packets_out.push_back(new_packet);
	return new_packet.lua_id_number_number;
}

bool multi_lua_send_packet(int packet_id, int mode, player* pl) {
	// make sure everything is safe
	if (pl == nullptr) {
		return false;
	}
	
	lua_sending_packet* packetp = &Lua_packets.packets_in[packet_in];

	if (packetp == nullptr) {
		return false;
	}

	// basic packet variables
	ubyte data[MAX_PACKET_SIZE];
	int packet_size = 0;	

	BUILD_HEADER(LUA_BASIC);

	ADD_USHORT(packetp->lua_type);

	// Begin calculating the packet length

	ubyte integer_size = (ubyte)packetp->integers.size();
	ubyte float_size = (ubyte)packetp->floats.size();

	ubyte bool_count = (ushort)packetp->bools.size();
	ubyte bool_size = 0;
	if (bool_count > 0){
		bool_size = 1 + ((bool_count -1) / BOOLS_PER_UBYTE); // 8 bools needs to return 1, not 2, same situation with multiples of 8.
	}

	ushort string_count = packetp->strings.size();
	ushort string_size;
	for (auto & string : packetp->strings) {
		string_size += string.len();
	}

	// add the sizes of the number of ints and floats everything except the strings, since those we hae to add one at a time.
	int anticipated_packet_length = MINIMUM_LUA_PACKET_LEN + integer_size + float_size + bool_size + string_size;

	ADD_USHORT(anticipated_packet_length);

	+	ADD_DATA(integer_size);

	ADD_
		for (auto& integers : packetp->integers) {
			ADDintegers
		}
	for (auto& integers : packetp->integers) {
		ADD_INT(integers);
	}

	ADD_DATA(float_size);

	for (auto& floats : packetp->floats) {
		ADD_FLOAT(floats)
	}

	ADD_DATA(bool_size);

	anticipated_packet_length +=  ;

	for (int i = 0; i < bool_size; i++) {
		ubyte mask = 0;
		for (int j = 0; j < 8; j++) {
			mask |= (int)packetp->bools[(i * 8) + j] << j;
		}
	}

	ADD_DATA(string_size);

	for (auto& strings : packetp_strings) {
		ADD_STRING(strings);
	}


	// send to different players based on the supplied mode.

	
	
}

void multi_lua_process_packet(ubyte* data, header* h_info) {
	int offset = 0;

	lua_received_packet new_packet;
	GET_INT(new_packet.lua_id_number);
	
}

void multi_lua_send_packet(int packet_number) {

	BUILD_HEADER(LUA_BASIC)
	
}