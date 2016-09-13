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

#include "pcaptransmitter.h"

PcapTransmitter::PcapTransmitter(const char *device)
    : txThread_(device)
{
}

bool PcapTransmitter::setRateAccuracy(
        AbstractPort::Accuracy accuracy)
{
    return txThread_.setRateAccuracy(accuracy);
}

void PcapTransmitter::clearPacketList()
{
    txThread_.clearPacketList();
}

void PcapTransmitter::loopNextPacketSet(
        qint64 size,
        qint64 repeats,
        long repeatDelaySec,
        long repeatDelayNsec)
{
    txThread_.loopNextPacketSet(size, repeats, repeatDelaySec, repeatDelayNsec);
}

bool PcapTransmitter::appendToPacketList(long sec, long nsec,
        const uchar *packet, int length)
{
    return txThread_.appendToPacketList(sec, nsec, packet, length);
}

void PcapTransmitter::setHandle(pcap_t *handle)
{
    txThread_.setHandle(handle);
}

void PcapTransmitter::setPacketListLoopMode(
        bool loop,
        quint64 secDelay,
        quint64 nsecDelay)
{
    txThread_.setPacketListLoopMode(loop, secDelay, nsecDelay);
}

void PcapTransmitter::useExternalStats(AbstractPort::PortStats *stats)
{
    txThread_.useExternalStats(stats);
}

void PcapTransmitter::start()
{
    txThread_.start();
}

void PcapTransmitter::stop()
{
    txThread_.stop();
}

bool PcapTransmitter::isRunning()
{
    return txThread_.isRunning();
}
