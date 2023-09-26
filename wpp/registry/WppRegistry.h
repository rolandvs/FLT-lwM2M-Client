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
#if MANDATORY_SECURITY_OBJ
#include "mandatory/security/Security.h"
#endif
#if MANDATORY_SERVER_OBJ
#include "mandatory/server/Server.h"
#endif
#if MANDATORY_DEVICE_OBJ
#include "mandatory/device/Device.h"
#endif
/* The end of the includes of the mandatory objects. */
/* !!! DO NOT DELETE OR CHANGE THE COMMENT ABOVE !!! */

/* The start of the includes of the optional objects. */
#if OPTIONAL_ACL_OBJ
#include "optional/acl/Acl.h"
#endif
#if OPTIONAL_CONN_MONITORING_OBJ
#include "optional/conn_monitoring/ConnMonitoring.h"
#endif
#if OPTIONAL_FIRMWARE_UPD_OBJ
#include "optional/firmware_upd/FirmwareUpd.h"
#endif
/* The end of the includes of the optional objects. */
/* !!! DO NOT DELETE OR CHANGE THE COMMENT ABOVE !!! */

namespace wpp {

class WppClient;

template<typename T>
class Object;

// TODO: Split mandatory and optional registers
// TODO: Add ability to check whether some object id is exist
// TODO: Add ability to get Lwm2mObject by ID
// TODO: Try to redesign the registry and objects to simplify access
class WppRegistry {
public:
	WppRegistry(WppClient &client);
	~WppRegistry() {}

	WppRegistry(const WppRegistry&) = delete;
	WppRegistry(WppRegistry&&) = delete;
	WppRegistry& operator=(const WppRegistry&) = delete;
	WppRegistry& operator=(WppRegistry&&) = delete;

	/* The start of the prototypes of the mandatory objects. */
	#if MANDATORY_SECURITY_OBJ
	Object<Security>& security();
	#endif
	#if MANDATORY_SERVER_OBJ
	Object<Server>& server();
	#endif
	#if MANDATORY_DEVICE_OBJ
	Object<Device>& device();
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
	WppClient &_client;
};

} // namespace wpp

#endif // WPP_REGISTRY_H_
