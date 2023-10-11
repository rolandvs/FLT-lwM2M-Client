/*
 * WppLwM2MServer
 * Generated on: 2023-10-11 15:47:20.421450
 * Author: valentin
 * Generated by: Vadimzakreva
 */

#include "mandatory/lwm2m_server_1_2/WppLwM2MServer.h"

#include <unordered_map>
#include <iostream>

#include "Resource.h"
#include "ResOp.h"
#include "types.h"
#include "WppLogs.h"

/* --------------- Code_cpp block 0 start --------------- */
#if RES_APN_LINK_1_10
#define TLS_DTLS_ALERT_CODE_MIN	0
#define TLS_DTLS_ALERT_CODE_MAX	255
#endif
/* --------------- Code_cpp block 0 end --------------- */

#define TAG "WppLwM2MServer"

namespace wpp {

WppLwM2MServer::WppLwM2MServer(lwm2m_context_t &context, const OBJ_LINK_T &id): Instance(context, id) {

	/* --------------- Code_cpp block 1 start --------------- */
	/* --------------- Code_cpp block 1 end --------------- */

	resourcesInit();

	/* --------------- Code_cpp block 2 start --------------- */
	/* --------------- Code_cpp block 2 end --------------- */
}

WppLwM2MServer::~WppLwM2MServer() {
	/* --------------- Code_cpp block 3 start --------------- */
	/* --------------- Code_cpp block 3 end --------------- */
}

Resource * WppLwM2MServer::getResource(ID_T id) {
	// Check if resource ID is valid
	if (_resources.find(id) == _resources.end()) return NULL;
	return &_resources[id];
}

std::vector<Resource *> WppLwM2MServer::getResourcesList() {
	std::vector<Resource *> list;
	for (auto &pair : _resources) {
		list.push_back(&pair.second);
	}
	return list;
}

std::vector<Resource *> WppLwM2MServer::getResourcesList(const ResOp& filter) {
	std::vector<Resource *> list;
	for (auto &pair : _resources) {
		if (filter.isCompatible(pair.second.getOperation())) list.push_back(&pair.second);
	}
	return list;
}

std::vector<Resource *> WppLwM2MServer::getInstantiatedResourcesList() {
	std::vector<Resource *> list;
	for (auto &pair : _resources) {
		if (!pair.second.isEmpty()) list.push_back(&pair.second);
	}
	return list;
}

std::vector<Resource *> WppLwM2MServer::getInstantiatedResourcesList(const ResOp& filter) {
	std::vector<Resource *> list;
	for (auto &pair : _resources) {
		if (!pair.second.isEmpty() && filter.isCompatible(pair.second.getOperation())) list.push_back(&pair.second);
	}
	return list;
}

void WppLwM2MServer::setDefaultState() {
	/* --------------- Code_cpp block 4 start --------------- */
	/* --------------- Code_cpp block 4 end --------------- */

	for (auto &pair : _resources) pair.second.clear();
	resourcesInit();

	/* --------------- Code_cpp block 5 start --------------- */
	/* --------------- Code_cpp block 5 end --------------- */
}

void WppLwM2MServer::serverOperationNotifier(ResOp::TYPE type, const ResLink &resId) {
	/* --------------- Code_cpp block 6 start --------------- */
	/* --------------- Code_cpp block 6 end --------------- */

	observerNotify(*this, resId, type);

	/* --------------- Code_cpp block 7 start --------------- */
	switch (type) {
	case ResOp::READ:
		WPP_LOGD_ARG(TAG, "Server READ -> resId: %d, resInstId: %d", resId.resId, resId.resInstId);
		break;
	case ResOp::WRITE:
		WPP_LOGD_ARG(TAG, "Server WRITE -> resId: %d, resInstId: %d", resId.resId, resId.resInstId);
		break;
	case ResOp::EXECUTE:
		WPP_LOGD_ARG(TAG, "Server EXECUTE -> resId: %d, resInstId: %d", resId.resId, resId.resInstId);
		break;
	case ResOp::DISCOVER:
		WPP_LOGD_ARG(TAG, "Server DISCOVER -> resId: %d, resInstId: %d", resId.resId, resId.resInstId);
		break;
	case ResOp::DELETE:
		WPP_LOGD_ARG(TAG, "Server DELETE -> resId: %d, resInstId: %d", resId.resId, resId.resInstId);
		break;
	default: break;
	}
	/* --------------- Code_cpp block 7 end --------------- */
}

void WppLwM2MServer::userOperationNotifier(ResOp::TYPE type, const ResLink &resId) {
	/* --------------- Code_cpp block 8 start --------------- */
	switch (type) {
	case ResOp::READ:
		WPP_LOGD_ARG(TAG, "User READ -> resId: %d, resInstId: %d", resId.resId, resId.resInstId);
		break;
	case ResOp::WRITE:
		WPP_LOGD_ARG(TAG, "User WRITE -> resId: %d, resInstId: %d", resId.resId, resId.resInstId);
		break;
	case ResOp::DELETE:
		WPP_LOGD_ARG(TAG, "User DELETE -> resId: %d, resInstId: %d", resId.resId, resId.resInstId);
		break;
	default: break;
	}
	/* --------------- Code_cpp block 8 end --------------- */
}

	/* --------------- Class private methods --------------- */
void WppLwM2MServer::resourcesInit() {
	/* --------------- Code_cpp block 9 start --------------- */
	// TODO: The most part of the server resources logic must be implemented
	// on wakaama core level, because the Server is only a state holder and
	// at this level, it does not have the required information for doing
	// sings described in the documentation.
	// TODO: Disable (Res id 4) must be implemented by wakaama core or WppClient
	// TODO: Notification Storing (Res id 6) must be implemented by wakaama core
	// TODO: Registration Update (Res id 8) must be implemented by wakaama core or WppClient
	// TODO: Bootstrap Request (Res id 9) must be implemented by wakaama core or WppClient
	_resources[BINDING_7].setDataVerifier((VERIFY_STRING_T)([this](const STRING_T& value) { return this->isBindingValid(value); }));
	#if RES_APN_LINK_1_10
	_resources[APN_LINK_10].setDataVerifier((VERIFY_UINT_T)[](const UINT_T& value) { return TLS_DTLS_ALERT_CODE_MIN <= value && value <= TLS_DTLS_ALERT_CODE_MAX; });
	#endif
	#if RES_PREFERRED_TRANSPORT_1_22
	_resources[PREFERRED_TRANSPORT_22].setDataVerifier((VERIFY_STRING_T)([this](const STRING_T& value) { return this->isBindingValid(value); }));
	#endif
	/* --------------- Code_cpp block 9 end --------------- */
}

/* --------------- Code_cpp block 10 start --------------- */
ool isBindingValid(const STRING_T& binding) {
	if(binding == WPP_SERV_BINDING_UDP) return true;
	if(binding == WPP_SERV_BINDING_TCP) return true;
	if(binding == WPP_SERV_BINDING_SMS) return true;
	if(binding == WPP_SERV_BINDING_NON_IP) return true;
	return false;
}
/* --------------- Code_cpp block 10 end --------------- */

} /* namespace wpp */
