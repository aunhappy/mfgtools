/*
 * Copyright (C) 2009-2011, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */
// StProgress.cpp: implementation of the StProgress class.
//
//////////////////////////////////////////////////////////////////////
#include "Observer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//
// synchronizing progress bar with tasks running.
// ----------------------------------------------
// all progress bar threads wait for m_start_event to signal.
// m_start_event signals when someone calls StProgress::UpdateProgress(task).
// the caller after finishing the task will wait on m_end_event to complete the progress bar if it has not completed.
// the thread that completed the progress bar will signal m_end_event
// the calling will resume the next task.
//


Observer::Observer()
{
	_inProgress = false;
}

Observer::~Observer()
{
}

bool Observer::InProgress()
{ 
	return _inProgress; 
}

void Observer::Begin()
{ 
	_inProgress = true; 
}

void Observer::Relax()
{
	_inProgress = false;
}
