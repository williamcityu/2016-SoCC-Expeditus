/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2007 University of Washington
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef DROPTAIL_H
#define DROPTAIL_H

#include <queue>
#include "ns3/packet.h"
#include "ns3/queue.h"

namespace ns3 {

class TraceContainer;

/**
 * \ingroup queue
 *
 * \brief A FIFO packet queue that drops tail-end packets on overflow
 */
class DropTailQueue : public Queue {
public:
  static TypeId GetTypeId (void);
  /**
   * \brief DropTailQueue Constructor
   *
   * Creates a droptail queue with a maximum size of 100 packets by default
   */
  DropTailQueue ();

  virtual ~DropTailQueue();

  /**
   * Enumeration of the modes supported in the class.
   *
   */
  enum Mode {
    ILLEGAL,     /**< Mode not set */
    PACKETS,     /**< Use number of packets for maximum queue size */
    BYTES,       /**< Use number of bytes for maximum queue size */  
  };

  /**
   * Set the operating mode of this device.
   *
   * \param mode The operating mode of this device.
   *
   */
  void SetMode (DropTailQueue::Mode mode);

  /**
   * Get the encapsulation mode of this device.
   *
   * \returns The encapsulation mode of this device.
   */
  DropTailQueue::Mode  GetMode (void);

private:
  virtual bool DoEnqueue (Ptr<Packet> p);
  virtual Ptr<Packet> DoDequeue (void);
  virtual Ptr<const Packet> DoPeek (void) const;
//  void ClearValue ();

  std::queue<Ptr<Packet> > m_packets;
  uint32_t m_maxPackets;
  uint32_t m_maxBytes;
  uint32_t m_bytesInQueue;
//  uint32_t m_SamplePackets;
//  bool m_StartSample;
  uint32_t m_CongestionLevel;
  Mode     m_mode;

  uint32_t m_markLine; //pks
};

}; // namespace ns3

#endif /* DROPTAIL_H */