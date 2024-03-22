/*
 * Device
 * Generated on: 2023-11-02 16:38:01
 * Created by: SinaiR&D
 */

#ifndef WPP_M_3_DEVICE_H
#define WPP_M_3_DEVICE_H

#include "DeviceConfig.h"
#include "DeviceInfo.h"
#include "Instance.h"
#include "InstSubject.h"

/* --------------- Сode_h block 0 start --------------- */
#include "WppTaskQueue.h"
#include "WppBindings.h"
/* --------------- Сode_h block 0 end --------------- */

namespace wpp {

class Device : public Instance {
public:
	enum ID: ID_T {
		#if RES_3_0
		MANUFACTURER_0 = 0,
		#endif
		#if RES_3_1
		MODEL_NUMBER_1 = 1,
		#endif
		#if RES_3_2
		SERIAL_NUMBER_2 = 2,
		#endif
		#if RES_3_3
		FIRMWARE_VERSION_3 = 3,
		#endif
		REBOOT_4 = 4,
		#if RES_3_5
		FACTORY_RESET_5 = 5,
		#endif
		#if RES_3_6
		AVAILABLE_POWER_SOURCES_6 = 6,
		#endif
		#if RES_3_7
		POWER_SOURCE_VOLTAGE_7 = 7,
		#endif
		#if RES_3_8
		POWER_SOURCE_CURRENT_8 = 8,
		#endif
		#if RES_3_9
		BATTERY_LEVEL_9 = 9,
		#endif
		#if RES_3_10
		MEMORY_FREE_10 = 10,
		#endif
		ERROR_CODE_11 = 11,
		#if RES_3_12
		RESET_ERROR_CODE_12 = 12,
		#endif
		#if RES_3_13
		CURRENT_TIME_13 = 13,
		#endif
		#if RES_3_14
		UTC_OFFSET_14 = 14,
		#endif
		#if RES_3_15
		TIMEZONE_15 = 15,
		#endif
		SUPPORTED_BINDING_AND_MODES_16 = 16,
		#if RES_3_17
		DEVICE_TYPE_17 = 17,
		#endif
		#if RES_3_18
		HARDWARE_VERSION_18 = 18,
		#endif
		#if RES_3_19
		SOFTWARE_VERSION_19 = 19,
		#endif
		#if RES_3_20
		BATTERY_STATUS_20 = 20,
		#endif
		#if RES_3_21
		MEMORY_TOTAL_21 = 21,
		#endif
		#if RES_3_22
		EXTDEVINFO_22 = 22,
		#endif
	};

	/* --------------- Code_h block 1 start --------------- */
	#if RES_3_6
	enum PwrSrcs: uint8_t {
		DC = 0,
		INTERN_BAT = 1,
		EXTERN_BAT = 2,
		FUEL_CELL = 3,
		PWR_OVER_ETHERNET = 4,
		USB = 5,
		AC = 6,
		SOLAR = 7,
		PWR_SRC_MAX
	};
	#endif

	enum ErrCode: uint8_t {
		NO_ERROR = 0,
		LOW_BAT = 1,
		EXT_PWR_SUPP_OFF = 2,
		GPS_FAIL = 3,
		LOW_SIG_STRENGTH = 4,
		OUT_OF_MEM = 5,
		SMS_FAIL = 6,
		IP_CONN_FAIL = 7,
		PERIPH_FAIL = 8,
		ERR_CODE_MAX
	};

	#if RES_3_20
	enum BatStatus {
		NORMAL = 0,
		CHARGING = 1,
		CHARGED = 2,
		DAMAGED = 3,
		LOW_BATTERY = 4,
		NOT_INSTALLED = 5,
		UNKNOWN = 6,
		BAT_STATUS_MAX
	};
	#endif
	/* --------------- Code_h block 1 end --------------- */

public:
	Device(lwm2m_context_t &context, const OBJ_LINK_T &id);
	~Device();

	/* --------------- Code_h block 2 start --------------- */
	/* --------------- Code_h block 2 end --------------- */

protected:
	/* --------------- Instance implementation part --------------- */
	/*
	 * Reset all resources values and internal state to default.
	 */
	void setDefaultState() override;
	/*
	 * Handles information about resource operation that made server
	 */
	void serverOperationNotifier(ID_T securityInstId, ResOp::TYPE type, const ResLink &resId) override;
	/*
	 * Handles information about resource operation that made user
	 */
	void userOperationNotifier(ResOp::TYPE type, const ResLink &resId) override;

	/* --------------- Code_h block 3 start --------------- */
	/* --------------- Code_h block 3 end --------------- */

private:
	/* --------------- Class private methods --------------- */
	/*
	 * Creates resources without initializing.
	 */
	void resourcesCreate();
	/*
	 * Initialize resources with default values
	 * Resource always must have at least one instance.
	 * Note: From server side, empty resource == undefined resource.
	 */	
	void resourcesInit();
	
	/* --------------- Code_h block 4 start --------------- */
	/* --------------- Code_h block 4 end --------------- */

private:
	/* --------------- Class private properties --------------- */
	/* --------------- Code_h block 5 start --------------- */
	#if RES_3_13
	WppTaskQueue::task_id_t _currentTimeTaskId;
	#endif
	/* --------------- Code_h block 5 end --------------- */
};

} /* namespace wpp */

#endif /* WPP_M_3_DEVICE_H */
