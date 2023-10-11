/*
 * WppLWM2MSecurity
 * Generated on: 2023-10-11 15:44:03.536311
 * Author: valentin
 * Generated by: Vadimzakreva
 */

#ifndef WPP_LWM2M_SECURITY_1_2_H
#define WPP_LWM2M_SECURITY_1_2_H

#include "WppLWM2MSecurityConfig.h"
#include "WppLWM2MSecurityInfo.h"
#include "Instance.h"
#include "InstSubject.h"

/* --------------- Сode_h block 0 start --------------- */
/* --------------- Сode_h block 0 end --------------- */

namespace wpp {

class WppLWM2MSecurity : public Instance, public InstSubject<WppLWM2MSecurity> {
public:
	enum ID: ID_T {
		LWM2M_SERVER_URI_0 = 0,
		BOOTSTRAP_SERVER_1 = 1,
		SECURITY_MODE_2 = 2,
		PUBLIC_KEY_OR_IDENTITY_3 = 3,
		SERVER_PUBLIC_KEY_4 = 4,
		SECRET_KEY_5 = 5,
		SMS_SECURITY_MODE_6 = 6,
		SMS_BINDING_KEY_PARAMETERS_7 = 7,
		SMS_BINDING_SECRET_KEY_S__8 = 8,
		LWM2M_SERVER_SMS_NUMBER_9 = 9,
		SHORT_SERVER_ID_10 = 10,
		CLIENT_HOLD_OFF_TIME_11 = 11,
		BOOTSTRAP_SERVER_ACCOUNT_TIMEOUT_12 = 12,
		MATCHING_TYPE_13 = 13,
		SNI_14 = 14,
		CERTIFICATE_USAGE_15 = 15,
		DTLS_TLS_CIPHERSUITE_16 = 16,
		OSCORE_SECURITY_MODE_17 = 17,
		GROUPS_TO_USE_BY_CLIENT_18 = 18,
		SIGNATURE_ALGORITHMS_SUPPORTED_BY_SERVER_19 = 19,
		SIGNATURE_ALGORITHMS_TO_USE_BY_CLIENT_20 = 20,
		SIGNATURE_ALGORITHM_CERTS_SUPPORTED_BY_SERVER_21 = 21,
		TLS_1_3_FEATURES_TO_USE_BY_CLIENT_22 = 22,
		TLS_EXTENSIONS_SUPPORTED_BY_SERVER_23 = 23,
		TLS_EXTENSIONS_TO_USE_BY_CLIENT_24 = 24,
		SECONDARY_LWM2M_SERVER_URI_25 = 25,
		MQTT_SERVER_26 = 26,
		LWM2M_COSE_SECURITY_27 = 27,
		RDS_DESTINATION_PORT_28 = 28,
		RDS_SOURCE_PORT_29 = 29,
		RDS_APPLICATION_ID_30 = 30,
	};

	/* --------------- Code_h block 1 start --------------- */
	#if RES_SMS_SECURITY_MODE_0_6
	enum SmsSecMode: uint8_t {
		SMS_SEC_MODE_MIN = 0,
		SMS_SEC_DTLS_PSK = 1,
		SMS_SEC_PACK_STRUCT = 2,
		SMS_NO_SEC = 3,
		SMS_SEC_MODE_MAX = 255
	};
	#endif

	#if RES_SMS_BINDING_SECRET_KEY_S__0_8
	enum SmsKeyLen: uint8_t {
		MIN_SMS_KEY_LEN = 16,
		MAX_SMS_KEY_LEN = 48
	};
	#endif

	#if RES_MATCHING_TYPE_0_13
	enum MatchType: uint8_t {
		EXACT_MATCH = 0,
		SHA_256 = 1,
		SHA_384 = 2,
		SHA_512 = 3,
		MAX_MATCH_TYPE
	};
	#endif

	#if RES_CERTIFICATE_USAGE_0_15
	enum CertUsage: uint8_t {
		CA_CONSTRAINT = 0,
		SERVICE_CERT_CONSTRAINT = 1,
		TRUST_ANCHOR_ASSERTION = 2,
		DOMAIN_ISSUED_CERT = 3,
		MAX_CERT_USAGE
	};
	#endif
	/* --------------- Code_h block 1 end --------------- */

public:
	WppLWM2MSecurity(lwm2m_context_t &context, const OBJ_LINK_T &id);
	~WppLWM2MSecurity();

