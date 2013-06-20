/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://www.xbmc.org
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

#include "Gif.h"

Gif::Gif()
{
  m_dll.Load();
  m_strMimeType = "";
  m_thumbnailbuffer = NULL;
  m_numFrames = 0;

}

Gif::~Gif()
{
  if (m_dll.IsLoaded()) 
  {
    m_dll.Unload();
  }
}

bool Gif::LoadImageFromMemory(unsigned char* buffer, unsigned int bufSize, unsigned int width, unsigned int height){return false;}
bool Gif::Decode(const unsigned char *pixels, unsigned int pitch, unsigned int format){return false;}
bool Gif::CreateThumbnailFromSurface(unsigned char* bufferin, unsigned int width, unsigned int height, unsigned int format, unsigned int pitch, const CStdString& destFile, 
                                unsigned char* &bufferout, unsigned int &bufferoutSize){return false;}
void Gif::ReleaseThumbnailBuffer(){return;}

bool Gif::LoadGif(const char* file)
{
  if (!m_dll.IsLoaded())
    return false;
  int err = 0;
  GifFileType* gif;

  gif = m_dll.DGifOpenFileName(file, &err);
  if (!gif)
    return false;

  err = m_dll.DGifSlurp(gif);
  m_numFrames = gif->ImageCount;
  GifImageDesc des = gif->Image;
  GraphicsControlBlock block;

  m_dll.DGifSavedExtensionToGCB(gif, 0, &block);
  m_delay = block.DelayTime;
  m_dll.DGifCloseFile(gif);
  return true;
}