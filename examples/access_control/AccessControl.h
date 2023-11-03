#ifndef ACCESS_CONTROL_H_
#define ACCESS_CONTROL_H_

#include <iostream>
#include "WppRegistry.h"
#include "ObjObserver.h"
#include "InstObserver.h"

#include <ifaddrs.h>

using namespace wpp;
using namespace std;


class AccessControl: public ObjObserver, public InstObserver {
	public:
	void init(Object &accssCtrlObj) {
		accssCtrlObj.subscribe(this);
        Instance *accssCtrl = accssCtrlObj.createInstance();
        accssCtrl->subscribe(this);

        accssCtrl->set(wpp::Lwm2mAccessControl::OBJECT_ID_0, INT_T(35464));
        accssCtrl->set(wpp::Lwm2mAccessControl::OBJECT_INSTANCE_ID_1, INT_T(35464));
        accssCtrl->set(wpp::Lwm2mAccessControl::ACCESS_CONTROL_OWNER_3, INT_T(35464));

        #if RES_2_2
        uint8_t acl = 0;
        acl |= (1 << wpp::Lwm2mAccessControl::ACL::LSB_READ);
        acl |= (1 << wpp::Lwm2mAccessControl::ACL::LSB_WRITE);
        acl |= (1 << wpp::Lwm2mAccessControl::ACL::LSB_EXEC);
        accssCtrl->set(wpp::Lwm2mAccessControl::ACL_2, INT_T(acl));
        #endif
	}

	void objectRestore(Object &object) override {
		cout << "AccessControl: objectRestore: " << (ID_T)object.getObjectID() << endl;
		object.clear();
        init(object);
	}

    void instanceCreated(Object &object, ID_T instanceId) override {
        cout << "AccessControl: instanceCreated: " << (ID_T)object.getObjectID() << ":" << instanceId << endl;
    }

    void instanceDeleting(Object &object, ID_T instanceId) override {
		cout << "AccessControl: instanceDeleting: " << (ID_T)object.getObjectID() << ":" << instanceId << endl;
	}

	void resourceRead(Instance &inst, const ResLink &resId) override {
        cout << "AccessControl: resourceRead: " << (ID_T)inst.getObjectID() << ":" << inst.getInstanceID() << ":" << resId.resId << ":" << resId.resInstId << endl;
    }

    void resourceWrite(Instance &inst, const ResLink &resId) override {
        cout << "AccessControl: resourceWrite: " << (ID_T)inst.getObjectID() << ":" << inst.getInstanceID() << ":" << resId.resId << ":" << resId.resInstId << endl;
    }

    void resourceExecute(Instance &inst, const ResLink &resId) override {
        cout << "AccessControl: resourceExecute: " << (ID_T)inst.getObjectID() << ":" << inst.getInstanceID() << ":" << resId.resId << ":" << resId.resInstId << endl;
    }

    void resourcesReplaced(Instance &inst) override {
        cout << "AccessControl: resourcesReplaced: " << (ID_T)inst.getObjectID() << ":" << inst.getInstanceID() << endl;
    }
};

#endif // ACCESS_CONTROL_H_
