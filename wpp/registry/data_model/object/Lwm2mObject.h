/*
 * Lwm2mObject.h
 *
 *  Created on: 20 Jul 2023
 *      Author: valentin
 */

#ifndef WPP_LWM2M_OBJECT_H_
#define WPP_LWM2M_OBJECT_H_

#include "types.h"
#include "ObjectInfo.h"

#include "liblwm2m.h"

namespace wpp {

// TODO: Add ability to get IWppInstance class by ID
class Lwm2mObject {
public:
	Lwm2mObject(const ObjectInfo &info): _objInfo(info) {}
	virtual ~Lwm2mObject() {}

	Lwm2mObject(const Lwm2mObject&) = delete;
	Lwm2mObject(Lwm2mObject&&) = delete;
	Lwm2mObject& operator=(const Lwm2mObject&) = delete;
	Lwm2mObject& operator=(Lwm2mObject&&) = delete;

	OBJ_ID getObjectID() { return _objInfo.objID; }
	lwm2m_object_t& getLwm2mObject() { return _lwm2m_object; }
	const ObjectInfo& getObjectInfo() { return _objInfo; }

	virtual size_t instanceCnt() = 0;
	virtual bool isInstanceExist(ID_T instanceID) = 0;

	virtual void clear() = 0;
	virtual void restore() = 0;

protected:
	lwm2m_object_t _lwm2m_object;
	ObjectInfo _objInfo;
};

} // namespace wpp


#endif /* WPP_LWM2M_OBJECT_H_ */
