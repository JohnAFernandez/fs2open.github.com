
#include "multi_bytestream_manager.h"

#include "network/multimsgs.h"
#include "network/multi_bytestream_manager.h"

bytestream_packet_manager Bytestream_Packet_Manager;

bytestream_packet::bytestream_packet(ubyte flags_in, SCP_string string_key_in, scripting::api::bytearray_h contents_in) {
	flags = flags_in;
	lua_string_key = string_key_in;
	contents = contents_in;
}

void bytestream_packet_manager::send_next_packet()
{
	send_bytestream_packet();
}

void bytestream_packet_manager::add_to_send_queue(bytestream_packet packet_to_send)
{
	_packets_to_send.push(packet_to_send);
}

void bytestream_packet_manager::add_to_send_queue(ubyte flags_in, SCP_string filename_in, scripting::api::bytearray_h contents_in)
{
	bytestream_packet new_packet(flags_in, filename_in, contents_in);
}

void bytestream_packet_manager::add_to_packets_received(bytestream_packet packet_received)
{
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
