#include <TestFireScript.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>
#include <Canis/AssetManager.hpp>

namespace
{
    Canis::ScriptConf scriptConf = {};
}

void RegisterTestFireScriptScript(Canis::App& _app)
{
    REGISTER_PROPERTY(scriptConf, TestFireScript, hideObject);

    DEFAULT_CONFIG(scriptConf, TestFireScript);

    scriptConf.DEFAULT_DRAW_INSPECTOR(TestFireScript);

    _app.RegisterScript(scriptConf);
}

DEFAULT_UNREGISTER_SCRIPT(scriptConf, TestFireScript)

void TestFireScript::Create() {}

void TestFireScript::Ready() {
    //if (hideObject)
    //    hideObject->active = false;

    //i32 textureId = AssetManager::LoadTexture("assets/textures/fire_textures/fire_" + std::to_string(1) + ".png");
    //i32 materialId = entity.GetComponent<Material>().materialId;
    //MaterialAsset* material = AssetManager::GetMaterial(materialId);
    //material->albedoId = textureId;
    i32 textureId = AssetManager::LoadTexture("assets/textures/fire_textures/fire_1.png");
    entity.GetComponent<Material>().materialFields.SetTexture("albedoFireMap", textureId);
}

void TestFireScript::Destroy() {}

void TestFireScript::Update(float _dt) 
{
    static float frameTimer = 0.0f;
    static int currentFrame = 1;
    const int maxFrames = 4;
    
    frameTimer += _dt;

    if (frameTimer >= 0.5f) 
    {
        frameTimer = 0.0f;
        currentFrame++;
        
        if (currentFrame > maxFrames) 
            currentFrame = 1;

        // pathst to the texture and the numbers relatively, slight change from original
        std::string path = "assets/textures/fire_textures/fire_" + std::to_string(currentFrame) + ".png";
        i32 textureId = AssetManager::LoadTexture(path);
        
        entity.GetComponent<Material>().materialFields.SetTexture("albedoFireMap", textureId);
    }

    //ZA LIGHT FLICKA
    if (entity.HasComponent<Canis::PointLight>()) 
    {
        auto& light = entity.GetComponent<Canis::PointLight>();
        
        //flicker math calc
        // sinf, rand, and noise because I read that it makes it look more realistic
        static float lightTimer = 0.0f;
        lightTimer += _dt * 25.0f; 

        float baseIntensity = 200.0f;
        float baseRange = 20.0f;

        // flickerMultiplier will go rapidly between ~0.85 and ~1.15 roughly
        float flickerMultiplier = 1.0f + (sinf(lightTimer) * 0.1f) + ((rand() % 10) / 100.0f);

        light.intensity = baseIntensity * flickerMultiplier;
        light.range = baseRange * (flickerMultiplier * 0.95f);
    }
}
