#include "IRenderScript.h"
#include "../controller/CentralController.h"
#include "../controller/RenderController.h"

std::string RenderScript::static_name = "";
RenderScript::RenderScript(RenderFunc f){
#ifdef GL_ERROR_HOOK
    m_render = f;
#else
    render = f;
#endif
    std::swap(name, static_name);
    if(name == "")
        global::con<RenderCtrl>().addScript(std::move(*this));
    else
        global::con<RenderCtrl>().addScript(this);
}

void RenderScript::setRender(RenderFunc &&f) {
#ifdef GL_ERROR_HOOK
    m_render = f;
#else
    render = f;
#endif
}

void* RenderScript::operator new(size_t size, std::string render_name){
    static_name = render_name;
    return  ::operator new(size);
}

#ifdef GL_ERROR_HOOK
void RenderScript::render(QTime &t) {
    if(!is_paused) m_render(t);
    auto er = gl.glGetError();
    if(er)
        LOG(INFO) << "catch Error: " << this << ' ' << er;
}
#endif
