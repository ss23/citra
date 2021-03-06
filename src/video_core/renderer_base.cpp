// Copyright 2015 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <memory>

#include "common/make_unique.h"

#include "core/settings.h"

#include "video_core/renderer_base.h"
#include "video_core/video_core.h"
#include "video_core/swrasterizer.h"
#include "video_core/renderer_opengl/gl_rasterizer.h"

void RendererBase::RefreshRasterizerSetting() {
    bool hw_renderer_enabled = VideoCore::g_hw_renderer_enabled;
    if (rasterizer == nullptr || opengl_rasterizer_active != hw_renderer_enabled) {
        opengl_rasterizer_active = hw_renderer_enabled;

        if (hw_renderer_enabled) {
            rasterizer = Common::make_unique<RasterizerOpenGL>();
        } else {
            rasterizer = Common::make_unique<VideoCore::SWRasterizer>();
        }
        rasterizer->InitObjects();
        rasterizer->Reset();
    }
}
