#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <zmk/events/sticky_key_event.h>
#include <zmk/widgets/sticky_keys.h>

static void sticky_key_status_render() {
    if (sticky_key_is_active(LSHFT)) {
        zmk_display_write_text("SHFT");
    }
    if (sticky_key_is_active(LEFT_COMMAND)) {
        zmk_display_write_text("CMD");
    }
    if (sticky_key_is_active(LEFT_CONTROL)) {
        zmk_display_write_text("CTRL");
    }
    // You can add more checks for other sticky keys here
}

static struct zmk_widget sticky_key_widget;

int sticky_key_widget_init(struct zmk_widget *widget) {
    widget->render = sticky_key_status_render;
    return 0;
}
