/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#undef DEBUG_CALLS

#include <IOKit/audio/IOAudioControlUserClient.h>
#include <IOKit/audio/IOAudioControl.h>
#include <IOKit/audio/IOAudioTypes.h>
#include <IOKit/audio/IOAudioDefines.h>

#include <IOKit/IOLib.h>
#include <IOKit/IOCommandGate.h>

#define super IOUserClient

OSDefineMetaClassAndStructors(IOAudioControlUserClient, IOUserClient)
OSMetaClassDefineReservedUsed(IOAudioControlUserClient, 0);

OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 1);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 2);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 3);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 4);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 5);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 6);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 7);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 8);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 9);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 10);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 11);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 12);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 13);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 14);
OSMetaClassDefineReservedUnused(IOAudioControlUserClient, 15);

// New code here
void IOAudioControlUserClient::sendChangeNotification(UInt32 notificationType)
{
    if (notificationMessage) {
        kern_return_t kr;

		notificationMessage->type = notificationType;
        kr = mach_msg_send_from_kernel(&notificationMessage->messageHeader, notificationMessage->messageHeader.msgh_size);
        if ((kr != MACH_MSG_SUCCESS) && (kr != MACH_SEND_TIMED_OUT)) {
            IOLog("IOAudioControlUserClient: sendRangeChangeNotification() failed - msg_send returned: %d\n", kr);
        }
    }
}

// Original code here...
IOAudioControlUserClient *IOAudioControlUserClient::withAudioControl(IOAudioControl *control, task_t clientTask, void *securityID, UInt32 type)
{
    IOAudioControlUserClient *client;

    client = new IOAudioControlUserClient;

    if (client) {
        if (!client->initWithAudioControl(control, clientTask, securityID, type)) {
            client->release();
            client = 0;
        }
    }
    
    return client;
}

bool IOAudioControlUserClient::initWithAudioControl(IOAudioControl *control, task_t task, void *securityID, UInt32 type)
{
    if (!initWithTask(task, securityID, type)) {
        return false;
    }

    if (!control) {
        return false;
    }

    audioControl = control;
    clientTask = task;
    notificationMessage = 0;

    return true;
}

void IOAudioControlUserClient::free()
{
#ifdef DEBUG_CALLS
    IOLog("IOAudioControlUserClient[%p]::free()\n", this);
#endif
    
    if (notificationMessage) {
        IOFreeAligned(notificationMessage, sizeof(IOAudioNotificationMessage));
        notificationMessage = 0;
    }

    super::free();
}

IOReturn IOAudioControlUserClient::clientClose()
{
#ifdef DEBUG_CALLS
    IOLog("IOAudioControlUserClient[%p]::clientClose()\n", this);
#endif

    if (audioControl && !isInactive()) {
        audioControl->clientClosed(this);
        audioControl = 0;
    }
    
    return kIOReturnSuccess;
}

IOReturn IOAudioControlUserClient::clientDied()
{
#ifdef DEBUG_CALLS
    IOLog("IOAudioControlUserClient[%p]::clientDied()\n", this);
#endif

    return clientClose();
}

IOReturn IOAudioControlUserClient::registerNotificationPort(mach_port_t port,
                                                            UInt32 type,			// No longer used now that we have the generic sendChangeNotification routine
                                                            UInt32 refCon)
{
    IOReturn result = kIOReturnSuccess;

    if (!isInactive()) {
        if (notificationMessage == 0) {
            notificationMessage = (IOAudioNotificationMessage *)IOMallocAligned(sizeof(IOAudioNotificationMessage), sizeof (IOAudioNotificationMessage *));
            if (!notificationMessage) {
                return kIOReturnNoMemory;
            }
        }
    
        notificationMessage->messageHeader.msgh_bits = MACH_MSGH_BITS(MACH_MSG_TYPE_COPY_SEND, 0);
        notificationMessage->messageHeader.msgh_size = sizeof(IOAudioNotificationMessage);
        notificationMessage->messageHeader.msgh_remote_port = port;
        notificationMessage->messageHeader.msgh_local_port = MACH_PORT_NULL;
        notificationMessage->messageHeader.msgh_reserved = 0;
        notificationMessage->messageHeader.msgh_id = 0;
    
        // notificationMessage->type = type;				// ignored now that we have the generic sendChangeNotification routine
        notificationMessage->ref = refCon;
    } else {
        result = kIOReturnNoDevice;
    }
    
    return result;
}

void IOAudioControlUserClient::sendValueChangeNotification()
{
	return sendChangeNotification(kIOAudioControlValueChangeNotification);
}
