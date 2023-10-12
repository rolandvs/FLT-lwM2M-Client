/*
 * Regestry.h
 *
 *  Created on: 18 Jul 2023
 *      Author: valentin
 */

#ifndef WPP_REGISTRY_H_
#define WPP_REGISTRY_H_

#include <mutex>

#include "Object.h"

/* The start of the includes of the mandatory objects. */
#if OBJ_DEVICE_1_2_M
#include "device_1_2/WppDevice.h"
#endif
#if OBJ_LWM2M_SECURITY_1_2_M
#include "lwm2m_security_1_2/WppLWM2MSecurity.h"
#endif
#if OBJ_LWM2M_SERVER_1_2_M
#include "lwm2m_server_1_2/WppLwM2MServer.h"
#endif
/* The end of the includes of the mandatory objects. */
/* !!! DO NOT DELETE OR CHANGE THE COMMENT ABOVE !!! */

/* The start of the includes of the optional objects. */
#if OPTIONAL_ACL_OBJ
#include "acl/Acl.h"
#endif
#if OPTIONAL_CONN_MONITORING_OBJ
#include "conn_monitoring/ConnMonitoring.h"
#endif
#if OPTIONAL_FIRMWARE_UPD_OBJ
#include "firmware_upd/FirmwareUpd.h"
#endif
/* The end of the includes of the optional objects. */
/* !!! DO NOT DELETE OR CHANGE THE COMMENT ABOVE !!! */

namespace wpp {
// TODO: Split mandatory and optional registers
// TODO: Add ability to check whether some object id is exist
// TODO: Add ability to get Lwm2mObject by ID
// TODO: Try to redesign the registry and objects to simplify access
class WppRegistry {
public:
	WppRegistry(lwm2m_context_t &context);
	~WppRegistry() {}

	WppRegistry(const WppRegistry&) = delete;
	WppRegistry(WppRegistry&&) = delete;
	WppRegistry& operator=(const WppRegistry&) = delete;
	WppRegistry& operator=(WppRegistry&&) = delete;

	bool registerObj(Lwm2mObject &object);
	bool deregisterObj(Lwm2mObject &object);
	bool isObjRegistered(Lwm2mObject &object);

	/* ------------- Mandatory objects prototype start ------------- */
	#if OBJ_DEVICE_1_2_M
	Object <WppDevice> & device();
	#endif
	#if OBJ_LWM2M_SECURITY_1_2_M
	Object <WppLWM2MSecurity> & lWM2MSecurity();
	#endif
	#if OBJ_LWM2M_SERVER_1_2_M
	Object <WppLwM2MServer> & lwM2MServer();
	#endif
	/* The end of the prototypes of the mandatory objects. */
	/* !!! DO NOT DELETE OR CHANGE THE COMMENT ABOVE !!! */

	/* The start of the prototypes of the optional objects. */
	#if OPTIONAL_ACL_OBJ
	Object<Acl>& acl();
	#endif
	#if OPTIONAL_CONN_MONITORING_OBJ
	Object<ConnMonitoring>& connMonitoring();
	#endif
	#if OPTIONAL_FIRMWARE_UPD_OBJ
		Object<FirmwareUpd>& firmwareUpd();
	#endif
	/* The end of the prototypes of the optional objects. */
	/* !!! DO NOT DELETE OR CHANGE THE COMMENT ABOVE !!! */

private:
	lwm2m_context_t &_context;
};

} // namespace wpp

#endif // WPP_REGISTRY_H_
