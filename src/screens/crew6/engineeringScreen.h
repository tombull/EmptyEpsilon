#ifndef ENGINEERING_SCREEN_H
#define ENGINEERING_SCREEN_H

#include "gui/gui2_overlay.h"
#include "shipTemplate.h"
#include "playerInfo.h"

class GuiSelfDestructButton;
class GuiKeyValueDisplay;
class GuiLabel;
class GuiSlider;
class GuiAutoLayout;
class GuiImage;
class GuiArrow;
class GuiToggleButton;
class GuiProgressbar;
class GuiProgressSlider;

class EngineeringScreen : public GuiOverlay
{
private:
    GuiOverlay* background_crosses;

    GuiKeyValueDisplay* energy_display;
    GuiKeyValueDisplay* hull_display;
    GuiKeyValueDisplay* front_shield_display;
    GuiKeyValueDisplay* rear_shield_display;
    GuiKeyValueDisplay* coolant_display;
    GuiKeyValueDisplay* repair_display;
    GuiSelfDestructButton* self_destruct_button;
    GuiLabel* power_label;
    GuiSlider* power_slider;
    GuiLabel* coolant_label;
    GuiSlider* coolant_slider;
    GuiLabel* repair_label;
    GuiSlider* repair_slider;

    class SystemRow
    {
    public:
        GuiAutoLayout* layout;
        GuiToggleButton* button;
        GuiProgressbar* damage_bar;
        GuiImage* damage_icon;
        GuiLabel* damage_label;
        GuiProgressbar* heat_bar;
        GuiArrow* heat_arrow;
        GuiImage* heat_icon;
        GuiLabel* heat_label;
        GuiProgressSlider* power_bar;
        GuiLabel* power_label;
        GuiProgressSlider* coolant_bar;
        GuiLabel* coolant_label;
        GuiProgressSlider* repair_bar;
        GuiLabel* repair_label;
    };
    std::vector<SystemRow> system_rows;
    GuiAutoLayout* system_effects_container;
    std::vector<GuiKeyValueDisplay*> system_effects;
    unsigned int system_effects_index;
    ESystem selected_system;

    float previous_energy_measurement;
    float previous_energy_level;
    float average_energy_delta;
    
    void addSystemEffect(string key, string value);
    void selectSystem(ESystem system);
public:
    EngineeringScreen(GuiContainer* owner, ECrewPosition crew_position=engineering);
    
    virtual void onDraw(sf::RenderTarget& window) override;
    virtual void onHotkey(const HotkeyResult& key) override;
    virtual bool onJoystickAxis(const AxisAction& axisAction) override;
};

#endif//ENGINEERING_SCREEN_H