	/* --------------- Code_h block 2 start --------------- */
	/* --------------- Code_h block 2 end --------------- */

protected:
	/* --------------- Instance implementation part --------------- */
	/* 
	 * Returns Resource object if it is exist
	 */
	Resource * getResource(ID_T id) override;
	/*
	 * Returns list with available resources
	 */
	std::vector<Resource *> getResourcesList() override;
	std::vector<Resource *> getResourcesList(const ResOp& filter) override;
	/*
	 * Returns list with available instantiated resources
	 */
	std::vector<Resource *> getInstantiatedResourcesList() override;
	std::vector<Resource *> getInstantiatedResourcesList(const ResOp& filter) override;
	/*
	 * Reset all resources values and internal state to default.
	 */
	void setDefaultState() override;
	/*
	 * Handles information about resource operation that made server
	 */
	void serverOperationNotifier(ResOp::TYPE type, const ResLink &resId) override;
	/*
	 * Handles information about resource operation that made user
	 */
	void userOperationNotifier(ResOp::TYPE type, const ResLink &resId) override;

private:
	/* --------------- Class private methods --------------- */
	/*
	 * Initialize resources with default values
	 * Resource always must have at least one instance.
	 */	
	void resourcesInit();
	
	/* --------------- Code_h block 3 start --------------- */
	/* --------------- Code_h block 3 end --------------- */

private:
	std::unordered_map<ID_T, Resource> _resources = {
		// KEY   VALUE
		{LWM2M_SERVER_URI_0,                                              {LWM2M_SERVER_URI_0,                                      ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::MANDATORY,        TYPE_ID::STRING }},          
		{BOOTSTRAP_SERVER_1,                                              {BOOTSTRAP_SERVER_1,                                      ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::MANDATORY,        TYPE_ID::BOOL }},            
		{SECURITY_MODE_2,                                                 {SECURITY_MODE_2,                                         ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::MANDATORY,        TYPE_ID::INT }},             
		{PUBLIC_KEY_OR_IDENTITY_3,                                        {PUBLIC_KEY_OR_IDENTITY_3,                                ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::MANDATORY,        TYPE_ID::OPAQUE }},          
		{SERVER_PUBLIC_KEY_4,                                             {SERVER_PUBLIC_KEY_4,                                     ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::MANDATORY,        TYPE_ID::OPAQUE }},          
		{SECRET_KEY_5,                                                    {SECRET_KEY_5,                                            ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::MANDATORY,        TYPE_ID::OPAQUE }},          
		#if RES_SMS_SECURITY_MODE_0_6                                                                                                                                                                                                                                
		{SMS_SECURITY_MODE_6,                                             {SMS_SECURITY_MODE_6,                                     ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::INT }},             
		#endif                                                                                                                                                                                                                                                       
		#if RES_SMS_BINDING_KEY_PARAMETERS_0_7                                                                                                                                                                                                                       
		{SMS_BINDING_KEY_PARAMETERS_7,                                    {SMS_BINDING_KEY_PARAMETERS_7,                            ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::OPAQUE }},          
		#endif                                                                                                                                                                                                                                                       
		#if RES_SMS_BINDING_SECRET_KEY_S__0_8                                                                                                                                                                                                                        
		{SMS_BINDING_SECRET_KEY_S__8,                                     {SMS_BINDING_SECRET_KEY_S__8,                             ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::OPAQUE }},          
		#endif                                                                                                                                                                                                                                                       
		#if RES_LWM2M_SERVER_SMS_NUMBER_0_9                                                                                                                                                                                                                          
		{LWM2M_SERVER_SMS_NUMBER_9,                                       {LWM2M_SERVER_SMS_NUMBER_9,                               ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::STRING }},          
		#endif                                                                                                                                                                                                                                                       
		#if RES_SHORT_SERVER_ID_0_10                                                                                                                                                                                                                                 
		{SHORT_SERVER_ID_10,                                              {SHORT_SERVER_ID_10,                                      ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::INT }},             
		#endif                                                                                                                                                                                                                                                       
		#if RES_CLIENT_HOLD_OFF_TIME_0_11                                                                                                                                                                                                                            
		{CLIENT_HOLD_OFF_TIME_11,                                         {CLIENT_HOLD_OFF_TIME_11,                                 ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::INT }},             
		#endif                                                                                                                                                                                                                                                       
		#if RES_BOOTSTRAP_SERVER_ACCOUNT_TIMEOUT_0_12                                                                                                                                                                                                                
		{BOOTSTRAP_SERVER_ACCOUNT_TIMEOUT_12,                             {BOOTSTRAP_SERVER_ACCOUNT_TIMEOUT_12,                     ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::INT }},             
		#endif                                                                                                                                                                                                                                                       
		#if RES_MATCHING_TYPE_0_13                                                                                                                                                                                                                                   
		{MATCHING_TYPE_13,                                                {MATCHING_TYPE_13,                                        ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_SNI_0_14                                                                                                                                                                                                                                             
		{SNI_14,                                                          {SNI_14,                                                  ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::STRING }},          
		#endif                                                                                                                                                                                                                                                       
		#if RES_CERTIFICATE_USAGE_0_15                                                                                                                                                                                                                               
		{CERTIFICATE_USAGE_15,                                            {CERTIFICATE_USAGE_15,                                    ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_DTLS_TLS_CIPHERSUITE_0_16                                                                                                                                                                                                                            
		{DTLS_TLS_CIPHERSUITE_16,                                         {DTLS_TLS_CIPHERSUITE_16,                                 ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::MULTIPLE,        IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_OSCORE_SECURITY_MODE_0_17                                                                                                                                                                                                                            
		{OSCORE_SECURITY_MODE_17,                                         {OSCORE_SECURITY_MODE_17,                                 ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::OBJ_LINK }},        
		#endif                                                                                                                                                                                                                                                       
		#if RES_GROUPS_TO_USE_BY_CLIENT_0_18                                                                                                                                                                                                                         
		{GROUPS_TO_USE_BY_CLIENT_18,                                      {GROUPS_TO_USE_BY_CLIENT_18,                              ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::MULTIPLE,        IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_SIGNATURE_ALGORITHMS_SUPPORTED_BY_SERVER_0_19                                                                                                                                                                                                        
		{SIGNATURE_ALGORITHMS_SUPPORTED_BY_SERVER_19,                     {SIGNATURE_ALGORITHMS_SUPPORTED_BY_SERVER_19,             ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::MULTIPLE,        IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_SIGNATURE_ALGORITHMS_TO_USE_BY_CLIENT_0_20                                                                                                                                                                                                           
		{SIGNATURE_ALGORITHMS_TO_USE_BY_CLIENT_20,                        {SIGNATURE_ALGORITHMS_TO_USE_BY_CLIENT_20,                ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::MULTIPLE,        IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_SIGNATURE_ALGORITHM_CERTS_SUPPORTED_BY_SERVER_0_21                                                                                                                                                                                                   
		{SIGNATURE_ALGORITHM_CERTS_SUPPORTED_BY_SERVER_21,                {SIGNATURE_ALGORITHM_CERTS_SUPPORTED_BY_SERVER_21,        ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::MULTIPLE,        IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_TLS_1_3_FEATURES_TO_USE_BY_CLIENT_0_22                                                                                                                                                                                                               
		{TLS_1_3_FEATURES_TO_USE_BY_CLIENT_22,                            {TLS_1_3_FEATURES_TO_USE_BY_CLIENT_22,                    ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_TLS_EXTENSIONS_SUPPORTED_BY_SERVER_0_23                                                                                                                                                                                                              
		{TLS_EXTENSIONS_SUPPORTED_BY_SERVER_23,                           {TLS_EXTENSIONS_SUPPORTED_BY_SERVER_23,                   ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_TLS_EXTENSIONS_TO_USE_BY_CLIENT_0_24                                                                                                                                                                                                                 
		{TLS_EXTENSIONS_TO_USE_BY_CLIENT_24,                              {TLS_EXTENSIONS_TO_USE_BY_CLIENT_24,                      ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::UINT }},            
		#endif                                                                                                                                                                                                                                                       
		#if RES_SECONDARY_LWM2M_SERVER_URI_0_25                                                                                                                                                                                                                      
		{SECONDARY_LWM2M_SERVER_URI_25,                                   {SECONDARY_LWM2M_SERVER_URI_25,                           ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::MULTIPLE,        IS_MANDATORY::OPTIONAL,         TYPE_ID::STRING }},          
		#endif                                                                                                                                                                                                                                                       
		#if RES_MQTT_SERVER_0_26                                                                                                                                                                                                                                     
		{MQTT_SERVER_26,                                                  {MQTT_SERVER_26,                                          ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::OBJ_LINK }},        
		#endif                                                                                                                                                                                                                                                       
		#if RES_LWM2M_COSE_SECURITY_0_27                                                                                                                                                                                                                             
		{LWM2M_COSE_SECURITY_27,                                          {LWM2M_COSE_SECURITY_27,                                  ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::MULTIPLE,        IS_MANDATORY::OPTIONAL,         TYPE_ID::OBJ_LINK }},        
		#endif                                                                                                                                                                                                                                                       
		#if RES_RDS_DESTINATION_PORT_0_28                                                                                                                                                                                                                            
		{RDS_DESTINATION_PORT_28,                                         {RDS_DESTINATION_PORT_28,                                 ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::INT }},             
		#endif                                                                                                                                                                                                                                                       
		#if RES_RDS_SOURCE_PORT_0_29                                                                                                                                                                                                                                 
		{RDS_SOURCE_PORT_29,                                              {RDS_SOURCE_PORT_29,                                      ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::INT }},             
		#endif                                                                                                                                                                                                                                                       
		#if RES_RDS_APPLICATION_ID_0_30                                                                                                                                                                                                                              
		{RDS_APPLICATION_ID_30,                                           {RDS_APPLICATION_ID_30,                                   ResOp(ResOp::READ|ResOp::WRITE),        IS_SINGLE::SINGLE,          IS_MANDATORY::OPTIONAL,         TYPE_ID::STRING }},          
		#endif                                                                                                                                                                                                                                                       
	};

	/* --------------- Code_h block 4 start --------------- */
	/* --------------- Code_h block 4 end --------------- */
};

} /* namespace wpp */

#endif /* WPP_LWM2M_SECURITY_1_2_H */
