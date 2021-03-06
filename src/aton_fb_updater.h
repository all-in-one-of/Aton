/*
Copyright (c) 2019,
Dan Bethell, Johannes Saam, Vahan Sosoyan.
All rights reserved. See COPYING.txt for more details.
*/

#ifndef FBUpdater_h
#define FBUpdater_h

#include "aton_node.h"

// Our FrameBuffer updater thread
static void fb_updater(unsigned index, unsigned nthreads, void* data)
{
    Aton* node = reinterpret_cast<Aton*>(data);
    double frame, prev_frame = 0;
    const int ms = 20;
    
    while (node->m_legit && node->m_multiframes)
    {
        frame = node->uiContext().frame();
        
        if (!node->m_framebuffers.empty() && frame != prev_frame)
        {
            node->flag_update();
            prev_frame = frame;
        }
        else
            SleepMS(ms);
    }
}

#endif /* FBUpdater */
