#include <TestGrassBladesScript.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>

namespace
{
    Canis::ScriptConf scriptConf = {};
}

void RegisterTestGrassBladesScriptScript(Canis::App& _app)
{
    // REGISTER_PROPERTY(scriptConf, TestGrassBladesScript, exampleProperty);

    DEFAULT_CONFIG(scriptConf, TestGrassBladesScript);

    scriptConf.DEFAULT_DRAW_INSPECTOR(TestGrassBladesScript);

    _app.RegisterScript(scriptConf);
}

DEFAULT_UNREGISTER_SCRIPT(scriptConf, TestGrassBladesScript)

void TestGrassBladesScript::Create() {}

void TestGrassBladesScript::Ready() {}

void TestGrassBladesScript::Destroy() {}

void TestGrassBladesScript::Update(float) {}
