/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_SF_WATCHDOG
#define ANDROID_SF_WATCHDOG

#include <utils/threads.h>
#include "SurfaceFlinger.h"
#include <utils/Singleton.h>
#include <utils/KeyedVector.h>

namespace android {

class SFWatchDog : public Thread
{
public:
                SFWatchDog();
    virtual    ~SFWatchDog();

    static sp<SFWatchDog> getInstance();

    bool        isSFThreadHang(nsecs_t* pStopTime);

    // set watch timestampe for main thread
    void        markStartTransactionTime(uint32_t index);
    void        unmarkStartTransactionTime(uint32_t index);

    // to work with screen status
    void        screenReleased();
    void        screenAcquired();

    uint32_t    registerNodeName(const char* name);
    void        setThreshold(const nsecs_t& time);
    nsecs_t     getThreshold();

    ssize_t     registerVirtualDisplay(const sp<ANativeWindow>& nativeWindow, const String8& info);
    ssize_t     unregisterVirtualDisplay(const sp<ANativeWindow>& nativeWindow);

private:
    static sp<SFWatchDog> sInstance;
    static Mutex          sLock;

    virtual bool        threadLoop();
    virtual status_t    readyToRun();
    virtual void        onFirstRef();

    void                getProperty();
    bool                createFolder(const char* path);

    mutable Mutex       mLock;
    mutable Mutex       mScreenLock;

    nsecs_t             mThreshold;
    uint32_t            mTimer;
    bool                mShowLog;
    uint32_t            mUpdateCount;

    bool                mFtraceDumped;

    class NodeElement : public RefBase {
    public:
        String8 mName;
        nsecs_t mStartTransactionTime;
    };

    Vector< sp<NodeElement> > mNodeList;
    KeyedVector< sp<ANativeWindow>, String8 > mVDSList;
};

}; // namespace android

#endif //ANDROID_SF_WATCHDOG
