#include <pebble.h>
#include "main.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_s911_18;
static TextLayer *time;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_s911_18 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_S911_18));
  // time
  time = text_layer_create(GRect(37, 29, 56, 36));
  text_layer_set_background_color(time, GColorClear);
  text_layer_set_text_color(time, GColorWhite);
  text_layer_set_text(time, "2045");
  text_layer_set_font(time, s_res_s911_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)time);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(time);
  fonts_unload_custom_font(s_res_s911_18);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_main(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_main(void) {
  window_stack_remove(s_window, true);
}
