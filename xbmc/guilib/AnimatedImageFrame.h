#pragma once
/*
 *      Copyright (C) 2012-2014 Team XBMC
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

class AnimatedImageFrame
{
public:

  AnimatedImageFrame() : m_width(0), m_height(0), m_pImage(NULL), m_delay(0), m_imageSize(0) {};

  AnimatedImageFrame(const AnimatedImageFrame& src) :
    m_height(src.m_height),
    m_width(src.m_width),
    m_pImage(NULL),
    m_delay(src.m_delay),
    m_imageSize(src.m_imageSize)
  {
    if (src.m_pImage)
    {
      m_pImage = new unsigned char[m_imageSize];
      memcpy(m_pImage, src.m_pImage, m_imageSize);
    }
  }

  virtual ~AnimatedImageFrame() {};

  unsigned int    m_width;
  unsigned int    m_height;
  unsigned char*  m_pImage;
  unsigned int    m_delay;

protected:
  unsigned int    m_imageSize;
};