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
 * MediaTek Inc. (C) 2015. All rights reserved.
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

package com.mediatek.internal.telephony.cdma.pluscode;

/**
 * This class represents mcc, sid, min ltm off, max ltm off states.
 * @hide
 */
public class MccSidLtmOff {
    public int mMcc;
    public int mSid;
    public int mLtmOffMin;
    public int mLtmOffMax;

    public static final int LTM_OFF_INVALID = 100;

    /**
     * Default constructor.
     */
    public MccSidLtmOff() {
        mMcc = -1;
        mSid = -1;
        mLtmOffMin = LTM_OFF_INVALID;
        mLtmOffMax = LTM_OFF_INVALID;
    }

    /**
     * Constructor.
     * @param mcc MCC
     * @param sid SID
     * @param ltmOffMin min LTM off
     * @param ltmOffMax max LTM off
     */
    public MccSidLtmOff(int mcc, int sid, int ltmOffMin, int ltmOffMax) {
        mMcc = mcc;
        mSid = sid;
        mLtmOffMin = ltmOffMin;
        mLtmOffMax = ltmOffMax;
    }

    /**
     * Copy constructor.
     * @param t the MccSidLtmOff object
     */
    public MccSidLtmOff(MccSidLtmOff t) {
        copyFrom(t);
    }

    /**
     * @hide
     */
    protected void copyFrom(MccSidLtmOff t) {
        mMcc = t.mMcc;
        mSid = t.mSid;
        mLtmOffMin = t.mLtmOffMin;
        mLtmOffMax = t.mLtmOffMax;
    }

    public int getMcc() {
        return mMcc;
    }

    public int getSid() {
        return mSid;
    }

    public int getLtmOffMin() {
        return mLtmOffMin;
    }

    public int getLtmOffMax() {
        return mLtmOffMax;
    }
}
