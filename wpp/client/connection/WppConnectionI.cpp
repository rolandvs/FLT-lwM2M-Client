/*
 * WppConnectionI.cpp
 *
 *  Created on: 22 Jul 2023
 *      Author: valentin
 */

#include "WppConnectionI.h"

//TODO: #include "liblwm2m.h"

namespace wpp {

/* ------------- Connection abilities ------------- */

bool WppConnectionI::addPacketToQueue(Packet packet) {
	Packet tmpPkt = packet;

	tmpPkt.buffer = new uint8_t[packet.length];
	memcpy(tmpPkt.buffer, packet.buffer, packet.length);

	if (!packets.push(&tmpPkt)) {
		delete [] tmpPkt.buffer;
		return false;
	}

	return true;
}

uint8_t WppConnectionI::getPacketQueueSize() {
	return packets.size();
}

bool WppConnectionI::setDataBlockSize(uint16_t size) {
	return true;// TODO: lwm2m_set_coap_block_size(size);
}

uint16_t WppConnectionI::getDataBlockSize()  {
	return 0; // TODO: lwm2m_get_coap_block_size();
}

void WppConnectionI::handlePacketsInQueue(lwm2m_context_t *context) {
	for (size_t i = 0; i < packets.size(); i++) {
		Packet pkt;
		packets.at(i, &pkt);
		packets.pop();

		//lwm2m_handle_packet(context, pkt->buffer, pkt->length, pkt->session);
		delete [] pkt.buffer;
	}
}

} /* namespace wpp */
