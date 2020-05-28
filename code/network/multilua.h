/*
* Copyright (C) Volition, Inc. 1999.  All rights reserved.
*
* All source code herein is the property of Volition, Inc. You may not sell 
* or otherwise commercially exploit the source or things you created based on the 
* source.
*
*/




#ifndef MULTI_MSGS_H
#define MULTI_MSGS_H

#include "globalincs/pstypes.h"

#include <cstdint>

struct net_player;
struct net_addr;
class object;
class ship;
struct wing;
struct header;
struct beam_info;
class ship_subsys;


// for sending information via LUA scripts
struct lua_packet_data{
	int lua_id_number;				// this is to help scipters track which packet is which

	SCP_vector<int>integers;		// the integers to be transmiited in the packet
	SCP_vector<float>floats;		// the floats to be transmiited in the packet
	SCP_vector<SCP_string>strings;	// the strings to be transmiited in the packet

	bool sent[MAX_PLAYERS];			// did we send it to this player (yet?)

	int sender_player_ID;			// who sent this packet to us?
};




void multi_lua_init();

void multi_lua_initialize_packet();