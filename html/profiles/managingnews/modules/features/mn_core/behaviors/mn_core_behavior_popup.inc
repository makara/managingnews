<?php

class mn_core_behavior_popup extends openlayers_behavior {
  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'mn_core') .'/behaviors/mn_core_behavior_popup.js');
    return $this->options;
  }
}
