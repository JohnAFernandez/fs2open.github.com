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
class lua_multi_packet{
	protected:
		int lua_packet_id		= 0;	// this is to help scipters track which packet is which

		ubyte lua_type			= 0;

		SCP_vector<int>integers;		// the integers to be transmiited in the packet
		SCP_vector<float>floats;		// the floats to be transmiited in the packet
		SCP_vector<SCP_string>strings;	// the strings to be transmiited in the packet
		SCP_vector<bool>bools;

		bool sent[MAX_PLAYERS];			// did we send it to this player (yet?)

};

class lua_received_packet : lua_multi_packet {	
	public:


};

class lua_sending_packet : lua_multi_packet {
	bool sent_to[MAX_PLAYERS];
};



void multi_lua_init();

void multi_lua_initialize_packet();