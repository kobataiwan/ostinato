/*
Copyright (C) 2010-2016 Srivats P.

This file is part of "Ostinato"

This is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#ifndef _PCAP_TRANSMITTER_H
#define _PCAP_TRANSMITTER_H

#include "abstractport.h"
#include "pcaptxthread.h"

class PcapTransmitter
{
public:
    PcapTransmitter(const char *device);

    bool setRateAccuracy(AbstractPort::Accuracy accuracy);

    void clearPacketList();
    void loopNextPacketSet(qint64 size, qint64 repeats,
                           long repeatDelaySec, long repeatDelayNsec);
    bool appendToPacketList(long sec, long usec, const uchar *packet,
                            int length);
    void setPacketListLoopMode(bool loop, quint64 secDelay, quint64 nsecDelay);

    void setHandle(pcap_t *handle);
    void useExternalStats(AbstractPort::PortStats *stats);

    void start();
    void stop();
    bool isRunning();

private:
    PcapTxThread txThread_;
};

#endif

