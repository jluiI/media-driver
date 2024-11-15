/*
* Copyright (c) 2021, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
//!
//! \file     decode_vp8_packet_xe2_lpm_base.h
//! \brief    Defines the implementation of vp8 decode packet of Xe2_LPM
//!

#ifndef __DECODE_VP8_PACKET_SINGLE_XE2_LPM_BASE_H__
#define __DECODE_VP8_PACKET_SINGLE_XE2_LPM_BASE_H__

#include "decode_vp8_packet.h"
#include "codec_hw_xe2_lpm_base.h"

namespace decode
{

class Vp8DecodePktXe2_Lpm_Base : public Vp8DecodePkt
{
public:
    Vp8DecodePktXe2_Lpm_Base(MediaPipeline *pipeline, MediaTask *task, CodechalHwInterfaceNext *hwInterface) :
        Vp8DecodePkt(pipeline, task, hwInterface)
    {
        m_hwInterface = dynamic_cast<CodechalHwInterfaceXe2_Lpm_Base *>(hwInterface);
    }

    virtual ~Vp8DecodePktXe2_Lpm_Base() {}

    //!
    //! \brief  Add the command sequence into the commandBuffer and
    //!         and return to the caller task
    //! \param  [in] commandBuffer
    //!         Pointer to the command buffer which is allocated by caller
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    virtual MOS_STATUS Submit(MOS_COMMAND_BUFFER* commandBuffer, uint8_t packetPhase = otherPacket) override;

protected:
    MOS_STATUS PackPictureLevelCmds(MOS_COMMAND_BUFFER &cmdBuffer);
    MOS_STATUS PackSliceLevelCmds(MOS_COMMAND_BUFFER &cmdBuffer);
    MOS_STATUS EnsureAllCommandsExecuted(MOS_COMMAND_BUFFER &cmdBuffer);

    CodechalHwInterfaceXe2_Lpm_Base *m_hwInterface = nullptr;

MEDIA_CLASS_DEFINE_END(decode__Vp8DecodePktXe2_Lpm_Base)
};

}

#endif
