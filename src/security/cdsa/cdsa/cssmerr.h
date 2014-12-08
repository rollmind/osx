/*
 * Copyright (c) 2000-2001 Apple Computer, Inc. All Rights Reserved.
 * 
 * The contents of this file constitute Original Code as defined in and are
 * subject to the Apple Public Source License Version 1.2 (the 'License').
 * You may not use this file except in compliance with the License. Please obtain
 * a copy of the License at http://www.apple.com/publicsource and read it before
 * using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT. Please see the License for the
 * specific language governing rights and limitations under the License.
 */


/*
   File:      cssmerr.h

   Contains:  Error Code Definitions for CSSM

   Copyright: (c) 1999-2000 Apple Computer, Inc., all rights reserved.
*/

#ifndef _CSSMERR_H_
#define _CSSMERR_H_  1

#ifdef __cplusplus
extern "C" {
#endif


/* Common error codes. */
enum {
	CSSM_BASE_ERROR =				-0x7FFF0000 /* 0x80010000 */
};

enum {
	CSSM_ERRORCODE_MODULE_EXTENT =	0x00000800,
	CSSM_ERRORCODE_CUSTOM_OFFSET =	0x00000400,
	CSSM_ERRORCODE_COMMON_EXTENT =	0x100
};

/* Macros for convertible error code manipulation. */
#define CSSM_ERRCODE(CODE) \
	(((CODE) - CSSM_BASE_ERROR) & (CSSM_ERRORCODE_MODULE_EXTENT - 1)) 

#define CSSM_ERRBASE(CODE) \
	((((CODE) - CSSM_BASE_ERROR) & ~(CSSM_ERRORCODE_MODULE_EXTENT - 1)) + CSSM_BASE_ERROR) 

#define CSSM_ERR_IS_CONVERTIBLE(CODE) \
	(CSSM_ERRCODE(CODE) < CSSM_ERRORCODE_COMMON_EXTENT)

#define CSSM_ERR_TAG(CODE, BASE) \
	(CSSM_ERRCODE(CODE) + (BASE))

/* Error Bases for different module types. */
enum {
	CSSM_CSSM_BASE_ERROR =				CSSM_BASE_ERROR,
	CSSM_CSSM_PRIVATE_ERROR =			CSSM_BASE_ERROR + CSSM_ERRORCODE_CUSTOM_OFFSET,
	CSSM_CSP_BASE_ERROR =				CSSM_CSSM_BASE_ERROR + CSSM_ERRORCODE_MODULE_EXTENT,
	CSSM_CSP_PRIVATE_ERROR =			CSSM_CSP_BASE_ERROR + CSSM_ERRORCODE_CUSTOM_OFFSET,
	CSSM_DL_BASE_ERROR =				CSSM_CSP_BASE_ERROR + CSSM_ERRORCODE_MODULE_EXTENT,
	CSSM_DL_PRIVATE_ERROR =				CSSM_DL_BASE_ERROR + CSSM_ERRORCODE_CUSTOM_OFFSET,
	CSSM_CL_BASE_ERROR =				CSSM_DL_BASE_ERROR + CSSM_ERRORCODE_MODULE_EXTENT,
	CSSM_CL_PRIVATE_ERROR =				CSSM_CL_BASE_ERROR + CSSM_ERRORCODE_CUSTOM_OFFSET,
	CSSM_TP_BASE_ERROR =				CSSM_CL_BASE_ERROR + CSSM_ERRORCODE_MODULE_EXTENT,
	CSSM_TP_PRIVATE_ERROR =				CSSM_TP_BASE_ERROR + CSSM_ERRORCODE_CUSTOM_OFFSET ,
	CSSM_KR_BASE_ERROR =				CSSM_TP_BASE_ERROR + CSSM_ERRORCODE_MODULE_EXTENT,
	CSSM_KR_PRIVATE_ERROR =				CSSM_KR_BASE_ERROR + CSSM_ERRORCODE_CUSTOM_OFFSET,
	CSSM_AC_BASE_ERROR =				CSSM_KR_BASE_ERROR + CSSM_ERRORCODE_MODULE_EXTENT,
	CSSM_AC_PRIVATE_ERROR =				CSSM_AC_BASE_ERROR + CSSM_ERRORCODE_CUSTOM_OFFSET
};

/* XXX @@@ MDS Error Bases same as DL for now. */
enum {
	CSSM_MDS_BASE_ERROR =				CSSM_CSP_BASE_ERROR + CSSM_ERRORCODE_MODULE_EXTENT,
	CSSM_MDS_PRIVATE_ERROR =			CSSM_MDS_BASE_ERROR + CSSM_ERRORCODE_CUSTOM_OFFSET
};

/* General Error Values. */
enum {
	CSSMERR_CSSM_INVALID_ADDIN_HANDLE =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT + 1,
	CSSMERR_CSSM_NOT_INITIALIZED =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT + 2,
	CSSMERR_CSSM_INVALID_HANDLE_USAGE =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT + 3,
	CSSMERR_CSSM_PVC_REFERENT_NOT_FOUND =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT + 4,
	CSSMERR_CSSM_FUNCTION_INTEGRITY_FAIL =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT + 5
};

/* Common Error Codes For All Module Types. */
enum {
	CSSM_ERRCODE_INTERNAL_ERROR =					0x0001,
	CSSM_ERRCODE_MEMORY_ERROR =						0x0002,
	CSSM_ERRCODE_MDS_ERROR =						0x0003,
	CSSM_ERRCODE_INVALID_POINTER =					0x0004,
	CSSM_ERRCODE_INVALID_INPUT_POINTER =			0x0005,
	CSSM_ERRCODE_INVALID_OUTPUT_POINTER =			0x0006,
	CSSM_ERRCODE_FUNCTION_NOT_IMPLEMENTED =			0x0007,
	CSSM_ERRCODE_SELF_CHECK_FAILED =				0x0008,
	CSSM_ERRCODE_OS_ACCESS_DENIED =					0x0009,
	CSSM_ERRCODE_FUNCTION_FAILED =					0x000A,
	CSSM_ERRCODE_MODULE_MANIFEST_VERIFY_FAILED =	0x000B,
	CSSM_ERRCODE_INVALID_GUID =						0x000C
};

/* Common Error Codes for ACLs */
enum {
	CSSM_ERRCODE_OPERATION_AUTH_DENIED =			0x0020,
	CSSM_ERRCODE_OBJECT_USE_AUTH_DENIED =			0x0021,
	CSSM_ERRCODE_OBJECT_MANIP_AUTH_DENIED =			0x0022,
	CSSM_ERRCODE_OBJECT_ACL_NOT_SUPPORTED =			0x0023,
	CSSM_ERRCODE_OBJECT_ACL_REQUIRED =				0x0024,
	CSSM_ERRCODE_INVALID_ACCESS_CREDENTIALS =		0x0025,
	CSSM_ERRCODE_INVALID_ACL_BASE_CERTS =			0x0026,
	CSSM_ERRCODE_ACL_BASE_CERTS_NOT_SUPPORTED =		0x0027,
	CSSM_ERRCODE_INVALID_SAMPLE_VALUE =				0x0028,
	CSSM_ERRCODE_SAMPLE_VALUE_NOT_SUPPORTED =		0x0029,
	CSSM_ERRCODE_INVALID_ACL_SUBJECT_VALUE =		0x002A,
	CSSM_ERRCODE_ACL_SUBJECT_TYPE_NOT_SUPPORTED =	0x002B,
	CSSM_ERRCODE_INVALID_ACL_CHALLENGE_CALLBACK =	0x002C,
	CSSM_ERRCODE_ACL_CHALLENGE_CALLBACK_FAILED =	0x002D,
	CSSM_ERRCODE_INVALID_ACL_ENTRY_TAG =			0x002E,
	CSSM_ERRCODE_ACL_ENTRY_TAG_NOT_FOUND =			0x002F,
	CSSM_ERRCODE_INVALID_ACL_EDIT_MODE =			0x0030,
	CSSM_ERRCODE_ACL_CHANGE_FAILED =				0x0031,
	CSSM_ERRCODE_INVALID_NEW_ACL_ENTRY =			0x0032,
	CSSM_ERRCODE_INVALID_NEW_ACL_OWNER =			0x0033,
	CSSM_ERRCODE_ACL_DELETE_FAILED =				0x0034,
	CSSM_ERRCODE_ACL_REPLACE_FAILED =				0x0035,
	CSSM_ERRCODE_ACL_ADD_FAILED =					0x0036
};

/* Common Error Codes for Specific Data Types */
enum {
	CSSM_ERRCODE_INVALID_CONTEXT_HANDLE =			0x0040,
	CSSM_ERRCODE_INCOMPATIBLE_VERSION =				0x0041,
	CSSM_ERRCODE_INVALID_CERTGROUP_POINTER =		0x0042,
	CSSM_ERRCODE_INVALID_CERT_POINTER =				0x0043,
	CSSM_ERRCODE_INVALID_CRL_POINTER =				0x0044,
	CSSM_ERRCODE_INVALID_FIELD_POINTER =			0x0045,
	CSSM_ERRCODE_INVALID_DATA =						0x0046,
	CSSM_ERRCODE_CRL_ALREADY_SIGNED =				0x0047,
	CSSM_ERRCODE_INVALID_NUMBER_OF_FIELDS =			0x0048,
	CSSM_ERRCODE_VERIFICATION_FAILURE =				0x0049,
	CSSM_ERRCODE_INVALID_DB_HANDLE =				0x004A,
	CSSM_ERRCODE_PRIVILEGE_NOT_GRANTED =			0x004B,
	CSSM_ERRCODE_INVALID_DB_LIST =					0x004C,
	CSSM_ERRCODE_INVALID_DB_LIST_POINTER =			0x004D,
	CSSM_ERRCODE_UNKNOWN_FORMAT =					0x004E,
	CSSM_ERRCODE_UNKNOWN_TAG =						0x004F,
	CSSM_ERRCODE_INVALID_CSP_HANDLE =				0x0050,
	CSSM_ERRCODE_INVALID_DL_HANDLE =				0x0051,
	CSSM_ERRCODE_INVALID_CL_HANDLE =				0x0052,
	CSSM_ERRCODE_INVALID_TP_HANDLE =				0x0053,
	CSSM_ERRCODE_INVALID_KR_HANDLE =				0x0054,
	CSSM_ERRCODE_INVALID_AC_HANDLE =				0x0055,
	CSSM_ERRCODE_INVALID_PASSTHROUGH_ID =			0x0056,
	CSSM_ERRCODE_INVALID_NETWORK_ADDR =				0x0057,
	CSSM_ERRCODE_INVALID_CRYPTO_DATA =				0x0058
};

/* CSSM Error Values Derived from Common Error Codes For All Module Types. */
enum {
	CSSMERR_CSSM_INTERNAL_ERROR =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_INTERNAL_ERROR,
	CSSMERR_CSSM_MEMORY_ERROR =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_MEMORY_ERROR,
	CSSMERR_CSSM_MDS_ERROR =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_MDS_ERROR,
	CSSMERR_CSSM_INVALID_POINTER =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_INVALID_POINTER,
	CSSMERR_CSSM_INVALID_INPUT_POINTER =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_INVALID_INPUT_POINTER,
	CSSMERR_CSSM_INVALID_OUTPUT_POINTER =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_INVALID_OUTPUT_POINTER,
	CSSMERR_CSSM_ERRCODE_FUNCTION_NOT_IMPLEMENTED =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_FUNCTION_NOT_IMPLEMENTED,
	CSSMERR_CSSM_SELF_CHECK_FAILED =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_SELF_CHECK_FAILED,
	CSSMERR_CSSM_OS_ACCESS_DENIED =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_OS_ACCESS_DENIED,
	CSSMERR_CSSM_FUNCTION_FAILED =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_FUNCTION_FAILED,
	CSSMERR_CSSM_MODULE_MANIFEST_VERIFY_FAILED =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_MODULE_MANIFEST_VERIFY_FAILED,
	CSSMERR_CSSM_INVALID_GUID =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_INVALID_GUID
};

/* CSSM Error Values for Specific Data Types. */
enum {
	CSSMERR_CSSM_INVALID_CONTEXT_HANDLE =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_INVALID_CONTEXT_HANDLE,
	CSSMERR_CSSM_INCOMPATIBLE_VERSION =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_INCOMPATIBLE_VERSION,
	CSSMERR_CSSM_PRIVILEGE_NOT_GRANTED =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRCODE_PRIVILEGE_NOT_GRANTED
};

/* CSSM Module-Specific Error Values */
enum {
	CSSM_CSSM_BASE_CSSM_ERROR =
		CSSM_CSSM_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT + 0x10,
	CSSMERR_CSSM_SCOPE_NOT_SUPPORTED =				CSSM_CSSM_BASE_CSSM_ERROR + 1,
	CSSMERR_CSSM_PVC_ALREADY_CONFIGURED =			CSSM_CSSM_BASE_CSSM_ERROR + 2,
	CSSMERR_CSSM_INVALID_PVC =						CSSM_CSSM_BASE_CSSM_ERROR + 3,
	CSSMERR_CSSM_EMM_LOAD_FAILED =					CSSM_CSSM_BASE_CSSM_ERROR + 4,
	CSSMERR_CSSM_EMM_UNLOAD_FAILED =				CSSM_CSSM_BASE_CSSM_ERROR + 5,
	CSSMERR_CSSM_ADDIN_LOAD_FAILED =				CSSM_CSSM_BASE_CSSM_ERROR + 6,
	CSSMERR_CSSM_INVALID_KEY_HIERARCHY =			CSSM_CSSM_BASE_CSSM_ERROR + 7,
	CSSMERR_CSSM_ADDIN_UNLOAD_FAILED =				CSSM_CSSM_BASE_CSSM_ERROR + 8,
	CSSMERR_CSSM_LIB_REF_NOT_FOUND =				CSSM_CSSM_BASE_CSSM_ERROR + 9,
	CSSMERR_CSSM_INVALID_ADDIN_FUNCTION_TABLE =		CSSM_CSSM_BASE_CSSM_ERROR + 10,
	CSSMERR_CSSM_EMM_AUTHENTICATE_FAILED =			CSSM_CSSM_BASE_CSSM_ERROR + 11,
	CSSMERR_CSSM_ADDIN_AUTHENTICATE_FAILED =		CSSM_CSSM_BASE_CSSM_ERROR + 12,
	CSSMERR_CSSM_INVALID_SERVICE_MASK =				CSSM_CSSM_BASE_CSSM_ERROR + 13,
	CSSMERR_CSSM_MODULE_NOT_LOADED =				CSSM_CSSM_BASE_CSSM_ERROR + 14,
	CSSMERR_CSSM_INVALID_SUBSERVICEID =				CSSM_CSSM_BASE_CSSM_ERROR + 15,
	CSSMERR_CSSM_BUFFER_TOO_SMALL =					CSSM_CSSM_BASE_CSSM_ERROR + 16,
	CSSMERR_CSSM_INVALID_ATTRIBUTE =				CSSM_CSSM_BASE_CSSM_ERROR + 17,
	CSSMERR_CSSM_ATTRIBUTE_NOT_IN_CONTEXT =			CSSM_CSSM_BASE_CSSM_ERROR + 18,
	CSSMERR_CSSM_MODULE_MANAGER_INITIALIZE_FAIL =	CSSM_CSSM_BASE_CSSM_ERROR + 19,
	CSSMERR_CSSM_MODULE_MANAGER_NOT_FOUND =			CSSM_CSSM_BASE_CSSM_ERROR + 20,
	CSSMERR_CSSM_EVENT_NOTIFICATION_CALLBACK_NOT_FOUND = CSSM_CSSM_BASE_CSSM_ERROR + 21
};

/* CSP Error Values Derived from Common Error Codes For All Module Types. */
enum {
	CSSMERR_CSP_INTERNAL_ERROR =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INTERNAL_ERROR,
	CSSMERR_CSP_MEMORY_ERROR =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_MEMORY_ERROR,
	CSSMERR_CSP_MDS_ERROR =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_MDS_ERROR,
	CSSMERR_CSP_INVALID_POINTER =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_POINTER,
	CSSMERR_CSP_INVALID_INPUT_POINTER =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_INPUT_POINTER,
	CSSMERR_CSP_INVALID_OUTPUT_POINTER =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_OUTPUT_POINTER,
	CSSMERR_CSP_FUNCTION_NOT_IMPLEMENTED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_FUNCTION_NOT_IMPLEMENTED,
	CSSMERR_CSP_SELF_CHECK_FAILED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_SELF_CHECK_FAILED,
	CSSMERR_CSP_OS_ACCESS_DENIED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_OS_ACCESS_DENIED,
	CSSMERR_CSP_FUNCTION_FAILED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_FUNCTION_FAILED
};

/* CSP Error Values Derived from ACL-based Error Codes. */
enum {
	CSSMERR_CSP_OPERATION_AUTH_DENIED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_OPERATION_AUTH_DENIED,
	CSSMERR_CSP_OBJECT_USE_AUTH_DENIED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_OBJECT_USE_AUTH_DENIED,
	CSSMERR_CSP_OBJECT_MANIP_AUTH_DENIED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_OBJECT_MANIP_AUTH_DENIED,
	CSSMERR_CSP_OBJECT_ACL_NOT_SUPPORTED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_OBJECT_ACL_NOT_SUPPORTED,
	CSSMERR_CSP_OBJECT_ACL_REQUIRED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_OBJECT_ACL_REQUIRED,
	CSSMERR_CSP_INVALID_ACCESS_CREDENTIALS =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_ACCESS_CREDENTIALS,
	CSSMERR_CSP_INVALID_ACL_BASE_CERTS =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_BASE_CERTS,
	CSSMERR_CSP_ACL_BASE_CERTS_NOT_SUPPORTED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_ACL_BASE_CERTS_NOT_SUPPORTED,
	CSSMERR_CSP_INVALID_SAMPLE_VALUE =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_SAMPLE_VALUE,
	CSSMERR_CSP_SAMPLE_VALUE_NOT_SUPPORTED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_SAMPLE_VALUE_NOT_SUPPORTED,
	CSSMERR_CSP_INVALID_ACL_SUBJECT_VALUE =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_SUBJECT_VALUE,
	CSSMERR_CSP_ACL_SUBJECT_TYPE_NOT_SUPPORTED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_ACL_SUBJECT_TYPE_NOT_SUPPORTED,
	CSSMERR_CSP_INVALID_ACL_CHALLENGE_CALLBACK =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_CHALLENGE_CALLBACK,
	CSSMERR_CSP_ACL_CHALLENGE_CALLBACK_FAILED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_ACL_CHALLENGE_CALLBACK_FAILED,
	CSSMERR_CSP_INVALID_ACL_ENTRY_TAG =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_ENTRY_TAG,
	CSSMERR_CSP_ACL_ENTRY_TAG_NOT_FOUND =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_ACL_ENTRY_TAG_NOT_FOUND,
	CSSMERR_CSP_INVALID_ACL_EDIT_MODE =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_EDIT_MODE,
	CSSMERR_CSP_ACL_CHANGE_FAILED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_ACL_CHANGE_FAILED,
	CSSMERR_CSP_INVALID_NEW_ACL_ENTRY =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_NEW_ACL_ENTRY,
	CSSMERR_CSP_INVALID_NEW_ACL_OWNER =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_NEW_ACL_OWNER,
	CSSMERR_CSP_ACL_DELETE_FAILED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_ACL_DELETE_FAILED,
	CSSMERR_CSP_ACL_REPLACE_FAILED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_ACL_REPLACE_FAILED,
	CSSMERR_CSP_ACL_ADD_FAILED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_ACL_ADD_FAILED
};

/* CSP Error Values for Specific Data Types. */
enum {
	CSSMERR_CSP_INVALID_CONTEXT_HANDLE =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_CONTEXT_HANDLE,
	CSSMERR_CSP_PRIVILEGE_NOT_GRANTED =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_PRIVILEGE_NOT_GRANTED,
	CSSMERR_CSP_INVALID_DATA =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_DATA,
	CSSMERR_CSP_INVALID_PASSTHROUGH_ID =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_PASSTHROUGH_ID,
	CSSMERR_CSP_INVALID_CRYPTO_DATA =
		CSSM_CSP_BASE_ERROR + CSSM_ERRCODE_INVALID_CRYPTO_DATA
};

/* CSP Module-Specific Error Values */
enum {
	/* General CSP Error Values */
	CSSM_CSP_BASE_CSP_ERROR =
		CSSM_CSP_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT,
	CSSMERR_CSP_INPUT_LENGTH_ERROR =				CSSM_CSP_BASE_CSP_ERROR + 1,
	CSSMERR_CSP_OUTPUT_LENGTH_ERROR =				CSSM_CSP_BASE_CSP_ERROR + 2,
	CSSMERR_CSP_PRIVILEGE_NOT_SUPPORTED =			CSSM_CSP_BASE_CSP_ERROR + 3,
	CSSMERR_CSP_DEVICE_ERROR =						CSSM_CSP_BASE_CSP_ERROR + 4,
	CSSMERR_CSP_DEVICE_MEMORY_ERROR =				CSSM_CSP_BASE_CSP_ERROR + 5,
	CSSMERR_CSP_ATTACH_HANDLE_BUSY =				CSSM_CSP_BASE_CSP_ERROR + 6,
	CSSMERR_CSP_NOT_LOGGED_IN =						CSSM_CSP_BASE_CSP_ERROR + 7,
	CSSMERR_CSP_INVALID_KEY =						CSSM_CSP_BASE_CSP_ERROR + 16,
	CSSMERR_CSP_INVALID_KEY_REFERENCE =				CSSM_CSP_BASE_CSP_ERROR + 17,
	CSSMERR_CSP_INVALID_KEY_CLASS =					CSSM_CSP_BASE_CSP_ERROR + 18,
	CSSMERR_CSP_ALGID_MISMATCH =					CSSM_CSP_BASE_CSP_ERROR + 19,
	CSSMERR_CSP_KEY_USAGE_INCORRECT =				CSSM_CSP_BASE_CSP_ERROR + 20,
	CSSMERR_CSP_KEY_BLOB_TYPE_INCORRECT =			CSSM_CSP_BASE_CSP_ERROR + 21,
	CSSMERR_CSP_KEY_HEADER_INCONSISTENT =			CSSM_CSP_BASE_CSP_ERROR + 22,
	CSSMERR_CSP_UNSUPPORTED_KEY_FORMAT =			CSSM_CSP_BASE_CSP_ERROR + 23,
	CSSMERR_CSP_UNSUPPORTED_KEY_SIZE =				CSSM_CSP_BASE_CSP_ERROR + 24,
	CSSMERR_CSP_INVALID_KEY_POINTER =				CSSM_CSP_BASE_CSP_ERROR + 25,
	CSSMERR_CSP_INVALID_KEYUSAGE_MASK =				CSSM_CSP_BASE_CSP_ERROR + 26,
	CSSMERR_CSP_UNSUPPORTED_KEYUSAGE_MASK =			CSSM_CSP_BASE_CSP_ERROR + 27,
	CSSMERR_CSP_INVALID_KEYATTR_MASK =				CSSM_CSP_BASE_CSP_ERROR + 28,
	CSSMERR_CSP_UNSUPPORTED_KEYATTR_MASK =			CSSM_CSP_BASE_CSP_ERROR + 29,
	CSSMERR_CSP_INVALID_KEY_LABEL =					CSSM_CSP_BASE_CSP_ERROR + 30,
	CSSMERR_CSP_UNSUPPORTED_KEY_LABEL =				CSSM_CSP_BASE_CSP_ERROR + 31,
	CSSMERR_CSP_INVALID_KEY_FORMAT =				CSSM_CSP_BASE_CSP_ERROR + 32,

	/* CSP Vector of Buffers Error Values. */
	CSSMERR_CSP_INVALID_DATA_COUNT =				CSSM_CSP_BASE_CSP_ERROR + 40,
	CSSMERR_CSP_VECTOR_OF_BUFS_UNSUPPORTED =		CSSM_CSP_BASE_CSP_ERROR + 41,
	CSSMERR_CSP_INVALID_INPUT_VECTOR =				CSSM_CSP_BASE_CSP_ERROR + 42,
	CSSMERR_CSP_INVALID_OUTPUT_VECTOR =				CSSM_CSP_BASE_CSP_ERROR + 43,

	/* CSP Cryptographic Context Error Values. */
	CSSMERR_CSP_INVALID_CONTEXT =					CSSM_CSP_BASE_CSP_ERROR + 48,
	CSSMERR_CSP_INVALID_ALGORITHM =					CSSM_CSP_BASE_CSP_ERROR + 49,
	CSSMERR_CSP_INVALID_ATTR_KEY = 					CSSM_CSP_BASE_CSP_ERROR + 54,
	CSSMERR_CSP_MISSING_ATTR_KEY = 					CSSM_CSP_BASE_CSP_ERROR + 55,
	CSSMERR_CSP_INVALID_ATTR_INIT_VECTOR = 			CSSM_CSP_BASE_CSP_ERROR + 56,
	CSSMERR_CSP_MISSING_ATTR_INIT_VECTOR = 			CSSM_CSP_BASE_CSP_ERROR + 57,
	CSSMERR_CSP_INVALID_ATTR_SALT = 				CSSM_CSP_BASE_CSP_ERROR + 58,
	CSSMERR_CSP_MISSING_ATTR_SALT = 				CSSM_CSP_BASE_CSP_ERROR + 59,
	CSSMERR_CSP_INVALID_ATTR_PADDING = 				CSSM_CSP_BASE_CSP_ERROR + 60,
	CSSMERR_CSP_MISSING_ATTR_PADDING = 				CSSM_CSP_BASE_CSP_ERROR + 61,
	CSSMERR_CSP_INVALID_ATTR_RANDOM = 				CSSM_CSP_BASE_CSP_ERROR + 62,
	CSSMERR_CSP_MISSING_ATTR_RANDOM = 				CSSM_CSP_BASE_CSP_ERROR + 63,
	CSSMERR_CSP_INVALID_ATTR_SEED = 				CSSM_CSP_BASE_CSP_ERROR + 64,
	CSSMERR_CSP_MISSING_ATTR_SEED = 				CSSM_CSP_BASE_CSP_ERROR + 65,
	CSSMERR_CSP_INVALID_ATTR_PASSPHRASE = 			CSSM_CSP_BASE_CSP_ERROR + 66,
	CSSMERR_CSP_MISSING_ATTR_PASSPHRASE = 			CSSM_CSP_BASE_CSP_ERROR + 67,
	CSSMERR_CSP_INVALID_ATTR_KEY_LENGTH = 			CSSM_CSP_BASE_CSP_ERROR + 68,
	CSSMERR_CSP_MISSING_ATTR_KEY_LENGTH = 			CSSM_CSP_BASE_CSP_ERROR + 69,
	CSSMERR_CSP_INVALID_ATTR_BLOCK_SIZE = 			CSSM_CSP_BASE_CSP_ERROR + 70,
	CSSMERR_CSP_MISSING_ATTR_BLOCK_SIZE = 			CSSM_CSP_BASE_CSP_ERROR + 71,
	CSSMERR_CSP_INVALID_ATTR_OUTPUT_SIZE = 			CSSM_CSP_BASE_CSP_ERROR + 100,
	CSSMERR_CSP_MISSING_ATTR_OUTPUT_SIZE = 			CSSM_CSP_BASE_CSP_ERROR + 101,
	CSSMERR_CSP_INVALID_ATTR_ROUNDS = 				CSSM_CSP_BASE_CSP_ERROR + 102,
	CSSMERR_CSP_MISSING_ATTR_ROUNDS = 				CSSM_CSP_BASE_CSP_ERROR + 103,
	CSSMERR_CSP_INVALID_ATTR_ALG_PARAMS = 			CSSM_CSP_BASE_CSP_ERROR + 104,
	CSSMERR_CSP_MISSING_ATTR_ALG_PARAMS = 			CSSM_CSP_BASE_CSP_ERROR + 105,
	CSSMERR_CSP_INVALID_ATTR_LABEL = 				CSSM_CSP_BASE_CSP_ERROR + 106,
	CSSMERR_CSP_MISSING_ATTR_LABEL = 				CSSM_CSP_BASE_CSP_ERROR + 107,
	CSSMERR_CSP_INVALID_ATTR_KEY_TYPE = 			CSSM_CSP_BASE_CSP_ERROR + 108,
	CSSMERR_CSP_MISSING_ATTR_KEY_TYPE = 			CSSM_CSP_BASE_CSP_ERROR + 109,
	CSSMERR_CSP_INVALID_ATTR_MODE = 				CSSM_CSP_BASE_CSP_ERROR + 110,
	CSSMERR_CSP_MISSING_ATTR_MODE = 				CSSM_CSP_BASE_CSP_ERROR + 111,
	CSSMERR_CSP_INVALID_ATTR_EFFECTIVE_BITS = 		CSSM_CSP_BASE_CSP_ERROR + 112,
	CSSMERR_CSP_MISSING_ATTR_EFFECTIVE_BITS = 		CSSM_CSP_BASE_CSP_ERROR + 113,
	CSSMERR_CSP_INVALID_ATTR_START_DATE = 			CSSM_CSP_BASE_CSP_ERROR + 114,
	CSSMERR_CSP_MISSING_ATTR_START_DATE = 			CSSM_CSP_BASE_CSP_ERROR + 115,
	CSSMERR_CSP_INVALID_ATTR_END_DATE = 			CSSM_CSP_BASE_CSP_ERROR + 116,
	CSSMERR_CSP_MISSING_ATTR_END_DATE = 			CSSM_CSP_BASE_CSP_ERROR + 117,
	CSSMERR_CSP_INVALID_ATTR_VERSION = 				CSSM_CSP_BASE_CSP_ERROR + 118,
	CSSMERR_CSP_MISSING_ATTR_VERSION = 				CSSM_CSP_BASE_CSP_ERROR + 119,
	CSSMERR_CSP_INVALID_ATTR_PRIME = 				CSSM_CSP_BASE_CSP_ERROR + 120,
	CSSMERR_CSP_MISSING_ATTR_PRIME = 				CSSM_CSP_BASE_CSP_ERROR + 121,
	CSSMERR_CSP_INVALID_ATTR_BASE = 				CSSM_CSP_BASE_CSP_ERROR + 122,
	CSSMERR_CSP_MISSING_ATTR_BASE = 				CSSM_CSP_BASE_CSP_ERROR + 123,
	CSSMERR_CSP_INVALID_ATTR_SUBPRIME = 			CSSM_CSP_BASE_CSP_ERROR + 124,
	CSSMERR_CSP_MISSING_ATTR_SUBPRIME = 			CSSM_CSP_BASE_CSP_ERROR + 125,
	CSSMERR_CSP_INVALID_ATTR_ITERATION_COUNT = 		CSSM_CSP_BASE_CSP_ERROR + 126,
	CSSMERR_CSP_MISSING_ATTR_ITERATION_COUNT = 		CSSM_CSP_BASE_CSP_ERROR + 127,
	CSSMERR_CSP_INVALID_ATTR_DL_DB_HANDLE = 		CSSM_CSP_BASE_CSP_ERROR + 128,
	CSSMERR_CSP_MISSING_ATTR_DL_DB_HANDLE = 		CSSM_CSP_BASE_CSP_ERROR + 129,
	CSSMERR_CSP_INVALID_ATTR_ACCESS_CREDENTIALS = 	CSSM_CSP_BASE_CSP_ERROR + 130,
	CSSMERR_CSP_MISSING_ATTR_ACCESS_CREDENTIALS = 	CSSM_CSP_BASE_CSP_ERROR + 131,
	CSSMERR_CSP_INVALID_ATTR_PUBLIC_KEY_FORMAT = 	CSSM_CSP_BASE_CSP_ERROR + 132,
	CSSMERR_CSP_MISSING_ATTR_PUBLIC_KEY_FORMAT = 	CSSM_CSP_BASE_CSP_ERROR + 133,
	CSSMERR_CSP_INVALID_ATTR_PRIVATE_KEY_FORMAT = 	CSSM_CSP_BASE_CSP_ERROR + 134,
	CSSMERR_CSP_MISSING_ATTR_PRIVATE_KEY_FORMAT = 	CSSM_CSP_BASE_CSP_ERROR + 135,
	CSSMERR_CSP_INVALID_ATTR_SYMMETRIC_KEY_FORMAT = CSSM_CSP_BASE_CSP_ERROR + 136,
	CSSMERR_CSP_MISSING_ATTR_SYMMETRIC_KEY_FORMAT = CSSM_CSP_BASE_CSP_ERROR + 137,
	CSSMERR_CSP_INVALID_ATTR_WRAPPED_KEY_FORMAT = 	CSSM_CSP_BASE_CSP_ERROR + 138,
	CSSMERR_CSP_MISSING_ATTR_WRAPPED_KEY_FORMAT = 	CSSM_CSP_BASE_CSP_ERROR + 139,

	/* CSP Staged Cryptographic API Error Values. */
	CSSMERR_CSP_STAGED_OPERATION_IN_PROGRESS =		CSSM_CSP_BASE_CSP_ERROR + 72,
	CSSMERR_CSP_STAGED_OPERATION_NOT_STARTED =		CSSM_CSP_BASE_CSP_ERROR + 73,
	CSSMERR_CSP_VERIFY_FAILED =						CSSM_CSP_BASE_CSP_ERROR + 74,
	CSSMERR_CSP_INVALID_SIGNATURE =					CSSM_CSP_BASE_CSP_ERROR + 75,
	CSSMERR_CSP_QUERY_SIZE_UNKNOWN =				CSSM_CSP_BASE_CSP_ERROR + 76,
	CSSMERR_CSP_BLOCK_SIZE_MISMATCH =				CSSM_CSP_BASE_CSP_ERROR + 77,
	CSSMERR_CSP_PRIVATE_KEY_NOT_FOUND =				CSSM_CSP_BASE_CSP_ERROR + 78,
	CSSMERR_CSP_PUBLIC_KEY_INCONSISTENT =			CSSM_CSP_BASE_CSP_ERROR + 79,
	CSSMERR_CSP_DEVICE_VERIFY_FAILED =				CSSM_CSP_BASE_CSP_ERROR + 80,
	CSSMERR_CSP_INVALID_LOGIN_NAME =				CSSM_CSP_BASE_CSP_ERROR + 81,
	CSSMERR_CSP_ALREADY_LOGGED_IN =					CSSM_CSP_BASE_CSP_ERROR + 82,
	CSSMERR_CSP_PRIVATE_KEY_ALREADY_EXISTS =		CSSM_CSP_BASE_CSP_ERROR + 83,
	CSSMERR_CSP_KEY_LABEL_ALREADY_EXISTS =			CSSM_CSP_BASE_CSP_ERROR + 84,
	CSSMERR_CSP_INVALID_DIGEST_ALGORITHM =			CSSM_CSP_BASE_CSP_ERROR + 85,
	CSSMERR_CSP_CRYPTO_DATA_CALLBACK_FAILED =		CSSM_CSP_BASE_CSP_ERROR + 86
};


/* TP Error Values Derived from Common Error Codes For All Module Types. */
enum {
	CSSMERR_TP_INTERNAL_ERROR =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INTERNAL_ERROR,
	CSSMERR_TP_MEMORY_ERROR =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_MEMORY_ERROR,
	CSSMERR_TP_MDS_ERROR =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_MDS_ERROR,
	CSSMERR_TP_INVALID_POINTER =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_POINTER,
	CSSMERR_TP_INVALID_INPUT_POINTER =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_INPUT_POINTER,
	CSSMERR_TP_INVALID_OUTPUT_POINTER =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_OUTPUT_POINTER,
	CSSMERR_TP_FUNCTION_NOT_IMPLEMENTED =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_FUNCTION_NOT_IMPLEMENTED,
	CSSMERR_TP_SELF_CHECK_FAILED =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_SELF_CHECK_FAILED,
	CSSMERR_TP_OS_ACCESS_DENIED =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_OS_ACCESS_DENIED,
	CSSMERR_TP_FUNCTION_FAILED =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_FUNCTION_FAILED,
	CSSMERR_TP_INVALID_CONTEXT_HANDLE =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_CONTEXT_HANDLE,
	CSSMERR_TP_INVALID_DATA =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_DATA,
	CSSMERR_TP_INVALID_DB_LIST =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_DB_LIST,
	CSSMERR_TP_INVALID_CERTGROUP_POINTER =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_CERTGROUP_POINTER,
	CSSMERR_TP_INVALID_CERT_POINTER =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_CERT_POINTER,
	CSSMERR_TP_INVALID_CRL_POINTER =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_CRL_POINTER,
	CSSMERR_TP_INVALID_FIELD_POINTER =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_FIELD_POINTER,
	CSSMERR_TP_INVALID_NETWORK_ADDR =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_NETWORK_ADDR,
	CSSMERR_TP_CRL_ALREADY_SIGNED =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_CRL_ALREADY_SIGNED,
	CSSMERR_TP_INVALID_NUMBER_OF_FIELDS =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_NUMBER_OF_FIELDS,
	CSSMERR_TP_VERIFICATION_FAILURE =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_VERIFICATION_FAILURE,
	CSSMERR_TP_INVALID_DB_HANDLE =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_DB_HANDLE,
	CSSMERR_TP_UNKNOWN_FORMAT =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_UNKNOWN_FORMAT,
	CSSMERR_TP_UNKNOWN_TAG =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_UNKNOWN_TAG,
	CSSMERR_TP_INVALID_PASSTHROUGH_ID =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_PASSTHROUGH_ID,
	CSSMERR_TP_INVALID_CSP_HANDLE =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_CSP_HANDLE,
	CSSMERR_TP_INVALID_DL_HANDLE =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_DL_HANDLE,
	CSSMERR_TP_INVALID_CL_HANDLE =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_CL_HANDLE,
	CSSMERR_TP_INVALID_DB_LIST_POINTER =
		CSSM_TP_BASE_ERROR + CSSM_ERRCODE_INVALID_DB_LIST_POINTER
};

/* TP Module-Specific Error Values */
enum {
	CSSM_TP_BASE_TP_ERROR =
		CSSM_TP_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT,
	CSSMERR_TP_INVALID_CALLERAUTH_CONTEXT_POINTER =	CSSM_TP_BASE_TP_ERROR + 1,
	CSSMERR_TP_INVALID_IDENTIFIER_POINTER =			CSSM_TP_BASE_TP_ERROR + 2,
	CSSMERR_TP_INVALID_KEYCACHE_HANDLE =			CSSM_TP_BASE_TP_ERROR + 3,
	CSSMERR_TP_INVALID_CERTGROUP =					CSSM_TP_BASE_TP_ERROR + 4,
	CSSMERR_TP_INVALID_CRLGROUP =					CSSM_TP_BASE_TP_ERROR + 5,
	CSSMERR_TP_INVALID_CRLGROUP_POINTER =			CSSM_TP_BASE_TP_ERROR + 6,
	CSSMERR_TP_AUTHENTICATION_FAILED =				CSSM_TP_BASE_TP_ERROR + 7,
	CSSMERR_TP_CERTGROUP_INCOMPLETE =				CSSM_TP_BASE_TP_ERROR + 8,
	CSSMERR_TP_CERTIFICATE_CANT_OPERATE =			CSSM_TP_BASE_TP_ERROR + 9,
	CSSMERR_TP_CERT_EXPIRED =						CSSM_TP_BASE_TP_ERROR + 10,
	CSSMERR_TP_CERT_NOT_VALID_YET =					CSSM_TP_BASE_TP_ERROR + 11,
	CSSMERR_TP_CERT_REVOKED =						CSSM_TP_BASE_TP_ERROR + 12,
	CSSMERR_TP_CERT_SUSPENDED =						CSSM_TP_BASE_TP_ERROR + 13,
	CSSMERR_TP_INSUFFICIENT_CREDENTIALS =			CSSM_TP_BASE_TP_ERROR + 14,
	CSSMERR_TP_INVALID_ACTION =						CSSM_TP_BASE_TP_ERROR + 15,
	CSSMERR_TP_INVALID_ACTION_DATA =				CSSM_TP_BASE_TP_ERROR + 16,
/*	CSSMERR_TP_INVALID_NETWORK_ADDR =				CSSM_TP_BASE_TP_ERROR + 17, */
	CSSMERR_TP_INVALID_ANCHOR_CERT =				CSSM_TP_BASE_TP_ERROR + 18,
	CSSMERR_TP_INVALID_AUTHORITY =					CSSM_TP_BASE_TP_ERROR + 19,
	CSSMERR_TP_VERIFY_ACTION_FAILED =				CSSM_TP_BASE_TP_ERROR + 20,
	CSSMERR_TP_INVALID_CERTIFICATE =				CSSM_TP_BASE_TP_ERROR + 21,
	CSSMERR_TP_INVALID_CERT_AUTHORITY =				CSSM_TP_BASE_TP_ERROR + 22,
	CSSMERR_TP_INVALID_CRL_AUTHORITY =				CSSM_TP_BASE_TP_ERROR + 23,
	CSSMERR_TP_INVALID_CRL_ENCODING =				CSSM_TP_BASE_TP_ERROR + 24,
	CSSMERR_TP_INVALID_CRL_TYPE =					CSSM_TP_BASE_TP_ERROR + 25,
	CSSMERR_TP_INVALID_CRL =						CSSM_TP_BASE_TP_ERROR + 26,
	CSSMERR_TP_INVALID_FORM_TYPE =					CSSM_TP_BASE_TP_ERROR + 27,
	CSSMERR_TP_INVALID_ID =							CSSM_TP_BASE_TP_ERROR + 28,
	CSSMERR_TP_INVALID_IDENTIFIER =					CSSM_TP_BASE_TP_ERROR + 29,
	CSSMERR_TP_INVALID_INDEX =						CSSM_TP_BASE_TP_ERROR + 30,
	CSSMERR_TP_INVALID_NAME =						CSSM_TP_BASE_TP_ERROR + 31,
	CSSMERR_TP_INVALID_POLICY_IDENTIFIERS =			CSSM_TP_BASE_TP_ERROR + 32,
	CSSMERR_TP_INVALID_TIMESTRING =					CSSM_TP_BASE_TP_ERROR + 33,
	CSSMERR_TP_INVALID_REASON =						CSSM_TP_BASE_TP_ERROR + 34,
	CSSMERR_TP_INVALID_REQUEST_INPUTS =				CSSM_TP_BASE_TP_ERROR + 35,
	CSSMERR_TP_INVALID_RESPONSE_VECTOR =			CSSM_TP_BASE_TP_ERROR + 36,
	CSSMERR_TP_INVALID_SIGNATURE =					CSSM_TP_BASE_TP_ERROR + 37,
	CSSMERR_TP_INVALID_STOP_ON_POLICY =				CSSM_TP_BASE_TP_ERROR + 38,
	CSSMERR_TP_INVALID_CALLBACK =					CSSM_TP_BASE_TP_ERROR + 39,
	CSSMERR_TP_INVALID_TUPLE =						CSSM_TP_BASE_TP_ERROR + 40,
	CSSMERR_TP_NOT_SIGNER =							CSSM_TP_BASE_TP_ERROR + 41,
	CSSMERR_TP_NOT_TRUSTED =						CSSM_TP_BASE_TP_ERROR + 42,
	CSSMERR_TP_NO_DEFAULT_AUTHORITY =				CSSM_TP_BASE_TP_ERROR + 43,
	CSSMERR_TP_REJECTED_FORM =						CSSM_TP_BASE_TP_ERROR + 44,
	CSSMERR_TP_REQUEST_LOST =						CSSM_TP_BASE_TP_ERROR + 45,
	CSSMERR_TP_REQUEST_REJECTED =					CSSM_TP_BASE_TP_ERROR + 46,
	CSSMERR_TP_UNSUPPORTED_ADDR_TYPE =				CSSM_TP_BASE_TP_ERROR + 47,
	CSSMERR_TP_UNSUPPORTED_SERVICE =				CSSM_TP_BASE_TP_ERROR + 48,
	CSSMERR_TP_INVALID_TUPLEGROUP_POINTER =			CSSM_TP_BASE_TP_ERROR + 49,
	CSSMERR_TP_INVALID_TUPLEGROUP =					CSSM_TP_BASE_TP_ERROR + 50
};

/* AC Error Values Derived from Common Error Codes For All Module Types. */
enum {
	CSSMERR_AC_INTERNAL_ERROR =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INTERNAL_ERROR,
	CSSMERR_AC_MEMORY_ERROR =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_MEMORY_ERROR,
	CSSMERR_AC_MDS_ERROR =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_MDS_ERROR,
	CSSMERR_AC_INVALID_POINTER =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_POINTER,
	CSSMERR_AC_INVALID_INPUT_POINTER =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_INPUT_POINTER,
	CSSMERR_AC_INVALID_OUTPUT_POINTER =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_OUTPUT_POINTER,
	CSSMERR_AC_FUNCTION_NOT_IMPLEMENTED =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_FUNCTION_NOT_IMPLEMENTED,
	CSSMERR_AC_SELF_CHECK_FAILED =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_SELF_CHECK_FAILED,
	CSSMERR_AC_OS_ACCESS_DENIED =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_OS_ACCESS_DENIED,
	CSSMERR_AC_FUNCTION_FAILED =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_FUNCTION_FAILED,
	CSSMERR_AC_INVALID_CONTEXT_HANDLE =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_CONTEXT_HANDLE,
	CSSMERR_AC_INVALID_DATA =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_DATA,
	CSSMERR_AC_INVALID_DB_LIST =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_DB_LIST,
	CSSMERR_AC_INVALID_PASSTHROUGH_ID =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_PASSTHROUGH_ID,
	CSSMERR_AC_INVALID_DL_HANDLE =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_DL_HANDLE,
	CSSMERR_AC_INVALID_CL_HANDLE =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_CL_HANDLE,
	CSSMERR_AC_INVALID_TP_HANDLE =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_TP_HANDLE,
	CSSMERR_AC_INVALID_DB_HANDLE =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_DB_HANDLE,
	CSSMERR_AC_INVALID_DB_LIST_POINTER =
		CSSM_AC_BASE_ERROR + CSSM_ERRCODE_INVALID_DB_LIST_POINTER
};

/* AC Module-Specific Error Values */
enum {
	CSSM_AC_BASE_AC_ERROR =
		CSSM_AC_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT,
	CSSMERR_AC_INVALID_BASE_ACLS =					CSSM_AC_BASE_AC_ERROR + 1,
	CSSMERR_AC_INVALID_TUPLE_CREDENTIALS =			CSSM_AC_BASE_AC_ERROR + 2,
	CSSMERR_AC_INVALID_ENCODING =					CSSM_AC_BASE_AC_ERROR + 3,
	CSSMERR_AC_INVALID_VALIDITY_PERIOD =			CSSM_AC_BASE_AC_ERROR + 4,
	CSSMERR_AC_INVALID_REQUESTOR =					CSSM_AC_BASE_AC_ERROR + 5,
	CSSMERR_AC_INVALID_REQUEST_DESCRIPTOR =			CSSM_AC_BASE_AC_ERROR + 6
};

/* CL Error Values Derived from Common Error Codes For All Module Types. */
enum {
	CSSMERR_CL_INTERNAL_ERROR =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INTERNAL_ERROR,
	CSSMERR_CL_MEMORY_ERROR =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_MEMORY_ERROR,
	CSSMERR_CL_MDS_ERROR =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_MDS_ERROR,
	CSSMERR_CL_INVALID_POINTER =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_POINTER,
	CSSMERR_CL_INVALID_INPUT_POINTER =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_INPUT_POINTER,
	CSSMERR_CL_INVALID_OUTPUT_POINTER =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_OUTPUT_POINTER,
	CSSMERR_CL_FUNCTION_NOT_IMPLEMENTED =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_FUNCTION_NOT_IMPLEMENTED,
	CSSMERR_CL_SELF_CHECK_FAILED =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_SELF_CHECK_FAILED,
	CSSMERR_CL_OS_ACCESS_DENIED =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_OS_ACCESS_DENIED,
	CSSMERR_CL_FUNCTION_FAILED =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_FUNCTION_FAILED,
	CSSMERR_CL_INVALID_CONTEXT_HANDLE =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_CONTEXT_HANDLE,
	CSSMERR_CL_INVALID_CERTGROUP_POINTER =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_CERTGROUP_POINTER,
	CSSMERR_CL_INVALID_CERT_POINTER =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_CERT_POINTER,
	CSSMERR_CL_INVALID_CRL_POINTER =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_CRL_POINTER,
	CSSMERR_CL_INVALID_FIELD_POINTER =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_FIELD_POINTER,
	CSSMERR_CL_INVALID_DATA =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_DATA,
	CSSMERR_CL_CRL_ALREADY_SIGNED =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_CRL_ALREADY_SIGNED,
	CSSMERR_CL_INVALID_NUMBER_OF_FIELDS =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_NUMBER_OF_FIELDS,
	CSSMERR_CL_VERIFICATION_FAILURE =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_VERIFICATION_FAILURE,
	CSSMERR_CL_UNKNOWN_FORMAT =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_UNKNOWN_FORMAT,
	CSSMERR_CL_UNKNOWN_TAG =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_UNKNOWN_TAG,
	CSSMERR_CL_INVALID_PASSTHROUGH_ID =
		CSSM_CL_BASE_ERROR + CSSM_ERRCODE_INVALID_PASSTHROUGH_ID
};

/* CL Module-Specific Error Values */
enum {
	CSSM_CL_BASE_CL_ERROR =
		CSSM_CL_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT,
	CSSMERR_CL_INVALID_BUNDLE_POINTER =				CSSM_CL_BASE_CL_ERROR + 1,
	CSSMERR_CL_INVALID_CACHE_HANDLE =				CSSM_CL_BASE_CL_ERROR + 2,
	CSSMERR_CL_INVALID_RESULTS_HANDLE =				CSSM_CL_BASE_CL_ERROR + 3,
	CSSMERR_CL_INVALID_BUNDLE_INFO =				CSSM_CL_BASE_CL_ERROR + 4,
	CSSMERR_CL_INVALID_CRL_INDEX =					CSSM_CL_BASE_CL_ERROR + 5,
	CSSMERR_CL_INVALID_SCOPE =						CSSM_CL_BASE_CL_ERROR + 6,
	CSSMERR_CL_NO_FIELD_VALUES =					CSSM_CL_BASE_CL_ERROR + 7,
	CSSMERR_CL_SCOPE_NOT_SUPPORTED =				CSSM_CL_BASE_CL_ERROR + 8
};

/* DL Error Values Derived from Common Error Codes For All Module Types. */
enum {
	CSSMERR_DL_INTERNAL_ERROR =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INTERNAL_ERROR,
	CSSMERR_DL_MEMORY_ERROR =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_MEMORY_ERROR,
	CSSMERR_DL_MDS_ERROR =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_MDS_ERROR,
	CSSMERR_DL_INVALID_POINTER =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_POINTER,
	CSSMERR_DL_INVALID_INPUT_POINTER =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_INPUT_POINTER,
	CSSMERR_DL_INVALID_OUTPUT_POINTER =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_OUTPUT_POINTER,
	CSSMERR_DL_FUNCTION_NOT_IMPLEMENTED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_FUNCTION_NOT_IMPLEMENTED,
	CSSMERR_DL_SELF_CHECK_FAILED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_SELF_CHECK_FAILED,
	CSSMERR_DL_OS_ACCESS_DENIED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_OS_ACCESS_DENIED,
	CSSMERR_DL_FUNCTION_FAILED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_FUNCTION_FAILED
};

/* DL Error Values Derived from ACL-based Error Codes. */
enum {
	CSSMERR_DL_OPERATION_AUTH_DENIED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_OPERATION_AUTH_DENIED,
	CSSMERR_DL_OBJECT_USE_AUTH_DENIED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_OBJECT_USE_AUTH_DENIED,
	CSSMERR_DL_OBJECT_MANIP_AUTH_DENIED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_OBJECT_MANIP_AUTH_DENIED,
	CSSMERR_DL_OBJECT_ACL_NOT_SUPPORTED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_OBJECT_ACL_NOT_SUPPORTED,
	CSSMERR_DL_OBJECT_ACL_REQUIRED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_OBJECT_ACL_REQUIRED,
	CSSMERR_DL_INVALID_ACCESS_CREDENTIALS =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_ACCESS_CREDENTIALS,
	CSSMERR_DL_INVALID_ACL_BASE_CERTS =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_BASE_CERTS,
	CSSMERR_DL_ACL_BASE_CERTS_NOT_SUPPORTED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_ACL_BASE_CERTS_NOT_SUPPORTED,
	CSSMERR_DL_INVALID_SAMPLE_VALUE =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_SAMPLE_VALUE,
	CSSMERR_DL_SAMPLE_VALUE_NOT_SUPPORTED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_SAMPLE_VALUE_NOT_SUPPORTED,
	CSSMERR_DL_INVALID_ACL_SUBJECT_VALUE =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_SUBJECT_VALUE,
	CSSMERR_DL_ACL_SUBJECT_TYPE_NOT_SUPPORTED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_ACL_SUBJECT_TYPE_NOT_SUPPORTED,
	CSSMERR_DL_INVALID_ACL_CHALLENGE_CALLBACK =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_CHALLENGE_CALLBACK,
	CSSMERR_DL_ACL_CHALLENGE_CALLBACK_FAILED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_ACL_CHALLENGE_CALLBACK_FAILED,
	CSSMERR_DL_INVALID_ACL_ENTRY_TAG =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_ENTRY_TAG,
	CSSMERR_DL_ACL_ENTRY_TAG_NOT_FOUND =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_ACL_ENTRY_TAG_NOT_FOUND,
	CSSMERR_DL_INVALID_ACL_EDIT_MODE =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_ACL_EDIT_MODE,
	CSSMERR_DL_ACL_CHANGE_FAILED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_ACL_CHANGE_FAILED,
	CSSMERR_DL_INVALID_NEW_ACL_ENTRY =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_NEW_ACL_ENTRY,
	CSSMERR_DL_INVALID_NEW_ACL_OWNER =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_NEW_ACL_OWNER,
	CSSMERR_DL_ACL_DELETE_FAILED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_ACL_DELETE_FAILED,
	CSSMERR_DL_ACL_REPLACE_FAILED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_ACL_REPLACE_FAILED,
	CSSMERR_DL_ACL_ADD_FAILED =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_ACL_ADD_FAILED
};

/* DL Error Values for Specific Data Types. */
enum {
	CSSMERR_DL_INVALID_DB_HANDLE =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_DB_HANDLE,
	CSSMERR_DL_INVALID_PASSTHROUGH_ID =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_PASSTHROUGH_ID,
	CSSMERR_DL_INVALID_NETWORK_ADDR =
		CSSM_DL_BASE_ERROR + CSSM_ERRCODE_INVALID_NETWORK_ADDR
};

/* DL Module-Specific Error Values */
enum {
	CSSM_DL_BASE_DL_ERROR =
		CSSM_DL_BASE_ERROR + CSSM_ERRORCODE_COMMON_EXTENT,
	CSSMERR_DL_DATABASE_CORRUPT =					CSSM_DL_BASE_DL_ERROR + 1,
	CSSMERR_DL_INVALID_RECORD_INDEX =				CSSM_DL_BASE_DL_ERROR + 8,
	CSSMERR_DL_INVALID_RECORDTYPE =					CSSM_DL_BASE_DL_ERROR + 9,
	CSSMERR_DL_INVALID_FIELD_NAME =					CSSM_DL_BASE_DL_ERROR + 10,
	CSSMERR_DL_UNSUPPORTED_FIELD_FORMAT =			CSSM_DL_BASE_DL_ERROR + 11,
	CSSMERR_DL_UNSUPPORTED_INDEX_INFO =				CSSM_DL_BASE_DL_ERROR + 12,
	CSSMERR_DL_UNSUPPORTED_LOCALITY =				CSSM_DL_BASE_DL_ERROR + 13,
	CSSMERR_DL_UNSUPPORTED_NUM_ATTRIBUTES =			CSSM_DL_BASE_DL_ERROR + 14,
	CSSMERR_DL_UNSUPPORTED_NUM_INDEXES =			CSSM_DL_BASE_DL_ERROR + 15,
	CSSMERR_DL_UNSUPPORTED_NUM_RECORDTYPES =		CSSM_DL_BASE_DL_ERROR + 16,
	CSSMERR_DL_UNSUPPORTED_RECORDTYPE =				CSSM_DL_BASE_DL_ERROR + 17,
	CSSMERR_DL_FIELD_SPECIFIED_MULTIPLE =			CSSM_DL_BASE_DL_ERROR + 18,
	CSSMERR_DL_INCOMPATIBLE_FIELD_FORMAT =			CSSM_DL_BASE_DL_ERROR + 19,
	CSSMERR_DL_INVALID_PARSING_MODULE =				CSSM_DL_BASE_DL_ERROR + 20,
	CSSMERR_DL_INVALID_DB_NAME =					CSSM_DL_BASE_DL_ERROR + 22,
	CSSMERR_DL_DATASTORE_DOESNOT_EXIST =			CSSM_DL_BASE_DL_ERROR + 23,
	CSSMERR_DL_DATASTORE_ALREADY_EXISTS =			CSSM_DL_BASE_DL_ERROR + 24,
	CSSMERR_DL_DB_LOCKED =							CSSM_DL_BASE_DL_ERROR + 25,
	CSSMERR_DL_DATASTORE_IS_OPEN =					CSSM_DL_BASE_DL_ERROR + 26,
	CSSMERR_DL_RECORD_NOT_FOUND =					CSSM_DL_BASE_DL_ERROR + 27,
	CSSMERR_DL_MISSING_VALUE =						CSSM_DL_BASE_DL_ERROR + 28,
	CSSMERR_DL_UNSUPPORTED_QUERY =					CSSM_DL_BASE_DL_ERROR + 29,
	CSSMERR_DL_UNSUPPORTED_QUERY_LIMITS =			CSSM_DL_BASE_DL_ERROR + 30,
	CSSMERR_DL_UNSUPPORTED_NUM_SELECTION_PREDS =	CSSM_DL_BASE_DL_ERROR + 31,
	CSSMERR_DL_UNSUPPORTED_OPERATOR =				CSSM_DL_BASE_DL_ERROR + 33,
	CSSMERR_DL_INVALID_RESULTS_HANDLE =				CSSM_DL_BASE_DL_ERROR + 34,
	CSSMERR_DL_INVALID_DB_LOCATION =				CSSM_DL_BASE_DL_ERROR + 35,
	CSSMERR_DL_INVALID_ACCESS_REQUEST =				CSSM_DL_BASE_DL_ERROR + 36,
	CSSMERR_DL_INVALID_INDEX_INFO =					CSSM_DL_BASE_DL_ERROR + 37,
	CSSMERR_DL_INVALID_SELECTION_TAG =				CSSM_DL_BASE_DL_ERROR + 38,
	CSSMERR_DL_INVALID_NEW_OWNER =					CSSM_DL_BASE_DL_ERROR + 39,
	CSSMERR_DL_INVALID_RECORD_UID =					CSSM_DL_BASE_DL_ERROR + 40,
	CSSMERR_DL_INVALID_UNIQUE_INDEX_DATA =			CSSM_DL_BASE_DL_ERROR + 41,
	CSSMERR_DL_INVALID_MODIFY_MODE =				CSSM_DL_BASE_DL_ERROR + 42,
	CSSMERR_DL_INVALID_OPEN_PARAMETERS =			CSSM_DL_BASE_DL_ERROR + 43,
	CSSMERR_DL_RECORD_MODIFIED =					CSSM_DL_BASE_DL_ERROR + 44,
	CSSMERR_DL_ENDOFDATA =							CSSM_DL_BASE_DL_ERROR + 45,
	CSSMERR_DL_INVALID_QUERY =						CSSM_DL_BASE_DL_ERROR + 46,
	CSSMERR_DL_INVALID_VALUE =						CSSM_DL_BASE_DL_ERROR + 47,
	CSSMERR_DL_MULTIPLE_VALUES_UNSUPPORTED =		CSSM_DL_BASE_DL_ERROR + 48,
	CSSMERR_DL_STALE_UNIQUE_RECORD =				CSSM_DL_BASE_DL_ERROR + 49
};


#ifdef __cplusplus
}
#endif

#endif /* _CSSMERR_H_ */
