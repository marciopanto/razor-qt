#ifndef RAZORDESKSWITCH_H
#define RAZORDESKSWITCH_H
#include "defs.h"
#include "razorplugin.h"
/**
 * @file razordeskswitch.h
 * @author Christopher "VdoP" Regali
 * @brief Declares Razordeskswitch
 */
#include "razor.h"

class RazorDeskSwitch;

/**
 * @brief a simple QSpinBox derivative for switching desktops
 */
class RazorDeskSwitchGUI: public QSpinBox
{
    Q_OBJECT
public:
    RazorDeskSwitchGUI(RazorDeskSwitch* parent);

protected:
    void wheelEvent(QWheelEvent* _event);

};

/**
 * @brief the plugin for switching Desktops via Razorbar
 */
class RazorDeskSwitch: public RazorPlugin
{
    Q_OBJECT
public:
    RazorDeskSwitch(RazorBar * panel, QWidget * parent, const QString & name);
    ~RazorDeskSwitch();
    bool handleEvent(XEvent* _event);

    int widthForHeight(int h)
    {
        return gui->width();
    }
    int heightForWidth(int w)
    {
        return gui->height();
    }
    RazorPlugin::RazorPluginSizing sizePriority()
    {
        return RazorPlugin::Static;
    }

private:
    int desktop;
    RazorDeskSwitchGUI* gui;
};

extern "C" RazorPlugin* init(RazorBar* panel, QWidget* parent, const QString & name);

#endif