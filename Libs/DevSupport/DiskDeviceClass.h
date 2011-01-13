/*
 * Copyright (C) 2009-2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */
#pragma once
#include "DeviceClass.h"

/// <summary>
/// The device class for disk devices.
/// </summary>
class DiskDeviceClass : public DeviceClass
{
public:
	DiskDeviceClass(void);
	virtual ~DiskDeviceClass(void);
	virtual std::list<Device*>& Refresh();
//	virtual NotifyStruct AddUsbDevice(LPCTSTR path);
//	virtual NotifyStruct RemoveUsbDevice(LPCTSTR path);

private:
   Device* CreateDevice(DeviceClass* deviceClass, SP_DEVINFO_DATA deviceInfoData, CStdString path);

public:
	CStdString ToString() { return _T("DiskDeviceClass"); }
};
