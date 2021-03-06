#ifndef UI_H
#define UI_H

#define UI_MAX_WIDGETS 128
#define UI_MAX_AUTO_LAYOUT_GROUPS 16
#define UI_MAX_WIDGET_ELEMENTS 16

#define UI_SRC_ID 1000
#define UIIDGen() UIIDInit(__LINE__ + UI_SRC_ID, 0)
#define UIIDGenI(i) UIIDInit(__LINE__ + UI_SRC_ID, i)

typedef enum widget_type
{
    UI_WIDGET_button,
    UI_WIDGET_custom_button,
    UI_WIDGET_option_button
} widget_type;

typedef struct ui_id
{
    u32 primary;
    u32 secondary;
} ui_id;

typedef struct ui_widget
{
    widget_type type;
    ui_id id;
    gs_vec2 rect_br;
    gs_vec2 rect_tl;
    f32 t_hot;
    f32 t_active;
    gs_color_t color;
    char *text;

    union
    {
        struct option
        {
            b32 is_active;
        } option;
    };
} ui_widget;

typedef struct ui
{
    gs_immediate_draw_t *renderer;
    gs_command_buffer_t *command_buffer;
    gs_asset_font_t *font;

    f32 mouse_x;
    f32 mouse_y;
    b32 left_mouse_down;
    b32 right_mouse_down;

    u32 widget_count;
    ui_widget widgets[UI_MAX_WIDGETS];
    ui_id hot;
    ui_id active;
} ui;

typedef struct ui_option
{
    ui_id selected;
    gs_color_t color;
    gs_vec2 size;
    b32 initalized;
} ui_option;

#endif
