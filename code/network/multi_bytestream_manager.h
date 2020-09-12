#pragma
#include "globalincs/pstypes.h"
#include "scripting/api/objs/bytearray.h"

constexpr ubyte			REBROADCAST	(1<<0);
constexpr ubyte   NO_SERVER_PROCESS	(1<<1);
constexpr ubyte			   ADDENDUM (1>>2);

constexpr int ALLOWED_KEY_SIZE (FILENAME_MAX * 4);

// limitation of this system is that if you are the client asking the server  to rebroadcast
// a client's message, there's no way to tell the server to only send the packet to individual recipients
// but we can send to a particular team and indiciate if this packet is for the server to process as well

struct bytestream_packet {
	int _player_id;							// the originating player, according to the server's index
	int _packet_id;							// the incoming packet id, *can* be used to distinguish one packet from another
	int _first_message_id;					// if this message was an addendum, what was the original 
	int _addendum_index;					// if this message is an addendum, what 
	ubyte _flags;							// who are we sending this to?  Does the server process this packets?
	SCP_string lua_string_key;				// how lua recognizes this packet.
	scripting::api::bytearray_h contents;	// the actual contents of the data being transmitted.

	bytestream_packet(ubyte flags_in, SCP_string filename_in, scripting::api::bytearray_h contents_in, int recipient_flags, bool rebroadcast, int team = -1 );
};

class bytestream_packet_manager {

private:
	std::queue <bytestream_packet> _packets_to_send;
	SCP_unordered_map<SCP_string, SCP_vector<bytestream_packet>> _packets_received;
	int _next_packet_id;



	void send_next_packet();
	int get_next_packet_id();

public:

	// functions to manage the messages within
	void add_to_send_queue(bytestream_packet packet_to_send);
	void add_to_send_queue(ubyte flags_in, SCP_string filename_in, scripting::api::bytearray_h contents_in);
	void add_to_packets_received(bytestream_packet packet_received);
	void clear_all_outbound_packets();
	void clear_all_received_packets();
	void clear_all();

	size_t get_sending_queue_size();

	void get_packet_contents();

	void do_frame();

	bytestream_packet find_matching_packet(SCP_string string_key_to_search);
};

extern bytestream_packet_manager Bytestream_Packet_Manager;
