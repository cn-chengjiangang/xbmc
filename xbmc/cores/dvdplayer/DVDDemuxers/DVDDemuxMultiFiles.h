/*
 *      Copyright (C) 2005-2014 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#pragma once
#include "DVDDemux.h"
#include "DVDInputStreams/DVDInputStreamMultiFiles.h"
#include <vector>

typedef boost::shared_ptr<CDVDDemux> DemuxPtr;

class CDVDDemuxMultiFiles : public CDVDDemux
{
public:
  CDVDDemuxMultiFiles();
  virtual ~CDVDDemuxMultiFiles();

  void Reset();
  void Abort();
  void Flush();
  bool Open(CDVDInputStream* pInput);
  DemuxPacket* Read();
  bool SeekTime(int time, bool backwords = false, double* startpts = NULL);
  virtual void SetSpeed(int iSpeed) {};
  int GetStreamLength();
  virtual CDemuxStream* GetStream(int iStreamId);
  int GetNrOfStreams();
  virtual std::string GetFileName() {return "";};

  void CDVDDemuxMultiFiles::UpdateActiveSteams(StreamType type, unsigned int index);

protected:
  void Dispose();
  bool UpdateStreamMap(int inputIndex, DemuxPtr demuxer);
  bool RebuildStreamMap();

  std::map<unsigned int, std::pair<unsigned int, unsigned int>> m_StreamMap;
  CDVDInputStreamMultiFiles* m_pInput;
  CDVDDemux* m_pDemuxer;                            // master demuxer for current playing file
  std::map<int, DemuxPtr> m_pDemuxers;              // demuxers for current playing file
  unsigned int m_activeAudioStream;
  unsigned int m_activeVideoStream;
  double m_lastAudioDts;
  double m_lastVideoDts;
};
