<?php

class mn_core_behavior_scalepoints extends openlayers_behavior {
  /**
   * Override of options_init().
   */
  function options_init() {
    $options = parent::options_init();
    $options['min'] = array(
      'pointRadius' => 5,
    );
    $options['max'] = array(
      'pointRadius' => 20,
    );
    $options['distinct'] = 5;
    return $options;
  }

  /**
   * Override of options_form().
   */
  function options_form() {
    $form = parent::options_form();
    $form['min'] = array(
      '#tree' => TRUE,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#type' => 'fieldset',
      '#title' => t('Minimum values'),
    );
    $form['max'] = array(
      '#tree' => TRUE,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#type' => 'fieldset',
      '#title' => t('Maximum values'),
    );
    foreach (array('min', 'max') as $key) {
      $form[$key]['pointRadius'] = array(
        '#title' => t('Radius'),
        '#type' => 'textfield',
        '#size' => 4,
        '#default_value' => $this->options[$key]['pointRadius'],
      );
      $form[$key]['fillOpacity'] = array(
        '#title' => t('Fill opacity'),
        '#type' => 'textfield',
        '#size' => 4,
        '#maxlength' => 4,
        '#default_value' => $this->options[$key]['fillOpacity'],
      );
      $form[$key]['strokeWidth'] = array(
        '#title' => t('Stroke width'),
        '#type' => 'textfield',
        '#size' => 4,
        '#maxlength' => 4,
        '#default_value' => $this->options[$key]['strokeWidth'],
      );
      // @TODO: Handle color gradation using API functions in color module
      /*
      $form[$key]['fillColor'] = array(
        '#title' => t('Fill color'),
        '#type' => 'textfield',
        '#size' => 7,
        '#maxlength' => 7,
        '#default_value' => $this->options[$key]['fillColor'],
      );
      $form[$key]['strokeColor'] = array(
        '#title' => t('Stroke color'),
        '#type' => 'textfield',
        '#size' => 7,
        '#maxlength' => 7,
        '#default_value' => $this->options[$key]['strokeColor'],
      );
      */
    }
    $form['distinct'] = array(
      '#title' => t('Number of distinct sizes'),
      '#type' => 'textfield',
      '#default_value' => $this->options['distinct'],
    );
    return $form;
  }

  /**
   * Generate weight segments from the number of distinct values.
   */
  function get_weights() {
    if (!is_numeric($this->options['distinct']) || $this->options['distinct'] < 1) {
      $this->options['distinct'] = 5;
    }
    $size = number_format(1 / $this->options['distinct'], 2);
    $weights = array();
    for ($i = 1; $i < $this->options['distinct']; $i++) {
      $key = (string) ($i * $size);
      $weights[$key] = $i;
    }
    $weights[1] = $this->options['distinct'];
    return $weights;
  }

  /**
   * Generate a weight => pointRadius mapping.
   */
  function get_styles() {
    $weights = array_values($this->get_weights());
    $styles = array();
    foreach (array_keys($this->options['min']) as $key) {
      if (!empty($this->options['min'][$key]) ||  !empty($this->options['max'][$key])) {
        $pointdiff = ($this->options['max'][$key] - $this->options['min'][$key]) / $this->options['distinct'];
        $pointdiff = number_format($pointdiff, 2);
        foreach ($weights as $weight) {
          $styles[$weight][$key] = $this->options['min'][$key] + ($weight - 1) * $pointdiff;
        }
        $styles[$this->options['distinct']][$key] = $this->options['max'][$key];
      }
    }
    return $styles;
  }

  /**
   * Render.
   */
  function render(&$map) {
    // Iterate twice. First determine min/max counts
    $min = $max = 0;
    foreach ($map['layers'] as $layer) {
      if ($layer['type'] == 'Vector' && !empty($layer['features'])) {
        foreach ($layer['features'] as $feature) {
          if (isset($feature['attributes']['count']) && $count = $feature['attributes']['count']) {
            $max = ($count > $max) ? $count : $max;
            $min = ($count < $min) ? $count : $min;
          }
        }
      }
    }
    if ($max > 0) {
      // Get weight divisions
      $weights = $this->get_weights();
      foreach ($map['layers'] as $k => $layer) {
        if ($layer['type'] == 'Vector' && !empty($layer['features'])) {
          foreach ($layer['features'] as $j => $feature) {
            if (isset($feature['attributes']['count']) && $count = $feature['attributes']['count']) {
              foreach ($weights as $percentile => $weight) {
                // For single elements, always use the smallest weight
                if ($max == 1) {
                  $map['layers'][$k]['features'][$j]['attributes']['weight'] = 1;
                }
                else if (($count/$max) <= $percentile) {
                  $map['layers'][$k]['features'][$j]['attributes']['weight'] = $weight;
                  break;
                }
              }
            }
          }
        }
      }
    }

    drupal_add_js(drupal_get_path('module', 'mn_core') .'/behaviors/mn_core_behavior_scalepoints.js');
    $options = array();
    $options['styles'] = $this->get_styles();

    return $options;
  }
}
