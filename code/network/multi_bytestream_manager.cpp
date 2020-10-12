
#include "multi_bytestream_manager.h"

#include "network/multimsgs.h"
#include "network/multi_bytestream_manager.h"

bytestream_packet_manager Bytestream_Packet_Manager;

bytestream_packet::bytestream_packet(ubyte flags_in, SCP_string string_key_in, scripting::api::bytearray_h contents_in, int recipient_flags, bool rebroadcast, int team = -1) {
	_flags = flags_in; // is flags_in going to be the same as recipient flags???/
	_string_key = string_key_in;
	_contents = contents_in;
}

bool bytestream_packet::send() 
{
	if (_flags& /*Needs correct condition here*/) {
		return send_bytestream_packet(_contents, _string_key, /*more flags to set this true or false*/, /*need to figure this one out too*/);
	}
	else {
		return false;
	}
}

SCP_string bytestream_packet::get_string_key()
{
	return _string_key;
}

void bytestream_packet_manager::send_next_packet()
{
	bytestream_packet packet_out = _packets_to_send.front();
	_packets_to_send.pop();
}

void bytestream_packet_manager::add_to_send_queue(bytestream_packet* packet_to_send)
{
	_packets_to_send.push(packet_to_send);
}

void bytestream_packet_manager::add_to_send_queue(ubyte flags_in, SCP_string string_key_in, scripting::api::bytearray_h contents_in, int recipient_flags, bool rebroadcast, int team)
{
	bytestream_packet new_packet(flags_in, string_key_in, contents_in, recipient_flags, rebroadcast, team);
}

void bytestream_packet_manager::add_to_packets_received(bytestream_packet* packet_received)
{
	_packets_received.find(packet_received->get_string_key());
	_packets_received.push_back(packet_received);
}

void bytestream_packet_manager::clear_all_received_packets() 
{
	_packets_received.clear();
}

void bytestream_packet_manager::clear_all_outbound_packets()
{
	while (!_packets_to_send.empty()) {
		_packets_to_send.pop();
	}
}

void bytestream_packet_manager::clear_all()
{
	clear_all_received_packets();
	clear_all_outbound_packets();
}

size_t bytestream_packet_manager::get_sending_queue_size()
{
	return _packets_to_send.size();
}

void bytestream_packet_manager::get_packet_contents()
{

}

void bytestream_packet_manager::do_frame()
{
	// sanity
	if (!(Game_mode & GM_MULTIPLAYER)) {
		return;
	}

	
	if (!_packets_to_send.empty()) {
		send_next_packet();
	}

	
}

int bytestream_packet_manager::get_next_packet_id() 
{
	return _next_packet_id++;
}
